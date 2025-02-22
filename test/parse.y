%{     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 30 Jul 13   */

/* Copyright (c) 2013 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/* 14 Feb 01; 01 Oct 04; 02 Mar 07; 27 Feb 08; 24 Jul 09; 02 Aug 12 */

/*
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.

; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.

; You should have received a copy of the GNU General Public License
; along with this program; if not, see <http://www.gnu.org/licenses/>.
  */


/* NOTE:   Copy your lexan.l lexical analyzer to this directory.      */

       /* To use:
                     make pars1y              has 1 shift/reduce conflict
                     pars1y                   execute the parser
                     i:=j .
                     ^D                       control-D to end input

                     pars1y                   execute the parser
                     begin i:=j; if i+j then x:=a+b*c else x:=a*b+c; k:=i end.
                     ^D

                     pars1y                   execute the parser
                     if x+y then if y+z then i:=j else k:=2.
                     ^D

           You may copy pars1.y to be parse.y and extend it for your
           assignment.  Then use   make parser   as above.
        */

        /* Yacc reports 1 shift/reduce conflict, due to the ELSE part of
           the IF statement, but Yacc's default resolves it in the right way.*/

#include <stdio.h>
#include <ctype.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"

        /* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;

%}

/* Order of tokens corresponds to tokendefs.c; do not change */

%token IDENTIFIER STRING NUMBER   /* token types */

%token PLUS MINUS TIMES DIVIDE    /* Operators */
%token ASSIGN EQ NE LT LE GE GT POINT DOT AND OR NOT DIV MOD IN

%token COMMA                      /* Delimiters */
%token SEMICOLON COLON LPAREN RPAREN LBRACKET RBRACKET DOTDOT

%token ARRAY BEGINBEGIN           /* Lex uses BEGIN */
%token CASE CONST DO DOWNTO ELSE END FILEFILE FOR FUNCTION GOTO IF LABEL NIL
%token OF PACKED PROCEDURE PROGRAM RECORD REPEAT SET THEN TO TYPE UNTIL
%token VAR WHILE WITH


%%
  program    : PROGRAM IDENTIFIER LPAREN IDENTIFIER RPAREN SEMICOLON lBlock DOT { parseresult = makeprogram($2, $4, $7); }
             ;

  lBlock     : LABEL numlist SEMICOLON cBlock  { $$ = $4; }
             | cBlock                          { $$ = $1; }
             ;

  numlist    : NUMBER COMMA numlist            { instlabel($1); }
             | NUMBER                          { instlabel($1); }
             ;
         
  cBlock     : CONST c_list tBlock             { $$ = $3; }
             | tBlock                          { $$ = $1; }
	     ;


  c_list     : IDENTIFIER EQ NUMBER SEMICOLON c_list { instconst($1, $3); }
             | IDENTIFIER EQ NUMBER SEMICOLON  { instconst($1, $3); }
             ;  

  tBlock     : TYPE tdef_list vBlock           { $$ = $3; }
             | vBlock                          { $$ = $1; }
             ;

  tdef       : IDENTIFIER EQ type              { insttype($1, $3); }
             ;

  tdef_list  : tdef SEMICOLON tdef_list        { $$ = $3; }
             | tdef SEMICOLON                  { $$ = $1; }
             ;

  type       : simple_type                     { $$ = $1; }
             | RECORD field_list END           { $$ = instrec($1, $2); }
             | POINT IDENTIFIER                { $$ = instpoint($1, $2); }
             | ARRAY LBRACKET simple_type_list RBRACKET OF type   { $$ = instarray($3, $6); }
             ;

  simple_type: IDENTIFIER                      { $$ = findtype($1); }
             | LPAREN id_list RPAREN           { $$ = instenum($2); }
             | NUMBER DOTDOT NUMBER            { $$ = instdotdot($1, $2, $3); }
             ;

  simple_type_list : simple_type COMMA simple_type_list    { $$ = cons($3, $1); } 
                   | simple_type                           { $$ = $1; }
                   ;

  field_list : id_list COLON type              { instfields($1, $3); }
             | id_list COLON type SEMICOLON field_list { instfields($1, $3); $$ = nconc($1, $5); }
             ;

  id_list    : IDENTIFIER COMMA id_list        { $$ = cons($1, $3); }
             | IDENTIFIER                      { $$ = cons($1, NULL); }
             ; 

  vBlock     : VAR vdef_list block             { $$ = $3; }       
             ;

  block      : BEGINBEGIN statement endpart   { $$ = makeprogn($1,cons($2, $3)); }
             ;

  vdef_list  : vdef SEMICOLON vdef_list        { $$ = $3; }  // maybe?
             | vdef SEMICOLON                  { $$ = $1; }  // mabye?
             ;

  vdef       : id_list COLON type              { instvars($1, $3); }
             ;

  statement  : BEGINBEGIN statement endpart   { $$ = makeprogn($1,cons($2, $3)); }
             | IF expr THEN statement endif   { $$ = makeif($1, $2, $4, $5); }
             | assignment                     { $$ = $1; }
             | funcCall                       { $$ = $1; }
             | WHILE expr DO statement        { $$ = makewhile($1, $2, $3, $4); }
             | REPEAT statement_list UNTIL expr  {$$ = makerepeat($1, $2, $3, $4);}
             | FOR assignment TO IDENTIFIER DO statement  { $$ = makefor(1, $1, $2, $3, $4, $5, $6); }
             | GOTO NUMBER                    { $$ = dogoto($1, $2); }
             | label                          { $$ = $1; }
             ;

  statement_list : statement SEMICOLON statement_list{ $$ = cons($1, $3); }
                 | statement                         { $$ = $1; }
                 ;
          
  funcCall   : IDENTIFIER LPAREN expr RPAREN   { $$ = makefuncall((TOKEN) talloc(), $1, $3);}
             ; 

  label      : NUMBER COLON statement          { $$ = dolabel($1, $2, $3); }
             ;

  endpart    :  SEMICOLON statement endpart    { $$ = cons($2, $3); }
             |  END                            { $$ = NULL; }
             ;

  endif      :  ELSE statement                 { $$ = $2; }
             |  /* empty */                    { $$ = NULL; }
             ;

  assignment :  factor ASSIGN expr             { $$ = binop($2, $1, $3); }
             ;

  expr       :  expr compare_op simple_expr    { $$ = binop($2, $1, $3); }  
             |  expr PLUS term                 { $$ = binop($2, $1, $3); }
             |  expr MINUS term                { $$ = binop($2, $1, $3); }
             |  term                           { $$ = $1; }
             |  funcCall TIMES funcCall        { $$ = binop($2, $1, $3); }
             |  funcCall                       { $$ = $1; }
             |  term EQ term                   { $$ = binop($2, $1, $3); }
             |  MINUS term                     { $$ = binop($1, $2, $2); }
             ;

  compare_op : EQ | LT | GT | NE | LE | GE | IN  { $$ = $1; }
             ;


  simple_expr: sign_term                       { $$ = $1; }
             | term                            { $$ = $1; }
//             | simple_expr plus_op term        { $$ = binop($2, $1, $3); }
             ;

  sign_term  : PLUS | MINUS term               { $$ = unaryop($1, $2); }
             ;     

  expr_list  : expr COMMA expr_list            { $$ = cons($1, $3); }
             | expr                            { $$ = cons($1, NULL); }
             ;


  term       :  term TIMES factor              { $$ = binop($2, $1, $3); }
             |  factor                         { $$ = $1; }
             ;

  factor     :  LPAREN expr RPAREN             { $$ = $2; }
             |  NUMBER                         { $$ = $1; }                          
             |  STRING                         { $$ = $1; }
             |  variable                       { $$ = $1; }
             |  NIL                            { $$ = $1; }
             ;

  variable   : IDENTIFIER                      { $$ = findid($1); }
             | variable LBRACKET expr_list RBRACKET { arrayref($1, NULL, $3, NULL); }
             | variable DOT IDENTIFIER        // { //$$ = reducedot($1, $2, $3); }
             | variable  POINT                 { $$ = dopoint($1, $2); }
             ;

%%

/* You should add your own debugging flags below, and add debugging
   printouts to your programs.

   You will want to change DEBUG to turn off printouts once things
   are working.
  */

#define DEBUG          1             /* set bits here for debugging, 0 = off  */
#define DB_CONS        1             /* bit to trace cons */
#define DB_BINOP       1             /* bit to trace binop */
#define DB_MAKEINTC    1             /* bit to trace makeintc */
#define DB_COPYTOK     1             /* bit to trace copytok */
#define DB_MAKEPROGRAM 1             /* bit to trace makeprogram */
#define DB_MAKEPROGN   1             /* bit to trace makeprogn */
#define DB_MAKEFUNCALL 1             /* bit to trace makefuncall */
#define DB_MAKEGOTO    1             /* bit to trace makegoto */
#define DB_MAKEIF      1             /* bit to trace makeif */
#define DB_MAKEFOR     1             /* bit to trace makefor */
#define DB_MAKELABEL   1             /* bit to trace makelabel */
#define DB_MAKEOP      1             /* bit to trace makeop */
#define DB_PARSERES    1             /* bit to trace parseresult */

#define DB_NCONC       1             
#define DB_INSTTYPE    1       
#define DB_INSTFIELDS  1            
#define DB_INSTREC     1            
#define DB_INSTLABEL   1
#define DB_INSTENUM    1
#define DB_MAKESUBRANGE 1
#define DB_INSTPOINT   1
#define DB_INSTARRAY   1
#define DB_INSTDOTDOT  1
#define DB_DOPOINT     1
#define DB_REDUCEDOT   1
#define DB_MAKEAREF    1
#define DB_DOLABEL     1
#define DB_ARRAYREF    1
#define DB_MAKEPLUS    1
#define DB_ADDINT      1
#define DB_UNARYOP     1
#define DB_MAKEWHILE   1
#define DB_MAKEPNB     1
#define DB_DOGOTO      1

 int labelnumber = 0;  /* sequential counter for internal label numbers */
 int label[100];       /* table for user label */


   /*  Note: you should add to the above values and insert debugging
       printouts in your routines similar to those that are shown here.     */


/* dogoto is the action for a goto statement.
   tok is a (now) unused token that is recycled. */
TOKEN dogoto(TOKEN tok, TOKEN labeltok) 
{
  if (DEBUG & DB_DOGOTO) {
    printf("In dogoto()\n");
    dbugprinttok(tok);
    dbugprinttok(labeltok);    
  }

  int user_label_num = -1;
  // find the user label in the user label table
  int index = 0;
  int found = 0;
  while (index < 100 && found == 0) {
    if (label[index] == labeltok->intval) {
      user_label_num = label[index];
      found = 1;
    }
    index++;
  }

  if (DEBUG & DB_DOGOTO) {
    printf("End of dogoto().\n");
    printf("use label number %d\n", user_label_num);
    printf("Pass to makegoto()\n\n");
  }
  return (makegoto(user_label_num));

}

/* makepnb is like makeprogn, except that if statements is already a progn,
   it just returns statements.  This is optional. */
TOKEN makepnb(TOKEN tok, TOKEN statements) 
{
  if (DEBUG & DB_MAKEPNB) 
  {
    printf("makepnb(); pass statements to makegprogn()");
  }
  
  return (makeprogn(tok, statements));
}

/* makewhile makes structures for a while statement.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN makewhile(TOKEN tok, TOKEN expr, TOKEN tokb, TOKEN statement) 
{

  if (DEBUG & DB_MAKEWHILE) {
    printf("makewhile()\n");
    dbugprinttok(tok);
    dbugprinttok(expr);
    dbugprinttok(tokb);
    dbugprinttok(statement);
  }

  TOKEN label_tok = makelabel();
  TOKEN while_tok = makepnb(talloc(), label_tok); 
  TOKEN if_tok = makeif(makeop(IFOP), expr, statement, NULL);

  label_tok->link = if_tok;
  TOKEN current = statement->operands;
  TOKEN oper = current->operands;
  while (oper) {
    current = oper;
    oper = oper->operands;
  }
  
  TOKEN goto_tok = makegoto(label_tok->operands->intval);
  current->link = goto_tok;
  if (DEBUG & DB_MAKEWHILE) {
    printf("End of makewhile().\n");
    dbugprinttok(while_tok);
  }

  return while_tok;
}


/* unaryop links a unary operator op to one operand, lhs */
TOKEN unaryop(TOKEN op, TOKEN lhs) 
{
  op->operands = lhs;          
  lhs->link = NULL;
  if (DEBUG & DB_UNARYOP)
  { 
    printf("unaryop\n");
    dbugprinttok(op);
    dbugprinttok(lhs);
  }
  return op;
}


/* addint adds integer off to expression exp, possibly using tok */
TOKEN addint(TOKEN exp, TOKEN off, TOKEN tok) 
{  
  if (DEBUG & DB_ADDINT) {
    printf("addint()\n");
    dbugprinttok(exp);
    dbugprinttok(off);
    dbugprinttok(tok);
  }

  int exp_int = exp->intval;
  int off_int = off->intval;

  exp->intval = exp_int + off_int;
  
  if (DEBUG & DB_ADDINT) 
  {
    printf("Added exp_int + off_int. New exp: %d\n", exp->intval);
    dbugprinttok(exp);
  }
  
  return exp;
}

/* makeplus makes a + operator.
   tok (if not NULL) is a (now) unused token that is recycled. */
TOKEN makeplus(TOKEN lhs, TOKEN rhs, TOKEN tok) 
{
  if (DEBUG & DB_MAKEPLUS) 
  {
    printf("makeplus()\n");
    dbugprinttok(lhs);
    dbugprinttok(rhs);
    dbugprinttok(tok);    
  }

  TOKEN plus_tok = makeop(PLUSOP);
  if (lhs && rhs) 
  {
    plus_tok->operands = lhs;
    lhs->link = rhs;
    rhs->link = NULL;
  }

  return plus_tok;
}



/* arrayref processes an array reference a[i]
   subs is a list of subscript expressions.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN arrayref(TOKEN arr, TOKEN tok, TOKEN subs, TOKEN tokb) 
{
  SYMBOL arrsyms[10];
  SYMBOL typesym;
  SYMBOL varsym = searchst(arr->stringval);  

  // for the variables
  int index = 0;
  SYMBOL current = varsym->datatype;
  while (current && current->kind != TYPESYM) {
    //for each variable
    arrsyms[index] = current;
    current = current->datatype;
    index++;
  }
  
  // expr is only one number 
  typesym = current;
  TOKEN array_ref = NULL;
  int size;
  if (subs->tokentype == NUMBERTOK && subs->link == NULL) {
    size = (subs->whichval-1)*typesym->size;
    array_ref = makearef(arr, makeintc(size), NULL);
    array_ref->datatype = varsym->basicdt;
    return array_ref;
  }

  //handle where  expr it's not number
  SYMBOL arrsym = arrsyms[0];
  int curr_size = arrsym->size/(arrsym->highbound-arrsym->lowbound+1);
  TOKEN mult = makeop(TIMESOP);
  TOKEN pos = makeintc(curr_size);
  TOKEN neg = makeintc(curr_size * -1);
  mult->operands = pos;
  pos->link = subs;
  neg->link = mult;

  TOKEN plus = makeplus(neg, mult, NULL);
  array_ref = makearef(arr, plus, NULL);
  array_ref->datatype = varsym->basicdt;
  int counter = 1;
  while (subs) {
    if (subs->tokentype == NUMBERTOK) {   
      array_ref->operands->link->operands = addint(array_ref->operands->link->operands, 
        makeintc(subs->whichval * typesym->size), NULL);
    }
    else {
      arrsym = arrsyms[counter];
      curr_size = arrsym->size / (arrsym->highbound - arrsym->lowbound + 1);
      pos = makeintc(curr_size);
      neg= makeintc(curr_size * -1);
      mult->operands = pos;
      pos->link = subs;
      array_ref->operands->link->operands = addint(array_ref->operands->link->operands, neg, NULL);
      TOKEN add = array_ref->operands->link->operands->link;
      TOKEN plus2 = makeplus(add, mult, NULL);
      array_ref->operands->link->operands->link = plus2;
    }
    TOKEN dlink = subs;
    subs = subs->link;
    dlink->link = NULL;
    counter++;
  }
  
  return array_ref;
  
}



/* dolabel is the action for a label of the form   <number>: <statement>
   tok is a (now) unused token that is recycled. */
TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement) 
{
  if (DEBUG & DB_DOLABEL) {
    printf("dolabel()\n");
    dbugprinttok(labeltok);
    dbugprinttok(tok);
    dbugprinttok(statement);   
  }
  
  int user_label_num = -1;
  // find the user label in the user label table
  int index = 0;
  int found = 0;
  while (index < 100 && found == 0) {
    if (label[index] == labeltok->intval) {
      user_label_num = label[index];
      found = 1;
    }
    index++;
  }

  TOKEN do_tok = makeop(PROGNOP);
  TOKEN label_tok = makeop(LABELOP);
  TOKEN num_tok = makeintc(user_label_num);
  do_tok->operands = label_tok;
  label_tok->operands = num_tok;
  label_tok->link = statement;

  if (DEBUG & DB_DOLABEL) {
    printf("End of dolabel().\n");
    dbugprinttok(do_tok);
  }

  return do_tok;
}


