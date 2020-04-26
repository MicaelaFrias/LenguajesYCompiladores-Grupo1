%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
int yystopparser=0;
FILE  *yyin;

%}

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
%token OP_DOSP
%token OP_COMPARACION OP_IGUAL
%token OP_AS
%token OP_SUM
%token IGUAL
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
          ;

temaEspecial: ifUnario {printf("--------------------------ESTO ES UN IF UNARIO\n\n\n");}
          |  accion {printf("--------------------------ESTO ES UNA ACCION\n\n\n");}
          |  let {printf("--------------------------ESTO ES UN LET\n\n\n");}
          ;

asignacion: ID  {printf("ok id\n");}
          OP_AS {printf("ok op asig\n");}
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
    ID {printf("ok id\n");}
    OP_IGUAL {printf("ok comparacion\n");}
    IF  {printf("ok if\n");}
    P_A  {printf("ok parentesis abierto\n");}
    condicion {printf("ok condicion\n");}
    COMA {printf("ok coma\n");}
    accion 
    COMA {printf("ok coma\n");}
    accion
    P_C {printf("ok parentesis cerrado\n");}
    ;

decision: decision1 
          | decision2 
          ;

cuerpoIf: IF {printf("ok if\n");}
          P_A {printf("ok parentesis abierto\n");}
          condicion 
          P_C {printf("ok parentesis cerrado\n");}
          THEN {printf("ok then\n");}
          bloqueTemasComunes
          ;

decision1: cuerpoIf
          ENDIF {printf("ok end if\n");}
          ;

decision2: cuerpoIf 
           ELSE {printf("ok else\n");}
           bloqueTemasComunes 
           ENDIF {printf("ok end if\n");}
          ;

condicion:  comparacion 
         | condicion 
         OP_LOG  {printf("ok operador logico\n");}
         condicion 
         ;

comparacion: factor 
            OP_COMPARACION {printf("ok operador comparacion\n");}
            factor 
            | factor 
            OP_IGUAL  {printf("ok igual\n");}
            factor 
            |
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
	ID {printf("ok var\n");}
      | CONST_INT {printf("ok int\n");}
      | CONST_STR {printf("ok str\n");}
      | CONST_REAL {printf("ok real\n");}
      ;

let: LET {printf("ok let\n");}
    listaVarLetIzq 
    OP_IGUAL {printf("ok igual\n");}
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

