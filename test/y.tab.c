/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parse.y" /* yacc.c:339  */
     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 30 Jul 13   */

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


#line 127 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    STRING = 259,
    NUMBER = 260,
    PLUS = 261,
    MINUS = 262,
    TIMES = 263,
    DIVIDE = 264,
    ASSIGN = 265,
    EQ = 266,
    NE = 267,
    LT = 268,
    LE = 269,
    GE = 270,
    GT = 271,
    POINT = 272,
    DOT = 273,
    AND = 274,
    OR = 275,
    NOT = 276,
    DIV = 277,
    MOD = 278,
    IN = 279,
    COMMA = 280,
    SEMICOLON = 281,
    COLON = 282,
    LPAREN = 283,
    RPAREN = 284,
    LBRACKET = 285,
    RBRACKET = 286,
    DOTDOT = 287,
    ARRAY = 288,
    BEGINBEGIN = 289,
    CASE = 290,
    CONST = 291,
    DO = 292,
    DOWNTO = 293,
    ELSE = 294,
    END = 295,
    FILEFILE = 296,
    FOR = 297,
    FUNCTION = 298,
    GOTO = 299,
    IF = 300,
    LABEL = 301,
    NIL = 302,
    OF = 303,
    PACKED = 304,
    PROCEDURE = 305,
    PROGRAM = 306,
    RECORD = 307,
    REPEAT = 308,
    SET = 309,
    THEN = 310,
    TO = 311,
    TYPE = 312,
    UNTIL = 313,
    VAR = 314,
    WHILE = 315,
    WITH = 316
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING 259
#define NUMBER 260
#define PLUS 261
#define MINUS 262
#define TIMES 263
#define DIVIDE 264
#define ASSIGN 265
#define EQ 266
#define NE 267
#define LT 268
#define LE 269
#define GE 270
#define GT 271
#define POINT 272
#define DOT 273
#define AND 274
#define OR 275
#define NOT 276
#define DIV 277
#define MOD 278
#define IN 279
#define COMMA 280
#define SEMICOLON 281
#define COLON 282
#define LPAREN 283
#define RPAREN 284
#define LBRACKET 285
#define RBRACKET 286
#define DOTDOT 287
#define ARRAY 288
#define BEGINBEGIN 289
#define CASE 290
#define CONST 291
#define DO 292
#define DOWNTO 293
#define ELSE 294
#define END 295
#define FILEFILE 296
#define FOR 297
#define FUNCTION 298
#define GOTO 299
#define IF 300
#define LABEL 301
#define NIL 302
#define OF 303
#define PACKED 304
#define PROCEDURE 305
#define PROGRAM 306
#define RECORD 307
#define REPEAT 308
#define SET 309
#define THEN 310
#define TO 311
#define TYPE 312
#define UNTIL 313
#define VAR 314
#define WHILE 315
#define WITH 316

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 297 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   107

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    79,    79,    82,    86,    87,    91,    92,    95,    96,
     102,   103,   106,   109,   113,   116,   119,   120,   123,   126,
     127,   130,   133,   134,   135,   137,   138,   139,   146,   147,
     150,   153,   154,   157,   158,   161,   164,   165,   166,   167,
     168,   169,   170,   173,   174,   177,   178,   179,   180
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "NUMBER", "PLUS",
  "MINUS", "TIMES", "DIVIDE", "ASSIGN", "EQ", "NE", "LT", "LE", "GE", "GT",
  "POINT", "DOT", "AND", "OR", "NOT", "DIV", "MOD", "IN", "COMMA",
  "SEMICOLON", "COLON", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET",
  "DOTDOT", "ARRAY", "BEGINBEGIN", "CASE", "CONST", "DO", "DOWNTO", "ELSE",
  "END", "FILEFILE", "FOR", "FUNCTION", "GOTO", "IF", "LABEL", "NIL", "OF",
  "PACKED", "PROCEDURE", "PROGRAM", "RECORD", "REPEAT", "SET", "THEN",
  "TO", "TYPE", "UNTIL", "VAR", "WHILE", "WITH", "$accept", "program",
  "lBlock", "cBlock", "c_list", "tBlock", "tdef_list", "type",
  "simple_type", "vBlock", "block", "vdef_list", "vdef", "vid_list",
  "varType", "statement", "statement_list", "funcCall", "endpart", "endif",
  "assignment", "expr", "term", "factor", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

