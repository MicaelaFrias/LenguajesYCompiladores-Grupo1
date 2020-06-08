%{
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
t_polaca polaca;
char comp[3];
char op[3];
char idValor[25];
int cantComparaciones=0;

t_pila pilaFalso;
t_pila pilaVerdadero;
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

iteracion: WHILE {
        apilar(&pilaVerdadero,insertarPolaca(&polaca,"ET"));
        }  
        P_A condicion P_C  bloqueTemasComunesYEspeciales ENDW {
        int posicionInicial, posicionBranch;
        char posFalso[25];
        char posInicio[25];
        if(!pilaVacia(&pilaVerdadero)){
                posicionInicial = desapilar(&pilaVerdadero); 
                sprintf(posInicio,"%d",posicionInicial);
                insertarPolaca(&polaca,"BI");
                escribirPosicionPolaca(&polaca,insertarPolaca(&polaca,""),posInicio);
        }
        sprintf(posFalso,"%d",insertarPolaca(&polaca,""));
         while(!pilaVacia(&pilaFalso)){
                posicionBranch = desapilar(&pilaFalso); 
                escribirPosicionPolaca(&polaca,posicionBranch,posFalso);
        }

        };


ifUnario: ID{
                strcpy(idValor,yylval.str_val);//guardamos en char* el yyval del id
        } 
        ASIG IF P_A condicion COMA {
                //desapilar pilaVerdadero
                int posicionBranch;
                char posActual[25];
                sprintf(posActual,"%d",posicionPolaca);
                while(!pilaVacia(&pilaVerdadero)){
                        posicionBranch = desapilar(&pilaVerdadero); 
                        escribirPosicionPolaca(&polaca,posicionBranch,posActual);
                }

        }
        expresion{
                insertarPolaca(&polaca,idValor);
                insertarPolaca(&polaca,"OP_ASIG");
                insertarPolaca(&polaca,"BI");
                apilar(&pilaVerdadero,insertarPolaca(&polaca,""));
        } 
        COMA{
                //desapilar pilaFalso.
                int posicionBranch;
                char posActual[25];
                sprintf(posActual,"%d",posicionPolaca);
                while(!pilaVacia(&pilaFalso)){
                        posicionBranch = desapilar(&pilaFalso); 
                        escribirPosicionPolaca(&polaca,posicionBranch,posActual);
                }
        }

        expresion{
                insertarPolaca(&polaca,idValor);
                insertarPolaca(&polaca,"OP_ASIG");
        } 
        P_C {
                int posicionBranch;
                char posActual[25];
                sprintf(posActual,"%d",posicionPolaca);
                if(!pilaVacia(&pilaVerdadero)){
                        posicionBranch = desapilar(&pilaVerdadero); 
                        escribirPosicionPolaca(&polaca,posicionBranch,posActual);
                }
        }; 

seleccion: seleccionSinElse finSeleccion;

seleccionSinElse: IF P_A condicion
        P_C THEN{
                int iPosicion;
                char posThen[25];
                sprintf(posThen,"%d",posicionPolaca);
                while(!pilaVacia(&pilaVerdadero)){
                iPosicion = desapilar(&pilaVerdadero); 
                escribirPosicionPolaca(&polaca,iPosicion,posThen);
                }
        }
        bloqueTemasComunesYEspeciales
        ;

finSeleccion: ELSE{
                        int posicionBranch;
                        char sPosicionPolaca[25];
                        sprintf(sPosicionPolaca,"%d",posicionPolaca);
                        while(!pilaVacia(&pilaFalso)){
                        posicionBranch = desapilar(&pilaFalso);
                        escribirPosicionPolaca(&polaca,posicionBranch,sPosicionPolaca);
                        }
                }
                bloqueTemasComunesYEspeciales ENDIF
        | ENDIF {
                int posicionBranch;
                char posEndIf[25];
                sprintf(posEndIf,"%d",insertarPolaca(&polaca,"ENDIF"));
                while(!pilaVacia(&pilaFalso)){
                posicionBranch = desapilar(&pilaFalso);
                escribirPosicionPolaca(&polaca,posicionBranch,posEndIf);
                }
        }
;


condicion: comparacion   { insertarPolaca(&polaca,"CMP"); insertarPolaca(&polaca,comp) ; apilar(&pilaFalso,insertarPolaca(&polaca,"")); cantComparaciones++}                       
           | condicion operador{
                   char* pos;
                   int iPosicion;
                   //Tratamiento especial por ser OR
                   if(!strcmp(operador,"OR") && cantComparaciones==1){
                            invertir_salto(comp);
                            iPosicion = desapilar(&pilaFalso); 
                            apilar(&pilaVerdadero,iPosicion);
                        escribirPosicionPolaca(&polaca,posicionPolaca-2,comp);
                   }

           } comparacion     
                {
                     insertarPolaca(&polaca,"CMP"); insertarPolaca(&polaca,comp);
                     apilar(&pilaFalso,insertarPolaca(&polaca,""));
                cantComparaciones = 0;
                }
           |OP_NOT{ invertir_salto(comp);} comparacion                 
           ;

operador: OP_OR  {strcpy(operador, "OR");}
        | OP_AND {strcpy(operador,"AND");}

comparacion: expresion comparador expresion             
            | P_A expresion comparador expresion P_C   
            ;

comparador: OP_MAYOR {strcpy(comp, "BLE");}
        | OP_MENOR {strcpy(comp, "BGE");}
        | OP_MAYORIGUAL {strcpy(comp,"BLT");}
        | OP_MENORIGUAL {strcpy(comp, "BGT");}
        | OP_DISTINTO {strcpy(comp, "BEQ");}
        | OP_IGUAL {strcpy(comp, "BNE");}
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
 
listaVarLetIzq: ID {
                        t_infoIds infoIds;
                        infoIds.nombre= yyval.str_val;   
                        PonerEnCola(&cola, &infoIds);                   
                }
              | listaVarLetIzq COMA ID {
                         t_infoIds infoIds;
                        infoIds.nombre= yyval.str_val;   
                        PonerEnCola(&cola, &infoIds);                                       
                }
              ;

listaVarLetDer: expresion
         {
                 t_infoIds infoIds; 
                char* id = SacarDeCola(&cola, &infoIds); 
                if(id==""){
                     printf("Numero de ids ingresados en el LET erroneos.\n");
                        yyerror();
                }
                insertarPolaca(&polaca,id); 
                insertarPolaca(&polaca,"OP_ASIG");   
               
        }
            
        | listaVarLetDer PYC expresion 
        
        {
               t_infoIds infoIds; 
                char* id = SacarDeCola(&cola, &infoIds); 
                 if(id==""){
                        printf("Numero de ids ingresados en el LET erroneos.\n");
                         yyerror();
                }
                insertarPolaca(&polaca,id); 
                insertarPolaca(&polaca,"OP_ASIG");   

         }
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
                {
                insertarPolaca(&polaca,yylval.str_val);
                insertarPolaca(&polaca,tipoDato);
                insertarPolaca(&polaca,":");
                }
              | listavariables ID PYC 
              { nuevoSimbolo(tipoDato,"--",(tipoDato=="String")?strlen(yylval.str_val):0);}
                {
                insertarPolaca(&polaca,yylval.str_val);
                insertarPolaca(&polaca,tipoDato);
                insertarPolaca(&polaca,":");
                }
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
        crearPila(&pilaFalso);
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

