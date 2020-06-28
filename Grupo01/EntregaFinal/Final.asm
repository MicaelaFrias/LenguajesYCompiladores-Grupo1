include macros2.asm
include number.asm
.MODEL LARGE
.386
.STACK 200h
.DATA
_a dd ?
_f455 dd ?
_h7 dd ?
_f4 dd ?
_dos dd ?
_tres dd ?
_e dd ?
_a3 dw ?
_f45 dw ?
_b dw ?
_uno dw ?
_j dd ?
_k dd ?

.CODE 
mov ah, 1;
int 21h ;
MOV AX, 4C00h; 
int 21h;
END
