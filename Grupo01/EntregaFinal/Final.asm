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
_4 dd 4
_5 dd 5
@RES dd ?
.CODE 
mov ah, 1;
int 21h ;
MOV AX, 4C00h; 
int 21h;
FLD uno
FSTP _3
FLD dos
FSTP _4
FILD _5
FLD a
FADD 
FSTP @RES
FFREE 
FLD @RES
FSTP tres
END
