How to Compile?
The Flex specification is processed as follows (the file lex.yy.c is produced):
 flex vars.l
The YACC specification is processed as follows (files y.tab.h, needed by the Flex-generated code, and y.tab.c):
 yacc -dtv vars.y
Compiling the C/C++ code (it is C++ simply because we programmed the extra code in that language):
 g++ -c lex.yy.c
 g++ -c y.tab.c
 g++ -o vars y.tab.o lex.yy.o











 ;int yylex(void);

; static
; void yyerror(char *s)
; {
;         printf("yyerror: %s\n", s);
; }


int yylex(void);
