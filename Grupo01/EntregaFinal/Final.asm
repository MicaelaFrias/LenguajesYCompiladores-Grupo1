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
_32 dd 32
_2 dd 2
_aaa dd aaa
_aaa dd aaa
_aaa dd aaa
_32 dd 32
_5 dd 5

.CODE 
mov ah, 1;
int 21h ;
MOV AX, 4C00h; 
int 21h;
FLD _32
FLD a
FXCH 
FCOM 
BGT 10
FLD _2
FLD a
FXCH 
FCOM 
BLE 18
FLD _aaa
FSTP b
FLD _aaa
FSTP b
BI 21
FLD _aaa
FSTP b
ENDIF: 
FLD _32
FLD a
FXCH 
FCOM 
FLD _5
FSTP a
END