#define YYPACT_NINF -52

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-52)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -23,    17,    35,    16,   -52,    54,    32,    36,   -32,    60,
      61,    62,    48,   -52,   -52,   -52,    56,   -48,    57,    10,
      45,    39,    49,    50,   -52,    69,   -52,    73,   -52,    62,
      -2,   -52,    62,    75,    55,   -52,    58,   -52,   -52,    20,
      -2,    76,    19,    -2,     5,   -52,   -52,   -52,   -52,   -52,
      60,   -52,    19,    19,     5,    70,    26,    59,   -52,   -52,
      14,    19,    77,    -1,    47,   -52,    63,    25,    -2,   -52,
     -52,   -52,    53,     8,   -52,    83,   -52,    80,    27,    87,
      14,    14,    -2,    14,    14,    -2,    19,     5,   -52,    64,
     -52,    59,   -52,    80,    80,    52,   -52,    80,   -52,    53,
     -52,    -2,    -2,   -52,   -52,   -52
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     5,     9,     0,     0,     0,     0,
      20,     0,     0,     0,     2,     0,     4,     0,     8,     0,
       0,    14,    17,     0,     0,    13,    11,    12,    19,     0,
       0,     0,     0,     0,     0,    26,    25,    16,    21,    18,
       7,    10,     0,     0,     0,     0,     0,    46,    48,    47,
       0,     0,    40,     0,    38,    44,    29,     0,     0,    32,
      15,     6,    35,     0,    22,     0,    46,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,     0,
      45,     0,    39,    36,    37,    34,    43,    41,    28,    27,
      31,     0,     0,    23,    24,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -52,   -52,   -52,   -52,    42,    78,   -52,   -52,   -52,    74,
     -52,    65,   -52,    67,   -52,   -30,     9,   -40,   -51,   -52,
      66,   -45,   -31,    15
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    12,    13,    17,    14,    19,    36,    37,    15,
      31,    21,    22,    23,    49,    66,    67,    45,    70,   103,
      46,    63,    64,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      44,    39,    62,    74,     9,    80,    81,    72,    73,    10,
      54,    11,    62,    62,    80,    81,    78,    76,    58,    59,
       3,    62,    57,    58,    59,    10,    60,    11,     1,    77,
      52,    68,    40,    80,    81,     4,   100,    88,    87,    92,
      41,    99,    61,    42,     5,    69,    62,    61,    53,    93,
      94,    43,    95,    97,    82,    83,    90,     6,    84,    80,
      81,     7,     8,    16,    18,    20,    24,    25,    27,    11,
      29,   104,   105,    30,    34,    32,    35,    33,    48,    55,
      52,    50,    75,    86,    51,    79,    89,    53,    83,    85,
      91,   102,    71,    28,    98,    26,    38,    47,    96,     0,
       0,   101,     0,     0,     0,     0,     0,    56
};

