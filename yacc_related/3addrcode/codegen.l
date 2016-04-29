/*******  codegen.l  **********/

%{
        #include<stdio.h>
        #include "y.tab.c"
        char ch='a';

%}
%%
[0-9]+ {yylval.dval=yytext[0]; return NUM;}
\n {return 0;}
. {return yytext[0];}
%%

char gencode(char ch1,char first,char op,char second)
{
        printf("\n%c = %c %c %c\n",ch,first,op,second);
        return ch++;
}
main()
{
        yyparse();
        return 0;
}
