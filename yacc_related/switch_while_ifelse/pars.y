%{
#include<stdio.h>
#include<stdlib.h>
%}

%token ID NUM SWITCH CASE DEFAULT BREAK LE GE EQ NE AND OR IF THEN WHILE
%right '='
%left AND OR
%left '<' '>' LE GE EQ NE
%left '+''-'
%left '*''/'
%right UMINUS
%left '!'

%%

S    :    ST{printf("\nInput accepted.\n");exit(0);};
      ;
ST  :    SWITCH'('ID')''{'B'}'
      ;
B    :    C 
      |    C D 
      ;
C  :    C C
    |    CASE NUM':'ST1 BREAK';' 
    ;
D  :    DEFAULT':'ST1 BREAK';'
    |    DEFAULT':'ST1
    ;
ST1    :    WHILE'('E2')' E';'
    |    IF'('E2')'THEN E';'
    |    ST1 ST1
    |    E';'
    ;
E2    :    E'<'E 
    |    E'>'E
    |    E LE E
    |    E GE E
    |    E EQ E
    |    E NE E
    |    E AND E
    |    E OR E
    ;
E    :    ID'='E
    |    E'+'E 
    |    E'-'E
    |    E'*'E 
    |    E'/'E
    |    E'<'E
    |    E'>'E
    |    E LE E
    |    E GE E
    |    E EQ E
    |    E NE E
    |    E AND E
    |    E OR E
    |    ID 
    |    NUM
    ;

%%

#include"lex.yy.c"

main()
{
    printf("\nEnter the expression: ");
    yyparse();
}