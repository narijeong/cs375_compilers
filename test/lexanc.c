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
      char c;
      while ((c = peekchar()) != EOF
             && (c == ' ' || c == '\n' || c == '\t'))
      {
        c = getchar();
        if(c == '{' || (c =='(' && peekchar() =='*'))
        {
          c = getchar();
          while(c != '}' || (c!= '*' && c!= ')'))
          {
            getchar();
          }
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
  int maxInt = 2147483647;
  long num;
  int  c, charval;
  int limit = 0;
  num = 0;
  int isFloat = 0;
  char sig[8];
  int exp = 0;
  double f;
  while ( (c = peekchar()) != EOF
            && CHARCLASS[c] == NUMERIC || (c == '.' && CHARCLASS[peek2char()] == NUMERIC) || c == 'e')
  {
    c = getchar();
    if(c != '0'  || (limit > 0 && limit < 8))
    {
      sig[limit] = c;
      limit++;
    }

    else if(c == '.')
    {
      isFloat = 1;
      if(limit == 0)
      {
        c = getchar();
        while(c == '0')
        {
          exp--;
          c = getchar();
        }
      }
      else
        exp+= limit;
     }
     if(c == 'e')
     {
	c = getchar();
	if(CHARCLASS[c] == NUMERIC)
	  exp += c -'0';
	else if(c == '+')
	  exp += peekchar() -'0';
	else
	  exp += (~peekchar() + 1) -'0';
     }
  }

  // return float
  if(isFloat == 1) {
    f = num;
    if(exp > 38 || exp < -38)
    {
      printf("Float number out of range");
      tok->tokentype = NUMBERTOK;
      tok->datatype = REAL;
      tok->intval = f;
      return (tok);
    }
    for(int i = 0; i < 8; ++i)
    {   c = sig[i];
        charval = (c - '0');
        f = f * 10 + charval;
    }
    for(int i = 0; i < exp; ++i)
    {
      f = f/10;
    }

    tok->tokentype = NUMBERTOK;
    tok->datatype = REAL;
    tok->intval = f;
    return (tok);
  }
  // return integer
  else //(isFloat == FALSE)
  {
    for(int i = 0; i < 8; i++)
    {
      c = sig[i];
      charval = (c - '0');
      //   int maxInt = 2147483647;
      if(i == 6 && (num >= maxInt/10) && sig[7] -'0' > 7) 
      {
        printf("Integer number out of range");
        tok->tokentype = NUMBERTOK;
        tok->datatype = INTEGER;
        tok->intval = num;
        return (tok);
      }
      num = num * 10 + charval;
    }
    tok->tokentype = NUMBERTOK;
    tok->datatype = INTEGER;
    tok->intval = num;
    return (tok);
  }
}
