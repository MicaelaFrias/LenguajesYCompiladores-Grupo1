%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "sintactico.tab.h"
#define COTA_INT 65536
#define COTA_FLOAT 4294967296
FILE  *yyin;
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

{ID}		    {
                    insertarEnTS(yytext,"ID","--",0);
                    return ID;
                }

{CONST_INT}	    {    
                    yylval.int_val = atoi(yytext);
    			    insertarEnTS("entero","CONST_INT","--",yylval.int_val);		
                    return CONST_INT;
               
                }

{CONST_STR}		{   
                    yylval.str_val = strdup(yytext);
                    insertarEnTS(yylval.str_val,"CONST_STR",yylval.str_val,0);
                    return CONST_STR;
                }

{CONST_REAL}    {                  
                    yylval.float_val = atof(yytext);
                    insertarEnTS("float","CONST_REAL","--",0);
                    return CONST_REAL; 
                }

{COMA}			{ return COMA;}
{COMENTARIOS}	{ return COMEN;}
{LETRA}	    	{ return LETRA;}	



