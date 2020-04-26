%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "sintactico.tab.h"
#define COTA_INT 65536
#define COTA_FLOAT 4294967296
FILE  *yyin;
int yylval;

%}
%option noyywrap  
%option yylineno 

DIGITO		            [0-9]
LETRA		        	[a-zA-Z]
COMA                    [","]
COM_INI                 ["***/"]    
COM_FIN                 ["/***"]
COMENTARIOS             ["***/"]({LETRA}|{DIGITO}|.)*["/***"]
CONST_STR               \"({LETRA}|{DIGITO}|.){0,30}\"
CONST_REAL              {DIGITO}+"."{DIGITO}+
CONST_INT               {DIGITO}+
ID			            {LETRA}({LETRA}|{DIGITO}|_)*
	


%% 
"program"		{ return PROGRAM;}
"define"		{ return DEFINE;}
"enddefine"		{ return ENDDEFINE;}
"beginp"		{ return BEGINP;}
"endp"			{ return ENDP;}
"real"			{ return REAL;}
"string"		{ return STRING;}
"if"			{ return IF;}
"let"			{ return LET;}
"then"   		{ return THEN;}
"else"   		{ return ELSE;}
"endif"	      	{ return ENDIF;}
"for"			{ return FOR;}
"to"		   	{ return TO;}
"do"	        { return DO;}
"endfor"		{ return ENDFOR;}
"while"	      	{ return WHILE;}
"in"	        { return IN;}
"endw"  		{ return ENDW;}
"repeat"		{ return REPEAT;}
"until"			{ return UNTIL;}
"defvar"  		{ return DEFVAR;}
"enddef"  		{ return ENDDEF;}
"float"  		{ return FLOAT;}
"int"  		    { return INT;}
"display"       { return DISPLAY;}
"get"           { return GET;}
"and"           { return OP_LOG;}
"or"            { return OP_LOG;}
"not"           { return OP_NOT;}
":="			{ return OP_ASIG;}
":"		    	{ return OP_DOSP;}
"+"		    	{ return OP_SUM;}
"-"		    	{ return OP_RES;}
"*"		    	{ return OP_MULT;}
"/"		    	{ return OP_DIV;}
"("		    	{ return P_A;}
")"		    	{ return P_C;}
">"             { return OP_COMPARACION;}
">="            { return OP_COMPARACION;}
"="             { return OP_COMPARACION;}
"<"             { return OP_COMPARACION;}
"<="            { return OP_COMPARACION;}
"<>"            { return OP_COMPARACION;}
";"             { return PYC;}
"and"           { return OP_LOG;}
"or"            { return OP_LOG;}
"not"           { return OP_LOG;}

{ID}				{ yylval.str_val = yytext; 
							insertarEnTS(yylval.str_val,"ID","--",0,0); 
							return ID;}
{CONST_INT}	{ yylval.int_val = atoi(yytext);
							int num = atoi(yytext); 
							if(num >= COTA_INT*(-1) && num <= COTA_INT){
									insertarEnTS("entero","CONST_INT","--",yylval.int_val,0);
									return CONST_INT; 
							}else{
									printf("ERROR - Int fuera de rango.\n");
									system ("Pause");
									exit(1);
							}
            }
{CONST_STR}		{ yylval.str_val = strdup(yytext);
								int cantCaracteres = strlen(yytext);
								if(cantCaracteres <= 30) { //Cuenta las commillas tambien
										insertarEnTS(yylval.str_val,"CONST_STR",yylval.str_val,0,0);
										return CONST_STR;
								} else {
										printf("ERROR - Constante string muy larga. Maximo 30 caracteres\n");
										system ("Pause");
										exit(3);
								}
              }
{CONST_REAL} { yylval.float_val = atof(yytext);
								double n = atof(yytext);
					
								if(n >= CONST_REAL*(-1) && n <= COTA_FLOAT){
			 						insertarEnTS("float","CONST_FLOAT","--",0,yylval.float_val);
									return CONST_FLOAT; 
								}else{
									printf("ERROR - Float fuera de rango.\n");
									system ("Pause");
									exit(2);
							}
}
{COMA}			{ return COMA;}
{COMENTARIOS}	{ return COMEN;}
{LETRA}	    	{ return LETRA;}	



