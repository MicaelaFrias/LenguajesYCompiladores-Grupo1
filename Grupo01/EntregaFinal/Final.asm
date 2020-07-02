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
_8 dd 8
_1 dd 1
_hola dd hola
@RES dd ?
.CODE 
mov ah, 1;
int 21h ;
MOV AX, 4C00h; 
int 21h;
ET: 
FLD _8
FLD a
FXCH 
FCOM 
BLE 14
FLD _1
FLD f4
FXCH 
FCOM 
BNE 14
FLD _hola
FSTP a3
ENDW: 
END
