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
a3 dd ?
f45 dd ?
b dd ?
uno dd ?
j dd ?
k dd ?
_4 dd 4
_5 dd 5
_3 dd 3
_z dd "z"
_y dd "y"
_32 dd 32
_7 dd 7
_37 dd 37
_9 dd 9
_44 dd 44
_a dd "a"
_65 dd 65
_85 dd 85
_r dd "r"
_21 dd 21
_36 dd 36
_h dd "h"
_8 dd 8
_78 dd 78
_c dd "c"
_67 dd 67
_89 dd 89
_34 dd 34
_45 dd 45
_75 dd 75
@RES dd ?
.CODE 
mov ah, 1;
int 21h ;
MOV AX, 4C00h; 
int 21h;
FLD _4
FLD a
FXCH 
FCOM 
FLD _5
FLD a
FXCH 
FCOM 
THEN0: 
FILD _3
FSTP a
ENDIF0: 
FLD f455
FLD a
FXCH 
FCOM 
FLD f455
FLD a
FXCH 
FCOM 
THEN1: 
FILD _z
FSTP b
FILD _y
FSTP b
FLD _32
FLD a
FXCH 
FCOM 
FLD _7
FLD a
FXCH 
FCOM 
THEN2: 
FLD _37
FLD h7
FXCH 
FCOM 
FLD _9
FLD a
FXCH 
FCOM 
THEN3: 
FILD _44
FSTP h7
ELSE0: 
FILD _a
FSTP b
ENDIF1: 
FILD _65
FSTP a
ENDIF2: 
FILD _85
FSTP a
ELSE1: 
FILD _r
FSTP b
ENDIF3: 
WHILE0: 
FLD _21
FLD a
FXCH 
FCOM 
FLD _36
FLD f4
FXCH 
FCOM 
THENW0: 
FILD _h
FSTP a3
WHILE1: 
FLD _8
FLD h7
FXCH 
FCOM 
FLD _78
FLD h7
FXCH 
FCOM 
THENW1: 
FILD _c
FSTP a3
ENDW0: 
ENDW1: 
getString a3
displayString a
FLD a
FLD a
FXCH 
FCOM 
FILD _67
FLD a
FADD 
FSTP @RES
FFREE 
FLD @RES
FSTP e
ELSE2: 
FILD _89
FLD a
FADD 
FSTP @RES
FFREE 
FLD @RES
FSTP e
ENDIF4: 
FLD uno
FSTP _34
FLD dos
FSTP _45
FILD _75
FLD a
FADD 
FSTP @RES
FFREE 
FLD @RES
FSTP tres
END
