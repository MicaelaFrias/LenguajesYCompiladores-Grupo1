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
_23 dd 23
_4 dd 4
_5 dd 5
_3 dd 3
_aaa dd aaa
_aaa dd aaa
_32 dd 32
_7 dd 7
_44 dd 44
_9 dd 9
_44 dd 44
_aaa dd aaa
_32 dd 32
_9 dd 9
_aaa dd aaa
_8 dd 8
_1 dd 1
_hola dd hola
_8 dd 8
_1 dd 1
_chau dd chau
_6 dd 6
_8 dd 8
_3 dd 3
_4 dd 4
_5 dd 5
@RES dd ?
.CODE 
mov ah, 1;
int 21h ;
MOV AX, 4C00h; 
int 21h;
FILD _23
FSTP 96
FLD _4
FLD a
FXCH 
FCOM 
BEQ THEN0
FLD _5
FLD a
FXCH 
FCOM 
BLE ENDIF0
THEN0: 
FILD _3
FSTP a
BI ENDIF0
ENDIF0: 
FLD f455
FLD a
FXCH 
FCOM 
BGT THEN1
FLD f455
FLD a
FXCH 
FCOM 
BLE ELSE0
THEN1: 
FILD _aaa
FSTP b
FILD _aaa
FSTP b
FLD _32
FLD a
FXCH 
FCOM 
BLE ENDIF1
FLD _7
FLD a
FXCH 
FCOM 
BGE ENDIF1
THEN2: 
FLD _44
FLD h7
FXCH 
FCOM 
BGT THEN3
FLD _9
FLD a
FXCH 
FCOM 
BLE ELSE0
THEN3: 
FILD _44
FSTP h7
BI ENDIF1
ELSE0: 
FILD _aaa
FSTP b
ENDIF1: 
FILD _32
FSTP a
BI ENDIF2
ENDIF2: 
FILD _9
FSTP a
BI ENDIF3
ELSE1: 
FILD _aaa
FSTP b
ENDIF3: 
WHILE0: 
FLD _8
FLD a
FXCH 
FCOM 
BLE ENDW0
FLD _1
FLD f4
FXCH 
FCOM 
BNE ENDW0
THENW0: 
FILD _hola
FSTP a3
WHILE1: 
FLD _8
FLD h7
FXCH 
FCOM 
BGT THENW1
FLD _1
FLD h7
FXCH 
FCOM 
BNE ENDW0
THENW1: 
FILD _chau
FSTP a3
BI WHILE1
ENDW0: 
BI WHILE0
ENDW1: 
getString a3
displayString a
FLD a
FLD a
FXCH 
FCOM 
BLE ELSE2
FILD _6
FLD a
FADD 
FSTP @RES
FFREE 
FLD @RES
FSTP e
BI ENDIF4
ELSE2: 
FILD _8
FLD a
FADD 
FSTP @RES
FFREE 
FLD @RES
FSTP e
ENDIF4: 
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
