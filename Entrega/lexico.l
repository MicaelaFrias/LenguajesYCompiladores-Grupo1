%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
FILE  *yyin;
int yylval;

%}
%option noyywrap  
%option yylineno 

DIGITO		    	[0-9]
LETRA			    [a-zA-Z]
COMA                [","]
COM_I			    ["/***"]
COM_F			    ["***/"]
COMENTARIO		    {COM_I}({LETRA}+|(DIGITO)+){COM_F}
CONST_STR           \"({LETRA}|{DIGITO}|.){2,5}\"
COMENTARIOS         "//"({LETRA}|{DIGITO}|.)+"//"
CONST_REAL          {DIGITO}+"."{DIGITO}+
CONST_INT           {DIGITO}+
ID			        {LETRA}({LETRA}|{DIGITO}|_)*
IGUAL               ["="]
OP_COMPARACION      ["<"|IGUAL|">"|"<="|">="|"><"]
OP_SUM              ["+"]
OP_RES              ["-"]
PYC                 [";"]
OP_MULT             ["*"]
OP_DIV              ["/"]
OP_AS   		    [":="]
OP_LOG              ["and"|"or"|"not"]
C_A                 ["["]
C_C                 ["]"]
P_A                 ["("]
P_C                 [")"]
	


%%
"program"		{ return PROGRAM;}
"define"		{ return DEFINE;}
"enddefine"		{ return ENDDEFINE;}
"beginp"		{ return BEGINP;}
"endp"			{ return ENDP;}
"string"		{ return STRING;}
"if"			{ return IF;}
"let"			{ return LET;}
"then"   		{ return THEN;}
"else"   		{ return ELSE;}
"endif"	      		{ return ENDIF;}
"for"			{ return FOR;}
"to"		      	{ return TO;}
"do"	         	{ return DO;}
"endfor"		{ return ENDFOR;}
"while"	      		{ return WHILE;}
"in"	         	{ return IN;}
"endw"  		{ return ENDW;}
"repeat"		{ return REPEAT;}
"until"			{ return UNTIL;}
"defvar"  		{ return DEFVAR;}
"enddef"  		{ return ENDDEF;}
"float"  		{ return FLOAT;}
"int"  		{ return INT;}
"display"       { return DISPLAY;}
"get"           { return GET;}
":="			{ return OP_AS;}
":"			{ return OP_DOSP;}
"+"			{ return OP_SUM;}
"-"			{ return OP_RES;}
"*"			{ return OP_MULT;}
"/"			{ return OP_DIV;}
"("			{ return P_A;}
")"			{ return P_C;}
">"                     { return OP_COMPARACION;}
">="                    { return OP_COMPARACION;}
"="                    { return OP_COMPARACION;}
"<"                     { return OP_COMPARACION;}
"<="                    { return OP_COMPARACION;}
"><"                    { return OP_COMPARACION;}
";"                    { return PYC;}
"and"                   { return OP_LOG;}
"or"                    { return OP_LOG;}
"not"                   { return OP_LOG;}
{ID}			{ return ID;}
{CONST_INT}		{ return CONST_INT;}
{IGUAL}		{ return IGUAL;}
{CONST_STR}		{ return CONST_STR;}
{CONST_REAL}		{ return CONST_REAL;}
{COMA}			{ return COMA;}
{COMENTARIOS}		{ return COMEN;}
{LETRA}		{ return LETRA;}	



