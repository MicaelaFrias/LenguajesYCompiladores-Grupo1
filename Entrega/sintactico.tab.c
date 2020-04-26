
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "sintactico.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "sintactico.tab.h"
nt yystopparser=0;
FILE  *yyin;
int insertarEnTS(char[],char[],char[],int,double);


/* Line 189 of yacc.c  */
#line 85 "sintactico.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     DEFINE = 259,
     ENDDEFINE = 260,
     CONST_INT = 261,
     CONST_REAL = 262,
     CONST_STR = 263,
     ID = 264,
     REAL = 265,
     FLOAT = 266,
     INT = 267,
     PYC = 268,
     STRING = 269,
     BEGINP = 270,
     ENDP = 271,
     IF = 272,
     THEN = 273,
     ELSE = 274,
     ENDIF = 275,
     LET = 276,
     FOR = 277,
     TO = 278,
     DO = 279,
     ENDFOR = 280,
     WHILE = 281,
     ENDW = 282,
     REPEAT = 283,
     UNTIL = 284,
     OP_LOG = 285,
     OP_NOT = 286,
     OP_DOSP = 287,
     OP_COMPARACION = 288,
     OP_ASIG = 289,
     OP_SUM = 290,
     OP_RES = 291,
     OP_DIV = 292,
     OP_MULT = 293,
     COMA = 294,
     P_A = 295,
     P_C = 296,
     C_A = 297,
     C_C = 298,
     LONG = 299,
     IN = 300,
     COMEN = 301,
     LETRA = 302,
     DEFVAR = 303,
     ENDDEF = 304,
     GET = 305,
     DISPLAY = 306
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 12 "sintactico.y"

int int_val;
double float_val;
char *str_val;



