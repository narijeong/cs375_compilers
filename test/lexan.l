%{    /* lex2.l -- partial lex specification for Pascal    22 Jul 13 */

/* Copyright (c) 2013 Gordon S. Novak Jr. and The University of Texas at Austin
   */

/* This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, see <http://www.gnu.org/licenses/>. */

/* To use:
        make lex2
        lex2
        x < 3.14            */

/* This file will work as given on a simple input such as:
   if i<j then x := 3.14

   Copy this file to lexan.l and expand it for your assignment.
   Use:
        make lexer
        lexer <graph1.pas
   */

#include <ctype.h>
#include "token.h"
#include "lexan.h"

int maketoken(int type, int which);
int install_id();
int install_string();
int install_inum(); // for integer
int install_fnum(); // for float
int yywrap();

/* If the lex yytext buffer turns out to be too small to hold comments,
   add the following lines:
 #undef YYLMAX
 #define YYLMAX 256
 */

TOKEN yylval;     /* This is the type of the lexical analyzer result */

%}


delim    [ \t\n]
ws       {delim}+
comment  \{[^\}]*\}|\(\*[(?!\*\))]*\*\)|\(\*[^\*\)]*\*\)
letter   [A-Za-z]
digit    [0-9]
id       {letter}({letter}|{digit})*
string   '([^']|'{2})*'
inumber  {digit}*

fnumber  {digit}+(\.{digit}+)?(e[+\-]?{digit}+)?
%%


{ws}      { /* no action and no return */ }
{comment}   { /* no action and no return */ }

and       {return maketoken(OPERATOR, AND);}
or        {return maketoken(OPERATOR, OR);}
not       {return maketoken(OPERATOR, NOT);}
div       {return maketoken(OPERATOR, DIV);}
mod       {return maketoken(OPERATOR, MOD);}
in        {return maketoken(OPERATOR, IN);}
"+"       {return(maketoken(OPERATOR, PLUS));}
"-"       {return(maketoken(OPERATOR, MINUS));}
"*"       {return(maketoken(OPERATOR, TIMES));}
"/"       {return(maketoken(OPERATOR, DIVIDE));}
"<"       {return(maketoken(OPERATOR, LT));}
"<="      {return(maketoken(OPERATOR, LE));}
"="       {return(maketoken(OPERATOR, EQ));}
"<>"      {return(maketoken(OPERATOR, NE));}
">"       {return(maketoken(OPERATOR, GT));}
">="      {return(maketoken(OPERATOR, GE));}
":="      {return(maketoken(OPERATOR, ASSIGN));}
"^"       {return(maketoken(OPERATOR, POINT));}
"."       {return(maketoken(OPERATOR, DOT));}

","       {return(maketoken(DELIMITER, COMMA));}
";"       {return(maketoken(DELIMITER, SEMICOLON));}
":"       {return(maketoken(DELIMITER, COLON));}
"("       {return(maketoken(DELIMITER, LPAREN));}
")"       {return(maketoken(DELIMITER, RPAREN));}
"["       {return(maketoken(DELIMITER, LBRACKET));}
"]"       {return(maketoken(DELIMITER, RBRACKET));}
".."      {return(maketoken(DELIMITER, DOTDOT));}

