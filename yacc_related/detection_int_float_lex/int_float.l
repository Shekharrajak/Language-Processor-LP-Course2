%{

%}

DIGIT    [0-9]

%%

{DIGIT}*        {ECHO;printf(" Integer");}
{DIGIT}*?\.{DIGIT}*    {ECHO;printf(" Float ");}

%%
main()
{
    yylex();
}