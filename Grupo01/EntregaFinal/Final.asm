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
_4 dd 4
_6 dd 6
_4.5 dd 4.5
_6 dd 6

.CODE 
mov ah, 1;
int 21h ;
MOV AX, 4C00h; 
int 21h;
FILD _4
FSTP a
FILD _6
FSTP dos
FILD _6
FLD _4.5
FADD 
END
