/*********  codegen.y  *********/

%{
        #include<stdio.h>
 int aaa;

%}

%union {
                char dval;
        }

%token <dval> NUM
%type <dval> E
%left '+' '-'
%left '*' '/'

%%
statement : E {printf("\nt = %c\n This Three Address Code Generate by AAA...\n",$1);}
          ;

E : E '+' E {$$=gencode($$,$1,'+',$3);}
  | E '-' E {$$=gencode($$,$1,'-',$3);}
  | E '*' E {$$=gencode($$,$1,'*',$3);}
  | E '/' E {$$=gencode($$,$1,'/',$3);}
  | '(' E ')' {$$=$2;}
  | NUM {$$=$1;}
  ;
%%
