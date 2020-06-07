%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "sintactico.tab.h"
int yystopparser=0;
FILE  *yyin;
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


int insertarEnTS(char[],char[],int);
int apilar(t_pila* ,const int );
int desapilar(t_pila *pila);
void crearPila(t_pila* pila);
int pilaVacia(t_pila* pila);

void crearPilaIds(t_pilaIds* pilaIds);
char *  desapilarId(t_pilaIds *pilaIds);
void crearPila(t_pila* );
void crearPilaIds(t_pilaIds* pilaIds);
int apilarId(t_pilaIds* pilaIds,const t_infoIds* infoPilaIds);
void crearPolaca(t_polaca* );
int insertarPolaca(t_polaca*,char*);
int escribirPosicionPolaca(t_polaca* ,int , char*);
void guardarArchivoPolaca(t_polaca*);
void  mostrarPilaIDs(t_pilaIds* );
int nuevoSimbolo(char* tipoDato,char valorString[],int longitud);
char[] invertir_salto(char @comp[]);

t_pila pila;
t_pilaIds pilaIds;
int posicion = 0;
t_polaca polaca;
char comp[3];
char op[3];

t_pila pilaVerdadero;
t_pila pilaFalso;
t_cola cola;
t_pilaIds pilaIds;
int posicionPolaca = 0;
t_polaca polaca;

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
%token OP_OR
%token OP_AND
%token OP_NOT
%token OP_DOSP
%token OP_IGUAL
%token OP_MAYOR
%token OP_MAYORIGUAL
%token OP_MENOR
%token OP_MENORIGUAL
%token OP_DISTINTO
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
%token COMENTARIOS
%token ASIG

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
      |BEGINP bloqueDeclaracion  {printf("--------------------------BLOQUE_DECLARACION\n\n\n");}  ENDP
        ;

bloqueTemasComunesYEspeciales: 
                  temaComunYEspecial
                  | bloqueTemasComunesYEspeciales temaComunYEspecial
                  ;


temaComunYEspecial: 
            iteracion {printf("--------------------------ITERACION\n\n\n");}
          | seleccion {printf("--------------------------DECISION\n\n\n");}
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
          | COMENTARIOS {printf("--------------------------COMENTARIO\n\n\n");}
        ;


                        
asignacion: ID { insertarPolaca(&polaca,yylval.str_val); } OP_ASIG expresion {insertarPolaca(&polaca,"OP_ASIG");}
                ;

iteracion: WHILE {apilar(&pila,posicion);} {insertarPolaca(&polaca,"ET");}  P_A condicion P_C   {insertarPolaca(&polaca,"BRANCH");}  {apilar(&pila,posicion); {insertarPolaca(&polaca,"Z");} } bloqueTemasComunesYEspeciales
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

        } ENDW ;
        
ifUnario: ID IF P_A condicion COMA expresion COMA expresion P_C ;

seleccion: IF P_A condicion {
                if(!strcmp(comp,"OR")){
                        insertarPolaca(&polaca,"BI");
                        apilar(&pilaFalso,insertarPolaca(&polaca,""));
                }
        }
        P_C THEN {
                  int iPosicion;
                  char* pos;
                  while(!pilaVacia(&pilaVerdadero)){
                        iPosicion = desapilar(&pilaVerdadero); printf("Desapile %u", iPosicion);
                        escribirPosicionPolaca(&polaca,iPosicion,itoa(posicion, pos, 10));
                  }
                 }
        bloqueTemasComunesYEspeciales ENDIF{
                  int iPosicion;
                  char* pos;
                  while(!pilaVacia(&pilaFalso)){
                        iPosicion = desapilar(&pilaFalso); printf("Desapile %u", iPosicion); 
                        escribirPosicionPolaca(&polaca,iPosicion,itoa(insertarPolaca(&polaca,"ENDIF"), pos, 10));
                  }
        }
          | IF condicion THEN bloqueTemasComunesYEspeciales ELSE  bloqueTemasComunesYEspeciales ENDIF
          ;

condicion: comparacion   { insertarPolaca(&polaca,"CMP"); insertarPolaca(&polaca,comp); apilar(&pilaFalso,insertarPolaca(&polaca,""));}
           | condicion operador comparacion      
                {
                        if(!strcmp(operador,"OR"))
                                invertir_salto(comp);
                        insertarPolaca(&polaca,"CMP"); insertarPolaca(&polaca,comp); apilar(&pilaFalso,insertarPolaca(&polaca,""));
                }
           |OP_NOT comparacion                   {insertarPolaca(&polaca);}  
           ;

