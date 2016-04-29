%option noyywrap
%{
#include <cstdlib>
#include <string>
#include<bits/stdc++.h>
using namespace std;

#include "y.tab.h"

int yylex ();
void yyerror(const char *);


%}
%%
[_[:alpha:]][_[:alnum:]]*     yylval.s = new std::string(yytext);  return VAR;
[[:digit:]]+                  yylval.i = strtol(yytext, NULL, 10); return INT;
[-+*/%=^:,]                   return *yytext;
.|\n                          ; /* ignore all the rest */
%%