/* makearef makes an array reference operation.
   off is be an integer constant token
   tok (if not NULL) is a (now) unused token that is recycled. */
TOKEN makearef(TOKEN var, TOKEN off, TOKEN tok) 
{
  if (DEBUG & DB_MAKEAREF) 
  {
    printf("makearef\n");
    dbugprinttok(var);
    dbugprinttok(off);
    dbugprinttok(tok);
  }

  SYMBOL sym = symalloc();
  sym->basicdt = var->datatype;
  var->link = off;

  TOKEN aref = makeop(AREFOP);
  aref->symtype = sym;
  aref->operands = var;

  if (DEBUG & DB_MAKEAREF) {
    printf("End of makearef().\n");
    dbugprinttok(aref);
  } 
  
  return aref;
}



/* reducedot handles a record reference.
   dot is a (now) unused token that is recycled. */
TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field) 
{
  TOKEN aref;

  return aref;
}

/* dopoint handles a ^ operator.
   tok is a (now) unused token that is recycled. */
TOKEN dopoint(TOKEN var, TOKEN tok) 
{
  tok->datatype = var->datatype;
  tok->operands = var;

  if (DEBUG & DB_DOPOINT) {
    printf("dopoint\n");
    dbugprinttok(tok);
  }

  return tok;  
}


