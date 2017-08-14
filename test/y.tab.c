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
#define YYLAST   233

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

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
       0,    79,    79,    82,    83,    86,    87,    90,    91,    95,
      96,    99,   100,   103,   106,   107,   110,   111,   112,   113,
     116,   117,   118,   121,   122,   125,   126,   129,   130,   133,
     136,   139,   140,   143,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   157,   158,   161,   164,   167,   168,   171,
     172,   175,   178,   179,   180,   181,   182,   183,   184,   185,
     188,   188,   188,   188,   188,   188,   188,   192,   193,   197,
     197,   200,   201,   205,   206,   209,   210,   211,   212,   213,
     216,   217,   218,   219
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
  "lBlock", "numlist", "cBlock", "c_list", "tBlock", "tdef", "tdef_list",
  "type", "simple_type", "simple_type_list", "field_list", "id_list",
  "vBlock", "block", "vdef_list", "vdef", "statement", "statement_list",
  "funcCall", "label", "endpart", "endif", "assignment", "expr",
  "compare_op", "simple_expr", "sign_term", "expr_list", "term", "factor",
  "variable", YY_NULLPTR
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

#define YYPACT_NINF -83

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-83)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -37,    17,    36,     9,   -83,    35,    20,    26,   -18,    65,
      70,    78,    80,    66,   -83,   -83,   -83,    74,     4,    61,
      62,    79,    76,    41,    81,    68,    71,    77,   -83,    99,
     -83,    70,    12,    37,    78,   -83,    80,    37,    73,   -83,
      80,    82,   -83,   -83,   -83,    87,   106,    80,    83,    80,
     -83,   -83,   -83,   -83,   -83,    84,   -83,   109,    52,    73,
      69,   132,    52,   -83,    73,    52,   -21,   -83,   -83,   -83,
     101,    -6,   -83,    65,   133,   -83,    85,     5,   105,   120,
      52,    73,   -83,    69,   143,   156,    19,   -83,   -21,   -83,
      94,   -83,   128,   134,   103,   142,    73,   -83,   -83,    52,
     -83,   161,    52,   -83,   -83,   -83,   148,   144,   -83,    37,
     175,   -83,   151,   171,    69,    69,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   118,    69,    69,   -83,   173,    73,
      73,    52,    73,   -21,   209,   -83,   194,   146,     5,   130,
     158,   -83,    84,   -83,   151,   151,   -83,    69,   -83,   -83,
     151,   -83,   151,   155,   154,   -83,   209,   -83,   -83,    52,
     -83,   -83,    37,    80,   151,    73,    73,   -83,   -83,   -83,
     -83,   -83,   -83
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     8,    12,     0,     0,     6,
       0,     0,     0,     0,    28,     0,     0,     0,     2,     0,
       7,     0,     0,     0,    15,    11,     0,     0,     0,    29,
      32,     0,     5,     3,    20,     0,     0,     0,     0,     0,
      13,    16,    14,    27,    33,    80,    77,    76,     0,     0,
       0,     0,     0,    79,     0,     0,     0,    37,    42,    36,
       0,    78,    31,    10,     0,    18,     0,     0,     0,     0,
       0,     0,    76,     0,    57,     0,    55,    74,     0,    80,
       0,    41,     0,    44,     0,     0,     0,    48,    30,     0,
      83,     0,     0,     9,    22,    21,    24,     0,    17,     0,
       0,    46,    59,     0,     0,     0,    60,    63,    61,    64,
      65,    62,    66,    75,     0,     0,     0,    34,     0,     0,
       0,     0,     0,     0,    51,    82,    72,     0,     0,     0,
      25,    45,     0,    56,    53,    54,    69,     0,    52,    67,
      68,    73,    58,     0,    50,    43,    39,    38,    47,     0,
      81,    23,     0,     0,    70,     0,     0,    35,    71,    19,
      26,    40,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -83,   -83,   -83,   163,   164,   122,   179,   -83,   168,   -30,
     -76,    60,    40,   -32,   188,   -83,   172,   -83,   -36,    96,
     -49,   -83,   -82,   -83,   153,   -33,   -83,   -83,   -83,    55,
     -80,   -38,   -83
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    13,    20,    14,    18,    15,    22,    23,    50,
      51,   107,    78,    25,    16,    39,    26,    27,    93,    94,
      67,    68,    98,   167,    69,   136,   124,   148,   149,   137,
      86,    87,    71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      70,   106,    66,   112,    53,    96,   127,    54,    44,    84,
      45,   100,   101,    84,     1,    76,    84,    79,     9,    97,
       3,    70,    70,    88,   102,    85,    70,   125,    10,    92,
     126,    84,    95,    47,   144,   145,     4,     5,     6,    11,
      44,    12,    45,    70,   150,   111,   152,   110,     9,     7,
      84,   158,     8,    84,    46,    55,    56,    82,    70,    83,
     133,    11,   106,    12,   143,    47,   134,   164,    17,    11,
      48,    12,    89,    56,    82,    19,    55,    56,    57,   140,
      58,    21,    84,    24,    28,    29,    31,   151,    32,    49,
      33,    70,    70,   154,    70,    37,   157,    58,   156,    63,
      12,    58,    34,    40,    41,    38,    36,    59,    73,    75,
      84,    99,    80,    77,   105,    60,    63,    61,    62,    74,
      63,    89,    56,    82,   146,   147,    64,    70,    70,   171,
     172,    79,   169,    65,   114,   115,    81,    91,   104,   116,
     117,   118,   119,   120,   121,   108,    58,   109,   114,   115,
     128,   113,   122,   116,   117,   118,   119,   120,   121,   125,
     130,   131,   114,   115,   135,    63,   122,   116,   117,   118,
     119,   120,   121,   138,   142,   139,   153,   160,   162,   132,
     122,   114,   115,   129,   163,   123,   116,   117,   118,   119,
     120,   121,   165,   166,    42,   103,    43,    30,   161,   122,
     114,   115,    52,   170,   141,   116,   117,   118,   119,   120,
     121,    35,    72,    90,   168,   114,   115,     0,   122,   159,
     116,   117,   118,   119,   120,   121,   155,     0,     0,     0,
       0,     0,     0,   122
};