/* Line 214 of yacc.c  */
#line 180 "sintactico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 192 "sintactico.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   176

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNRULES -- Number of states.  */
#define YYNSTATES  138

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     8,    12,    16,    18,    21,    23,
      26,    28,    30,    32,    34,    36,    38,    40,    42,    44,
      46,    48,    50,    51,    52,    58,    59,    60,    69,    80,
      88,    98,   100,   102,   106,   111,   112,   117,   119,   121,
     123,   125,   127,   131,   133,   135,   137,   139,   141,   143,
     145,   146,   147,   148,   158,   160,   161,   166,   168,   169,
     174,   178,   180,   182,   184,   185,   190,   192,   195,   196,
     201,   203,   205,   207,   209,   210,   211,   217,   218,   222,
     223,   227,   229,   231,   233
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    -1,     3,    54,    55,    -1,    15,    56,
      16,    -1,    15,    57,    16,    -1,    58,    -1,    56,    58,
      -1,    59,    -1,    57,    59,    -1,    46,    -1,    63,    -1,
      67,    -1,    87,    -1,    93,    -1,    60,    -1,    96,    -1,
      98,    -1,    85,    -1,    66,    -1,    73,    -1,    77,    -1,
      -1,    -1,     9,    61,    34,    62,    76,    -1,    -1,    -1,
      26,    64,    40,    68,    65,    41,    56,    27,    -1,     9,
      34,    17,    40,    68,    39,    73,    39,    73,    41,    -1,
      17,    40,    68,    41,    18,    56,    20,    -1,    17,    40,
      68,    41,    18,    56,    19,    56,    20,    -1,    70,    -1,
      69,    -1,    70,    30,    70,    -1,    31,    40,    70,    41,
      -1,    -1,    76,    33,    71,    76,    -1,    35,    -1,    36,
      -1,    38,    -1,    37,    -1,    74,    -1,    74,    72,    75,
      -1,    75,    -1,    47,    -1,    76,    -1,     9,    -1,     6,
      -1,     8,    -1,     7,    -1,    -1,    -1,    -1,    21,    78,
      81,    34,    79,    40,    80,    83,    41,    -1,     9,    -1,
      -1,    81,    39,    82,     9,    -1,    74,    -1,    -1,    83,
      13,    84,    74,    -1,     9,    34,    86,    -1,     9,    -1,
       6,    -1,    74,    -1,    -1,    48,    88,    89,    49,    -1,
      90,    -1,    89,    90,    -1,    -1,    92,    32,    91,    93,
      -1,    11,    -1,    14,    -1,    12,    -1,     9,    -1,    -1,
      -1,     9,    94,    13,    95,    93,    -1,    -1,    50,    97,
       9,    -1,    -1,    51,    99,   100,    -1,     8,    -1,     7,
      -1,     6,    -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    59,    59,    59,    64,    65,    68,    69,    72,    73,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    87,
      88,    89,    92,    93,    92,    97,    99,    97,   106,   119,
     121,   125,   126,   130,   132,   136,   135,   140,   141,   142,
     143,   147,   150,   151,   155,   156,   160,   161,   162,   163,
     166,   168,   169,   166,   174,   176,   175,   180,   182,   181,
     186,   191,   192,   193,   196,   196,   201,   202,   206,   205,
     210,   211,   212,   215,   216,   217,   216,   222,   222,   226,
     226,   230,   231,   232,   233
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "DEFINE", "ENDDEFINE",
  "CONST_INT", "CONST_REAL", "CONST_STR", "ID", "REAL", "FLOAT", "INT",
  "PYC", "STRING", "BEGINP", "ENDP", "IF", "THEN", "ELSE", "ENDIF", "LET",
  "FOR", "TO", "DO", "ENDFOR", "WHILE", "ENDW", "REPEAT", "UNTIL",
  "OP_LOG", "OP_NOT", "OP_DOSP", "OP_COMPARACION", "OP_ASIG", "OP_SUM",
  "OP_RES", "OP_DIV", "OP_MULT", "COMA", "P_A", "P_C", "C_A", "C_C",
  "LONG", "IN", "COMEN", "LETRA", "DEFVAR", "ENDDEF", "GET", "DISPLAY",
  "$accept", "programa", "$@1", "codigo", "bloqueTemasComunes",
  "bloqueTemasEspeciales", "temaComun", "temaEspecial", "asignacion",
  "$@2", "$@3", "iteracion", "$@4", "$@5", "ifUnario", "decision",
  "condicion", "condicionMultiple", "comparacion", "$@6", "operacion",
  "accion", "expresion", "termino", "factor", "let", "$@7", "$@8", "$@9",
  "listaVarLetIzq", "$@10", "listaVarLetDer", "$@11", "variablesNumericas",
  "valorNumerico", "bloqueDeclaracion", "$@12", "declaraciones",
  "declaracion", "$@13", "tipodato", "listavariables", "$@14", "$@15",
  "entrada", "$@16", "salida", "$@17", "terminoSalida", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    54,    53,    55,    55,    56,    56,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    59,
      59,    59,    61,    62,    60,    64,    65,    63,    66,    67,
      67,    68,    68,    69,    69,    71,    70,    72,    72,    72,
      72,    73,    74,    74,    75,    75,    76,    76,    76,    76,
      78,    79,    80,    77,    81,    82,    81,    83,    84,    83,
      85,    86,    86,    86,    88,    87,    89,    89,    91,    90,
      92,    92,    92,    93,    94,    95,    93,    97,    96,    99,
      98,   100,   100,   100,   100
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     3,     3,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     0,     5,     0,     0,     8,    10,     7,
       9,     1,     1,     3,     4,     0,     4,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       0,     0,     0,     9,     1,     0,     4,     1,     0,     4,
       3,     1,     1,     1,     0,     4,     1,     2,     0,     4,
       1,     1,     1,     1,     0,     0,     5,     0,     3,     0,
       3,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     0,     3,    47,    49,    48,
      46,     0,    50,    25,    10,    44,    64,    77,    79,     0,
       0,     6,     8,    15,    11,    19,    12,    20,    41,    43,
      45,    21,    18,    13,    14,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,     4,     7,    46,
       5,     9,    37,    38,    40,    39,     0,    47,    46,     0,
      63,    60,    23,    75,    46,     0,     0,    32,    31,     0,
      54,     0,     0,    70,    72,    71,     0,    66,     0,    78,
      83,    82,    81,    84,    80,     0,     0,    42,     0,     0,
       0,     0,     0,     0,    35,    51,    55,    26,    65,    67,
      68,     0,    24,    73,    76,     0,     0,    33,     0,     0,
       0,     0,     0,     0,    34,     0,    36,    52,    56,     0,
      69,     0,     0,    29,     0,     0,     0,     0,    57,     0,
      27,     0,    30,    58,    53,    28,     0,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,    19,    20,    21,    22,    23,    38,
      89,    24,    42,   111,    25,    26,    66,    67,    68,   108,
      56,    27,    28,    29,    30,    31,    41,   109,   124,    71,
     110,   129,   136,    32,    61,    33,    43,    76,    77,   112,
      78,    34,    39,    90,    35,    44,    36,    45,    84
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -99
static const yytype_int16 yypact[] =
{
      14,   -99,    22,    13,   -99,    -3,   -99,   -99,   -99,   -99,
     120,    17,   -99,   -99,   -99,   -99,   -99,   -99,   -99,    16,
     118,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   121,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,    95,    29,    52,
     141,    60,    32,     1,    62,   154,     7,   -99,   -99,    39,
     -99,   -99,   -99,   -99,   -99,   -99,    31,   -99,   -99,    35,
     121,   -99,   -99,   -99,   -99,    37,    38,   -99,    50,    51,
     -99,   -23,   141,   -99,   -99,   -99,    83,   -99,    55,   -99,
     -99,   -99,   -99,   -99,   -99,   122,    66,   -99,   141,   167,
      81,   167,    75,   167,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,    78,   -99,    86,   -99,    73,    65,   -99,   167,    79,
     112,    94,    81,    31,   -99,    10,   -99,   -99,   -99,    65,
     -99,    97,    65,   -99,    31,    59,    31,    72,   121,    -6,
     -99,    99,   -99,   -99,   -99,   -99,    31,   121
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -99,   -99,   -99,   -99,   -98,   -99,   -19,   123,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -62,   -99,   -39,   -99,
     -99,   -67,   -36,    82,   -38,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,    68,   -99,
     -99,   -81,   -99,   -99,   -99,   -99,   -99,   -99,   -99
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -75
static const yytype_int16 yytable[] =
{
      48,    60,    69,     7,     8,     9,    10,   133,   115,   104,
      97,    95,    73,    74,    11,    75,    96,     1,    12,    46,
     -74,   125,     4,    13,   127,    46,   101,    11,     5,   122,
     123,   120,    47,    11,    69,   134,    13,     7,     8,     9,
      64,    85,    13,    14,    15,    16,   121,    17,    18,    60,
      69,   102,   105,    69,   107,    69,    14,    40,    16,   131,
      17,    18,    14,    62,    16,    63,    17,    18,    46,    70,
     116,    79,    72,    86,    46,    88,    11,    91,    15,    92,
      93,    46,    11,    59,    94,    13,   130,   100,   128,    11,
     103,    13,   132,   106,    73,    74,    48,    75,    13,   -74,
     137,    57,     8,     9,    58,    14,    48,    16,    48,    17,
      18,    14,    59,    16,   114,    17,    18,   113,    14,   117,
      16,   118,    17,    18,     7,     8,     9,    49,    57,     8,
       9,    58,    98,   -74,    50,   119,   126,   -73,    87,    12,
     135,     0,    15,    51,    99,     0,   -73,     7,     8,     9,
      64,     0,     0,     0,    37,     0,    52,    53,    54,    55,
      80,    81,    82,    83,     0,    15,   -73,     0,   -73,    15,
     -73,   -73,    65,     7,     8,     9,    64
};

static const yytype_int16 yycheck[] =
{
      19,    37,    40,     6,     7,     8,     9,    13,   106,    90,
      72,    34,    11,    12,    17,    14,    39,     3,    21,     9,
      13,   119,     0,    26,   122,     9,    88,    17,    15,    19,
      20,   112,    16,    17,    72,    41,    26,     6,     7,     8,
       9,    34,    26,    46,    47,    48,   113,    50,    51,    85,
      88,    89,    91,    91,    93,    93,    46,    40,    48,   126,
      50,    51,    46,    34,    48,    13,    50,    51,     9,     9,
     108,     9,    40,    34,     9,    40,    17,    40,    47,    41,
      30,     9,    17,    17,    33,    26,    27,    32,   124,    17,
       9,    26,    20,    18,    11,    12,   115,    14,    26,    13,
     136,     6,     7,     8,     9,    46,   125,    48,   127,    50,
      51,    46,    17,    48,    41,    50,    51,    39,    46,    40,
      48,     9,    50,    51,     6,     7,     8,     9,     6,     7,
       8,     9,    49,    13,    16,    41,    39,    17,    56,    21,
      41,    -1,    47,    20,    76,    -1,    26,     6,     7,     8,
       9,    -1,    -1,    -1,    34,    -1,    35,    36,    37,    38,
       6,     7,     8,     9,    -1,    47,    46,    -1,    48,    47,
      50,    51,    31,     6,     7,     8,     9
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    53,    54,     0,    15,    55,     6,     7,     8,
       9,    17,    21,    26,    46,    47,    48,    50,    51,    56,
      57,    58,    59,    60,    63,    66,    67,    73,    74,    75,
      76,    77,    85,    87,    93,    96,    98,    34,    61,    94,
      40,    78,    64,    88,    97,    99,     9,    16,    58,     9,
      16,    59,    35,    36,    37,    38,    72,     6,     9,    17,
      74,    86,    34,    13,     9,    31,    68,    69,    70,    76,
       9,    81,    40,    11,    12,    14,    89,    90,    92,     9,
       6,     7,     8,     9,   100,    34,    34,    75,    40,    62,
      95,    40,    41,    30,    33,    34,    39,    68,    49,    90,
      32,    68,    76,     9,    93,    70,    18,    70,    71,    79,
      82,    65,    91,    39,    41,    56,    76,    40,     9,    41,
      93,    73,    19,    20,    80,    56,    39,    56,    74,    83,
      27,    73,    20,    13,    41,    41,    84,    74
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 59 "sintactico.y"
    {printf("Inicia COMPILADOR\n");;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 61 "sintactico.y"
    {printf("Fin COMPILADOR\n");;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 76 "sintactico.y"
    {printf("--------------------------ESTO ES UN COMENTARIO\n\n\n");;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 77 "sintactico.y"
    {printf("--------------------------ESTO ES UNA ITERACION\n\n\n");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 78 "sintactico.y"
    {printf("--------------------------ESTO ES UNA DECISION\n\n\n");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 79 "sintactico.y"
    {printf("--------------------------ESTO ES UNA DECLARACION\n\n\n");;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 80 "sintactico.y"
    {printf("--------------------------ESTO ES UNA LISTA DE VARIABLES\n\n\n");;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 81 "sintactico.y"
    {printf("--------------------------ESTO ES UNA ASIGNACION\n\n\n");;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 82 "sintactico.y"
    {printf("--------------------------ESTO ES UNA ENTREADA\n\n\n");;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 83 "sintactico.y"
    {printf("--------------------------ESTO ES UNA SALIDA\n\n\n");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 84 "sintactico.y"
    {printf("--------------------------ESTO ES UNA VARIABLE NUMERICA\n\n\n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 87 "sintactico.y"
    {printf("--------------------------ESTO ES UN IF UNARIO\n\n\n");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 88 "sintactico.y"
    {printf("--------------------------ESTO ES UNA ACCION\n\n\n");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 89 "sintactico.y"
    {printf("--------------------------ESTO ES UN LET\n\n\n");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 92 "sintactico.y"
    {printf("ok id\n");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 93 "sintactico.y"
    {printf("ok op asig\n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 97 "sintactico.y"
    {printf("ok while\n");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 99 "sintactico.y"
    {printf("ok condicion\n");;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 102 "sintactico.y"
    {printf("ok endwhile \n");;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 119 "sintactico.y"
    {printf("ok end if\n");;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 121 "sintactico.y"
    {printf("ok end if\n");;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 130 "sintactico.y"
    {("ok comparacion and/or\n");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 132 "sintactico.y"
    {("ok comparacion not\n");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 136 "sintactico.y"
    {printf("ok operador comparacion\n");;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 140 "sintactico.y"
    {printf("ok suma\n");;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 141 "sintactico.y"
    {printf("ok resta\n");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 142 "sintactico.y"
    {printf("ok multiplicacion\n");;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 143 "sintactico.y"
    {printf("ok division\n");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 160 "sintactico.y"
    {printf("ok var\n");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 161 "sintactico.y"
    {printf("ok int\n");;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 162 "sintactico.y"
    {printf("ok str\n");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 163 "sintactico.y"
    {printf("ok real\n");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 166 "sintactico.y"
    {printf("ok let\n");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 168 "sintactico.y"
    {printf("ok igual\n");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 169 "sintactico.y"
    {printf("ok parentesis abierto\n");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 171 "sintactico.y"
    {printf("ok parentesis cerrado\n");;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 174 "sintactico.y"
    {printf("ok id\n");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 176 "sintactico.y"
    {printf("ok coma\n");;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 177 "sintactico.y"
    {printf("ok id\n");;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 182 "sintactico.y"
    {printf("ok punto y coma\n");;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 196 "sintactico.y"
    {printf("ok def var\n");;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 198 "sintactico.y"
    {printf("ok end def\n");;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 206 "sintactico.y"
    {printf("ok op asignacion\n");;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 210 "sintactico.y"
    {printf("ok float\n");;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 211 "sintactico.y"
    {printf("ok float\n");;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 212 "sintactico.y"
    {printf("ok int\n");;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 215 "sintactico.y"
    {printf("ok id\n");;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 216 "sintactico.y"
    {printf("ok id\n");;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 217 "sintactico.y"
    {printf("ok punto y coma \n");;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 222 "sintactico.y"
    {printf("ok get\n");;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 223 "sintactico.y"
    {printf("ok id\n");;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 226 "sintactico.y"
    {printf("ok display\n");;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 227 "sintactico.y"
    {printf("ok terminoDisplay\n");;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 230 "sintactico.y"
    {printf("ok const_string\n");;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 231 "sintactico.y"
    {printf("ok const_real\n");;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 232 "sintactico.y"
    {printf("ok const_int\n");;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 233 "sintactico.y"
    {printf("ok id\n");;}
    break;



/* Line 1455 of yacc.c  */
#line 1928 "sintactico.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 236 "sintactico.y"


int main(int argc,char *argv[])
{
  if ((yyin = fopen(argv[1], "rt")) == NULL)
  {
	printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
  }
  else
  {
	yyparse();
  }
  fclose(yyin);
  return 0;
}
int yyerror(void)
     {
       printf("Syntax Error\n");
	 system ("Pause");
	 exit (1);
     }

int insertarEnTS(char nombreSimbolo[],char tipoSimbolo[],char valorString[],int valorInteger, double valorFloat){
  FILE *archTS2 = fopen("ts.txt","r");
  char simboloTS[100];
  char valor[20];
  char valorCte[20];
  char valorBuscado[20];
  char linea[100];
  char separador[] = "\t\t\t";
  char *pos;
  int longitud;
  int band = 0;
  int i = 0;
  if(strcmp(tipoSimbolo,"ID") != 0){
    if(strcmp(tipoSimbolo,"CONST_INT") == 0){
      sprintf(valor,"%d",valorInteger);
      strcpy(valorCte,"_");
      strcat(valorCte,valor);

      strcpy(simboloTS,"_");
      strcat(simboloTS,valor);
      strcat(simboloTS,"\t\t\t");
      strcat(simboloTS,"CteInt");
      strcat(simboloTS,"\t\t\t");
      strcat(simboloTS,valor);
    }
    if(strcmp(tipoSimbolo,"CONST_FLOAT") == 0){
      sprintf(valor,"%.3f",valorFloat);
      strcpy(valorCte,"_");
      strcat(valorCte,valor);

      strcpy(simboloTS,"_");
      strcat(simboloTS,valor);
      strcat(simboloTS,"\t\t\t");
      strcat(simboloTS,"CteReal");
      strcat(simboloTS,"\t\t\t");
      strcat(simboloTS,valor);
    }
    if(strcmp(tipoSimbolo,"CONST_STR") == 0){
      sprintf(valor,"%s",nombreSimbolo);
      strcpy(valorCte,"_");
      strcat(valorCte,valor);

      strcpy(simboloTS,"_");
      strcat(simboloTS,nombreSimbolo);
      strcat(simboloTS,"\t\t\t");
      strcat(simboloTS,"CteStr");
      strcat(simboloTS,"\t\t");
      strcat(simboloTS,valorString);
    }
  }else{
    strcpy(simboloTS,nombreSimbolo);
    strcat(simboloTS,"\t\t\t");
    strcat(simboloTS,tipoSimbolo);
    strcat(simboloTS,"\t\t\t");
    strcat(simboloTS,valorString);
  }
  strcat(simboloTS,"\t\t\t");
  strcat(simboloTS,"--");

  //Lee línea a línea y escribe en pantalla hasta el fin de fichero
  rewind(archTS2);
  do {
	  pos = fgets(linea,100,archTS2);
	  strcpy(valorBuscado,simboloTS);
	  strcat(valorBuscado,"\n");
	  if(strcmp(valorBuscado,linea) == 0){
		  band = 1;
	  }
	  i++;
  }while(pos != NULL && band == 0);
  fclose(archTS2);
  archTS2 = fopen("ts.txt","a");
  if(band == 0){
    fprintf(archTS2,"%s\n",simboloTS);
  }
  fclose(archTS2);
}