/* instdotdot installs a .. subrange in the symbol table.
   dottok is a (now) unused token that is recycled. */
TOKEN instdotdot(TOKEN lowtok, TOKEN dottok, TOKEN hightok)
{
  TOKEN ret = makesubrange(dottok, lowtok->intval, hightok->intval);
  
  if (DEBUG && DB_INSTDOTDOT) {
    printf("instdotdot; pass param on makesubrange()\n");
    dbugprinttok(lowtok);
    dbugprinttok(hightok);
    dbugprinttok(dottok);
  }

  return ret;
}

/* instarray installs an array declaration into the symbol table.
   bounds points to a SUBRANGE symbol table entry.
   The symbol table pointer is returned in token typetok. */
TOKEN instarray(TOKEN bounds, TOKEN typetok) 
{

  SYMBOL type_sym = searchst(typetok->stringval);
  SYMBOL prev_sym = NULL;
  int low, high;

  TOKEN current = bounds;
  while (current) {
    SYMBOL arr_sym = symalloc();
    arr_sym->kind = ARRAYSYM; 
    arr_sym->datatype = type_sym;

    if (prev_sym) {
      arr_sym->datatype = typetok->symtype;
      arr_sym->size = (high - low + 1) * prev_sym->size;  
    }
    else
      arr_sym->size = (high - low + 1) * type_sym->size;

    low = current->symtype->lowbound;
    high = current->symtype->highbound;
    arr_sym->lowbound = low;
    arr_sym->highbound = high;
    typetok->symtype = arr_sym;
    prev_sym = arr_sym;  
    current = current->link;
  }

  if (DEBUG && DB_INSTARRAY) {
    printf("End of instdotdot\n");
    dbugprinttok(bounds);
    dbugprinttok(typetok);
  } 
 
   return typetok;

}


