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
_50.3 dd 50.3
_3 dd 3

.CODE 
mov ah, 1;
int 21h ;
MOV AX, 4C00h; 
int 21h;
END
