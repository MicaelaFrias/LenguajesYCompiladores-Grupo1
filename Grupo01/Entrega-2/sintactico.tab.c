
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
int yystopparser=0;
FILE  *yyin;
char operador[30];
char* tipoDato;

//////////////////////PILA
	typedef struct
	{
		int posicion;
	}t_info;

	typedef struct s_nodoPila{
    	t_info info;
    	struct s_nodoPila* psig;
	}t_nodoPila;

	typedef t_nodoPila *t_pila;

        typedef struct
	{
		char* tipoDato;
                char* nombre;
	}t_infoIds;

        typedef struct s_nodoPilaIds{
    	t_infoIds infoIds;
    	struct s_nodoPilaIds* psig;
	}t_nodoPilaIds;


	typedef t_nodoPilaIds *t_pilaIds;

/////////////////////POLACA
	typedef struct
	{
		char contenido[30];
		int posicion;
	}t_infoPolaca;
  
  typedef struct s_nodoPolaca{
    	t_infoPolaca info;
    	struct s_nodoPolaca* psig;
	}t_nodoPolaca;

	typedef t_nodoPolaca* t_polaca;

///////////////////COLA

typedef struct s_nodoCola{
t_infoIds infoIds;
struct s_nodoCola* sig;
}t_nodoCola;

typedef struct {
t_nodoCola* pri;
t_nodoCola* ult;
}t_cola;

/////////////////DECLARACION FUNCIONES
int insertarEnTS(char[],char[],int);
int apilar(t_pila* pila,const int iPosicion);
int desapilar(t_pila *pila);
void crearPila(t_pila* pila);
int pilaVacia(t_pila* pila);


void crearPilaIds(t_pilaIds* pilaIds);
char *  desapilarId(t_pilaIds *pilaIds);
int apilarId(t_pilaIds* pilaIds,const t_infoIds* infoPilaIds);
void  mostrarPilaIDs(t_pilaIds* );

void crearCola(t_cola *pcola);
int PonerEnCola(t_cola *pcola,const t_infoIds *infoIds);
char* SacarDeCola (t_cola *pcola, t_infoIds *infoIds);

void crearPolaca(t_polaca* );
int insertarPolaca(t_polaca*,char*);
int escribirPosicionPolaca(t_polaca* ,int , char*);
void guardarArchivoPolaca(t_polaca*);
void  mostrarPilaIDs(t_pilaIds* );
int nuevoSimbolo(char* tipoDato,char* valorString,int longitud);
char* invertir_salto(char* comp);

t_pila pila;
t_pilaIds pilaIds;
int posicion = 0;
t_polaca polaca;
char comp[3];
char op[3];
int cantComparaciones=0;

t_pila pila;
t_pila pilaVerdadero;
t_cola cola;
t_pilaIds pilaIds;
int posicionPolaca = 0;
t_polaca polaca;



/* Line 189 of yacc.c  */
#line 180 "sintactico.tab.c"

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
     OP_OR = 285,
     OP_AND = 286,
     OP_NOT = 287,
     OP_DOSP = 288,
     OP_IGUAL = 289,
     OP_MAYOR = 290,
     OP_MAYORIGUAL = 291,
     OP_MENOR = 292,
     OP_MENORIGUAL = 293,
     OP_DISTINTO = 294,
     OP_ASIG = 295,
     OP_SUM = 296,
     OP_RES = 297,
     OP_DIV = 298,
     OP_MULT = 299,
     COMA = 300,
     P_A = 301,
     P_C = 302,
     C_A = 303,
     C_C = 304,
     LONG = 305,
     IN = 306,
     DEFVAR = 307,
     ENDDEF = 308,
     GET = 309,
     DISPLAY = 310,
     COMENTARIOS = 311,
     ASIG = 312
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 107 "sintactico.y"

int int_val;
double float_val;
char *str_val;