/* instpoint will install a pointer type in symbol table */
TOKEN instpoint(TOKEN tok, TOKEN typename) 
{
  SYMBOL sym, ptr_sym;;
  
  sym = searchins(typename->stringval);
  sym->kind = TYPESYM;

  ptr_sym = symalloc();
  ptr_sym->kind = POINTERSYM;
  ptr_sym->basicdt = POINTER;
  ptr_sym->size = basicsizes[POINTER];
  ptr_sym->datatype = sym;

  tok->symtype = ptr_sym;
  tok->datatype = POINTER;


  if (DEBUG & DB_INSTPOINT) {
    printf("End of instpoint().\n");
    dbugprinttok(tok);
   // dbprsymbol(tok->symtype);
  }

  return tok;

}

/* makesubrange makes a SUBRANGE symbol table entry, puts the pointer to it
into tok, and returns tok. */
TOKEN makesubrange(TOKEN tok, int low, int high) 
{

  TOKEN subran_tok = copytok(tok);
  SYMBOL subrange = symalloc();
  subrange->kind = SUBRANGE;
  subrange->lowbound = low;
  subrange->highbound = high; 
  subrange->basicdt = INTEGER;
  subrange->size = basicsizes[INTEGER];
  subran_tok->symtype = subrange;
  
  if (DEBUG & DB_MAKESUBRANGE) {
    printf("End of makesubrng\n");
    dbugprinttok(subran_tok);
    printf(" low: %d, high: %d\n\n", low, high);
  }

  return subran_tok;
}


