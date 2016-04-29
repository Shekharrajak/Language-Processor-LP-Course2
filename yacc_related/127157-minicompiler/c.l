alpha [a-zA-Z]
digit [0-9]

%%
[ \t]		;
[ \n]   { yylineno = yylineno + 1;}
int	return INT;
"unsigned int"	return UNSIGNED;
bool return BOOL;
void return VOID;
while	return WHILE;
if	return IF;
else	return ELSE;
switch	return SWITCH;
case 	return CASE;
break	return BREAK;
default	return DEFAULT;
printf  return PRINTF;
main 	return MAIN;

^"#include ".+ ;
{digit}+       return NUM;
{alpha}({alpha}|{digit})* {yylval.str = malloc(100);strcpy(yylval.str,yytext);if(yylval.str==NULL)printf("errror\n");return ID;}
"<="    return LE;
">="    return GE;
"=="    return EQ;
"!="    return NE;
">"	return GT;
"<"	return LT;
"."     return DOT;
"||"	return OR;
"&&"	return AND;
"!"		return NOT;
"+="	return ADD;
"-="	return SUB;
"*="	return MUL;
"/="	return DIV;
"="     return ASSIGN;
','		return COMMA;
\/\/.* ;
\/\*(.*\n)*.*\*\/ ;
.       return yytext[0];
%%
