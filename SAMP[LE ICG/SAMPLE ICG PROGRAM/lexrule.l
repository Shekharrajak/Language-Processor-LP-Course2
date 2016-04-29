%{
	#include <stdlib.h>
	#include "rule.h"
	#define STRDUP( var ) var = new char[strlen(yytext)];strcpy(var,yytext);
%}

digit [0-9]
alpha [a-zA-z]

%%
<<EOF>>        {return 0; }
int            {return INT;}
float 		   {return FLOAT;}
bool           {return BOOL;}

if             {return IF;}
else           {return ELSE;}
while          {return WHILE;}
switch         {return SWITCH;}
case           {return CASE;}
default        {return DEFAULT;}



= 			   {return ASSIGN;}
"+="           {return PLUSEQ;}
-=             {return MINUSEQ;}
"*="           {return TIMESEQ;}
"/="           {return DIVIDEQ;}


"+" 		   {return PLUS;}
-              {return MINUS;}
"*"  		   {return TIMES;}
"/"            {return DIVIDE;}
@              {return EXP;}


"|"            {return IOR;}
&              {return IAND;}
~              {return INOT;}
"^"            {return XOR;}


"||"           {return OR;}
&&             {return AND;}
!			   {return NOT;}

== 	 		   {return EQ;}
!= 			   {return NEQ;}
"<"  		   {return LT;}
"<=" 		   {return LEQ;}
>              {return GT;}
>= 			   {return GEQ;}

"("            {return  LP;}
")"            {return  RP;}	
"{"            {return  LB;}
"}"            {return  RB;}
;              {return  SEMICOLON;}
:              {return COLON;}

(({digit}*)|({digit}+([eE][+\-]?{digit}+)))\.{digit}+([eE][+\-]?{digit}+)?       {STRDUP(yylval.exp.addr);return DOUBLENUM;}
({digit}+|({digit}+[eE][+]?{digit}+))                                            {STRDUP(yylval.exp.addr);return INTNUM;}
true          															 		 {return TRUE;}
false 																			 {return FALSE;}
{alpha}+({digit}|{alpha})*                                                       {STRDUP(yylval.exp.addr);return ID;}

[\r\t\f\v\n ]+  {/* remove whilte space*/}
.  {/**Record error*/}
#.* {/**Remove all #include  and #define */}
%%