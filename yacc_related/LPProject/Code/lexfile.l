/* recognize tokens for the grammar */
letter	[A-Za-z_]
digit	[0-9]
%{
/*
# define AUTHOR				"Avinash Yadav"
# define ROLL_NUMBER		"127210"
# define ENGG_BRANCH		"Computer Science And Engineering (CSE)"
# define CLASS_AND_SECTION	"B Tech, (3/4), CSE - B"
# define APP_NAME			"Language Processors Major Assignment: Intermediate Code Generation"
# define ACADEMIC_SESSION	"2014-2015"
# define INSTITUTE			"NIT Warangal"
*/
# include "myStruct.h"
# include "yaccfile.tab.h"
%}

%%
"bool"		{	
				memset(&yylval, 0, sizeof(yylval));
				yylval.type = KW_BOOL;				
				return KW_BOOL;	
			}
"int"		{	
				memset(&yylval, 0, sizeof(yylval));
				yylval.type = KW_INT;				
				return KW_INT;	
			}
"u_int"		{	
				memset(&yylval, 0, sizeof(yylval));
				yylval.type = KW_U_INT;				
				return KW_U_INT;	
			}

"true"		{	
				memset(&yylval, 0, sizeof(yylval));
				yylval.val = 1;
				return KW_VAL_TRUE;
			}
"false"		{	
				memset(&yylval, 0, sizeof(yylval));
				yylval.val = 0;
				return KW_VAL_FALSE;
			}

"if"		{	return KW_IF;	}
"else"		{	return KW_ELSE;	}
"switch"	{	return KW_SWITCH;	}
"case"		{	return KW_CASE;	}
"default"	{	return KW_DEFAULT;	}
"break"		{	return KW_BREAK;	}
"while"		{	return KW_WHILE;	}

{letter}({letter}|{digit})*	{					
								memset(&yylval, 0, sizeof(yylval));
								strcpy(yylval.varName, yytext);
								return IDENTIFIER;
							}

{digit}+	{
				memset(&yylval, 0, sizeof(yylval));
				yylval.type = NUMBER;
				yylval.val = atoi(yytext);
				return NUMBER;
			}

"="		{	
			memset(&yylval, 0, sizeof(yylval));
			return IS_ASSIGNED;
		}
"+="	{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return PLUS_ASSIGNED;
		}
"-="	{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return MINUS_ASSIGNED;
		}
"*="	{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return MULTIPLY_ASSIGNED;
		}
"/="	{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return DIVIDE_ASSIGNED;
		}

"+"		{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return ADD;
		}
"-"		{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return SUB;
		}
"*"		{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return MUL;
		}
"/"		{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return DIV;
		}
"@"		{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return POW;
		}

"||"	{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return BOOL_OR;
		}
"&&"	{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return BOOL_AND;
		}
"!"		{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return BOOL_NOT;
		}

"|"		{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return BITWISE_OR;
		}
"&"		{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return BITWISE_AND;
		}
"^"		{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return BITWISE_XOR;
		}
"~"		{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return BITWISE_NOT;
		}

">"		{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return IS_GREATER_THAN;
		}
">="	{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return IS_GREATER_THAN_OR_EQUAL_TO;
		}
"<"		{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return IS_LESS_THAN;
		}
"<="	{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return IS_LESS_THAN_OR_EQUAL_TO;
		}
"=="	{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return IS_EQUAL_TO;
		}
"!="	{	
			memset(&yylval, 0, sizeof(yylval));
			strcpy(yylval.oprtr,yytext);
			return IS_NOT_EQUAL_TO;
		}

";"		{	return SEMI_COLON;	}
":"		{	return COLON;	}
","		{	return COMMA;	}
"("		{	return OPEN_PARANTHESIS;	}
")"		{	return CLOSE_PARANTHESIS;	}
"{"		{	return OPEN_BRACE;	}
"}"		{	return CLOSE_BRACE;	}

\n		{	/* ignore */	}
[ \t]	{	/* ignore */	}
.		{	printf("Mystery character %c\n", *yytext);	}
%%