/* instenum installs an enumerated subrange in the symbol table,
   e.g., type color = (red, white, blue)
   by calling makesubrange and returning the token it returns. */
TOKEN instenum(TOKEN idlist) 
{
  int size = 0;

  TOKEN current = idlist;
  while(current) {
    instconst(current, makeintc(size));
    current = current->link;
    size++;
  }

  //make a subrange with the upper bound and lower bound
  //corresponding to the enum ids
  TOKEN subrange = makesubrange(idlist, 0, size - 1); 
  return subrange;
}

/* nconc concatenates two token lists, destructively, by making the last link
   of lista point to listb.
   (nconc '(a b) '(c d e))  =  (a b c d e)  */
/* nconc is useful for putting together two fieldlist groups to
   make them into a single list in a record declaration. */
TOKEN nconc(TOKEN lista, TOKEN listb) 
{ 
  TOKEN current = lista;
  while(current->link != NULL) 
    current = current->link;

  current->link = listb;

  if (DEBUG & DB_NCONC)
  { 
    printf("End of nconc\n");
    dbugprinttok(lista);
    dbugprinttok(listb);
  }

  return lista;
}


/* instlabel installs a user label into the label table */
void  instlabel (TOKEN num) 
{
   label[labelnumber++] = num->intval;
}


