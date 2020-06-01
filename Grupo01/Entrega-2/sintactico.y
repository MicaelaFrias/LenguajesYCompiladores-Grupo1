%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "sintactico.tab.h"
int yystopparser=0;
int posicion = 0;
FILE  *yyin;
char* tipoDato;
//////////////////////PILA
	typedef struct
	{
		int posicion;
	}t_info;
        typedef struct
	{
		char* tipoDato;
                char* nombre;
	}t_infoIds;

	typedef struct s_nodoPila{
    	t_info info;
    	struct s_nodoPila* psig;
	}t_nodoPila;

        typedef struct s_nodoPilaIds{
    	t_infoIds info;
    	struct s_nodoPilaIds* psig;
	}t_nodoPilaIds;

	typedef t_nodoPila *t_pila;
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

	typedef t_nodoPolaca *t_polaca;

int insertarEnTS(char[],char[],int);
int apilar(t_pila* ,const t_info* );
t_info* desapilar(t_pila *pila);
void crearPila(t_pila* );
int verTopePila(const t_pila* , t_info* );
void crearPolaca(t_polaca* );
int insertarPolaca(t_polaca* , char*);
int escribirPosicionPolaca(t_polaca* ,int , char*);
void guardarArchivoPolaca(t_polaca*);

t_pila* pila;
t_pila* pilaIds;
t_polaca* polaca;

%}

%union {
int int_val;
double float_val;
char *str_val;
}

%token PROGRAM
%token DEFINE
%token ENDDEFINE
%token CONST_INT
%token CONST_REAL
%token CONST_STR
%token ID
%token REAL
%token FLOAT
%token INT
%token PYC
%token STRING
%token BEGINP
%token ENDP
%token IF THEN ELSE ENDIF
%token LET
%token FOR TO DO ENDFOR
%token WHILE ENDW
%token REPEAT UNTIL
%token OP_LOG
%token OP_NOT
%token OP_DOSP
%token OP_COMPARACION
%token OP_ASIG
%token OP_SUM
%token OP_RES
%token OP_DIV
%token OP_MULT
%token COMA
%token P_A P_C
%token C_A C_C
%token LONG
%token IN
%token DEFVAR
%token ENDDEF
%token GET
%token DISPLAY

%%
programa:  
        PROGRAM {printf("COMPILACION INICIADA\n");}
        codigo
        {printf("COMPILACION EXITOSA\n");}
        ;

codigo: 
        BEGINP bloqueTemasComunesYEspeciales ENDP
      |BEGINP bloqueDeclaracion {printf("--------------------------BLOQUE_DECLARACION\n\n\n");}
      bloqueTemasComunesYEspeciales ENDP
        ;

bloqueTemasComunesYEspeciales: 
                  temaComunYEspecial
                  | bloqueTemasComunesYEspeciales temaComunYEspecial
                  ;


temaComunYEspecial: 
            iteracion {printf("--------------------------ITERACION\n\n\n");}
          | decision {printf("--------------------------DECISION\n\n\n");}
          | listavariables {printf("--------------------------LISTA_VARIABLES\n\n\n");}
          | asignacion {printf("--------------------------ASIGNACION\n\n\n");}
          | entrada {printf("--------------------------ENTRADA\n\n\n");}
          | salida {printf("--------------------------SALIDA\n\n\n");}
          | condicion {printf("--------------------------CONDICION\n\n\n");}
          | expresion {printf("--------------------------EXPRESION\n\n\n");}
          | termino {printf("--------------------------TERMINO\n\n\n");}
          | factor {printf("--------------------------FACTOR\n\n\n");}
          | listaVarLetDer {printf("--------------------------LISTA_VARIABLES_LET_DERECHA\n\n\n");}
          | listaVarLetIzq {printf("--------------------------LISTA_VARIABLES_LET_IZQUIERDA\n\n\n");}
          | tipodato {printf("--------------------------TIPO_DE_DATO\n\n\n");}
		  | ifUnario {printf("--------------------------IF_UNARIO\n\n\n");}
          | let {printf("--------------------------LET\n\n\n");}
        ;


asignacion: ID OP_ASIG expresion  

iteracion: WHILE P_A condicion P_C bloqueTemasComunesYEspeciales ENDW ;

ifUnario: ID OP_ASIG IF P_A condicion COMA expresion COMA expresion P_C ;

decision: IF P_A condicion P_C THEN bloqueTemasComunesYEspeciales ENDIF
          | IF P_A condicion P_C THEN bloqueTemasComunesYEspeciales ELSE  bloqueTemasComunesYEspeciales ENDIF
          ;

condicion: comparacion 
           | condicion OP_LOG comparacion
           |OP_NOT comparacion
           ;

comparacion: expresion OP_COMPARACION expresion 
            | P_A expresion OP_COMPARACION expresion P_C
            ;

expresion: expresion OP_SUM termino 
         | expresion OP_RES termino
         | termino
          ;

termino: factor
        | termino OP_DIV factor
        | termino OP_MULT factor
        ;

factor: ID   
        | CONST_INT 
        | CONST_STR 
        | CONST_REAL 
      ;

