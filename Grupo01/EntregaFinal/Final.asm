include macros2.asm
include number.asm
.MODEL LARGE
.386
.STACK 200h
.DATA
a dd ?
f455 dd ?
h7 dd ?
f4 dd ?
dos dd ?
tres dd ?
e dd ?
a3 dw ?
f45 dw ?
b dw ?
uno dw ?
j dd ?
k dd ?
_3 dd 3
_5 dd 5
@RES dd ?
.CODE 
mov ah, 1;
int 21h ;
MOV AX, 4C00h; 
int 21h;
FILD _3
FSTP _3
FLD a
FLD a
FXCH 
FCOM 
BGE ELSE0
FILD _5
FILD _5
FADD 
FSTP @RES
FFREE 
FLD e
FSTP e
BI ENDIF0
ELSE0: 
FLD e
FSTP e
ENDIF0: 
END
