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
%token INTEGER
%token STRING
%token BEGINP
%token ENDP
%token IF THEN ELSE ENDIF
%token FOR TO DO ENDFOR
%token WHILE ENDW
%token REPEAT UNTIL
%token OP_LOG
%token OP_COMPARACION
%token OP_AS
%token OP_SURES
%token OP_MULTDIV
%token COMA
%token P_A P_C
%token C_A C_C
%token LONG
%token IN
%token COMEN


%%
programa:  PROGRAM {printf("Inicia COMPILADOR\n");}
           codigo
           {printf("Fin COMPILADOR\n");}
           ;
codigo: BEGINP bloqueTemasComunes ENDP ;

bloqueTemasComunes: temaComun
                  | bloqueTemasComunes temaComun
                  ;

temaComun: COMEN {printf("esto es un comentario\n");}
          | decision {printf("esto es una decision\n");}
          ;

decision: IF  {printf("ok if\n");}
          condicion {printf("ok condicion\n");}
          THEN {printf("ok then \n");}
          ENDIF {printf("ok endif\n");}
          ;

condicion: comparacion {printf("ok comp\n");}
         ;

comparacion: factor OP_COMPARACION factor 
          ;

factor: 
	ID {printf("ok var\n");}
      |CONST_INT {printf("ok int\n");}
      | CONST_STR {printf("ok str\n");}
      | CONST_REAL {printf("ok real\n");}
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