/* insttype will install a type name in symbol table.
   typetok is a token containing symbol table pointers. */
void  insttype(TOKEN typename, TOKEN typetok) 
{
    SYMBOL sym, type_sym;
    type_sym = typetok->symtype;
    sym = searchins(typename->stringval);
    sym->kind = TYPESYM;
    sym->datatype = type_sym;
    sym->basicdt = type_sym->basicdt;
    sym->size = type_sym->size;

}


/* instfields will install type in a list idlist of field name tokens:
   re, im: real    put the pointer to REAL in the RE, IM tokens.
   typetok is a token whose symtype is a symbol table pointer.
   Note that nconc() can be used to combine these lists after instrec() */
TOKEN instfields(TOKEN idlist, TOKEN typetok) 
{

  SYMBOL rec_sym, type_sym;
  TOKEN current = idlist;
  int total = 0;

  while (current) {
    type_sym = searchst(typetok->stringval);
    rec_sym = makesym(current->stringval);
    rec_sym->datatype = type_sym;
    rec_sym->offset = total;
    rec_sym->size = type_sym->size;
    total += type_sym->size;

    if (type_sym->kind == BASICTYPE)
      rec_sym->basicdt = type_sym->basicdt;
    current->symtype = rec_sym;
    current = current->link;
  }

  return idlist;
}

/* instrec will install a record definition.  Each token in the linked list
   argstok has a pointer its type.  rectok is just a trash token to be
   used to return the result in its symtype */
TOKEN instrec(TOKEN rectok, TOKEN argstok) 
{

  int total;

  SYMBOL rec_sym = symalloc();
  rec_sym->kind = RECORDSYM;
  rec_sym->datatype = argstok->symtype;
  rectok->symtype = rec_sym;

  TOKEN current = argstok;
 
  total = wordaddress(argstok->symtype->size, 8);
  while (current->link) {
    current->symtype->link = current->link->symtype;
    current->link->symtype->offset = total;   
    total+= wordaddress(current->link->symtype->size, 8);
    current = current->link;
  }

  rec_sym->size = total;

  if (DEBUG && DB_INSTREC) {
    printf("End of instrec.\n");
    dbugprinttok(rectok);
    dbugprinttok(argstok);
  }
  return rectok;
}



 /* makerepeat makes structures for a repeat statement.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokb, TOKEN expr)
{
  int to = labelnumber;
  //making label token
  TOKEN label = makelabel();
  tok = makeprogn(tok, label);
   
  // for the statment 
  TOKEN progn = makeprogn(tokb, statements);
  label->link = progn;
  TOKEN to_tok = makegoto(to);
  TOKEN link_progn = makeprogn((TOKEN) talloc(), NULL);
  link_progn->link = to_tok;

  TOKEN iftok = talloc();
  iftok = makeif(iftok, expr, link_progn, to_tok);
  progn->link = iftok;

  return tok;
}



/* cons links a new item onto the front of a list.  Equivalent to a push.
   (cons 'a '(b c))  =  (a b c)    */
TOKEN cons(TOKEN item, TOKEN list)           
  { item->link = list;
    if (DEBUG & DB_CONS)
       { printf("cons\n");
         dbugprinttok(item);
         dbugprinttok(list);
       };
    return item;
  }

/* binop links a binary operator op to two operands, lhs and rhs. */
TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs)        /* reduce binary operator */
  { op->operands = lhs;          /* link operands to operator       */
    lhs->link = rhs;             /* link second operand to first    */
    rhs->link = NULL;            /* terminate operand list          */
    if (DEBUG & DB_BINOP)
       { printf("binop\n");
         dbugprinttok(op);
         dbugprinttok(lhs);
         dbugprinttok(rhs);
       };
    return op;
  }

/* makeop makes a new operator token with operator number opnum.
   Example:  makeop(FLOATOP)  */
TOKEN makeop(int opnum)
{
  TOKEN tok = talloc();
  tok->tokentype = OPERATOR;
  tok->whichval = opnum;
  if (DEBUG & DB_MAKEOP) {
    printf("makeop\n");
    dbugprinttok(tok);
  }
  return(tok);
}

/* makeintc makes a new token with num as its value */
TOKEN makeintc(int num)
{
  TOKEN tok = talloc();
  tok->tokentype = NUMBERTOK;
  tok->datatype = INTEGER;
  tok->intval = num;
  if (DEBUG & DB_MAKEINTC) 
  {
    printf("makeintc\n");
    dbugprinttok(tok);
  }
  return tok;
}

