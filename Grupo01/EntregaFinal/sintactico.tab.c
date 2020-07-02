
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
int posicion = 0;
int indice = 0;

//para controlar la cantidad de saltos por falso en los cliclos anidados
int vecFalsosAnidados[30];
int cantCliclosAnidados=0;
int cantFalsos=0;
FILE  *yyin;
char operador[30];
char* tipoDato;
char idAsigna [30];
char tipoDatoActual[50] = "";
char res[30];
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
                char nombre[25];
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
        
        typedef struct
	{
		char nombreVariable[30];
		char tipoVariable[30];

	}t_variables;

//para operadores en assembler
typedef struct
{
        char nombreOperador[30];
}t_operador;

typedef struct
{
        char nombrePalabraReservada[30];
}t_palabraReservada;

////////para pila de operandos

typedef struct
{
        char nombre[30];
}t_infoOperandos;

typedef struct s_nodoPilaOperandos{
t_infoOperandos infoOperandos;
struct s_nodoPilaOperandos* psig;
}t_nodoPilaOperandos;


typedef t_nodoPilaOperandos *t_pilaOperandos;
////////para TS
typedef struct s_dato_TS
{
  char nombre[32];
  char tipo[32];
  char valor[32];
  int longitud;
} t_dato_TS;

typedef struct s_nodo_TS
{
  t_dato_TS dato;
  struct s_nodo_TS *sig;
} t_nodo_TS;

typedef t_nodo_TS* t_TS;
/////////////////DECLARACION FUNCIONES
int apilar(t_pila* pila,const int iPosicion);
int desapilar(t_pila *pila);
void crearPila(t_pila* pila);
void VaciarPila(t_pila* pila);
int pilaVacia(t_pila* pila);


void crearPilaIds(t_pilaIds* pilaIds);
char *  desapilarId(t_pilaIds *pilaIds);
int apilarId(t_pilaIds* pilaIds,const t_infoIds* infoPilaIds);
void  mostrarPilaIDs(t_pilaIds* );

void crearPolaca(t_polaca* );
int insertarPolaca(t_polaca*,char*);
int escribirPosicionPolaca(t_polaca* ,int , char*);
void guardarArchivoPolaca(t_polaca*);
void  mostrarPilaIDs(t_pilaIds* );
int nuevoSimbolo(char* tipoDato,char* valorString,int longitud);
char* invertir_salto(char* comp);
void liberarPolaca(t_polaca *polaca);

void mostrarArrayVariables(t_variables* );
void validarDeclaracionID(char *);
char * obtenerTipoDeDato(char *);

////////FUNCIONES PARA ASSEMBLER
void generarCodigoUsuario(FILE * finalFile, t_polaca* polaca);
void generarAsm(t_TS* );
void llenarVectorOperadores(t_operador [30]);
void llenarVectorPalabrasReservadas(t_palabraReservada [30]);
t_operador vectorOperadores[32];
t_palabraReservada vectorPalabrasReservadas [30];
int esOperador(char valor[32]);
int esPalabraReservada(char valor[32]);

//estructura ts
int insertarEnTS(t_TS*,t_dato_TS*);
void crearTS(t_TS *);
void liberarTS(t_TS*);
t_TS TS;
//pila operandos
void crearPilaOperandos(t_pilaOperandos* pilaOperandos);
int apilarOperando(t_pilaOperandos* pilaOperandos,char nombreOperando[30]);
char* desapilarOperando(t_pilaOperandos *pilaOperandos);
int pilaOperandoVacia(t_pilaOperandos* ppilaOperando);
//declaracion de variables
t_pila pila;
char comp[3];
char op[3];
char idValor[25];
int cantComparaciones=0;

t_pila pilaFalso;
t_pila pilaVerdadero;
t_pilaIds pilaIds;
int posicionPolaca = 0;
t_polaca polaca;
t_variables arrayVariables[500];



/* Line 189 of yacc.c  */
#line 245 "sintactico.tab.c"

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
#line 172 "sintactico.y"

int int_val;
double float_val;
char *str_val;



