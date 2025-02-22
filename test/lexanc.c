

/* lex1.c         14 Feb 01; 31 May 12       */

/* This file contains code stubs for the lexical analyzer.
   Rename this file to be lexanc.c and fill in the stubs.    */

/* Copyright (c) 2001 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "token.h"
#include "lexan.h"

/* This file will work as given with an input file consisting only
   of integers separated by blanks:
   make lex1
   lex1
   12345 123    345  357
   */

#define NUM_RESERVED 29
#define NUM_OPS 6
#define NUM_OPS_SYM 13
#define NUM_DELI 8
static char *reserved[] = {"array", "begin", "case", "const", "do", "downto", "else", "end", "file", "for", "function", "goto", "if", "label", "nil",   
"of", "packed", "procedure", "program", "record", "repeat", "set", "then", "to", "type", "until", "var", "while", "with"};
static char *ops[] = {"and", "or", "not", "div", "mod", "in"};
static char *ops_sym[] = {"+", "-", "*", "/", ":=", "=", "<>", "<", "<=", ">=", ">", "^", ","}; 
static char *deli[] = {",", ";", ":", "(",  ")", "[", " ]", ".."};
/* Skip blanks and whitespace.  Expand this function to skip comments too. */
void skipblanks ()
{
  int c;
  int c2;
  while ((c = peekchar()) != EOF
           && (c == ' ' || c == '\n' || c == '\t' || c == '{' 
           || (c == '(' && (c2 = peek2char()) == '*')))
  {
    c = getchar();
      if(c == '{'){
        while ((c = peekchar()) != EOF && c != '}')
        {
          c = getchar();
        }
      }
      else if(c == '(')
      {
        c = getchar(); //'*'
        while ((c = peekchar()) != EOF
               && (c != '*' || peek2char() != ')'))
        {
          c = getchar();
        }
	getchar();
	getchar();
      }
  }

}

/* Get identifiers and reserved words */
TOKEN identifier (TOKEN tok)
{
  int nc = 0;
  char str[16];
  char c;
  while( (c = peekchar()) != EOF
         && (CHARCLASS[c] == ALPHA || CHARCLASS[c] == NUMERIC))
  {
    c = getchar();
    if(nc < 15)
    {
      str[nc] = c;
      nc++;
      // check for reserved word
      if(CHARCLASS[c] == ALPHA)
      {
        for(int i = 0; i < NUM_RESERVED; ++i)
        {
          if(strcmp(reserved[i], str)== 0)
          {
            tok->tokentype = RESERVED;
            tok->whichval = (i+1);
            return tok;
          }
        }
        for(int i = 0; i < NUM_OPS; ++i)
        {
          if(strcmp(ops[i], str)== 0)
          {
            tok->tokentype = OPERATOR;
            tok->whichval = (i+14);
            return tok;
          }
        }
      }
    }
  }
  tok->tokentype = IDENTIFIERTOK;
  strcpy(tok->stringval,str);
  return tok;
}

TOKEN getstring (TOKEN tok)
{
  char str[16];
  int nc = 0;
  char c = getchar(); // c == '\''
  while( ((c = peekchar()) != EOF && c != '\'') 
        || (c == '\'' && peek2char() =='\''))
  {
    c = getchar();
    if(nc < 15)
    {
      if(c == '\'')
      {
        c = getchar();
      }
      str[nc] = c;
      nc++;
    }
  }
  getchar();
  tok->tokentype = STRINGTOK;
  strcpy(tok->stringval,str);
  return tok;
}

TOKEN special (TOKEN tok)
{
  char c;
  char c2;
  char str[5];
  while( (c = peekchar()) != EOF
        && CHARCLASS[c] == SPECIAL)
  {
    c = getchar();
    str[0] = c;
    if(CHARCLASS[peekchar()] == SPECIAL && c != peekchar())
    {
      str[1] = peekchar();
    
      for(int i = 0; i < NUM_OPS; ++i)
      {
        if(strcmp(str, ops_sym[i]) == 0)
        {
          getchar();
          tok->tokentype =  OPERATOR;
          tok->whichval =  (i+1);
          return tok;
        }
      }
      for(int i = 0; i < NUM_DELI; ++i)
      {
        if(strcmp(str, deli[i]) == 0)
        {
          getchar();
          tok->tokentype =  DELIMITER;
          tok->whichval =  (i+1);
          return tok;
        }
      }
    }
    else if(c == '.' && peekchar() == '.')
    {
      getchar();
      tok->tokentype =  DELIMITER;
      tok->whichval =  8;
      return tok;
    }
    else
    {
      for(int i = 0; i < NUM_OPS; ++i)
      {
        if(strcmp(str, ops_sym[i]) == 0)
        {
          getchar();
          tok->tokentype =  OPERATOR;
          tok->whichval =  (i+1);
          return tok;
        }
      }
      for(int i = 0; i < NUM_DELI; ++i)
      {
        if(strcmp(str, deli[i]) == 0)
        {
          getchar();
          tok->tokentype =  DELIMITER;
          tok->whichval =  (i+1);
          return tok;
        }
      }
    }
  }

}

