

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
  int nc;
  char c;
  char str[5];
  while( (c = peekchar()) != EOF
        && CHARCLASS[c] == SPECIAL)
  {
    c = getchar();
    str[nc] = c;
    nc++;
    for(int i = 0; i < NUM_OPS_SYM; ++i)
    {
      if(strcmp(ops_sym[i], str)== 0)
      {
        tok->tokentype = OPERATOR;
        tok->whichval = (i+1);
        return tok;
      }
    }
    // Delimiter
    for(int i = 0; i < NUM_DELI; ++i)
    {
      if(strcmp(deli[i], str)== 0)
      {
        tok->tokentype = DELIMITER;
        tok->whichval = (i+1);
        return tok;
      }
    }
  }
}

/* Get and convert unsigned numbers of all types. */
TOKEN number (TOKEN tok)
{
  long num;
  int  c, charval;
  num = 0;
  double f;
  int int_overflow = 0;
  int float_overflow = 0;
  int dot = 0;
  int expo = 0;
  int limit = 0; // to count for significand digits
  int digit_count = 0;
  int dec_digit_count = 0;

  while ( (c = peekchar()) != EOF
          && CHARCLASS[c] == NUMERIC)
  {
    c = getchar();
    digit_count++;
    charval = (c - '0');
    // check for int overflow error
    if(digit_count == 10 && num >= 214748364 && charval > 7)
      int_overflow = 1;

    num = num * 10 + charval;
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

  // now the number is FP

  f = num;
  if(c == '.' && CHARCLASS[peekchar()] == NUMERIC)
  {

    //The number form is 0.001433 and 000.00333
    if(f == 0)
    {
      expo--; // expo == -1

      // count 0s right after decimal
      while ( (c = peekchar()) != EOF
          && CHARCLASS[c] == NUMERIC && c == '0')
      {
        c = getchar();
        expo--;
      }
      // count significant
      while ( (c = peekchar()) != EOF
          && CHARCLASS[c] == NUMERIC)
      {
        c = getchar();
        if(limit < 8)
        {
          charval = (c - '0');
          f = f * 10 + charval;
          limit++;
        }
      }
    }
    //3.144444 or 31444.4444 -> 3.14
    else {
      if(digit_count < 8)
      	limit = digit_count;
      else
        limit = 8;

      while ( (c = peekchar()) != EOF
          && CHARCLASS[c] == NUMERIC)
      {
        c = getchar();
        dec_digit_count++;
        if(limit < 8)
        {
          charval = (c - '0');
          f = f * 10 + charval;
          limit++;
        }
      }
    }
    c = getchar(); 
  }

  // check for e
  int e = 0;
  char sign;

 // if (c == 'e' && (CHARCLASS[peekchar()] == NUMERIC || peekchar() == '+' || peekchar() == '-'))
  if (c == 'e')
  {
    tok->tokentype = NUMBERTOK;
    tok->datatype = REAL;
    tok->realval = 5;
    return (tok);


    c = getchar(); //numer or +/-
    if(CHARCLASS[c] == NUMERIC)
      e += (c -'0');
    else  // there is a sign after e
    {
      sign = getchar(); //get +/-
      while ( (c = peekchar()) != EOF
          && CHARCLASS[c] == NUMERIC)
      {
        c = getchar();
        charval = c - '0';
        e = e*10 + charval;
      }
      if(sign  == '-')
	e = e*(-1);
    }
  }

  // express the FP in scientific representation

  // num < 0
  if(digit_count == 0)
  {
    if(dot == 0)
      expo = 0;
    else
      expo = expo - (limit-1) + e;
    // out of range error
    if(expo < -38)
    {
      printf("Floating number out of range\n");
      tok->tokentype = NUMBERTOK;
      tok->datatype = REAL;
      tok->realval = f;
      return (tok);
    }
    expo = (~expo) + 1;
    for(int i = 0; i < expo; i++)
    {
      f = f/10;
    }
  }

  // number > 0
  else if(digit_count >= 0)
  {
    expo = digit_count + e - 1;
    // out of range error
    if(expo > 38)
      float_overflow = 1;

    for(int i = 0; i < dec_digit_count; i++)
      f = f/10;

    if(e > 0) {
       for(int i = 0; i < e; i++)
        f = f*10;
    }
    else
    {
       e = e*(-1);
       for(int i = 0; i < e; i++)
         f = f/10;
    }
  }

  //return error message
  if(float_overflow == 1)
    printf("Floating number out of range\n");

  //return the FP
  tok->tokentype = NUMBERTOK;
  tok->datatype = REAL;
  tok->realval = f;
  return (tok);
}
