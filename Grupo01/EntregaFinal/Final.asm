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
_4.66 dd 4.66
_4 dd 4
_54 dd 54
_5.3 dd 5.3
@RES dd ?
.CODE 
mov ah, 1;
int 21h ;
MOV AX, 4C00h; 
int 21h;
FLD _4.66
FSTP a
FILD _4
FSTP h7
FLD _5.3
FILD _54
FADD 
FSTP @RES
FFREE 
FLD @RES
FSTP dos
END