/* Line 214 of yacc.c  */
#line 346 "sintactico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 358 "sintactico.tab.c"

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
#define YYLAST   316

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  144

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
      69,    70,    71,    81,    82,    83,    84,    85,    86,   102,
     105,   106,   107,   108,   118,   119,   124,   126,   128,   129,
     134,   135,   139,   141,   143,   147,   153,   155,   157,   159,
     161,   163,   165,   169,   173,   175,   179,   183,   185,   187,
     189,   191,   193,   200,   202,   206,   208,   212,   216,   218,
     221,   225,   227,   229,   231,   234,   238,   241
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,    -1,     3,    60,    61,    -1,    15,    64,
      16,    -1,    -1,    15,    97,    62,    64,    16,    -1,    -1,
      15,    97,    63,    16,    -1,    65,    -1,    64,    65,    -1,
      68,    -1,    78,    -1,   101,    -1,    66,    -1,   102,    -1,
     103,    -1,    85,    -1,    91,    -1,    92,    -1,    93,    -1,
      96,    -1,    95,    -1,   100,    -1,    72,    -1,    94,    -1,
      56,    -1,    -1,     9,    67,    40,    91,    -1,    -1,    -1,
      -1,    26,    69,    46,    85,    70,    47,    71,    64,    27,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    73,    57,    17,
      46,    85,    45,    74,    91,    75,    45,    76,    91,    77,
      47,    -1,    79,    83,    -1,    -1,    -1,    -1,    17,    80,
      46,    85,    81,    47,    18,    82,    64,    -1,    -1,    19,
      84,    64,    20,    -1,    20,    -1,    89,    -1,    -1,    85,
      88,    86,    89,    -1,    -1,    32,    87,    89,    -1,    30,
      -1,    31,    -1,    91,    90,    91,    -1,    46,    91,    90,
      91,    47,    -1,    35,    -1,    37,    -1,    36,    -1,    38,
      -1,    39,    -1,    34,    -1,    92,    41,    91,    -1,    92,
      42,    91,    -1,    92,    -1,    93,    43,    92,    -1,    93,
      44,    92,    -1,    93,    -1,     9,    -1,     6,    -1,     8,
      -1,     7,    -1,    21,    95,    40,    46,    96,    47,    -1,
       9,    -1,     9,    45,    95,    -1,    91,    -1,    96,    13,
      91,    -1,    52,    98,    53,    -1,    99,    -1,    98,    99,
      -1,   100,    33,   101,    -1,    11,    -1,    14,    -1,    12,
      -1,     9,    13,    -1,   101,     9,    13,    -1,    54,     9,
      -1,    55,    93,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   226,   226,   226,   232,   233,   233,   235,   235,   239,
     240,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   265,   265,   268,
     277,   279,   268,   312,   315,   326,   332,   343,   312,   358,
     360,   368,   371,   360,   387,   387,   418,   437,   438,   438,
     456,   456,   459,   460,   462,   463,   466,   467,   468,   469,
     470,   471,   474,   475,   476,   479,   480,   481,   485,   507,
     523,   539,   555,   558,   563,   570,   582,   596,   599,   600,
     603,   606,   607,   608,   611,   618,   626,   633
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
  "$@4", "iteracion", "$@5", "$@6", "$@7", "ifUnario", "$@8", "$@9",
  "$@10", "$@11", "$@12", "seleccion", "seleccionSinElse", "$@13", "$@14",
  "$@15", "finSeleccion", "$@16", "condicion", "$@17", "$@18", "operador",
  "comparacion", "comparador", "expresion", "termino", "factor", "let",
  "listaVarLetIzq", "listaVarLetDer", "bloqueDeclaracion", "declaraciones",
  "declaracion", "tipodato", "listavariables", "entrada", "salida", 0
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
      70,    71,    68,    73,    74,    75,    76,    77,    72,    78,
      80,    81,    82,    79,    84,    83,    83,    85,    86,    85,
      87,    85,    88,    88,    89,    89,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    92,    92,    92,    93,    93,
      93,    93,    94,    95,    95,    96,    96,    97,    98,    98,
      99,   100,   100,   100,   101,   101,   102,   103
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     3,     0,     5,     0,     4,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     0,
       0,     0,     9,     0,     0,     0,     0,     0,    15,     2,
       0,     0,     0,     9,     0,     4,     1,     1,     0,     4,
       0,     3,     1,     1,     3,     5,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     3,     1,     1,     1,
       1,     1,     6,     1,     3,     1,     3,     3,     1,     2,
       3,     1,     1,     1,     2,     3,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     0,     3,    69,    71,    70,
      68,    81,    83,    82,    40,     0,    29,    50,     0,     0,
       0,     0,    26,     0,     9,    14,    11,    24,    12,     0,
      17,    47,    18,    19,    20,    25,    22,    21,     5,    23,
      13,    15,    16,    84,     0,     0,     0,     0,    73,     0,
       0,     0,    68,     0,    64,    67,     0,    78,     0,    86,
      87,     4,    10,    44,    46,    39,    52,    53,    48,    61,
      56,    58,    57,    59,    60,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,     0,     0,     0,     0,     0,
      51,     0,     0,    77,    79,     0,     0,     0,    54,    62,
      63,    65,    66,    76,     0,     8,    85,    28,     0,    41,
       0,    30,     0,     0,    80,     0,    49,     6,     0,     0,
      75,     0,     0,    55,    45,     0,     0,    72,    31,    34,
      42,     0,     0,     0,     0,    35,    43,    32,     0,    36,
       0,    37,     0,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,    81,    82,    23,    24,    25,    45,
      26,    50,   122,   131,    27,    46,   132,   138,   140,   142,
      28,    29,    47,   119,   133,    65,    96,    30,    97,    51,
      68,    31,    75,    32,    54,    55,    35,    36,    37,    38,
      56,    57,    39,    40,    41,    42
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -81
static const yytype_int16 yypact[] =
{
       0,   -81,    13,     4,   -81,    23,   -81,   -81,   -81,   -81,
      -7,   -81,   -81,   -81,   -81,    15,   -81,   -81,   109,    97,
      17,   109,   -81,   131,   -81,   -81,   -81,   -81,   -81,    47,
      40,   -81,   277,   246,   266,   -81,   -81,    26,    12,   -81,
      32,   -81,   -81,   -81,    15,    -4,     2,    -3,    16,     6,
      22,     1,   -81,   257,    41,    69,     3,   -81,    48,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   109,   109,   109,   109,   109,
     109,   243,    71,    77,   -81,   109,    75,    56,    51,    56,
     -81,   257,   109,   -81,   -81,    91,   243,     1,   -81,   -81,
     -81,   -81,   -81,   -81,   158,   -81,   -81,   -81,    59,    40,
     109,    40,    60,   107,    32,   185,   -81,   -81,    56,    74,
     -81,    -2,    87,   -81,   -81,    27,   104,   -81,   -81,   -81,
     -81,   243,   109,   243,   216,   -81,   243,   -81,    79,   -81,
     109,   -81,    89,   -81
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -81,   -81,   -81,   -81,   -81,   -81,   -80,   -11,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -66,   -81,   -81,
     -81,   -49,    93,     9,    -5,    -1,   -81,    10,    34,   -81,
     -81,    94,   -14,    58,   -81,   -81
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -76
static const yytype_int16 yytable[] =
{
      33,   104,    90,     1,    34,    58,    43,     7,     8,     9,
      52,    80,    62,     4,    11,    12,   115,    13,    33,     5,
      60,   109,    34,   111,    48,    49,    59,    53,    -7,     7,
       8,     9,    10,   -27,    11,    12,    85,    13,    44,    80,
      14,    83,    58,    87,    15,   127,    88,    18,   116,    16,
     -33,   134,   125,   136,    84,    17,    93,    66,    67,    86,
      91,    44,     7,     8,     9,    52,    63,    64,    89,    18,
      66,    67,   129,   101,   102,    19,    33,    20,    21,    22,
      34,    95,    76,    77,    98,    99,   100,   105,    17,   103,
     106,    33,   108,    62,   107,    34,    91,   110,    91,    33,
     113,   112,    18,    34,    62,   118,    91,   123,    11,    12,
      33,    13,    78,    79,    34,     7,     8,     9,    52,   120,
      43,   126,   130,    62,   139,    62,    33,    91,    33,    33,
      34,    33,    34,    34,   128,    34,   143,     7,     8,     9,
      10,   135,    11,    12,   121,    13,    92,    61,    14,   141,
      94,     0,    15,   114,     0,     0,     0,    16,     0,     0,
       0,     0,     0,    17,     7,     8,     9,    10,     0,    11,
      12,     0,    13,     0,   117,    14,     0,    18,     0,    15,
       0,     0,     0,     0,    16,    20,    21,    22,     0,     0,
      17,     7,     8,     9,    10,     0,    11,    12,     0,    13,
       0,     0,    14,     0,    18,   124,    15,     0,     0,     0,
       0,    16,    20,    21,    22,     0,     0,    17,     0,     0,
       0,     0,     7,     8,     9,    10,     0,    11,    12,     0,
      13,    18,     0,    14,     0,     0,     0,    15,     0,    20,
      21,    22,    16,   137,     0,     0,     0,     0,    17,     7,
       8,     9,    10,     0,    11,    12,     0,    13,     0,   -64,
      14,     0,    18,     0,    15,     0,     0,     0,     0,    16,
      20,    21,    22,     0,     0,    17,     0,     0,     0,   -67,
     -64,   -64,   -64,   -64,   -64,   -64,     0,    76,    77,    18,
     -75,    69,    70,    71,    72,    73,    74,    20,    21,    22,
     -67,   -67,   -67,   -67,   -67,   -67,     0,   -67,   -67,    78,
      79,    69,    70,    71,    72,    73,    74
};

static const yytype_int16 yycheck[] =
{
       5,    81,    51,     3,     5,    19,    13,     6,     7,     8,
       9,    13,    23,     0,    11,    12,    96,    14,    23,    15,
      21,    87,    23,    89,     9,    15,     9,    18,    16,     6,
       7,     8,     9,    40,    11,    12,    40,    14,    45,    13,
      17,     9,    56,    46,    21,    47,    40,    46,    97,    26,
      57,   131,   118,   133,    44,    32,    53,    30,    31,    57,
      51,    45,     6,     7,     8,     9,    19,    20,    46,    46,
      30,    31,    45,    78,    79,    52,    81,    54,    55,    56,
      81,    33,    41,    42,    75,    76,    77,    16,    32,    80,
      13,    96,    17,   104,    85,    96,    87,    46,    89,   104,
       9,    92,    46,   104,   115,    46,    97,    47,    11,    12,
     115,    14,    43,    44,   115,     6,     7,     8,     9,   110,
      13,    47,    18,   134,    45,   136,   131,   118,   133,   134,
     131,   136,   133,   134,    47,   136,    47,     6,     7,     8,
       9,   132,    11,    12,   110,    14,    53,    16,    17,   140,
      56,    -1,    21,    95,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    32,     6,     7,     8,     9,    -1,    11,
      12,    -1,    14,    -1,    16,    17,    -1,    46,    -1,    21,
      -1,    -1,    -1,    -1,    26,    54,    55,    56,    -1,    -1,
      32,     6,     7,     8,     9,    -1,    11,    12,    -1,    14,
      -1,    -1,    17,    -1,    46,    20,    21,    -1,    -1,    -1,
      -1,    26,    54,    55,    56,    -1,    -1,    32,    -1,    -1,
      -1,    -1,     6,     7,     8,     9,    -1,    11,    12,    -1,
      14,    46,    -1,    17,    -1,    -1,    -1,    21,    -1,    54,
      55,    56,    26,    27,    -1,    -1,    -1,    -1,    32,     6,
       7,     8,     9,    -1,    11,    12,    -1,    14,    -1,    13,
      17,    -1,    46,    -1,    21,    -1,    -1,    -1,    -1,    26,
      54,    55,    56,    -1,    -1,    32,    -1,    -1,    -1,    13,
      34,    35,    36,    37,    38,    39,    -1,    41,    42,    46,
      13,    34,    35,    36,    37,    38,    39,    54,    55,    56,
      34,    35,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    34,    35,    36,    37,    38,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    59,    60,     0,    15,    61,     6,     7,     8,
       9,    11,    12,    14,    17,    21,    26,    32,    46,    52,
      54,    55,    56,    64,    65,    66,    68,    72,    78,    79,
      85,    89,    91,    92,    93,    94,    95,    96,    97,   100,
     101,   102,   103,    13,    45,    67,    73,    80,     9,    95,
      69,    87,     9,    91,    92,    93,    98,    99,   100,     9,
      93,    16,    65,    19,    20,    83,    30,    31,    88,    34,
      35,    36,    37,    38,    39,    90,    41,    42,    43,    44,
      13,    62,    63,     9,    95,    40,    57,    46,    40,    46,
      89,    91,    90,    53,    99,    33,    84,    86,    91,    91,
      91,    92,    92,    91,    64,    16,    13,    91,    17,    85,
      46,    85,    91,     9,   101,    64,    89,    16,    46,    81,
      91,    96,    70,    47,    20,    85,    47,    47,    47,    45,
      18,    71,    74,    82,    64,    91,    64,    27,    75,    45,
      76,    91,    77,    47
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
#line 226 "sintactico.y"
    {printf("COMPILACION INICIADA\n");;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 228 "sintactico.y"
    {printf("COMPILACION EXITOSA\n");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 233 "sintactico.y"
    {printf("--------------------------BLOQUE_DECLARACION\n\n\n");;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 235 "sintactico.y"
    {printf("--------------------------BLOQUE_DECLARACION\n\n\n");;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 245 "sintactico.y"
    {printf("--------------------------ITERACION\n\n\n");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 246 "sintactico.y"
    {printf("--------------------------DECISION\n\n\n");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 247 "sintactico.y"
    {printf("--------------------------LISTA_VARIABLES\n\n\n");;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 248 "sintactico.y"
    {printf("--------------------------ASIGNACION\n\n\n");;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 249 "sintactico.y"
    {printf("--------------------------ENTRADA\n\n\n");;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 250 "sintactico.y"
    {printf("--------------------------SALIDA\n\n\n");;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 251 "sintactico.y"
    {printf("--------------------------CONDICION\n\n\n");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 252 "sintactico.y"
    {printf("--------------------------EXPRESION\n\n\n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 253 "sintactico.y"
    {printf("--------------------------TERMINO\n\n\n");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 254 "sintactico.y"
    {printf("--------------------------FACTOR\n\n\n");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 255 "sintactico.y"
    {printf("--------------------------LISTA_VARIABLES_LET_DERECHA\n\n\n");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 256 "sintactico.y"
    {printf("--------------------------LISTA_VARIABLES_LET_IZQUIERDA\n\n\n");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 257 "sintactico.y"
    {printf("--------------------------TIPO_DE_DATO\n\n\n");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 258 "sintactico.y"
    {printf("--------------------------IF_UNARIO\n\n\n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 259 "sintactico.y"
    {printf("--------------------------LET\n\n\n");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 260 "sintactico.y"
    {printf("--------------------------COMENTARIO\n\n\n");;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 265 "sintactico.y"
    { validarDeclaracionID(yylval.str_val); strcpy(tipoDatoActual,obtenerTipoDeDato(yylval.str_val));  insertarPolaca(&polaca,yylval.str_val); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 265 "sintactico.y"
    {insertarPolaca(&polaca,"OP_ASIG"); strcpy(tipoDatoActual,"");;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 268 "sintactico.y"
    {
                apilar(&pilaVerdadero,insertarPolaca(&polaca,"ET"));
                cantCliclosAnidados++; 
                //guardamos la cantidad de saltos por falso que tiene el if anidado anterior
                if(cantCliclosAnidados>1){ 
                        vecFalsosAnidados[cantCliclosAnidados-2] = cantFalsos;
                        cantFalsos = 0;
                        }
                ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 277 "sintactico.y"
    {
                 cantComparaciones = 0;
        ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 279 "sintactico.y"
    {
                int posicionBranch=0;
                char sPosicionPolaca [25];
                sprintf(sPosicionPolaca,"%d",posicionPolaca);
                 if(!pilaVacia(&pilaVerdadero)){
                        posicionBranch = desapilar(&pilaVerdadero); 
                        escribirPosicionPolaca(&polaca,posicionBranch,sPosicionPolaca);
                }
        ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 288 "sintactico.y"
    {
        int posicionInicial, posicionBranch, falsosADesapilar = (cantFalsos ==2)?1:0;
        char posFalso[25];
        char posInicio[25];
        if(!pilaVacia(&pilaVerdadero)){
                posicionInicial = desapilar(&pilaVerdadero); 
                sprintf(posInicio,"%d",posicionInicial);
                insertarPolaca(&polaca,"BI");
                escribirPosicionPolaca(&polaca,insertarPolaca(&polaca,""),posInicio);
        }
        sprintf(posFalso,"%d",insertarPolaca(&polaca,"ENDW"));
         while(!pilaVacia(&pilaFalso) &&falsosADesapilar>=0){
                posicionBranch = desapilar(&pilaFalso); 
                escribirPosicionPolaca(&polaca,posicionBranch,posFalso);
                falsosADesapilar--;
        }
        //actualizamos la cantidad de falsos que tenia el if anterior
        cantFalsos = vecFalsosAnidados[cantCliclosAnidados-2];
        //reducimos la cant de cantCliclosAnidados
        cantCliclosAnidados--;

        ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 312 "sintactico.y"
    {   validarDeclaracionID(yylval.str_val); strcpy(tipoDatoActual,obtenerTipoDeDato(yylval.str_val)); 
                strcpy(idValor,yylval.str_val);//guardamos en char* el yyval del id
        ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 315 "sintactico.y"
    {
                //desapilar pilaVerdadero
                int posicionBranch;
                char posActual[25];
                sprintf(posActual,"%d",posicionPolaca);
                while(!pilaVacia(&pilaVerdadero)){
                        posicionBranch = desapilar(&pilaVerdadero); 
                        escribirPosicionPolaca(&polaca,posicionBranch,posActual);
                }

        ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 326 "sintactico.y"
    {
                insertarPolaca(&polaca,idValor);
                insertarPolaca(&polaca,"OP_ASIG");
                insertarPolaca(&polaca,"BI");
                apilar(&pilaVerdadero,insertarPolaca(&polaca,""));
        ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 332 "sintactico.y"
    {
                //desapilar pilaFalso.
                int posicionBranch;
                char posActual[25];
                sprintf(posActual,"%d",posicionPolaca);
                while(!pilaVacia(&pilaFalso)){
                        posicionBranch = desapilar(&pilaFalso); 
                        escribirPosicionPolaca(&polaca,posicionBranch,posActual);
                }
        ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 343 "sintactico.y"
    {
                insertarPolaca(&polaca,idValor);
                insertarPolaca(&polaca,"OP_ASIG");
        ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 347 "sintactico.y"
    {
                int posicionBranch;
                char posActual[25];
                sprintf(posActual,"%d",posicionPolaca);
                if(!pilaVacia(&pilaVerdadero)){
                        posicionBranch = desapilar(&pilaVerdadero); 
                        escribirPosicionPolaca(&polaca,posicionBranch,posActual);
                }
                strcpy(tipoDatoActual,"");
        ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 360 "sintactico.y"
    {
                cantCliclosAnidados++; 
                //guardamos la cantidad de saltos por falso que tiene el if anidado anterior
                if(cantCliclosAnidados>1){ 
                        vecFalsosAnidados[cantCliclosAnidados-2] = cantFalsos;
                        cantFalsos = 0;
                        }
                ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 368 "sintactico.y"
    {
                 cantComparaciones = 0;
        ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 371 "sintactico.y"
    {
                int iPosicion;
                char posThen[25];
                //salto por verdadero
                sprintf(posThen,"%d",posicionPolaca);
                if(!pilaVacia(&pilaVerdadero)){
                iPosicion = desapilar(&pilaVerdadero); 
                escribirPosicionPolaca(&polaca,iPosicion,posThen);
                }
        ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 381 "sintactico.y"
    {
                insertarPolaca(&polaca,"BI");
                apilar(&pilaFalso,insertarPolaca(&polaca,""));
        ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 387 "sintactico.y"
    {
                int posicionBranch, falsosADesapilar = (cantFalsos ==2)?1:0, posAux;
                char sPosicionPolaca[25];
                sprintf(sPosicionPolaca,"%d",posicionPolaca);
                //desapilo salto de BI
                posAux = desapilar(&pilaFalso);
                while(!pilaVacia(&pilaFalso) && falsosADesapilar>=0){
                        //salto por falso
                        posicionBranch = desapilar(&pilaFalso);
                        escribirPosicionPolaca(&polaca,posicionBranch,sPosicionPolaca);
                falsosADesapilar--;
                }
                //apilo nuevamente el salto del BI anterior, solo quiero desapilar el de la condicion
                apilar(&pilaFalso,posAux);

        ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 403 "sintactico.y"
    {
                int posicionBranch;
                char posEndIf[25];
                //salto por falso
                sprintf(posEndIf,"%d",insertarPolaca(&polaca,"ENDIF"));
                if(!pilaVacia(&pilaFalso)){
                        posicionBranch = desapilar(&pilaFalso);
                        escribirPosicionPolaca(&polaca,posicionBranch,posEndIf);
                        }
                //actualizamos la cantidad de falsos que tenia el if anterior
                cantFalsos = vecFalsosAnidados[cantCliclosAnidados-2];
                //reducimos la cant de cantCliclosAnidados
                cantCliclosAnidados--;
                ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 418 "sintactico.y"
    {
                
                int posicionBranch, falsosADesapilar = (cantFalsos ==2)?2:1;
                char posEndIf[25];
                //salto por falso
                sprintf(posEndIf,"%d",insertarPolaca(&polaca,"ENDIF"));
                while(!pilaVacia(&pilaFalso)&& falsosADesapilar>=0){
                posicionBranch = desapilar(&pilaFalso);
                escribirPosicionPolaca(&polaca,posicionBranch,posEndIf);
                falsosADesapilar--;
                }
                //actualizamos la cantidad de falsos que tenia el if anterior
                cantFalsos = vecFalsosAnidados[cantCliclosAnidados-2];
                //reducimos la cant de cantCliclosAnidados
                cantCliclosAnidados--;
        ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 437 "sintactico.y"
    { insertarPolaca(&polaca,"CMP"); insertarPolaca(&polaca,comp) ;cantFalsos++; apilar(&pilaFalso,insertarPolaca(&polaca,"")); cantComparaciones++;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 438 "sintactico.y"
    {
                   char* pos;
                   int iPosicion;
                   //Tratamiento especial por ser OR
                   if(!strcmp(operador,"OR") && cantComparaciones==1){
                            invertir_salto(comp);
                            iPosicion = desapilar(&pilaFalso);
                            cantFalsos--;  
                            apilar(&pilaVerdadero,iPosicion);
                        escribirPosicionPolaca(&polaca,posicionPolaca-2,comp);
                   }

           ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 451 "sintactico.y"
    {
                     insertarPolaca(&polaca,"CMP"); insertarPolaca(&polaca,comp);
                     apilar(&pilaFalso,insertarPolaca(&polaca,""));
                     cantFalsos++; 
                ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 456 "sintactico.y"
    { invertir_salto(comp);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 459 "sintactico.y"
    {strcpy(operador, "OR");   strcpy(tipoDatoActual,"");  ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 460 "sintactico.y"
    {strcpy(operador,"AND");  strcpy(tipoDatoActual,"");  ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 466 "sintactico.y"
    {strcpy(comp, "BLE");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 467 "sintactico.y"
    {strcpy(comp, "BGE");;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 468 "sintactico.y"
    {strcpy(comp,"BLT");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 469 "sintactico.y"
    {strcpy(comp, "BGT");;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 470 "sintactico.y"
    {strcpy(comp, "BEQ");;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 471 "sintactico.y"
    {strcpy(comp, "BNE");;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 474 "sintactico.y"
    {insertarPolaca(&polaca,"OP_SUM"); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 475 "sintactico.y"
    {insertarPolaca(&polaca,"OP_RES"); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 479 "sintactico.y"
    { insertarPolaca(&polaca,"OP_DIV");  ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 480 "sintactico.y"
    { insertarPolaca(&polaca,"OP_MULT"); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 485 "sintactico.y"
    { 

                        if(!strcmp(tipoDatoActual ,"")){

                              strcpy(tipoDatoActual,obtenerTipoDeDato(yylval.str_val));  
                        }else{

                                validarDeclaracionID(yylval.str_val);  
                                char sTipoVariable[50];

                                strcpy(sTipoVariable, obtenerTipoDeDato(yylval.str_val));
                                
                                if (strcmp(sTipoVariable,tipoDatoActual)){
                                        printf("Se espera dato del tipo %s y recibe tipo de dato %s\n",tipoDatoActual,sTipoVariable);
                                        return yyerror();   
                                }
                               
                                
                        }

                         insertarPolaca(&polaca,yylval.str_val);   ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 507 "sintactico.y"
    { 

                         if(!strcmp(tipoDatoActual ,"")){

                              strcpy(tipoDatoActual,obtenerTipoDeDato(yylval.str_val));  
                        }else{
                
                        if(strcmp(tipoDatoActual,"Integer") && strcmp(tipoDatoActual,"Float")){
                                printf("Se espera dato del tipo %s y recibe tipo de dato %s\n",tipoDatoActual,"Integer");
                                return yyerror();
                         }  

                        }
                         insertarPolaca(&polaca,yylval.str_val);
                        ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 523 "sintactico.y"
    {

                          if(!strcmp(tipoDatoActual ,"")){

                              strcpy(tipoDatoActual,obtenerTipoDeDato(yylval.str_val));  
                        }else{
                
                         if(strcmp(tipoDatoActual,"String")){
                                printf("Se espera dato del tipo %s y recibe tipo de dato %s\n",tipoDatoActual,"String");
                                return yyerror();
                         }  

                        }
                         insertarPolaca(&polaca,yylval.str_val);
                        ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 539 "sintactico.y"
    { 
                           if(!strcmp(tipoDatoActual ,"")){

                              strcpy(tipoDatoActual,obtenerTipoDeDato(yylval.str_val));  
                        }else{

                        if(strcmp(tipoDatoActual,"Float")){
                                printf("Se espera dato del tipo %s y recibe tipo de dato %s\n",tipoDatoActual,"Float");
                                return yyerror();
                         }

                         }
                          insertarPolaca(&polaca,yylval.str_val); 
                        ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 558 "sintactico.y"
    {
                        t_infoIds infoIds;
                        strcpy(infoIds.nombre, yyval.str_val);   
                        apilarId(&pilaIds, &infoIds);                   
                ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 563 "sintactico.y"
    {
                         t_infoIds infoIds;
                        strcpy(infoIds.nombre, yyval.str_val);   
                        apilarId(&pilaIds, &infoIds);                                                       
                ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 571 "sintactico.y"
    {
                char* id = desapilarId(&pilaIds); 
                if(id==""){
                     printf("Numero de ids ingresados en el LET erroneos.\n");
                        yyerror();
                }
                insertarPolaca(&polaca,id); 
                insertarPolaca(&polaca,"OP_ASIG");   
               
        ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 584 "sintactico.y"
    {
                char* id = desapilarId(&pilaIds); 
                 if(id==""){
                        printf("Numero de ids ingresados en el LET erroneos.\n");
                         yyerror();
                }
                insertarPolaca(&polaca,id); 
                insertarPolaca(&polaca,"OP_ASIG");   

         ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 606 "sintactico.y"
    {tipoDato = "Float";}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 607 "sintactico.y"
    {tipoDato = "String";}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 608 "sintactico.y"
    {tipoDato = "Integer";}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 612 "sintactico.y"
    {
                  strcpy(arrayVariables[indice].nombreVariable,yylval.str_val);  
                  strcpy(arrayVariables[indice].tipoVariable,tipoDato);  
                  indice++;    
                  nuevoSimbolo(tipoDato,"--",(tipoDato=="String")?strlen(yylval.str_val):0);
                ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 618 "sintactico.y"
    {
                  nuevoSimbolo(tipoDato,"--",(tipoDato=="String")?strlen(yylval.str_val):0);
                  strcpy(arrayVariables[indice].nombreVariable,yylval.str_val);  
                  strcpy(arrayVariables[indice].tipoVariable,tipoDato);  
                  indice++;    
                  ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 627 "sintactico.y"
    {
                insertarPolaca(&polaca,yylval.str_val);
                insertarPolaca(&polaca,"GET");
        ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 634 "sintactico.y"
    {
                insertarPolaca(&polaca,"DISPLAY");
        ;}
    break;



/* Line 1455 of yacc.c  */
#line 2477 "sintactico.tab.c"
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
#line 639 "sintactico.y"


int main(int argc,char *argv[])
{
        crearPila(&pilaFalso);
        crearTS(&TS);
        crearPila(&pilaVerdadero);
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
        //ññenamos arrays para codigo usuario assembler
        llenarVectorOperadores(vectorOperadores);
        llenarVectorPalabrasReservadas(vectorPalabrasReservadas);
        //generamos assembler
        generarAsm(&TS);
        liberarPolaca(&polaca);
        liberarTS(&TS);
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
void VaciarPila(t_pila* pila){
         pila = NULL;
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
         return NULL;
    }

    aux=*pilaIds;
    strcpy(infoPilaIds,(*pilaIds)->infoIds.nombre);

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
//////////////////////////PILA OPERANDOS
void crearPilaOperandos(t_pilaOperandos* pilaOperandos){
        pilaOperandos = NULL;
}

int apilarOperando(t_pilaOperandos* pilaOperandos,char nombreOperando[30])
{   t_nodoPilaOperandos *nuevoNodo=(t_nodoPilaOperandos*) malloc(sizeof(t_nodoPilaOperandos));
    if(nuevoNodo==NULL)
        return(0); //Sin_memoria

    strcpy(nuevoNodo->infoOperandos.nombre,nombreOperando);
          nuevoNodo->psig=*pilaOperandos;
    *pilaOperandos=nuevoNodo;
    return(1);
}

char* desapilarOperando(t_pilaOperandos *pilaOperandos)
{ 
    t_nodoPilaOperandos *aux;
    char * nombreOperando;
    
    if(*pilaOperandos==NULL){
         return NULL;
    }

    aux=*pilaOperandos;
    strcpy(nombreOperando,(*pilaOperandos)->infoOperandos.nombre);

    *pilaOperandos=(*pilaOperandos)->psig; 
    free(aux); 
        
    return nombreOperando; 
}

int pilaOperandoVacia(t_pilaOperandos* ppilaOperando){
        return !(*ppilaOperando);
}
///////////////////////// POLACA

void crearPolaca(t_polaca* ppolaca){

        *ppolaca = NULL;
}

int insertarPolaca(t_polaca* ppolaca,char *contenido)
{
        t_nodoPolaca* nuevoNodo = (t_nodoPolaca*)malloc(sizeof(t_nodoPolaca));
        if(!nuevoNodo){
                return 0;
        }
 
        strcpy(nuevoNodo->info.contenido,contenido);
        nuevoNodo->info.posicion=posicionPolaca++;
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
		t_nodoPolaca* aux;
                aux = *ppolaca;
		if(!pint){
			printf("Error al crear el archivo intermedia.txt\n");
			return;
		}
		while(aux)
	    {
	        fprintf(pint, "%s\n",aux->info.contenido);
	        aux=aux->psig;
	    }
		fclose(pint);
	}
void liberarPolaca(t_polaca *ppolaca){
	t_nodoPolaca* nuevoNodo;	
	while(*ppolaca)
        {
        nuevoNodo=*ppolaca;
        *ppolaca=(*ppolaca)->psig;
        free(nuevoNodo);
        }
}
///////////////////////// UTILES
void validarDeclaracionID(char * nombreID){
        
    int i;
    int iExiste = 0;
    for(i=0;i<indice;i++)
    {
        if ( strcmp(arrayVariables[i].nombreVariable,nombreID) == 0)
        {
                iExiste = 1;
        }
    }

    if (iExiste == 0){
        printf("La variable %s no esta declarada\n",nombreID);
        yyerror();
    }
    
}

char * obtenerTipoDeDato(char* nombreID){
        
         int i;

    for(i=0;i<indice;i++)
    {
       if ( strcmp(arrayVariables[i].nombreVariable,nombreID) == 0)
        {
               return arrayVariables[i].tipoVariable;
        }
    }
   

}

void mostrarArrayVariables(t_variables* vec){
        
         int i;

    for(i=0;i<indice;i++)
    {
         printf("variable: %s \t",vec[i].nombreVariable);
         printf("tipovariable: %s \t",vec[i].tipoVariable);
         printf("\n");
    }
   

}

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
  FILE *tablaSimbolos = fopen("ts.txt","rw");
  char lineaescrita[100];
  t_dato_TS datoTs ;
  char valorBuscado[100];
  char linealeida[100];
  char *lineasiguiente;
  int encontro = 0;
  int i = 0;
  sprintf(lineaescrita, (longitud != 0)? 
          "%s\t\t%s\t\t%s\t\t%d":
          "%s\t\t%s\t\t%s\t\t--",
          yylval.str_val,tipoDato,valorString,longitud); //nombre-tipo de dato-valor-longitud
//llenamos dato para TS
strcpy(datoTs.nombre, yylval.str_val);
strcpy(datoTs.tipo,tipoDato);
datoTs.longitud = longitud;
strcpy(datoTs.valor,valorString);


insertarEnTS(&TS,&datoTs);

  lineasiguiente = fgets(linealeida,100,tablaSimbolos);
  while(lineasiguiente  && !encontro){
	  strcpy(valorBuscado,lineaescrita);
	  strcat(valorBuscado,"\n");
          encontro = !strcmp(valorBuscado,linealeida);
	  lineasiguiente = fgets(linealeida,100,tablaSimbolos);
  }
  fclose(tablaSimbolos);
  tablaSimbolos = fopen("ts.txt","a");
  if(!encontro){
    fprintf(tablaSimbolos,"%s\n",lineaescrita);
  }
  fclose(tablaSimbolos);
}

int buscarEnTS(){
  FILE *tablaSimbolos = fopen("ts.txt","rw");
  

  fclose(tablaSimbolos);
}

int insertarEnTS(t_TS* ts,t_dato_TS* dato){
t_nodo_TS* nuevoNodo = (t_nodo_TS*)malloc(sizeof(t_nodo_TS));
        if(!nuevoNodo){
                return 0;
        }
        //insertamos simbolo
        strcpy(nuevoNodo->dato.nombre,dato->nombre);
        strcpy(nuevoNodo->dato.tipo ,dato->tipo);
        strcpy(nuevoNodo->dato.valor,dato->valor);
        nuevoNodo->dato.longitud = dato->longitud;
        nuevoNodo->sig=NULL;


        while( *ts)
        {            
                ts=&(*ts)->sig;     
        }       
        
        *ts=nuevoNodo;        
        return 1;
}

void crearTS(t_TS * ts){
        *ts = NULL;
}

void liberarTS(t_TS* ts){
        t_nodo_TS* nuevoNodo;	
        while(*ts)
        {
        nuevoNodo=*ts;
        *ts=(*ts)->sig;
        free(nuevoNodo);
        }
}
///////////////////////////ASSEMBLER
void llenarVectorOperadores(t_operador vecOperadores[30]){
      strcpy(vecOperadores[0].nombreOperador ,"OP_SUM");
      strcpy(vecOperadores[1].nombreOperador ,"OP_MULT");
      strcpy(vecOperadores[2].nombreOperador ,"OP_DIV");
      strcpy(vecOperadores[3].nombreOperador, "OP_RES");
      strcpy(vecOperadores[4].nombreOperador, "OP_ASIG");

}

void llenarVectorPalabrasReservadas(t_palabraReservada vectorPalabrasReservadas[30]){
      strcpy(vectorPalabrasReservadas[0].nombrePalabraReservada ,"CMP");
      strcpy(vectorPalabrasReservadas[1].nombrePalabraReservada ,"BLE");
      strcpy(vectorPalabrasReservadas[2].nombrePalabraReservada ,"BGT");
      strcpy(vectorPalabrasReservadas[3].nombrePalabraReservada, "BLT");
      strcpy(vectorPalabrasReservadas[4].nombrePalabraReservada, "BEQ");
      strcpy(vectorPalabrasReservadas[5].nombrePalabraReservada, "BNE");
      strcpy(vectorPalabrasReservadas[6].nombrePalabraReservada, "BI");
      strcpy(vectorPalabrasReservadas[7].nombrePalabraReservada ,"ENDIF");
      strcpy(vectorPalabrasReservadas[8].nombrePalabraReservada ,"ET");
      strcpy(vectorPalabrasReservadas[9].nombrePalabraReservada ,"ENDW");
      strcpy(vectorPalabrasReservadas[10].nombrePalabraReservada ,"BGE");

}

int esOperador(char valor[32]){
        int i = 0;
        for(i = 0;i<=5;i++){
                if(!strcmp(vectorOperadores[i].nombreOperador,valor))
                return 1;
        }
        return 0;
}

int esPalabraReservada(char valor[32] ){
        int i = 0;
        for(i = 0;i<=11;i++){
                if(!strcmp(vectorPalabrasReservadas[i].nombrePalabraReservada,valor))
                return 1;
        }
        return 0;
}

//CODIGO USUARIO
void generarCodigoUsuario(FILE* finalFile, t_polaca* polaca){
        t_nodoPolaca* aux;

        int tieneOperador = 0;
        t_pilaOperandos pilaOperandos;
        crearPilaOperandos(&pilaOperandos);
        aux = *polaca;
        //insertar codigo de usuario en assembler
        while(aux){
                //apilamos operandos
                //vemos si no es un operador, y por ende no esta en el vector de operadores
                if(!esOperador(aux->info.contenido)){
                        if(!esPalabraReservada(aux->info.contenido)){
                                apilarOperando(&pilaOperandos,aux->info.contenido);
                        }
                        else{ //si no lo esta, vemos si no es una palabra reservada como cmp o los branchs

                                if(!strcmp(aux->info.contenido,"CMP")){
                                        //si es comparador desapilo 2
                                fprintf(finalFile,"FLD %s\n",desapilarOperando(&pilaOperandos));
                                fprintf(finalFile,"FLD %s\n",desapilarOperando(&pilaOperandos));
                                fprintf(finalFile,"FXCH \n");
                                fprintf(finalFile,"FCOM \n");           
                                }
                                else{
                                        if(!strcmp(aux->info.contenido,"ENDIF") || !strcmp(aux->info.contenido,"ET") || !strcmp(aux->info.contenido,"ENDW") )
                                        fprintf(finalFile,"%s: \n",aux->info.contenido);
                                        
                                        else{
                                                //si es un salto leo el siguiente valor de la polaca
                                                char salto[30];
                                                strcpy(salto,aux->info.contenido);
                                                aux=aux->psig;
                                                fprintf(finalFile,"%s %s\n",salto,aux->info.contenido);
                                        }
                                }
                                
                        }
                }
                else{ 
                        //agregamos variable res para guardar respuesta de operaciones
                        strcpy(res, "@RES");
                        //si es un operador desapilo los dos apilados anteriormente

                        if(!strcmp(aux->info.contenido ,"OP_SUM")){
                             
                                fprintf(finalFile,"FLD %s\n",desapilarOperando(&pilaOperandos));
                                fprintf(finalFile,"FLD %s\n",desapilarOperando(&pilaOperandos));
                                fprintf(finalFile,"FADD \n");
                                fprintf(finalFile,"FSTP %s\n",res);
                                apilarOperando(&pilaOperandos,res);
                                fprintf(finalFile,"FFREE \n");
                                tieneOperador = 1;
                        }
                         if(!strcmp(aux->info.contenido ,"OP_MULT")){
                                fprintf(finalFile,"FLD %s\n",desapilarOperando(&pilaOperandos));
                                fprintf(finalFile,"FLD %s\n",desapilarOperando(&pilaOperandos));
                                fprintf(finalFile,"FMUL \n");
                                fprintf(finalFile,"FSTP %s\n",res);
                                apilarOperando(&pilaOperandos,res);
                                fprintf(finalFile,"FFREE \n");
                                tieneOperador = 1;

                        }
                         if(!strcmp(aux->info.contenido ,"OP_DIV")){
                                fprintf(finalFile,"FLD %s\n",desapilarOperando(&pilaOperandos));
                                fprintf(finalFile,"FLD %s\n",desapilarOperando(&pilaOperandos));
                                fprintf(finalFile,"FDIV \n");
                                fprintf(finalFile,"FSTP %s\n",res);
                                apilarOperando(&pilaOperandos,res);
                                fprintf(finalFile,"FFREE \n");
                                tieneOperador = 1;

                        }
                         if(!strcmp(aux->info.contenido ,"OP_RES")){
                                fprintf(finalFile,"FLD %s\n",desapilarOperando(&pilaOperandos));
                                fprintf(finalFile,"FLD %s\n",desapilarOperando(&pilaOperandos));
                                fprintf(finalFile,"FSUB \n");
                                fprintf(finalFile,"FSTP %s\n",res);
                                apilarOperando(&pilaOperandos,res);
                                fprintf(finalFile,"FFREE \n");
                                tieneOperador = 1;

                        }
                         if(!strcmp(aux->info.contenido , "OP_ASIG")){

                                strcpy(idAsigna,desapilarOperando(&pilaOperandos));

                                if(strcmp(idAsigna,"@RES")!=0 && tieneOperador){
                                fprintf(finalFile,"FLD %s\n",desapilarOperando(&pilaOperandos));
                                fprintf(finalFile,"FSTP %s\n",idAsigna);
                                
                                }
                                else{
                                fprintf(finalFile,"FLD %s\n",idAsigna);
                                fprintf(finalFile,"FSTP %s\n",desapilarOperando(&pilaOperandos));  
                                tieneOperador = 0;  
                                }
                                
                                
                        
                        }

                }
                
	        aux=aux->psig;
	}
}

void generarAsm(t_TS* TS){
	printf("***Generando ASM**** \n");
	FILE *finalFile = fopen("Final.asm","w");
	if(finalFile == NULL)
	{
		printf("Error al crear el archivo Final.asm");
		getchar();
		exit(0);
	}
	fprintf(finalFile, "include macros2.asm\n");
	fprintf(finalFile, "include number.asm\n");
	fprintf(finalFile,".MODEL LARGE\n");
	fprintf(finalFile,".386\n");
	fprintf(finalFile,".STACK 200h\n");
	fprintf(finalFile,".DATA\n");
	//////////////////////////////DECLARAMOS VARIABLES	
        // estructuras necesarias para recorrer la TS
	int  tipoDatoId;
        t_nodo_TS* aux;
        aux = *TS;
	
            //recorremos la Tabla de simbolos (estructura) y declaramos ids y ctes
	 while(aux)  
	{
                tipoDatoId = (!strcmp(aux->dato.tipo, "Integer"))?1:
                (!strcmp(aux->dato.tipo, "Float"))?2:
                (!strcmp(aux->dato.tipo, "String"))?3:0;
                switch(tipoDatoId){
                        case 0:
                        //Si es 0 no tiene tipo por lo tanto es una cte y guardamos valor
                                if(!strcmp(aux->dato.tipo,"String"))
                                        fprintf(finalFile,"%s dw %s\n",aux->dato.nombre, aux->dato.valor);  
                                else
                                        fprintf(finalFile,"%s dd %s\n",aux->dato.nombre, aux->dato.valor);         
                                break;
                        case 1: 	  
                                fprintf(finalFile,"%s dd %s\n",aux->dato.nombre, "?");         
                                break;
                        case 2:    
                                fprintf(finalFile,"%s dd %s\n",aux->dato.nombre,"?");        
                                break;
                        case 3:  
                                fprintf(finalFile,"%s dw %s\n",aux->dato.nombre,"?"); 
                                break;		
                        }
    
                aux=aux->sig;
        }
        fprintf(finalFile,"@RES dd ?");
	fprintf(finalFile,"\n.CODE \n");
	fprintf(finalFile,"mov ah, 1;\n");
	fprintf(finalFile,"int 21h ;\n");
	fprintf(finalFile,"MOV AX, 4C00h; \n");
	fprintf(finalFile,"int 21h;\n");
        //PROGRAMA DE USUARIO
        generarCodigoUsuario(finalFile, &polaca);
	fprintf(finalFile,"END\n");

        ////////////////////////////////PROGRAMA DEL USUARIO

	fclose(finalFile);

} 

