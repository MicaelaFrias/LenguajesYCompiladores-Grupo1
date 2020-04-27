%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "sintactico.tab.h"
int yystopparser=0;
FILE  *yyin;
int insertarEnTS(char[],char[],char[],int);
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
%token COMEN
%token LETRA
%token DEFVAR
%token ENDDEF
%token GET
%token DISPLAY

%%
programa:  PROGRAM {printf("Inicia COMPILADOR\n");}
           codigo
           {printf("Fin COMPILADOR\n");}
           ;

codigo: BEGINP bloqueTemasComunes ENDP
        | BEGINP bloqueTemasEspeciales ENDP
        ;

bloqueTemasComunes: temaComun
                  | bloqueTemasComunes temaComun
                  ;

bloqueTemasEspeciales: temaEspecial
                  | bloqueTemasEspeciales temaEspecial
                  ;

temaComun: COMEN {printf("--------------------------ESTO ES UN COMENTARIO\n\n\n");}
          |  iteracion {printf("--------------------------ESTO ES UNA ITERACION\n\n\n");}
          | decision {printf("--------------------------ESTO ES UNA DECISION\n\n\n");}
          | bloqueDeclaracion {printf("--------------------------ESTO ES UNA DECLARACION\n\n\n");}
          | listavariables {printf("--------------------------ESTO ES UNA LISTA DE VARIABLES\n\n\n");}
          | asignacion {printf("--------------------------ESTO ES UNA ASIGNACION\n\n\n");}
          | entrada {printf("--------------------------ESTO ES UNA ENTREADA\n\n\n");}
          | salida {printf("--------------------------ESTO ES UNA SALIDA\n\n\n");}
          | variablesNumericas {printf("--------------------------ESTO ES UNA VARIABLE NUMERICA\n\n\n");}
          ;

temaEspecial: ifUnario {printf("--------------------------ESTO ES UN IF UNARIO\n\n\n");}
          |  accion {printf("--------------------------ESTO ES UNA ACCION\n\n\n");}
          |  let {printf("--------------------------ESTO ES UN LET\n\n\n");}
          ;

asignacion: ID  {printf("ok id\n");}
          OP_ASIG {printf("ok op asig\n");}
          factor 
          ;

iteracion: WHILE  {printf("ok while\n");}
          P_A 
          condicion {printf("ok condicion\n");}
          P_C
          bloqueTemasComunes
          ENDW {printf("ok endwhile \n");}
          ;

ifUnario:
          ID 
          OP_ASIG 
          IF 
          P_A 
          condicion 
          COMA 
          accion 
          COMA 
          accion
          P_C 
    ;

decision: 
          IF P_A condicion P_C THEN bloqueTemasComunes ENDIF {printf("ok end if\n");}
          |
          IF P_A condicion P_C THEN bloqueTemasComunes ELSE  bloqueTemasComunes ENDIF {printf("ok end if\n");}
         
          ;

condicion: comparacion
         | condicionMultiple
         ;

condicionMultiple:
          comparacion OP_LOG comparacion {("ok comparacion and/or\n");}
          |
          OP_NOT P_A comparacion P_C {("ok comparacion not\n");}
          ;

comparacion: factor 
            OP_COMPARACION {printf("ok operador comparacion\n");}
            factor 
          ;

operacion: OP_SUM   {printf("ok suma\n");} 
          | OP_RES  {printf("ok resta\n");} 
          | OP_MULT {printf("ok multiplicacion\n");} 
          | OP_DIV  {printf("ok division\n");} 
          ;

accion:    
      expresion
      ;

expresion: expresion operacion termino
          | termino
          ;

termino:
      LETRA
      | factor
      ;

factor: 
	    ID 
      | CONST_INT {printf("ok int\n");}
      | CONST_STR {printf("ok str\n");}
      | CONST_REAL {printf("ok real\n");}
      ;

let: LET {printf("ok let\n");}
    listaVarLetIzq 
    OP_ASIG {printf("ok igual\n");}
    P_A {printf("ok parentesis abierto\n");}
    listaVarLetDer 
    P_C {printf("ok parentesis cerrado\n");}
    ;
 
listaVarLetIzq: ID {printf("ok id\n");}
         | listaVarLetIzq 
         COMA  {printf("ok coma\n");}
         ID {printf("ok id\n");}
         ;
 
listaVarLetDer: expresion
         | listaVarLetDer 
         PYC {printf("ok punto y coma\n");}
         expresion
         ;

variablesNumericas: ID
                    OP_ASIG
                    valorNumerico
                    ;

valorNumerico: ID
              | CONST_INT
              | expresion
              ;

bloqueDeclaracion: DEFVAR  {printf("ok def var\n");}
                   declaraciones
                   ENDDEF {printf("ok end def\n");}
                   ;

declaraciones: declaracion
              | declaraciones declaracion
              ;           

declaracion:  tipodato 
              OP_DOSP  {printf("ok op asignacion\n");}
              listavariables          
              ;

tipodato: FLOAT {printf("ok float\n");}
          | STRING {printf("ok float\n");}
          |  INT {printf("ok int\n");}
          ;

listavariables: ID  {printf("ok id\n");}
                | ID {printf("ok id\n");}
                PYC {printf("ok punto y coma \n");}
                listavariables
                ;


entrada: GET {printf("ok get\n");}
         ID {printf("ok id\n");}
         ;

salida: DISPLAY {printf("ok display\n");}
        terminoSalida {printf("ok terminoDisplay\n");}
        ;

terminoSalida:  CONST_STR     {printf("ok const_string\n");}
            |   CONST_REAL    {printf("ok const_real\n");}
            |   CONST_INT     {printf("ok const_int\n");}
            |   ID            {printf("ok id\n");}
            ;

%%

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

int insertarEnTS(char nombreSimbolo[],char tilineasiguienteimbolo[],char valorString[],int longitud){
  FILE *archTS2 = fopen("ts.txt","rw");
  char lineaescrita[100];
  char valorCte[20];
  char valorBuscado[20];
  char linealeida[100];
  char separador[] = "\t\t\t";
  char *lineasiguiente;
  int encontro = 0;
  int i = 0;
  sprintf(lineaescrita, (longitud != 0)? 
          "%s\t\t\t%s\t\t\t%s\t\t\t%d":
          "%s\t\t\t%s\t\t\t%s\t\t\t--",
          nombreSimbolo,tilineasiguienteimbolo,valorString,longitud);

  //Lee línea a línea y escribe en pantalla hasta el fin de fichero
  lineasiguiente = fgets(linealeida,100,archTS2);
  while(lineasiguiente  && !encontro){
	  strcpy(valorBuscado,lineaescrita);
	  strcat(valorBuscado,"\n");
    encontro = !strcmp(valorBuscado,linealeida);
	  lineasiguiente = fgets(linealeida,100,archTS2);
  }
  fclose(archTS2);
  archTS2 = fopen("ts.txt","a");
  if(!encontro){
    fprintf(archTS2,"%s\n",lineaescrita);
  }
  fclose(archTS2);
}

