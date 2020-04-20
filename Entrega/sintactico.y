/* simplest version of calculator */
%{
#include <stdio.h>
%}

/* declare tokens */
%token NUMBER
%token ADD SUB MUL DIV ABS PA PC
%token EOL

%%

calclist:                   
 | calclist exp EOL { printf("= %d\n", $2); } 
 ;

exp: termino     
 | exp ADD termino { $$ = $1 + $3; }
 | exp SUB termino { $$ = $1 - $3; }
 ;

termino: factor     
 | termino MUL factor { $$ = $1 * $3; }
 | termino DIV factor { $$ = $1 / $3; }
 ;

factor: NUMBER  
 | ABS factor   { $$ = $2 >= 0? $2 : - $2; }
 | PA exp PC    { $$ = $2 }
;
%%
main(int argc, char **argv)
{
  yyparse();
}

yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}