static const yytype_int8 yycheck[] =
{
      30,     3,    42,    54,    36,     6,     7,    52,    53,    57,
      40,    59,    52,    53,     6,     7,    61,     3,     4,     5,
       3,    61,     3,     4,     5,    57,     7,    59,    51,    60,
      10,    26,    34,     6,     7,     0,    87,    29,    68,    79,
      42,    86,    28,    45,    28,    40,    86,    28,    28,    80,
      81,    53,    82,    84,    55,     8,    29,     3,    11,     6,
       7,    29,    26,     3,     3,     3,    18,    11,    11,    59,
      25,   101,   102,    34,     5,    26,     3,    27,     3,     3,
      10,    26,    56,    58,    26,     8,     3,    28,     8,    26,
       3,    39,    50,    19,    85,    17,    29,    32,    83,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    -1,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    63,     3,     0,    28,     3,    29,    26,    36,
      57,    59,    64,    65,    67,    71,     3,    66,     3,    68,
       3,    73,    74,    75,    18,    11,    67,    11,    71,    25,
      34,    72,    26,    27,     5,     3,    69,    70,    75,     3,
      34,    42,    45,    53,    77,    79,    82,    73,     3,    76,
      26,    26,    10,    28,    77,     3,    82,     3,     4,     5,
       7,    28,    79,    83,    84,    85,    77,    78,    26,    40,
      80,    66,    83,    83,    80,    56,     3,    84,    83,     8,
       6,     7,    55,     8,    11,    26,    58,    77,    29,     3,
      29,     3,    79,    84,    84,    77,    85,    84,    78,    83,
      80,    37,    39,    81,    77,    77
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    70,    71,    72,    73,    73,    74,    75,
      75,    76,    77,    77,    77,    77,    77,    77,    78,    78,
      79,    80,    80,    81,    81,    82,    83,    83,    83,    83,
      83,    83,    83,    84,    84,    85,    85,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     1,     3,     1,     5,     4,     3,     1,
       4,     3,     1,     1,     3,     3,     3,     2,     3,     3,
       1,     1,     3,     5,     6,     1,     1,     4,     3,     1,
       4,     3,     1,     2,     0,     3,     3,     3,     1,     3,
       1,     3,     2,     3,     1,     3,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 79 "parse.y" /* yacc.c:1646  */
    { parseresult = makeprogram((yyvsp[-6]), (yyvsp[-4]), (yyvsp[-1])); }
#line 1450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 82 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 86 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 87 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 91 "parse.y" /* yacc.c:1646  */
    { instconst((yyvsp[-4]), (yyvsp[-2])); }
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 92 "parse.y" /* yacc.c:1646  */
    { instconst((yyvsp[-3]), (yyvsp[-1])); }
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 95 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 96 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 113 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 116 "parse.y" /* yacc.c:1646  */
    { (yyval) = makeprogn((yyvsp[-2]),cons((yyvsp[-1]), (yyvsp[0]))); }
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 123 "parse.y" /* yacc.c:1646  */
    { instvars((yyvsp[-2]), findtype((yyvsp[0]))); }
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 126 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 127 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 130 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 133 "parse.y" /* yacc.c:1646  */
    { (yyval) = makeprogn((yyvsp[-2]),cons((yyvsp[-1]), (yyvsp[0]))); }
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 134 "parse.y" /* yacc.c:1646  */
    { (yyval) = makeif((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-1]), (yyvsp[0])); }
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 135 "parse.y" /* yacc.c:1646  */
    { (yyval) = makefor(1, (TOKEN) talloc(), (yyvsp[-4]), (yyvsp[-2]), NULL, NULL, (yyvsp[0])); }
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 137 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 138 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 139 "parse.y" /* yacc.c:1646  */
    {(yyval) = makerepeat((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 146 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 147 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 150 "parse.y" /* yacc.c:1646  */
    { (yyval) = makefuncall((TOKEN) talloc(), (yyvsp[-3]), (yyvsp[-1]));}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 153 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-1]), (yyvsp[0])); }
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 154 "parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 157 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 158 "parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 161 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 164 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 165 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 166 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 167 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 168 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 169 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 170 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[0]), (yyvsp[0])); }
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 173 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 174 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 177 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 178 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 179 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 180 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1694 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 183 "parse.y" /* yacc.c:1906  */


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

 int labelnumber = 0;  /* sequential counter for internal label numbers */

   /*  Note: you should add to the above values and insert debugging
       printouts in your routines similar to those that are shown here.     */

 /* makerepeat makes structures for a repeat statement.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokb, TOKEN expr){
  int num_to_go_to = labelnumber;
  TOKEN labeltok = makelabel();
  tok = makeprogn(tok, labeltok);
  TOKEN progn_statements = makeprogn(tokb, statements);
  labeltok->link = progn_statements;
  TOKEN go_to_tok = makegoto(num_to_go_to);
  TOKEN empty_progn = makeprogn((TOKEN) talloc(), NULL);
  empty_progn->link = go_to_tok;
  TOKEN if_token = talloc();
  if_token = makeif(if_token, expr, empty_progn, go_to_tok);
  progn_statements->link = if_token;
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
    sym->basicdt = type->basicdt;
    if(consttok->datatype == INTEGER)
    {
      sym->constval.intnum = consttok->intval;
    }
    else if(consttok->datatype == REAL)
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
