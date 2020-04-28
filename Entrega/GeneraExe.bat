c:\GnuWin32\bin\flex lexico.l
pause
c:\GnuWin32\bin\bison -d sintactico.y
pause
c:\MinGW\bin\gcc.exe lex.yy.c sintactico.tab.c -o a.exe
pause
pause
a.exe comunes.txt

pause