/* copytok makes a new token that is a copy of origtok */
TOKEN copytok(TOKEN origtok)
{
  TOKEN newTok = talloc();
  newTok->tokentype = origtok->tokentype;
  newTok->datatype = origtok->datatype;
  newTok->symtype = origtok->symtype;
  newTok->symentry = origtok->symentry;
  newTok->operands = origtok->operands;
  newTok->link = origtok->link;
  newTok->whichval = origtok->whichval;
  newTok->intval = origtok->intval;
  newTok->realval = origtok->realval;

  if (DEBUG & DB_COPYTOK)
  {
    printf("copytok\n");
    dbugprinttok(newTok);
  }
  return newTok;
}

/* makeif makes an IF operator and links it to its arguments.
   tok is a (now) unused token that is recycled to become an IFOP operator */
TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart)
  {  tok->tokentype = OPERATOR; 
     tok->whichval = IFOP;
     if (elsepart != NULL) elsepart->link = NULL;
     thenpart->link = elsepart;
     exp->link = thenpart;
     tok->operands = exp;
     if (DEBUG & DB_MAKEIF)
        { printf("makeif\n");
          dbugprinttok(tok);
          dbugprinttok(exp);
          dbugprinttok(thenpart);
          dbugprinttok(elsepart);
        };
     return tok;
   }

/* makeprogram makes the tree oof the top-level program */
// prog_name: program name identifier, args: argument, block: inside the program
TOKEN makeprogram(TOKEN prog_name, TOKEN args, TOKEN block) 
{
  // create new tokens
  TOKEN program = talloc();
  TOKEN progn = talloc();
  
  program->tokentype = OPERATOR;
  program->whichval = PROGRAMOP;
  program->operands = prog_name;

  progn = makeprogn(progn, args);
  prog_name->link = progn;
  progn->link = block;
  
  if (DEBUG & DB_MAKEPROGRAM)
  { printf("makeprogram\n");
    dbugprinttok(program);
    dbugprinttok(progn);
    dbugprinttok(prog_name);
    dbugprinttok(args);
  };
  
  return program;
}

/* makeprogn makes a PROGN operator and links it to the list of statements.
   tok is a (now) unused token that is recycled. */
TOKEN makeprogn(TOKEN tok, TOKEN statements)
  {  tok->tokentype = OPERATOR;
     tok->whichval = PROGNOP;
     tok->operands = statements;
     if (DEBUG & DB_MAKEPROGN)
       { printf("makeprogn\n");
         dbugprinttok(tok);
         dbugprinttok(statements);
       };
     return tok;
   }

/* makefuncall makes a FUNCALL operator and links it to the fn and args.
   tok is a (now) unused token that is recycled. */
TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args)
{
  
  tok->operands = fn;
  tok->whichval = FUNCALLOP;
  fn->link = args;

  if (DEBUG & DB_MAKEPROGN)
  { 
    printf("makefuncall\n");
    dbugprinttok(tok);
    dbugprinttok(fn);
    dbugprinttok(args);
  };
 
  return tok;
}

/* makefor makes structures for a for statement.
   sign is 1 for normal loop, -1 for downto.
   asg is an assignment statement, e.g. (:= i 1)
   endexpr is the end expression
   tok, tokb and tokc are (now) unused tokens that are recycled. */
TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexpr, 
              TOKEN tokc, TOKEN statement) 
{

// tokb = lim(repeat), id = lim, statement = statement 
// |  FOR assignment TO IDENTIFIER DO statement { $$ = makefor(1, (TOKEN) talloc(), $2, $4, NULL, NULL, $6); }
// assignment = IDENTIFIER ASSIGN expression  -> returns op token with link

  //progn (:=i 0)
  tok = makeprogn(tok, asg);
  
  // create label to link to asg 
  TOKEN label = makelabel();
  asg->link = label;

  TOKEN compare;
  TOKEN incORdec;
  if (sign == 1) 
  {
    compare = makeop(LEOP);
    incORdec = makeop(PLUSOP);
  }
  else {
    compare = makeop(GEOP);
    incORdec = makeop(MINUSOP);
  }

  TOKEN statement_progn = talloc();
  statement_progn = makeprogn(statement_progn, statement);
  
  TOKEN conditionIf =  talloc();
  conditionIf = makeif(conditionIf, compare, statement_progn, NULL);
  label->link = conditionIf;
  
  //TOKEN start_var
  TOKEN start_var = copytok(asg->operands);

  conditionIf->operands = compare;
  compare->operands = start_var;
  //link to end_var (tokb)
  start_var->link = tokb;
  
  // after statement
  //(:=i(+i 1))
  TOKEN assign = makeop(ASSIGNOP);
  TOKEN copy_var1 = copytok(start_var);
  assign->operands = copy_var1;
  copy_var1->link = incORdec;
  TOKEN copy_var2 = copytok(start_var);
  incORdec->operands = copy_var2;
  copy_var2->link = makeintc(1);

  statement->link = assign;
  assign->link = makegoto(labelnumber - 1);


  if (DEBUG & DB_MAKEFOR) 
  {
    printf("makefor\n");
    dbugprinttok(tok);
    dbugprinttok(asg);
    dbugprinttok(tokb);
    dbugprinttok(endexpr);
    dbugprinttok(tokc);
    dbugprinttok(compare);
    dbugprinttok(incORdec);
    dbugprinttok(start_var);
    dbugprinttok(copy_var1);
    dbugprinttok(copy_var2);
  }
  return tok;
}