operador: OP_OR {strcpy(@operador, "OR");}
        | OP_AND {strcpy(@operador,"AND");}

comparacion: expresion comparador expresion              {insertarPolaca(&polaca, @comp);}
            | P_A expresion comparador expresion P_C     {insertarPolaca(&polaca, @comp);}
            ;

comparador: OP_MAYOR {strcpy(@comp, "BLE");}
        | OP_MENOR {strcpy(@comp, "BGE");}
        | OP_MAYORIGUAL {strcpy(@comp,"BLT");}
        | OP_MENORIGUAL {strcpy(@comp, "BGT");}
        | OP_DISTINTO {strcpy(@comp, "BEQ");}
        | OP_IGUAL {strcpy(@comp, "BNE");}
        ;

expresion: expresion OP_SUM termino   { insertarPolaca(&polaca,"OP_SUM");  }
         | expresion OP_RES termino  { insertarPolaca(&polaca,"OP_RES"); }
         | termino                              
          ;

termino: factor
        | termino OP_DIV factor   { insertarPolaca(&polaca,"OP_DIV");  }
        | termino OP_MULT factor   { insertarPolaca(&polaca,"OP_MULT"); }
        ;

factor: ID                     { insertarPolaca(&polaca,yylval.str_val); }
        | CONST_INT            { insertarPolaca(&polaca,yylval.str_val); }
        | CONST_STR            { insertarPolaca(&polaca,yylval.str_val); }
        | CONST_REAL           { insertarPolaca(&polaca,yylval.str_val); }
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

listavariables: ID PYC                 
                {
                     nuevoSimbolo(tipoDato,"--",(tipoDato=="String")?strlen(yylval.str_val):0);
                     t_infoIds* infoId;
                }
              | listavariables ID PYC {nuevoSimbolo(tipoDato,"--",(tipoDato=="String")?strlen(yylval.str_val):0);}
              ;

entrada: GET ID 
        {
                insertarPolaca(&polaca,yylval.str_val);
                insertarPolaca(&polaca,"GET");
        }
        ;

salida: DISPLAY factor 
        {
                insertarPolaca(&polaca,"DISPLAY");
        }
        ;

%%

int main(int argc,char *argv[])
{
   
        crearPila(&pila);
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
    printf("Apile: %d\n",iPosicion);
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
        return NULL;
    aux=*pila;
    iPosicion=(*pila)->info.posicion ;
    *pila=(*pila)->psig; 
    free(aux); 
   printf("Desapile: %d\n",iPosicion);
    return iPosicion; 
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
    printf("desapile");
    t_nodoPilaIds *aux;
    char * infoPilaIds;
    
    if(*pilaIds==NULL){
         return NULL;
    }

    aux=*pilaIds;
    *pilaIds=(*pilaIds)->psig; 
    infoPilaIds=(*pilaIds)->infoIds.nombre;

    free(aux); 
              
    return infoPilaIds; 
}

int pilaVacia(t_pila* ppila){
        return !(*ppila);
}

void mostrarPilaIDs(t_pilaIds* pilaIds)
{

        while(*pilaIds){
          printf("Pila: %s\n",(*pilaIds)->infoIds.nombre);    
          *pilaIds=(*pilaIds)->psig; 
        }
         
}

void VaciarPila(t_pilaIds* pilaIds){
         pilaIds = NULL;
}

///////////////////////// POLACA

// esto no deberia ser una lista?

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
        nuevoNodo->info.posicion=posicion++;
        nuevoNodo->psig=NULL;

        while( *ppolaca)
        {            
                ppolaca=&(*ppolaca)->psig;     
        }
        
        *ppolaca=nuevoNodo;        
        return 1;
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

char[] invertir_salto(char[] @comp){
        switch (@comp){
                case "BLE":
                strcpy(@comp,"BGT");
                break;
                case "BGE":
                strcpy(@comp,"BLT");
                break;
                case "BLT":
                strcpy(@comp,"BGE");
                break;
                case "BGT":
                strcpy(@comp,"BLE");
                break;
                case "BEQ":
                strcpy(@comp,"BNE");
                break;
                case "BNE":
                strcpy(@comp,"BEQ");
                break;
        }
        return @comp;
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