array     {return(maketoken(RESERVED, ARRAY));}
begin     {return(maketoken(RESERVED, BEGINBEGIN));}
case      {return(maketoken(RESERVED, CASE));}
const     {return(maketoken(RESERVED, CONST));}
do        {return(maketoken(RESERVED, DO));}
downto    {return(maketoken(RESERVED, DOWNTO));}
else      {return(maketoken(RESERVED, ELSE));}
end       {return(maketoken(RESERVED, END));}
file      {return(maketoken(RESERVED, FILEFILE));}
for       {return(maketoken(RESERVED, FOR));}
function  {return(maketoken(RESERVED, FUNCTION));}
goto      {return(maketoken(RESERVED, GOTO));}
if        {return(maketoken(RESERVED, IF));}
label     {return(maketoken(RESERVED, LABEL));}
nil       {return(maketoken(RESERVED, NIL));}
of        {return(maketoken(RESERVED, OF));}
packed    {return(maketoken(RESERVED, PACKED));}
procedure {return(maketoken(RESERVED, PROCEDURE));}
program   {return(maketoken(RESERVED, PROGRAM));}
record    {return(maketoken(RESERVED, RECORD));}
repeat    {return(maketoken(RESERVED, REPEAT));}
set       {return(maketoken(RESERVED, SET));}
then      {return(maketoken(RESERVED, THEN));}
to        {return(maketoken(RESERVED, TO));}
type      {return(maketoken(RESERVED, TYPE));}
until     {return(maketoken(RESERVED, UNTIL));}
var       {return(maketoken(RESERVED, VAR));}
while     {return(maketoken(RESERVED, WHILE));}
with      {return(maketoken(RESERVED, WITH));}

{id}      {return(install_id());}
{string}  {return(install_string());}
{inumber}  {return(install_inum());}
{fnumber} {return(install_fnum());}

%%

/* Note that lex always returns two values:
   1. "What is it?": a small integer such as NUMBER that indicates the
      kind of item that was found; this is the return() value.
   2. The value itself.  This is yylval, which points to a TOKEN.   */

/* Make simple tokens. */
int maketoken(int type, int which)
  {
  yylval = (TOKEN) talloc();  /* Make new token, set yylval to point to it */
  yylval->tokentype = type;
  if (type == RESERVED)
     yylval->whichval = which - RESERVED_BIAS;
     else if (type == OPERATOR)
             yylval->whichval = which - OPERATOR_BIAS;
             else if (type == DELIMITER)
                     yylval->whichval = which - DELIMITER_BIAS;
                     else yylval->whichval = which;
  return(which);
  }

int install_id()
 { int i, c, n;
  yylval = (TOKEN) talloc();  /* Make new token, set yylval to point to it */
  yylval->tokentype = IDENTIFIERTOK;
  n = yyleng;            /* number of characters */
  if ( n > 15 ) n = 15;
  for (i = 0; i < n ; i++)
   { c = yytext[i];
          /* if (islower(c)) c = toupper(c); */ /* to raise to upper case */
     yylval->stringval[i] = c;
    };
  yylval->stringval[n] = '\0';
          /* printf("id  %10s   n = %4d\n", yytext, n); */
  return(IDENTIFIER);
 }

 int install_string()
 { int i, c, n, endOfString;
  yylval = (TOKEN) talloc();  /* Make new token, set yylval to point to it */
  yylval->tokentype = STRINGTOK;
  i = 1;
  n = 0;
  endOfString = 0;

  while(i < 16 && endOfString == 0)
  { 
    c = yytext[i];
    if (c == '\'' && yytext[i+1] == '\0')
      endOfString = 1;
    else {
      yylval->stringval[n] = c;
      n++;
      i++;
    }
  }
  /* printf("id  %10s   n = %4d\n", yytext, n); */
  return(STRING);
 }

int install_inum() {  /* Note -- you may use sscanf for this assignment. */
  int inum;
  yylval = (TOKEN) talloc();   /* Make new token, set yylval to point to it */
  yylval->tokentype = NUMBERTOK;
  yylval->datatype = INTEGER;
       /* printf("num %10s   n = %4d\n",yytext,yyleng); */
  sscanf(yytext, "%d", &inum);
  yylval->intval = inum;
  return(NUMBER);
 }


int install_fnum() {  /* Note -- you may use sscanf for this assignment. */
  float fnum;
  yylval = (TOKEN) talloc();   /* Make new token, set yylval to point to it */
  yylval->tokentype = NUMBERTOK;
  yylval->datatype = REAL;
       /* printf("num %10s   n = %4d\n",yytext,yyleng); */
  sscanf(yytext, "%f", &fnum);
  yylval->realval = fnum;
  return(NUMBER);
 } 

 


int yywrap() {  return(1);  }       /* lex may need this. */