/* makelabel makes a new label, using labelnumber++ */
TOKEN makelabel()  
{
  TOKEN tok = talloc();
  tok->tokentype = OPERATOR;
  tok->whichval = LABELOP;
  tok->operands = makeintc(labelnumber);
  labelnumber++;
  
  if (DEBUG & DB_MAKELABEL) 
  {
    printf("makelabel\n");
    dbugprinttok(tok);
  }
  return tok;
}

/* makegoto makes a GOTO operator to go to the specified label.
   The label number is put into a number token. */
TOKEN makegoto(int label) 
{
  TOKEN tok = talloc();
  tok->tokentype = OPERATOR;
  tok->whichval = GOTOOP;
  tok->operands = makeintc(labelnumber - 1);
 
  if (DEBUG & DB_MAKEGOTO) 
  {
    printf("makegoto\n");
    dbugprinttok(tok);
  }
  return tok;
}

/* findid finds an identifier in the symbol table, sets up symbol table
   pointers, changes a constant to its number equivalent */
TOKEN findid(TOKEN tok)
{
  SYMBOL sym, type;

  sym = searchst(tok->stringval);
  tok->symentry = sym;
  type = sym->datatype;
  tok->symtype = type;
  if ( type->kind == BASICTYPE || type->kind == POINTERSYM )
  {
      tok->datatype = type->basicdt;
  }
  
  return tok;
}

/* instconst installs a constant in the symbol table */
void instconst(TOKEN idtok, TOKEN consttok) 
{
  SYMBOL sym, type; 
  int align;
    if(consttok->datatype == INTEGER)
    {
      type = searchst("integer");	
      //sym->constval.intnum = consttok->intval;

    }
    else if(consttok->datatype == REAL)
    {
      type = searchst("real");
      //sym->constval.realnum = consttok->realval;
    }

    align = alignsize(type);
    sym = insertsym(idtok->stringval);
    sym->kind = CONSTSYM;
    sym->datatype = type;
    sym->size = type->size;
    sym->basicdt = consttok->datatype;
    if(sym->basicdt == INTEGER)
    {
      sym->constval.intnum = consttok->intval;
    }
    else if(sym->basicdt == REAL)
    { 
      sym->constval.realnum = consttok->realval;
    }
}


/* findtype looks up a type name in the symbol table, puts the pointer
   to its type into tok->symtype, returns tok. */
TOKEN findtype(TOKEN tok) {
  SYMBOL sym = searchst(tok->stringval);
  tok->symtype = sym;
  return tok;
}

/* instvars will install variables in symbol table.
   typetok is a token containing symbol table pointer for type. */
void instvars(TOKEN idlist, TOKEN typetok)  
{  
  SYMBOL sym, type; 
  int align;
  type = typetok->symtype;
  align = alignsize(type);
  while ( idlist != NULL )
  {  
    sym = insertsym(idlist->stringval);
    sym->size = type->size;   
    sym->kind = VARSYM;
    sym->offset = wordaddress(blockoffs[blocknumber], align);
    blockoffs[blocknumber] = sym->size + sym->offset;
    sym->datatype = type;
    sym->basicdt = type->basicdt;
    idlist = idlist->link;   
  };
}

int wordaddress(int n, int wordsize)
  { return ((n + wordsize - 1) / wordsize) * wordsize; }
 
yyerror(s)
  char * s;
  { 
  fputs(s,stderr); putc('\n',stderr);
  }

main()
  { int res;
    initsyms();
    res = yyparse();
    printst();
    printf("yyparse result = %8d\n", res);
    if (DEBUG & DB_PARSERES) dbugprinttok(parseresult);
    ppexpr(parseresult);           /* Pretty-print the result tree */
  }