/* Get and convert unsigned numbers of all types. */
TOKEN number (TOKEN tok)
{
  long num = 0;
  double f = 0;
  int nc = 0;
  int c, charval;
  int int_overflow = 0;
  int float_overflow = 0;
  int expo = 0; // exponent to mutiply to get the original value
  int exponent = 0; // exponent that is mult by scientific rep.
  int num_sig = 0; 

  while ( (c = peekchar()) != EOF
          && CHARCLASS[c] == NUMERIC)
  {
    // TO DO: CHECK float OVERFLOW

    c = getchar();
    charval = (c - '0');

    // check for int overflow
    if(nc > 10 || num > 214748364 || (num == 214748364 && charval > 7 ))
      int_overflow = 1;

    // increase int value
    num = num*10 + charval;

    // incase nc
    if(f > 0 || charval > 0)
    {
      nc++;
      if(num_sig < 8)
      {
        num_sig++;
        f = f*10 + charval;
      }
      else
        expo++;
    }
  }

  c = getchar();

  // if the number is integer return integer
  if((c != '.' && c != 'e') || (c == '.' && CHARCLASS[peekchar()] != NUMERIC))
  {
    // print int overflow
    if(int_overflow == 1)
    printf("Integer number out of range\n");
    tok->tokentype = NUMBERTOK;
    tok->datatype = INTEGER;
    tok->intval = num;
    return (tok);
  }

  if(num_sig > 0)
    exponent  += (num_sig -1) + expo;
  else
    exponent -= 1;
  // now the number is FP from here
  if(c == '.' && CHARCLASS[peekchar()] == NUMERIC)
  {
    while ( (c = peekchar()) != EOF
          && CHARCLASS[c] == NUMERIC)
    {
      c = getchar();
      if(num_sig < 8)
        charval = c - '0';
        if(f > 0 || charval > 0) // 0.001111111, 111.001
        {
          f = f * 10 + charval;
          num_sig++;
          expo--;
        }
        else
        {
	  exponent--;
          expo--;
	}
    }
  c = getchar();
  }

  // check for e
  int e = 0;
  char sign;

  if (c == 'e' && (CHARCLASS[peekchar()] == NUMERIC || peekchar() == '+' || peekchar() == '-'))
  {
   // c = getchar(); //numer or +/-
    if(CHARCLASS[peekchar()] == NUMERIC) {
      while(peekchar() != EOF && CHARCLASS[peekchar()] == NUMERIC)
      {
        c = getchar();
        charval = c -'0';
        e = e*10 + charval;
      }
      expo += e;
      exponent += e;
    }
    else  // there is a sign after e
    {
      c = getchar();
      sign = c; //get +/-
      while ( (c = peekchar()) != EOF
          && CHARCLASS[c] == NUMERIC)
      {
        c = getchar();
        charval = c - '0';
        e = e*10 + charval;
      }
      if(sign  == '-')
      {
        expo -= e;
	exponent -= e;
      }
      else
      {
        expo += e;
        exponent += e;
      }
    }
  }

   // express the FP in scientific representation
  if(exponent > 38 || exponent < -38)
    printf("Floating number out of range\n");
  if(expo < 0)
  {
    expo = expo*(-1);
    for(int i = 0; i < expo; ++i)
      f = f/10;
  }
  else
  {
    for(int i = 0; i < expo; i++)
         f = f*10;
  }

  // return token object
  tok->tokentype = NUMBERTOK;
  tok->datatype = REAL;
  tok->realval = f;
  return (tok);
}
