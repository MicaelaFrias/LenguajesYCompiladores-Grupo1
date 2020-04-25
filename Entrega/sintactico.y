%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "sintactico.tab.h"
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
%token OP_COMPARACION
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

temaComun: COMEN {printf("esto es un comentario\n\n\n");}
          |  iteracion {printf("esto es una iteracion\n\n\n")}
          | decision {printf("esto es una decision\n\n\n");}
          | declaraciones {printf("esto es una declaracion\n\n\n");}
          | listavariables {printf("esto es una lita de variables\n\n\n");}
          | asignacion {printf("esto es una asignacion\n\n\n");}
          ;

temaEspecial: ifUnario {printf("esto es un if unario\n\n\n")}
          |  accion {printf("esto es una accion\n\n\n")}
          |  let {printf("esto es un let\n\n\n")}
          ;

decision: IF  {printf("ok if\n");}
          condicion {printf("ok condicion\n");}
          THEN {printf("ok then \n");}
          ENDIF {printf("ok endif\n");}
          ;
asignacion: ID  {printf("ok id\n");}
          OP_AS {printf("ok op asig\n");}
          ID {printf("ok id \n");}
          ;

iteracion: WHILE  {printf("ok while\n");}
          condicion {printf("ok condicion\n");}
          ENDW {printf("ok endwhile \n");}
          ;

ifUnario:
    ID {printf("ok id\n");}
    OP_COMPARACION {printf("ok igual\n");}
    IF  {printf("ok if\n");}
    P_A  {printf("ok parentesis abierto\n")}
    condicion {printf("ok condicion\n");}
    COMA {printf("ok coma\n");}
    accion 
    COMA {printf("ok coma\n");}
    accion
    P_C {printf("ok parentesis cerrado\n")}
    ;

condicion: comparacion {printf("ok comp\n");}
         ;

comparacion: factor OP_COMPARACION factor 
          ;

operacion: OP_SUM {printf("ok suma\n");} 
          | OP_RES {printf("ok resta\n");} 
          | OP_MULT {printf("ok multiplicacion\n");} 
          | OP_DIV {printf("ok division\n");} 
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
      |CONST_INT {printf("ok int\n");}
      | CONST_STR {printf("ok str\n");}
      | CONST_REAL {printf("ok real\n");}
      ;



let: LET 
  ;

declaraciones: declaracion
              |declaraciones declaracion
              ;

declaracion: DEFVAR  {printf("ok def var\n")}
              tipodato 
              OP_DOSP  {printf("ok op asignacion\n")}
              listavariables
              ENDDEF {printf("ok end def\n")}
              ;

tipodato: FLOAT {printf("ok float\n")}
              | STRING {printf("ok float\n")}
              |  INT {printf("ok int\n")}
              ;

listavariables: ID  {printf("ok id\n")}
                | ID {printf("ok id\n")}
                PYC {printf("ok punto y coma \n")}
                listavariables

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