let: LET listaVarLetIzq OP_ASIG P_A listaVarLetDer P_C
    ;
 
listaVarLetIzq: ID 
              | listaVarLetIzq COMA ID
              ;
 
listaVarLetDer: expresion
              | listaVarLetDer PYC expresion
              ;

bloqueDeclaracion: DEFVAR declaraciones ENDDEF 
                  ;

declaraciones: declaracion
              | declaraciones declaracion
              ;           

declaracion: tipodato OP_DOSP listavariables          
            ;

tipodato: FLOAT {tipoDato = "Float"}
        | STRING {tipoDato = "String"}
        |  INT {tipoDato = "Integer"}
        ;

listavariables: ID                  
                {
                     nuevoSimbolo(tipoDato,"--",(tipoDato=="String")?strlen(yylval.str_val):0);
                     t_infoIds* infoId;
                     //ACA TENEMOS QUE APILAR LOS IDS PARA TENER SU TIPO AL INSERTAR EN POLACA
                //      (*infoId).tipoDato = "dedetipoDato";
                //      (*infoId).nombre = yylval.str_val;
                // apilarId(pilaIds,infoId);
                }
              | listavariables PYC ID {nuevoSimbolo(tipoDato,"--",(tipoDato=="String")?strlen(yylval.str_val):0);}
              ;


entrada: GET ID 
        ;

salida: DISPLAY factor 
        ;

%%

int main(int argc,char *argv[])
{
        
        crearPila(pila);
        crearPolaca(polaca);
        if ((yyin = fopen(argv[1], "rt")) == NULL)
        {
                printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
        }
        else
        {
                yyparse();
        }
        fclose(yyin);
        guardarArchivoPolaca(polaca);
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

int apilar(t_pila* pila,const t_info* infoPila)
{   t_nodoPila *nuevoNodo=(t_nodoPila*) malloc(sizeof(t_nodoPila));
    if(nuevoNodo==NULL)
        return(0); //Sin_memoria
    nuevoNodo->info=*infoPila;
    nuevoNodo->psig=*pila;
    *pila=nuevoNodo;
    return(1);
}

t_info* desapilar(t_pila *pila)
{   t_nodoPila *aux;
    t_info * infoPila;
    if(*pila==NULL)
        return(0);
    aux=*pila;
    *infoPila=(*pila)->info;
    *pila=(*pila)->psig; 
    free(aux); 
    return infoPila; 
}


///////////////////////// PILA IDs
void crearPilaIds(t_pilaIds* pilaIds){
        pilaIds = NULL;
}

int apilarId(t_pilaIds* pilaIds,const t_infoIds* infoPilaIds)
{   t_nodoPilaIds *nuevoNodo=(t_nodoPilaIds*) malloc(sizeof(t_nodoPilaIds));
    if(nuevoNodo==NULL)
        return(0); //Sin_memoria
    nuevoNodo->info=*infoPilaIds;
    nuevoNodo->psig=*pilaIds;
    *pilaIds=nuevoNodo;
    return(1);
}

t_infoIds* desapilarId(t_pilaIds *pilaIds)
{   t_nodoPilaIds *aux;
    t_infoIds * infoPilaIds;
    if(*pilaIds==NULL)
        return(0);
    aux=*pilaIds;
    *infoPilaIds=(*pilaIds)->info;
    *pilaIds=(*pilaIds)->psig; 
    free(aux); 
    return infoPilaIds; 
}


///////////////////////// POLACA
void crearPolaca(t_polaca* polaca){
        polaca = NULL;
}

int insertarPolaca(t_polaca* polaca, char *contenido)
{
        t_nodoPolaca* nuevoNodo = (t_nodoPolaca*)malloc(sizeof(t_nodoPolaca));
        if(!nuevoNodo)
                return 0;
        strcpy(nuevoNodo->info.contenido,contenido);
        nuevoNodo->info.posicion=posicion++;
        nuevoNodo->psig=NULL;
        
        while(*polaca)
        {
                polaca=&(*polaca)->psig;
        }
        *polaca=nuevoNodo;
        return 1;
}

int escribirPosicionPolaca(t_polaca* polaca,int posicion, char *contenido) //insertar en polaca y poner pos actual 
	{
	        t_nodoPolaca* aux;
		aux=*polaca;
	    while(aux!=NULL && aux->info.posicion<=posicion){
	    	aux=aux->psig;
                    if(aux->info.posicion==posicion){
                        strcpy(aux->info.contenido,contenido);
                        return 1;
                    }
	    }	    
	    return 0;
	}


void guardarArchivoPolaca(t_polaca *polaca){
		FILE*pint=fopen("intermedia.txt","w+");
		t_nodoPolaca* nuevoNodo;
		if(!pint){
			printf("Error al crear el archivo intermedia.txt\n");
			return;
		}
		while(*polaca)
	    {
	        nuevoNodo=*polaca;
	        fprintf(pint, "%s\n",nuevoNodo->info.contenido);
	        *polaca=(*polaca)->psig;
	        free(nuevoNodo);
	    }
		fclose(pint);
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