static const yytype_int16 yycheck[] =
{
      38,    77,    38,    83,    36,    26,    88,    37,     3,    58,
       5,    17,    18,    62,    51,    47,    65,    49,    36,    40,
       3,    59,    60,    59,    30,    58,    64,     8,    46,    62,
      11,    80,    65,    28,   114,   115,     0,    28,     3,    57,
       3,    59,     5,    81,   124,    81,   126,    80,    36,    29,
      99,   133,    26,   102,    17,     3,     4,     5,    96,     7,
      96,    57,   138,    59,   113,    28,    99,   147,     3,    57,
      33,    59,     3,     4,     5,     5,     3,     4,     5,   109,
      28,     3,   131,     3,    18,    11,    25,   125,    26,    52,
      11,   129,   130,   129,   132,    27,   132,    28,   131,    47,
      59,    28,    26,    26,     5,    34,    25,    34,    26,     3,
     159,    10,    28,    30,    29,    42,    47,    44,    45,    32,
      47,     3,     4,     5,     6,     7,    53,   165,   166,   165,
     166,   163,   162,    60,     6,     7,    27,     5,     5,    11,
      12,    13,    14,    15,    16,    40,    28,    27,     6,     7,
      56,     8,    24,    11,    12,    13,    14,    15,    16,     8,
      26,    58,     6,     7,     3,    47,    24,    11,    12,    13,
      14,    15,    16,    25,     3,    31,     3,    31,    48,    37,
      24,     6,     7,    55,    26,    29,    11,    12,    13,    14,
      15,    16,    37,    39,    31,    73,    32,    18,   138,    24,
       6,     7,    34,   163,    29,    11,    12,    13,    14,    15,
      16,    23,    40,    60,   159,     6,     7,    -1,    24,    25,
      11,    12,    13,    14,    15,    16,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    63,     3,     0,    28,     3,    29,    26,    36,
      46,    57,    59,    64,    66,    68,    76,     3,    67,     5,
      65,     3,    69,    70,     3,    75,    78,    79,    18,    11,
      68,    25,    26,    11,    26,    76,    25,    27,    34,    77,
      26,     5,    65,    66,     3,     5,    17,    28,    33,    52,
      71,    72,    70,    75,    71,     3,     4,     5,    28,    34,
      42,    44,    45,    47,    53,    60,    80,    82,    83,    86,
      93,    94,    78,    26,    32,     3,    75,    30,    74,    75,
      28,    27,     5,     7,    82,    87,    92,    93,    80,     3,
      86,     5,    87,    80,    81,    87,    26,    40,    84,    10,
      17,    18,    30,    67,     5,    29,    72,    73,    40,    27,
      87,    80,    92,     8,     6,     7,    11,    12,    13,    14,
      15,    16,    24,    29,    88,     8,    11,    84,    56,    55,
      26,    58,    37,    80,    87,     3,    87,    91,    25,    31,
      71,    29,     3,    82,    92,    92,     6,     7,    89,    90,
      92,    93,    92,     3,    80,    81,    87,    80,    84,    25,
      31,    73,    48,    26,    92,    37,    39,    85,    91,    71,
      74,    80,    80
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    68,    68,    69,    70,    70,    71,    71,    71,    71,
      72,    72,    72,    73,    73,    74,    74,    75,    75,    76,
      77,    78,    78,    79,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    81,    81,    82,    83,    84,    84,    85,
      85,    86,    87,    87,    87,    87,    87,    87,    87,    87,
      88,    88,    88,    88,    88,    88,    88,    89,    89,    90,
      90,    91,    91,    92,    92,    93,    93,    93,    93,    93,
      94,    94,    94,    94
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     4,     1,     3,     1,     3,     1,     5,
       4,     3,     1,     3,     3,     2,     1,     3,     2,     6,
       1,     3,     3,     3,     1,     3,     5,     3,     1,     3,
       3,     3,     2,     3,     3,     5,     1,     1,     4,     4,
       6,     2,     1,     3,     1,     4,     3,     3,     1,     2,
       0,     3,     3,     3,     3,     1,     3,     1,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     4,     3,     2
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
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 82 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 83 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 86 "parse.y" /* yacc.c:1646  */
    { instlabel((yyvsp[-2])); }
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 87 "parse.y" /* yacc.c:1646  */
    { instlabel((yyvsp[0])); }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 90 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 91 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 95 "parse.y" /* yacc.c:1646  */
    { instconst((yyvsp[-4]), (yyvsp[-2])); }
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 96 "parse.y" /* yacc.c:1646  */
    { instconst((yyvsp[-3]), (yyvsp[-1])); }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 99 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 100 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 103 "parse.y" /* yacc.c:1646  */
    { insttype((yyvsp[-2]), (yyvsp[0])); }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 106 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 107 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 110 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 111 "parse.y" /* yacc.c:1646  */
    { (yyval) = instrec((yyvsp[-2]), (yyvsp[-1])); }
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 112 "parse.y" /* yacc.c:1646  */
    { (yyval) = instpoint((yyvsp[-1]), (yyvsp[0])); }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 113 "parse.y" /* yacc.c:1646  */
    { (yyval) = instarray((yyvsp[-3]), (yyvsp[0])); }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 116 "parse.y" /* yacc.c:1646  */
    { (yyval) = findtype((yyvsp[0])); }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 117 "parse.y" /* yacc.c:1646  */
    { (yyval) = instenum((yyvsp[-1])); }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 118 "parse.y" /* yacc.c:1646  */
    { (yyval) = instdotdot((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 121 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[0]), (yyvsp[-2])); }
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 122 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 125 "parse.y" /* yacc.c:1646  */
    { instfields((yyvsp[-2]), (yyvsp[0])); }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 126 "parse.y" /* yacc.c:1646  */
    { instfields((yyvsp[-4]), (yyvsp[-2])); (yyval) = nconc((yyvsp[-4]), (yyvsp[0])); }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 129 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 130 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[0]), NULL); }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 133 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 136 "parse.y" /* yacc.c:1646  */
    { (yyval) = makeprogn((yyvsp[-2]),cons((yyvsp[-1]), (yyvsp[0]))); }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 139 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 140 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 143 "parse.y" /* yacc.c:1646  */
    { instvars((yyvsp[-2]), (yyvsp[0])); }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 146 "parse.y" /* yacc.c:1646  */
    { (yyval) = makeprogn((yyvsp[-2]),cons((yyvsp[-1]), (yyvsp[0]))); }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 147 "parse.y" /* yacc.c:1646  */
    { (yyval) = makeif((yyvsp[-4]), (yyvsp[-3]), (yyvsp[-1]), (yyvsp[0])); }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 148 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 149 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 150 "parse.y" /* yacc.c:1646  */
    { (yyval) = makewhile((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 151 "parse.y" /* yacc.c:1646  */
    {(yyval) = makerepeat((yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0]));}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 152 "parse.y" /* yacc.c:1646  */
    { (yyval) = makefor(1, (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 153 "parse.y" /* yacc.c:1646  */
    { (yyval) = dogoto((yyvsp[-1]), (yyvsp[0])); }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 154 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 157 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 158 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 161 "parse.y" /* yacc.c:1646  */
    { (yyval) = makefuncall((TOKEN) talloc(), (yyvsp[-3]), (yyvsp[-1]));}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 164 "parse.y" /* yacc.c:1646  */
    { (yyval) = dolabel((yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 167 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-1]), (yyvsp[0])); }
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 168 "parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 171 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 172 "parse.y" /* yacc.c:1646  */
    { (yyval) = NULL; }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 175 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 178 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 179 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 180 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 181 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 182 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 183 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 184 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 185 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[0]), (yyvsp[0])); }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 188 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 192 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 193 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 197 "parse.y" /* yacc.c:1646  */
    { (yyval) = unaryop((yyvsp[-1]), (yyvsp[0])); }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 200 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[-2]), (yyvsp[0])); }
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 201 "parse.y" /* yacc.c:1646  */
    { (yyval) = cons((yyvsp[0]), NULL); }
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 205 "parse.y" /* yacc.c:1646  */
    { (yyval) = binop((yyvsp[-1]), (yyvsp[-2]), (yyvsp[0])); }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 206 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 209 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 210 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 211 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 212 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 213 "parse.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 216 "parse.y" /* yacc.c:1646  */
    { (yyval) = findid((yyvsp[0])); }
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 217 "parse.y" /* yacc.c:1646  */
    { arrayref((yyvsp[-3]), NULL, (yyvsp[-1]), NULL); }
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 219 "parse.y" /* yacc.c:1646  */
    { (yyval) = dopoint((yyvsp[-1]), (yyvsp[0])); }
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1955 "y.tab.c" /* yacc.c:1646  */
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
#line 222 "parse.y" /* yacc.c:1906  */


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
