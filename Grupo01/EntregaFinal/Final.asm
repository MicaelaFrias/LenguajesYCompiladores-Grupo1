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
_aaa dd aaa
_aaa dd aaa
_32 dd 32
_7 dd 7
_44 dd 44
_9 dd 9
_44 dd 44
_aaa dd aaa
_9 dd 9
_aaa dd aaa
_3.5 dd 3.5
_3 dd 3
_2.5 dd 2.5
_8 dd 8
_1 dd 1
_hola dd hola
_8 dd 8
_1 dd 1
_chau dd chau
_8 dd 8
_1 dd 1
_hola dd hola
_8 dd 8
_1 dd 1
_hola dd hola
_3 dd 3
_2.5 dd 2.5
_2.5 dd 2.5
_4 dd 4
_5 dd 5
_3 dd 3
_32 dd 32
_2 dd 2
_aaa dd aaa
_aaa dd aaa
_aaa dd aaa
<<<<<<< HEAD
_32 dd 32
_5 dd 5
=======
_5 dd 5
_6 dd 6
_8 dd 8
>>>>>>> d3e599c3e1f3a064f996ea11ea645d45fac6b871

.CODE 
mov ah, 1;
int 21h ;
MOV AX, 4C00h; 
int 21h;
FLD f455
FLD a
FXCH 
FCOM 
BGT 10
FLD f455
FLD a
FXCH 
FCOM 
BLE 56
FLD _aaa
FSTP b
FLD _aaa
FSTP b
FLD _32
FLD a
FXCH 
FCOM 
BLE 50
FLD _7
FLD a
FXCH 
FCOM 
FLD _44
FLD h7
FXCH 
FCOM 
BGT 36
FLD _9
FLD a
FXCH 
FCOM 
BLE 41
FLD _44
FSTP h7
BI 44
FLD _aaa
FSTP b
ENDIF: 
FLD a
FSTP a
BI 50
ENDIF: 
FLD _9
FSTP a
BI 59
FLD _aaa
FSTP b
ENDIF: 
FLD _3.5
FLD a
FXCH 
FCOM 
BNE 78
FLD k
FLD j
FADD 
FLD _2.5
FLD f455
FADD 
FLD _3
FLD a
FADD 
FLD 50
FLD BGE
FADD 
FSTP √ãu‡ã}‰VËLIˇˇY√ÃÃÃÃÃÃÃãˇUãÏj@ˇuˇuËˇˇˇÉƒ]√ÃÃÃÃÃÃÃÃÃãˇUãÏVãuÖˆuËÓ ¸ˇj^3…QQQQQâ0ËçC˛ˇÉƒã∆Î$hÄ
BI 78
ENDIF: 
FLD _8
FLD a
FXCH 
FCOM 
BLE 110
FLD _1
FLD f4
FXCH 
FCOM 
BNE 110
FLD _hola
FSTP a3
ET: 
FLD _8
FLD h7
FXCH 
FCOM 
BGT 104
FLD _1
FLD h7
FXCH 
FCOM 
BNE 109
FLD _chau
FSTP a3
BI 93
ENDW: 
ENDW: 
FLD _8
FLD a
FXCH 
FCOM 
BLE 125
FLD _1
FLD f4
FXCH 
FCOM 
BNE 125
FLD _hola
FSTP a3
ENDW: 
FLD _8
FLD a
FXCH 
FCOM 
BLE 169
FLD _1
FLD f4
FXCH 
FCOM 
BNE 169
FLD _hola
FSTP a3
FLD _3
FLD a
FXCH 
FCOM 
BNE 152
FLD _2.5
FLD _2.5
FADD 
FSTP a
BI 152
ENDIF: 
FLD _4
FLD a
FXCH 
FCOM 
BEQ 163
FLD _5
FLD a
FXCH 
FCOM 
BLE 168
FLD _3
FSTP a
BI 168
ENDIF: 
ENDW: 
FLD _32
FLD a
FXCH 
FCOM 
BGT 180
FLD _2
FLD a
FXCH 
FCOM 
<<<<<<< HEAD
BLE 18
=======
BLE 188
>>>>>>> d3e599c3e1f3a064f996ea11ea645d45fac6b871
FLD _aaa
FSTP b
FLD _aaa
FSTP b
BI 191
FLD _aaa
FSTP b
ENDIF: 
<<<<<<< HEAD
FLD _32
=======
FLD a
>>>>>>> d3e599c3e1f3a064f996ea11ea645d45fac6b871
FLD a
FXCH 
FCOM 
FLD _5
<<<<<<< HEAD
FSTP a
=======
FLD a
FADD 
FSTP e
BI 211
FLD e
FSTP a
FLD a
FLD a
FXCH 
FCOM 
BLE 223
FLD _6
FLD a
FADD 
FSTP e
BI 228
FLD _8
FLD a
FADD 
FSTP e
>>>>>>> d3e599c3e1f3a064f996ea11ea645d45fac6b871
END