/* Line 214 of yacc.c  */
#line 281 "sintactico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 293 "sintactico.tab.c"

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
#define YYLAST   286

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  131

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     8,    12,    13,    19,    20,    25,
      27,    30,    32,    34,    36,    38,    40,    42,    44,    46,
      48,    50,    52,    54,    56,    58,    60,    62,    63,    68,
      69,    70,    71,    81,    91,    92,    93,   103,   105,   106,
     111,   112,   116,   118,   120,   124,   130,   132,   134,   136,
     138,   140,   142,   146,   150,   152,   154,   158,   162,   164,
     166,   168,   170,   177,   179,   183,   185,   189,   193,   195,
     198,   202,   204,   206,   208,   211,   215,   218
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,    -1,     3,    60,    61,    -1,    15,    64,
      16,    -1,    -1,    15,    88,    62,    64,    16,    -1,    -1,
      15,    88,    63,    16,    -1,    65,    -1,    64,    65,    -1,
      68,    -1,    73,    -1,    92,    -1,    66,    -1,    93,    -1,
      94,    -1,    76,    -1,    82,    -1,    83,    -1,    84,    -1,
      87,    -1,    86,    -1,    91,    -1,    72,    -1,    85,    -1,
      56,    -1,    -1,     9,    67,    40,    82,    -1,    -1,    -1,
      -1,    26,    69,    46,    76,    47,    70,    64,    71,    27,
      -1,     9,    17,    46,    76,    45,    82,    45,    82,    47,
      -1,    -1,    -1,    17,    46,    76,    74,    47,    18,    75,
      64,    20,    -1,    80,    -1,    -1,    76,    79,    77,    80,
      -1,    -1,    32,    78,    80,    -1,    30,    -1,    31,    -1,
      82,    81,    82,    -1,    46,    82,    81,    82,    47,    -1,
      35,    -1,    37,    -1,    36,    -1,    38,    -1,    39,    -1,
      34,    -1,    82,    41,    83,    -1,    82,    42,    83,    -1,
      83,    -1,    84,    -1,    83,    43,    84,    -1,    83,    44,
      84,    -1,     9,    -1,     6,    -1,     8,    -1,     7,    -1,
      21,    86,    40,    46,    87,    47,    -1,     9,    -1,    86,
      45,     9,    -1,    82,    -1,    87,    13,    82,    -1,    52,
      89,    53,    -1,    90,    -1,    89,    90,    -1,    91,    33,
      92,    -1,    11,    -1,    14,    -1,    12,    -1,     9,    13,
      -1,    92,     9,    13,    -1,    54,     9,    -1,    55,    84,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   161,   161,   161,   167,   168,   168,   170,   170,   174,
     175,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   200,   200,   203,
     206,   209,   203,   226,   228,   234,   228,   256,   257,   257,
     280,   280,   283,   284,   286,   287,   290,   291,   292,   293,
     294,   295,   298,   299,   300,   303,   304,   305,   308,   309,
     310,   311,   314,   317,   322,   329,   342,   357,   360,   361,
     364,   367,   368,   369,   372,   377,   380,   387
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
  "FOR", "TO", "DO", "ENDFOR", "WHILE", "ENDW", "REPEAT", "UNTIL", "OP_OR",
  "OP_AND", "OP_NOT", "OP_DOSP", "OP_IGUAL", "OP_MAYOR", "OP_MAYORIGUAL",
  "OP_MENOR", "OP_MENORIGUAL", "OP_DISTINTO", "OP_ASIG", "OP_SUM",
  "OP_RES", "OP_DIV", "OP_MULT", "COMA", "P_A", "P_C", "C_A", "C_C",
  "LONG", "IN", "DEFVAR", "ENDDEF", "GET", "DISPLAY", "COMENTARIOS",
  "ASIG", "$accept", "programa", "$@1", "codigo", "$@2", "$@3",
  "bloqueTemasComunesYEspeciales", "temaComunYEspecial", "asignacion",
  "$@4", "iteracion", "$@5", "$@6", "$@7", "ifUnario", "seleccion", "$@8",
  "$@9", "condicion", "$@10", "$@11", "operador", "comparacion",
  "comparador", "expresion", "termino", "factor", "let", "listaVarLetIzq",
  "listaVarLetDer", "bloqueDeclaracion", "declaraciones", "declaracion",
  "tipodato", "listavariables", "entrada", "salida", 0
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
     305,   306,   307,   308,   309,   310,   311,   312
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    60,    59,    61,    62,    61,    63,    61,    64,
      64,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    67,    66,    69,
      70,    71,    68,    72,    74,    75,    73,    76,    77,    76,
      78,    76,    79,    79,    80,    80,    81,    81,    81,    81,
      81,    81,    82,    82,    82,    83,    83,    83,    84,    84,
      84,    84,    85,    86,    86,    87,    87,    88,    89,    89,
      90,    91,    91,    91,    92,    92,    93,    94
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     3,     0,     5,     0,     4,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     0,
       0,     0,     9,     9,     0,     0,     9,     1,     0,     4,
       0,     3,     1,     1,     3,     5,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     3,     3,     1,     1,
       1,     1,     6,     1,     3,     1,     3,     3,     1,     2,
       3,     1,     1,     1,     2,     3,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     0,     3,    59,    61,    60,
      58,    71,    73,    72,     0,     0,    29,    40,     0,     0,
       0,     0,    26,     0,     9,    14,    11,    24,    12,    17,
      37,    18,    19,    20,    25,    22,    21,     5,    23,    13,
      15,    16,    74,     0,     0,     0,    63,     0,     0,     0,
      58,     0,    54,    55,     0,    68,     0,    76,    77,     4,
      10,    42,    43,    38,    51,    46,    48,    47,    49,    50,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,     0,     0,     0,    41,     0,    67,    69,
       0,     0,    52,    53,    44,    56,    57,    64,    66,     0,
       8,    75,     0,    28,     0,     0,     0,     0,     0,    70,
      39,     6,     0,     0,    65,     0,    30,    45,     0,    35,
      62,     0,     0,     0,    31,     0,     0,     0,    33,    36,
      32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     6,    77,    78,    23,    24,    25,    44,
      26,    48,   121,   127,    27,    28,   104,   123,    29,    91,
      49,    63,    30,    72,    31,    52,    53,    34,    35,    36,
      37,    54,    55,    38,    39,    40,    41
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -77
static const yytype_int16 yypact[] =
{
       0,   -77,    43,    34,   -77,    -2,   -77,   -77,   -77,   -77,
      47,   -77,   -77,   -77,   -17,    16,   -77,   -77,   148,    65,
      54,   148,   -77,   127,   -77,   -77,   -77,   -77,   -77,   100,
     -77,    72,   231,   242,   -77,    20,    75,    77,   -77,    61,
     -77,   -77,   -77,    50,    60,    25,   -77,   -23,    66,    29,
     -77,   211,    -4,   -77,     9,   -77,    84,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     148,   148,   148,   148,   148,   111,   148,   208,   107,   112,
      25,   148,   100,   211,    82,    25,   -77,   148,   -77,   -77,
     128,    29,    -4,    -4,   109,   -77,   -77,   -77,   109,   154,
     -77,   -77,    36,   109,    93,   148,    11,    42,   129,    61,
     -77,   -77,   148,   134,   109,    14,   -77,   -77,   104,   -77,
     -77,   208,   148,   208,   208,    57,   181,   120,   -77,   -77,
     -77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -77,   -77,   -77,   -77,   -77,   -77,   -76,   -21,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -34,   -77,
     -77,   -77,   -35,   113,    10,     3,    -5,   -77,   143,    62,
     -77,   -77,   115,    -6,    86,   -77,   -77
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -66
static const yytype_int16 yytable[] =
{
      33,    99,    60,     1,     7,     8,     9,    10,    32,    11,
      12,    82,    13,    56,    86,    14,    58,    84,    33,    15,
      11,    12,    75,    13,    16,    46,    32,    76,    51,    45,
      17,     7,     8,     9,    50,     7,     8,     9,    50,    73,
      74,    61,    62,     4,    18,   124,   102,   126,    56,     5,
      19,   106,    20,    21,    22,    83,   110,    17,   116,    83,
      42,   120,    88,    57,    43,    75,    61,    62,    95,    96,
      79,    18,    33,    92,    93,    18,    11,    12,    60,    13,
      32,   112,    94,    70,    71,   -65,    98,   -27,    76,   117,
      83,   103,   -63,    -7,    33,    83,    80,   107,    70,    71,
      81,    83,    32,    60,   128,    60,    64,    65,    66,    67,
      68,    69,    85,    70,    71,   114,    33,    90,    33,    33,
      97,    33,   118,   100,    32,   101,    32,    32,   105,    32,
      61,    62,   125,     7,     8,     9,    10,   108,    11,    12,
     113,    13,    42,    59,    14,    70,    71,   130,    15,   122,
      70,    71,   119,    16,     7,     8,     9,    50,    47,    17,
       7,     8,     9,    10,    87,    11,    12,   115,    13,    89,
     111,    14,     0,    18,     0,    15,   109,     0,     0,     0,
      16,    20,    21,    22,     0,     0,    17,     7,     8,     9,
      10,     0,    11,    12,     0,    13,     0,     0,    14,     0,
      18,   129,    15,     0,     0,     0,     0,    16,    20,    21,
      22,     0,     0,    17,     7,     8,     9,    10,     0,    11,
      12,     0,    13,     0,     0,    14,     0,    18,     0,    15,
       0,     0,     0,     0,    16,    20,    21,    22,     0,     0,
      17,     0,     0,     0,   -54,    64,    65,    66,    67,    68,
      69,     0,    70,    71,    18,   -55,     0,     0,     0,     0,
       0,     0,    20,    21,    22,   -54,   -54,   -54,   -54,   -54,
     -54,     0,   -54,   -54,    73,    74,   -55,   -55,   -55,   -55,
     -55,   -55,     0,   -55,   -55,   -55,   -55
};

static const yytype_int8 yycheck[] =
{
       5,    77,    23,     3,     6,     7,     8,     9,     5,    11,
      12,    45,    14,    19,    49,    17,    21,    40,    23,    21,
      11,    12,    45,    14,    26,     9,    23,    13,    18,    46,
      32,     6,     7,     8,     9,     6,     7,     8,     9,    43,
      44,    30,    31,     0,    46,   121,    80,   123,    54,    15,
      52,    85,    54,    55,    56,    45,    91,    32,    47,    49,
      13,    47,    53,     9,    17,    45,    30,    31,    73,    74,
       9,    46,    77,    70,    71,    46,    11,    12,    99,    14,
      77,    45,    72,    41,    42,    13,    76,    40,    13,    47,
      80,    81,    45,    16,    99,    85,    46,    87,    41,    42,
      40,    91,    99,   124,    47,   126,    34,    35,    36,    37,
      38,    39,    46,    41,    42,   105,   121,    33,   123,   124,
       9,   126,   112,    16,   121,    13,   123,   124,    46,   126,
      30,    31,   122,     6,     7,     8,     9,     9,    11,    12,
      47,    14,    13,    16,    17,    41,    42,    27,    21,    45,
      41,    42,    18,    26,     6,     7,     8,     9,    15,    32,
       6,     7,     8,     9,    51,    11,    12,   105,    14,    54,
      16,    17,    -1,    46,    -1,    21,    90,    -1,    -1,    -1,
      26,    54,    55,    56,    -1,    -1,    32,     6,     7,     8,
       9,    -1,    11,    12,    -1,    14,    -1,    -1,    17,    -1,
      46,    20,    21,    -1,    -1,    -1,    -1,    26,    54,    55,
      56,    -1,    -1,    32,     6,     7,     8,     9,    -1,    11,
      12,    -1,    14,    -1,    -1,    17,    -1,    46,    -1,    21,
      -1,    -1,    -1,    -1,    26,    54,    55,    56,    -1,    -1,
      32,    -1,    -1,    -1,    13,    34,    35,    36,    37,    38,
      39,    -1,    41,    42,    46,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    56,    34,    35,    36,    37,    38,
      39,    -1,    41,    42,    43,    44,    34,    35,    36,    37,
      38,    39,    -1,    41,    42,    43,    44
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    59,    60,     0,    15,    61,     6,     7,     8,
       9,    11,    12,    14,    17,    21,    26,    32,    46,    52,
      54,    55,    56,    64,    65,    66,    68,    72,    73,    76,
      80,    82,    83,    84,    85,    86,    87,    88,    91,    92,
      93,    94,    13,    17,    67,    46,     9,    86,    69,    78,
       9,    82,    83,    84,    89,    90,    91,     9,    84,    16,
      65,    30,    31,    79,    34,    35,    36,    37,    38,    39,
      41,    42,    81,    43,    44,    45,    13,    62,    63,     9,
      46,    40,    76,    82,    40,    46,    80,    81,    53,    90,
      33,    77,    83,    83,    82,    84,    84,     9,    82,    64,
      16,    13,    76,    82,    74,    46,    76,    82,     9,    92,
      80,    16,    45,    47,    82,    87,    47,    47,    82,    18,
      47,    70,    45,    75,    64,    82,    64,    71,    47,    20,
      27
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
#line 161 "sintactico.y"
    {printf("COMPILACION INICIADA\n");;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 163 "sintactico.y"
    {printf("COMPILACION EXITOSA\n");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 168 "sintactico.y"
    {printf("--------------------------BLOQUE_DECLARACION\n\n\n");;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 170 "sintactico.y"
    {printf("--------------------------BLOQUE_DECLARACION\n\n\n");;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 180 "sintactico.y"
    {printf("--------------------------ITERACION\n\n\n");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 181 "sintactico.y"
    {printf("--------------------------DECISION\n\n\n");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 182 "sintactico.y"
    {printf("--------------------------LISTA_VARIABLES\n\n\n");;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 183 "sintactico.y"
    {printf("--------------------------ASIGNACION\n\n\n");;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 184 "sintactico.y"
    {printf("--------------------------ENTRADA\n\n\n");;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 185 "sintactico.y"
    {printf("--------------------------SALIDA\n\n\n");;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 186 "sintactico.y"
    {printf("--------------------------CONDICION\n\n\n");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 187 "sintactico.y"
    {printf("--------------------------EXPRESION\n\n\n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 188 "sintactico.y"
    {printf("--------------------------TERMINO\n\n\n");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 189 "sintactico.y"
    {printf("--------------------------FACTOR\n\n\n");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 190 "sintactico.y"
    {printf("--------------------------LISTA_VARIABLES_LET_DERECHA\n\n\n");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 191 "sintactico.y"
    {printf("--------------------------LISTA_VARIABLES_LET_IZQUIERDA\n\n\n");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 192 "sintactico.y"
    {printf("--------------------------TIPO_DE_DATO\n\n\n");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 193 "sintactico.y"
    {printf("--------------------------IF_UNARIO\n\n\n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 194 "sintactico.y"
    {printf("--------------------------LET\n\n\n");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 195 "sintactico.y"
    {printf("--------------------------COMENTARIO\n\n\n");;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 200 "sintactico.y"
    { insertarPolaca(&polaca,yylval.str_val); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 200 "sintactico.y"
    {insertarPolaca(&polaca,"OP_ASIG");;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 203 "sintactico.y"
    {
        apilar(&pila,posicion);insertarPolaca(&polaca,"ET");
        ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 206 "sintactico.y"
    {
        insertarPolaca(&polaca,"BRANCH");apilar(&pila,posicion); insertarPolaca(&polaca,"Z");;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 209 "sintactico.y"
    {
        insertarPolaca(&polaca,"BI");
         int iPosicion;
         char sPosicion[10];

         iPosicion = desapilar(&pila); // esta es la posicion donde debo ir si falla la condicion del while
         sprintf(sPosicion,"%d",posicion+1);

         escribirPosicionPolaca(&polaca,iPosicion,sPosicion);  
         iPosicion = desapilar(&pila); // esta es la posicion donde debo ir si la condicion de while se cumple 
         sprintf(sPosicion,"%d",iPosicion); 

         insertarPolaca(&polaca,sPosicion);


        ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 228 "sintactico.y"
    {
          if(!strcmp(operador,"OR")){
                        insertarPolaca(&polaca,"BI");
                        apilar(&pila,insertarPolaca(&polaca,""));
                }
;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 234 "sintactico.y"
    {
           int iPosicion;
        char posThen[25];
        sprintf(posThen,"%d",posicion);
                while(!pilaVacia(&pilaVerdadero)){
                iPosicion = desapilar(&pilaVerdadero); 
                escribirPosicionPolaca(&polaca,iPosicion,posThen);
 }
 ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 243 "sintactico.y"
    {
        int iPosicion;
        char posEnd[25];
        sprintf(posEnd,"%d",insertarPolaca(&polaca,"ENDIF"));
        while(!pilaVacia(&pila)){
        iPosicion = desapilar(&pila);
        escribirPosicionPolaca(&polaca,iPosicion,posEnd);
        }
        ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 256 "sintactico.y"
    { insertarPolaca(&polaca,"CMP"); insertarPolaca(&polaca,comp) ; apilar(&pila,insertarPolaca(&polaca,"")); cantComparaciones++;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 257 "sintactico.y"
    {
                   char* pos;
                   int iPosicion;

                   //Tratamiento especial por ser OR
                   if(!strcmp(operador,"OR") && cantComparaciones==1){
                            invertir_salto(comp);
                            iPosicion = desapilar(&pila); 
                            apilar(&pilaVerdadero,iPosicion);
                        escribirPosicionPolaca(&polaca,posicion-2,comp);

                   }

           ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 271 "sintactico.y"
    {
                        if(!strcmp(operador,"OR")&& cantComparaciones!=1){
                            invertir_salto(comp);
                        escribirPosicionPolaca(&polaca,posicion-2,comp);
                   }
                     insertarPolaca(&polaca,"CMP"); insertarPolaca(&polaca,comp);
                     (!strcmp(operador,"OR"))?apilar(&pilaVerdadero,insertarPolaca(&polaca,"")):apilar(&pila,insertarPolaca(&polaca,""));
                cantComparaciones = 0;
                ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 280 "sintactico.y"
    { invertir_salto(comp);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 283 "sintactico.y"
    {strcpy(operador, "OR");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 284 "sintactico.y"
    {strcpy(operador,"AND");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 290 "sintactico.y"
    {strcpy(comp, "BLE");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 291 "sintactico.y"
    {strcpy(comp, "BGE");;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 292 "sintactico.y"
    {strcpy(comp,"BLT");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 293 "sintactico.y"
    {strcpy(comp, "BGT");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 294 "sintactico.y"
    {strcpy(comp, "BEQ");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 295 "sintactico.y"
    {strcpy(comp, "BNE");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 298 "sintactico.y"
    { insertarPolaca(&polaca,"OP_SUM");  ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 299 "sintactico.y"
    { insertarPolaca(&polaca,"OP_RES"); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 304 "sintactico.y"
    { insertarPolaca(&polaca,"OP_DIV");  ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 305 "sintactico.y"
    { insertarPolaca(&polaca,"OP_MULT"); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 308 "sintactico.y"
    { insertarPolaca(&polaca,yylval.str_val); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 309 "sintactico.y"
    { insertarPolaca(&polaca,yylval.str_val); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 310 "sintactico.y"
    { insertarPolaca(&polaca,yylval.str_val); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 311 "sintactico.y"
    { insertarPolaca(&polaca,yylval.str_val); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 317 "sintactico.y"
    {
                        t_infoIds infoIds;
                        infoIds.nombre= yyval.str_val;   
                        PonerEnCola(&cola, &infoIds);                   
                ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 322 "sintactico.y"
    {
                         t_infoIds infoIds;
                        infoIds.nombre= yyval.str_val;   
                        PonerEnCola(&cola, &infoIds);                                       
                ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 330 "sintactico.y"
    {
                 t_infoIds infoIds; 
                char* id = SacarDeCola(&cola, &infoIds); 
                if(id==""){
                     printf("Numero de ids ingresados en el LET erroneos.\n");
                        yyerror();
                }
                insertarPolaca(&polaca,id); 
                insertarPolaca(&polaca,"OP_ASIG");   
               
        ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 344 "sintactico.y"
    {
               t_infoIds infoIds; 
                char* id = SacarDeCola(&cola, &infoIds); 
                 if(id==""){
                        printf("Numero de ids ingresados en el LET erroneos.\n");
                         yyerror();
                }
                insertarPolaca(&polaca,id); 
                insertarPolaca(&polaca,"OP_ASIG");   

         ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 367 "sintactico.y"
    {tipoDato = "Float";}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 368 "sintactico.y"
    {tipoDato = "String";}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 369 "sintactico.y"
    {tipoDato = "Integer";}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 373 "sintactico.y"
    {
                     nuevoSimbolo(tipoDato,"--",(tipoDato=="String")?strlen(yylval.str_val):0);
                     t_infoIds* infoId;
                ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 377 "sintactico.y"
    {nuevoSimbolo(tipoDato,"--",(tipoDato=="String")?strlen(yylval.str_val):0);;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 381 "sintactico.y"
    {
                insertarPolaca(&polaca,yylval.str_val);
                insertarPolaca(&polaca,"GET");
        ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 388 "sintactico.y"
    {
                insertarPolaca(&polaca,"DISPLAY");
        ;}
    break;



/* Line 1455 of yacc.c  */
#line 2154 "sintactico.tab.c"
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
#line 393 "sintactico.y"


int main(int argc,char *argv[])
{
        crearPila(&pila);
        crearPila(&pilaVerdadero);
        crearCola(&cola);
        crearPilaIds(&pilaIds);
        crearPolaca(&polaca);
        if ((yyin = fopen(argv[1], "rt")) == NULL)
        {
                printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
        }
        else
        {
                yyparse();
        }
        fclose(yyin);
        guardarArchivoPolaca(&polaca);
        return 0;
}
int yyerror(void)
     {
       printf("Syntax Error\n");
	 system ("Pause");
	 exit (1);
     }



//////////////////////////////////////////////// FUNCIONES  /////////////////////////////////////////////////////////////////////////////////
///////////////////////// PILA
void crearPila(t_pila* pila){
        pila = NULL;
}

int apilar(t_pila* pila,const int iPosicion)
{       
    t_nodoPila *nuevoNodo=(t_nodoPila*) malloc(sizeof(t_nodoPila));
    if(nuevoNodo==NULL){
        return(0); //Sin_memoria
    }
    nuevoNodo->info.posicion=iPosicion;
    nuevoNodo->psig=*pila;
    *pila=nuevoNodo;
    return(1);
}

int desapilar(t_pila *pila)
{   
    t_nodoPila *aux;
    int iPosicion ;
    if(*pila==NULL)
        return 0;
    aux=*pila;
    iPosicion=(*pila)->info.posicion ;
    *pila=(*pila)->psig; 
    free(aux); 
    return iPosicion; 
}


int pilaVacia(t_pila* ppila){
        return !(*ppila);
}
///////////////////////// PILA IDs
void crearPilaIds(t_pilaIds* pilaIds){
        pilaIds = NULL;
}

int apilarId(t_pilaIds* pilaIds,const t_infoIds* infoPilaIds)
{   t_nodoPilaIds *nuevoNodo=(t_nodoPilaIds*) malloc(sizeof(t_nodoPilaIds));
    if(nuevoNodo==NULL)
        return(0); //Sin_memoria

    strcpy(nuevoNodo->infoIds.nombre,infoPilaIds->nombre);
          nuevoNodo->psig=*pilaIds;
    *pilaIds=nuevoNodo;
    return(1);
}

char * desapilarId(t_pilaIds *pilaIds)
{ 
    t_nodoPilaIds *aux;
    char * infoPilaIds;
    
    if(*pilaIds==NULL){
         return (*pilaIds)->infoIds.nombre;
    }

    aux=*pilaIds;
    infoPilaIds=(*pilaIds)->infoIds.nombre;

    *pilaIds=(*pilaIds)->psig; 
    free(aux); 
        
        
    return infoPilaIds; 
}

void mostrarPilaIDs(t_pilaIds* pilaIds)
{

        while(*pilaIds){
          *pilaIds=(*pilaIds)->psig; 
        }
         
}

void VaciarPila(t_pilaIds* pilaIds){
         pilaIds = NULL;
}

///////////////////////////COLA
void crearCola(t_cola *pcola) // Vacia la cola
{
    pcola->pri=NULL;
    pcola->ult=NULL;
}

int PonerEnCola(t_cola *pcola,const t_infoIds *infoIds)
{
    t_nodoCola* nue =(t_nodoCola*) malloc(sizeof(t_nodoCola));
    if(nue==NULL)
        return(0);
    nue->infoIds=*infoIds;
    nue->sig=NULL;
    if(pcola->pri==NULL)
        pcola->pri=nue;
    else pcola->ult->sig=nue;
    pcola->ult = nue;
    return 1;
}

char* SacarDeCola (t_cola *pcola, t_infoIds *infoIds)
{
    t_nodoCola* aux;
    if(pcola->pri == NULL)
        return("");
    aux=pcola->pri;
    *infoIds=aux->infoIds;
    pcola->pri=aux->sig;
    free(aux);
    if(pcola->pri==NULL)
        pcola->ult=NULL;
   return infoIds->nombre;
}

///////////////////////// POLACA

void crearPolaca(t_polaca* ppolaca){

        *ppolaca = NULL;
}

int insertarPolaca(t_polaca* ppolaca,char *contenido)
{
        t_nodoPolaca* nuevoNodo = (t_nodoPolaca*)malloc(sizeof(t_nodoPolaca));
        if(!nuevoNodo){
                return 1;
        }
 
        strcpy(nuevoNodo->info.contenido,contenido);
        nuevoNodo->info.posicion=posicion++;
        nuevoNodo->psig=NULL;

        while( *ppolaca)
        {            
                ppolaca=&(*ppolaca)->psig;     
        }
        
        *ppolaca=nuevoNodo;        
        return nuevoNodo->info.posicion;
}

int escribirPosicionPolaca(t_polaca* ppolaca,int posicion, char *contenido) //insertar en polaca y poner pos actual 
	{
	        t_nodoPolaca* aux;
		aux=*ppolaca;
	    while(aux!=NULL && aux->info.posicion<=posicion){
	    	aux=aux->psig;
                    if(aux->info.posicion==posicion){
                        strcpy(aux->info.contenido,contenido);
                        return 1;
                    }
	    }	    
	    return 0;
	}


void guardarArchivoPolaca(t_polaca *ppolaca){
		FILE*pint=fopen("intermedia.txt","w+");
		t_nodoPolaca* nuevoNodo;
		if(!pint){
			printf("Error al crear el archivo intermedia.txt\n");
			return;
		}
		while(*ppolaca)
	    {
	        nuevoNodo=*ppolaca;
	        fprintf(pint, "%s\n",nuevoNodo->info.contenido);
	        *ppolaca=(*ppolaca)->psig;
	        free(nuevoNodo);
	    }
		fclose(pint);
	}
   
///////////////////////// UTILES

char* invertir_salto(char* comp){
                if(!strcmp("BLE",comp))
                strcpy(comp,"BGT");
                else if(!strcmp("BGE",comp))
                strcpy(comp,"BLT");
                else if(!strcmp("BLT",comp))
                strcpy(comp,"BGE");
                else if(!strcmp("BGT",comp))
                strcpy(comp,"BLE");
                else if(!strcmp("BEQ",comp))
                strcpy(comp,"BNE");
                else if(!strcmp("BNE",comp))
                strcpy(comp,"BEQ");

        return comp;
}
///////////////////////// TABLA DE SIMBOLOS
int nuevoSimbolo(char* tipoDato,char valorString[],int longitud){
  FILE *tablasimbolos = fopen("ts.txt","rw");
  char lineaescrita[100];
  char valorBuscado[100];
  char linealeida[100];
  char *lineasiguiente;
  int encontro = 0;
  int i = 0;
  sprintf(lineaescrita, (longitud != 0)? 
          "%s\t\t%s\t\t%s\t\t%d":
          "%s\t\t%s\t\t%s\t\t--",
          yylval.str_val,tipoDato,valorString,longitud); //nombre-tipo de dato-valor-longitud

  lineasiguiente = fgets(linealeida,100,tablasimbolos);
  while(lineasiguiente  && !encontro){
	  strcpy(valorBuscado,lineaescrita);
	  strcat(valorBuscado,"\n");
          encontro = !strcmp(valorBuscado,linealeida);
	  lineasiguiente = fgets(linealeida,100,tablasimbolos);
  }
  fclose(tablasimbolos);
  tablasimbolos = fopen("ts.txt","a");
  if(!encontro){
    fprintf(tablasimbolos,"%s\n",lineaescrita);
  }
  fclose(tablasimbolos);
}
int buscarEnTS(){
  FILE *tablasimbolos = fopen("ts.txt","rw");
  

  fclose(tablasimbolos);
}


