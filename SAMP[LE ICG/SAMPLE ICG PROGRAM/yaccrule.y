%{
  #include <bits/stdc++.h>
  #include "codegener.cpp"
  using namespace std;

  extern FILE* yyin;
  int yylex(void);
  void yyerror(const char *);
  extern int quadIndex;
%}
%token IF
%token ELSE
%token WHILE
%token SWITCH
%token CASE DEFAULT
%token INT FLOAT BOOL 
%token ASSIGN PLUSEQ MINUSEQ TIMESEQ DIVIDEQ
%token PLUS MINUS TIMES DIVIDE EXP
%token IOR IAND INOT XOR
%token OR AND NOT
%token EQ NEQ LT LEQ GT GEQ
%token LP RP
%token LB RB
%token SEMICOLON COLON
%token DOUBLENUM INTNUM TRUE FALSE ID

%left  PLUS MINUS TIMES DIVIDE  IOR IAND  XOR  
%right INOT NOT EXP ASSIGN PLUSEQ MINUSEQ TIMESEQ DIVIDEQ
%union{
  struct BackpatchList{
    int ins;
    BackpatchList *next;
  };

  struct marks{
    int instr;
  }mark;
  struct info{
    char *addr;
    BackpatchList *tlist;
    BackpatchList *flist;
  }exp;
  struct next{
      int instr;
      BackpatchList *nextList;
  }List;
  char *str;
}

%type<str> RELOP
%type<type> var-type declaration 
%type<exp>  Exp subif  constant  ID
%type<mark> marker
%type<List> statement Next selection-statement compound-statement iteration-statement  statement-list 

%%
start:
  var-type ID LP  RP compound-statement{
	  backpatch($5.nextList,quadIndex);
	  gencode("ret",0);
  }
;
/*Compound statement e.g. { some code } */
compound-statement:
   LB statement-list RB {$$.nextList = $2.nextList;}
;
statement-list:
  statement-list marker statement{ backpatch($1.nextList,$2.instr); $$.nextList = $3.nextList;}
  |statement {$$.nextList = $1.nextList;}
  | {/*Suffice for empty block */ $$.nextList = NULL; }
;

statement:
  SEMICOLON{}
  |Exp SEMICOLON{}
  |declaration{$$.nextList=NULL;}
  |compound-statement{$$.nextList = $1.nextList;}
  |selection-statement{$$.nextList = $1.nextList;}
  |iteration-statement{$$.nextList = $1.nextList;}
;

declaration:
    var-type ID SEMICOLON{}
  | var-type ID ASSIGN Exp SEMICOLON {gencode($2.addr,$4.addr);}
;
var-type:
  INT {}
  |FLOAT {}
  |BOOL {}
;
/**Switch statement */
switch-statement:
  case-list{}
  |case-list default-statement{}
  |default-statement case-list{}
  |case-list default-statement case-list{}
;
default-statement:
   DEFAULT COLON compound-statement{ }
;
case-list:
  CASE constant    COLON compound-statement{ }
  |case-list CASE constant    COLON compound-statement{ }
;

/**Selection statement e.g. if (E) {} else { } , switch(E){ },if (E){} e.t.c*/
selection-statement:
  subif marker statement{ 
  backpatch($1.tlist,$2.instr);
  $$.nextList = mergeList($1.flist,$3.nextList);
}
| subif marker statement ELSE Next statement { 
	backpatch($1.tlist,$2.instr);
    backpatch($1.flist,$5.instr);
    YYSTYPE::BackpatchList *temp = mergeList($3.nextList,$5.nextList);
    $$.nextList = mergeList(temp,$6.nextList);
}
|SWITCH LP Exp RP marker LB switch-statement RB{}
;

subif: IF LP Exp RP{
		$$.tlist = $3.tlist;
		$$.flist = $3.flist;
}
;

Next:{
  $$.nextList = makelist(quadIndex);
  gencode("goto",-1);
  $$.instr = quadIndex;
}
;
/**Iteration statement*/
iteration-statement:
  WHILE marker LP Exp RP marker statement{
    backpatch($7.nextList,$2.instr);
    backpatch($4.tlist,$6.instr);
    $$.nextList = $4.flist;
    gencode("goto",$2.instr);
}
;

/**Assignment expression e.g. constants , */
Exp:
  Exp ASSIGN Exp {
        gencode($1.addr,$3.addr);
        $$.flist = NULL;
        $$.tlist = NULL;
  }
  |Exp PLUSEQ Exp {
        $$.flist = NULL;
        $$.tlist = NULL;
        $$.addr  = newtemp();
        gencode($$.addr  ,$1.addr,"+",$3.addr);
        gencode($1.addr,$$.addr );
        $$.addr  = $1.addr;
  }
  |Exp MINUSEQ Exp {
       $$.flist = NULL;
       $$.tlist = NULL;
        $$.addr  = newtemp();
        gencode($$.addr  ,$1.addr,"-",$3.addr);
        gencode($1.addr,$$.addr );
        $$.addr  = $1.addr;
  }
  |Exp TIMESEQ Exp {
       $$.flist = NULL;
       $$.tlist = NULL;
	    $$.addr  = newtemp();
	    gencode($$.addr  ,$1.addr,"*",$3.addr);
	    gencode($1.addr,$$.addr );
	    $$.addr  = $1.addr;
  }
  |Exp DIVIDEQ Exp {
       $$.flist = NULL;
       $$.tlist = NULL;
        $$.addr  = newtemp();
        gencode($$.addr  ,$1.addr,"/",$3.addr);
        gencode($1.addr,$$.addr );
        $$.addr  = $1.addr;
  } 
  |Exp OR marker Exp{
      backpatch($1.flist,$3.instr);
      $$.flist = $4.flist;
      $$.tlist = mergeList($1.tlist,$4.tlist);
  }
  |Exp AND marker Exp{
      backpatch($1.tlist,$3.instr);
      $$.tlist = $4.tlist;
      $$.flist = mergeList($1.flist,$4.flist);
  }
  |Exp IOR Exp{
      $$.addr  = newtemp();
      $$.flist = NULL;
      $$.tlist = NULL;
      gencode($$.addr ,$1.addr,"|",$3.addr);
  }
  |Exp XOR Exp{
	    $$.addr  = newtemp();
	    $$.flist = NULL;
	    $$.tlist = NULL;
	    gencode($$.addr ,$1.addr,"XOR",$3.addr);
   }
  |Exp IAND Exp{
      $$.addr  = newtemp();
      $$.flist = NULL;
      $$.tlist = NULL;
      gencode($$.addr ,$1.addr,"&",$3.addr);
  }
  |Exp RELOP Exp{
      $$.tlist = makelist(quadIndex);
      $$.flist = makelist(quadIndex+1);
      gencode("if",$1.addr,$2,$3.addr,"goto",-1); 
      gencode("goto",-1);
  } 
  |Exp PLUS Exp{
      $$.addr  = newtemp();
      $$.tlist  = NULL;
      $$.flist  = NULL;
      gencode($$.addr  ,$1.addr,"+",$3.addr);
  }
  |Exp MINUS Exp{
      $$.addr  = newtemp();
      $$.tlist  = NULL;
      $$.flist  = NULL;
      gencode($$.addr  ,$1.addr,"-",$3.addr);
  }
  |Exp TIMES Exp{
      $$.addr  = newtemp();
      $$.tlist  = NULL;
      $$.flist  = NULL;
      gencode($$.addr  ,$1.addr,"*",$3.addr);
  }
  |Exp DIVIDE Exp{
      $$.addr   = newtemp();
      $$.tlist  = NULL;
      $$.flist  = NULL;
      gencode($$.addr  ,$1.addr,"/",$3.addr);
  }
  |Exp EXP Exp{
    $$.addr  = newtemp();
    $$.tlist  = NULL;
    $$.flist  = NULL;
    gencode($$.addr  ,$1.addr,"@",$3.addr);
  }
  |INOT  Exp{
      $$.addr  = newtemp();
      $$.tlist  = $2.tlist;
      $$.flist  = $2.flist;
      gencode($$.addr ,"~",$2.addr);
  }
  |NOT Exp{
  	  if($2.tlist==NULL && $2.flist ==NULL){
			  gencode("if",$2.addr,"!=","0","goto",-1);
	          gencode("goto",-1); 
	          $2.tlist = makelist(quadIndex-2);
	          $2.flist = makelist(quadIndex-1);
	  } 
      $$.tlist  = $2.flist;
      $$.flist  = $2.tlist;
  }
 |
 ID{
  $$.addr  = $1.addr;
  $$.tlist  = NULL;
  $$.flist  = NULL;
 }
 |constant   {
    $$.addr  = $1.addr;
    $$.tlist  = $1.tlist;
    $$.flist  = $1.flist;
  }
  |LP Exp RP{
    $$.addr  = $2.addr;
    $$.flist  = $2.flist;
    $$.tlist  = $2.tlist;
  }
;
constant :
  INTNUM {
    char *temp = $$.addr; 
    $$.addr   = newtemp();
    $$.flist = NULL;
    $$.tlist = NULL;
    gencode($$.addr ,temp);
  }
  |DOUBLENUM {
    char *temp = $$.addr ; 
    $$.addr   = newtemp();
    $$.flist = NULL;
    $$.tlist = NULL;
    gencode($$.addr ,temp);
  }
  |TRUE {
    $$.tlist = makelist(quadIndex);
    $$.flist = NULL;
    gencode("goto",-1);
  }
  |FALSE {
    $$.flist = makelist(quadIndex);
    $$.tlist = NULL;
    gencode("goto",-1);
  }
;
RELOP:
     GT  {$$=(char*)">";}
   | GEQ {$$ =(char*)">=";}
   | LT  {$$ =(char*)"<";}
   | LEQ {$$ =(char*)"<=";}
   | EQ {$$ = (char*)"==";}
   | NEQ {$$=(char*)"!=";}
;
marker:
{$$.instr = quadIndex;}
;
%%
void yyerror(const char *s){
  sprintf("%s\n",s);
}
int main(int argc,char *argv[ ]){
  FILE* fp=NULL;
  if(argc==2){
    fp=fopen(argv[1],"r");
  }
  if(fp==NULL){
      fprintf(stderr, "%s\n","file not found");
      return 0;
  }
  yyin=fp;
  while(!feof(yyin)){
    yyparse();
  }
  fclose(fp);
  printCode();
  return 0;
}