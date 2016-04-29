%{
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int linecount=0;
char table[MAX][200];
char replacement[MAX][4];
int v[MAX]={0},vcount=0;
%}

//tokens to be returned by Lexical analyser
%token INT UNSIGNED BOOL VOID
%token WHILE COMMA
%token IF ELSE PRINTF SWITCH CASE BREAK 
%token ADD SUB MUL DIV
%token DEFAULT
%token NUM ID
%token INCLUDE MAIN
%token DOT NOT
%token ASSIGN

//associativity of operators
%right ASSIGN
%left AND OR
%union{
	char *str;
}
%left '<' '>' LE GE EQ NE LT GT

%%
//...........................................................................................................................................

//starting symbol of the grammar
start :	declaration start
	  |	main start
	  |
	  ;

//main is the only function that is allowed in C1 language
main  :	INT	MAIN '(' ')' block
	  ;

//set of statements enclosed within a pair of braces
block : '{' stmts '}'
	  ;

//syntax for declararing a variable
declaration :	type declarations ';'
			;

//types allowed			
type :	INT
	 |	UNSIGNED
	 |	BOOL
	 |	VOID
	 ;

//declarations may comprise of either simple declaration,or variable can be assigned some value at the time of declaration
//multiple declarations will be separated by ,
declarations : ID{insert_into_symbol_table($<str>1);check_if_declared($<str>1);} ',' declarations
			 | assignment_declr ',' declarations
			 | ID{insert_into_symbol_table($<str>1);check_if_declared($<str>1);}
			 | assignment_declr
			 ;

//for declarations of form  int a=5; symbol table needs to be referred
assignment_declr :	ID{insert_into_symbol_table($<str>1),check_if_declared($<str>1);IDpush($<str>1);} ASSIGN expr{assignment();}	
		   ;
//assignment of the form ID = EXPR
assignment :	ID{IDpush($<str>1);check_if_declared($<str>1);} ASSIGN expr{assignment();}	
		   ;	   

//expressions like ID+=EXPR
shorthand :		ID{IDpush($<str>1);check_if_declared($<str>1);} ADD expr{shorthand1();}
		  |		ID{IDpush($<str>1);check_if_declared($<str>1);} SUB expr{shorthand2();}
		  |		ID{IDpush($<str>1);check_if_declared($<str>1);} MUL expr{shorthand3();}
		  | 	ID{IDpush($<str>1);check_if_declared($<str>1);} DIV expr{shorthand4();}
		  ;		   	

//set of statements
stmts : stmt stmts
	  |
	  ;

//a statement can take any of the listed forms
stmt  :	assignment ';'
	  |	declaration
	  | shorthand ';'
	  | while
	  | if
	  | switch
	  ;  
//grammar for an expressions considering precedence of operators
expr  : expr AND{push();} E{expressions();}
	  | expr OR{push();}  E{expressions();}
	  | E
	  ;

E 	  : E '|'{push();} F{expressions();}
	  | E '^'{push();} F{expressions();}
	  | E '&'{push();} F{expressions();}
	  | E '~'{push();} F{expressions();}
	  | F
	  ;

F 	  : F LE{push();} G{expressions();}
	  |	F GE{push();} G{expressions();}
	  | F EQ{push();} G{expressions();}
	  | F NE{push();} G{expressions();}
	  | F LT{push();} G{expressions();}
	  | F GT{push();} G{expressions();}
	  | G
	  ;

G 	  : G '+'{push();} H{expressions();}	
	  | G '-'{push();} H{expressions();}
	  | H
	  ;

H 	  : H '*'{push();} I{expressions();} 
	  | H '/'{push();} I{expressions();} 
	  | I
	  ;	

I 	  : J '@'{push();} I{expressions();} 
	  | J
	  ;

J 	  : '(' expr ')'
	  | ID{IDpush();check_if_declared($<str>1);}
	  | NUM{push();}
	  ;	

//while loop construct
while : WHILE {while_label1();} '(' expr ')'{while_label2();} whilefactor
	  ;
//to eliminate shift/reduce conflict	  
whilefactor : block{while_label3();}
			| stmt{while_label3();}
			;	

//grammar for if-else
if    : IF '(' expr ')'{if_label1();} block factor
	  ;

//to eliminate shift/reduce conflict
factor :{if_label3();}
	   |{if_label2();}ELSE block{if_label3();}
	   ;

//structure of switch statement
switch : SWITCH '(' ID ')'{switch_push();} '{' cases switchfactor
	   ;

//to eliminate shift/reduce conflict	      
switchfactor : '}'{exit_switch();}
			 | default '}'{exit_switch();}

//set of cases
cases  : case cases
	   |
	   ;

case   : CASE NUM {label_switch2();} {extra_label_switch();} ':' stmts break	  
	   ;

//default case can also be present
default : DEFAULT ':' stmts 
		;	

//to take different action if break statement is present		
break : BREAK ';'{switch_break();} {label_switch1();}
	  | {without_break();} {label_switch1();}
	  ;		   	 

%%
//...........................................................................................................................................

#include"lex.yy.c"
#include <ctype.h>
int count=0;

char st[100][10];
int top=0;
int i=0;
char temp[2]="t";

int label[20];
int lnum=0;
int ltop=0;

int eslnum = 0;
int prev_break = 1;
char switch_stack[10][10];
int switch_stack_top = 0;

char symbolTable[100][20];
int size = 0;
int line=0;

int main(int argc, char *argv[])
{
   char ch;
   yyin = fopen(argv[1], "r");
   if(!yyparse())
   {
	    printf("\nParsing completed successfully\n");
		printf("\nEnter any key to generate intermediate code....\n");
		scanf("%c",&ch);
		printf("\nIntermediate code :\n");
		backpatch();
	}
	else
		printf("\nParsing failed\n");

	fclose(yyin);
    return 0;
}

//for printing error messages        
yyerror(char *s) 
{
	printf("%d : %s %s\n", yylineno, s, yytext );
}  

//insert each declared variable in the table,and give error if already declared
insert_into_symbol_table(char *str)
{
	int i=0;
	for(;i<size;i++)
	{
		if(strcmp(symbolTable[i],str)==0)
		{
			printf("Error line(%d): %s is redeclared\n",yylineno, str);
			exit(0);
		}
	}
	printf("%s added to symbol table\n",str);
	strcpy(symbolTable[size++],str);
}

//checks whether an identifier is declared or not by scanning the symbol table
check_if_declared(char *str)
{
	int i=0;
	for(;i<size;i++)
	{
		if(strcmp(symbolTable[i],str)==0)
			break;
	}
	if(i==size)
	{
		printf("Error line(%d): %s not declared \n",yylineno, str);
		exit(0);
	}
}

//to generate target line no for goto statements and place them appropriately
backpatch()
{
	int i;
	for(i=0;i<linecount;i++)
	{
		if((table[i][0]=='L')||(table[i][0]=='E'))
		{
			int num=0,index=1;
			if(table[i][index]=='L')
				index++;
			while(isdigit(table[i][index]))
			{
				num=10*num+table[i][index++]-'0';
			}
			v[i]=1;
			char str[10];
			sprintf(str,"%d",line);
			strcpy(replacement[num],str);
		}
		else
			line++;
	}
    line=0;
	for(i=0;i<linecount;i++)
	{
		if(!v[i])
		{
			int j;
			for(j=0;j<strlen(table[i]);j++)
			{
				if((table[i][j]=='L')||(table[i][j]=='E'))
				{
					int num=0,index=j+1;
					if(table[i][index]=='L')
						index++;
					while(isdigit(table[i][index]))
					{
						num=10*num+table[i][index++]-'0';
					}
					sprintf(table[i]+j,"%s",replacement[num]);

				}
			}
			printf("%d\t%s\n",line++,table[i]);
		}
	}
}  

//push current literal on the stack   
push()
{
  	strcpy(st[++top],yytext);
  	yytext[0]='\0';
}

//push identifier
IDpush(char *str)
{
  	strcpy(st[++top],str);
  	yytext[0]='\0';
}

//for expressions of the for ID = ID1 operator ID2 ie. 2 operands on right side
expressions()
{
 	sprintf(temp,"t%d",i);
  	sprintf(table[linecount],"%s = %s %s %s",temp,st[top-2],st[top-1],st[top]);
  	linecount++;
  	top-=2;
 	strcpy(st[top],temp);
 	i++;
}

//single operand on right hand side
assignment()
{
 	sprintf(table[linecount],"%s = %s",st[top-1],st[top]);
 	linecount++;
 	top-=1;
}

//to generate intermediate for shorthand statements
//for +=
shorthand1()
{
	sprintf(table[linecount],"%s = %s + %s",st[top-1],st[top-1],st[top]);
 	linecount++;
 	top-=1;
}

//for -=
shorthand2()
{
	sprintf(table[linecount],"%s = %s - %s",st[top-1],st[top-1],st[top]);
 	linecount++;
 	top-=1;
}

//for *=
shorthand3()
{
	sprintf(table[linecount],"%s = %s * %s",st[top-1],st[top-1],st[top]);
 	linecount++;
 	top-=1;
}

//for /=
shorthand4()
{
	sprintf(table[linecount],"%s = %s / %s",st[top-1],st[top-1],st[top]);
 	linecount++;
 	top-=1;
}

//will generate label at the start of the loop,where jump has to be made after each iteration.	  
while_label1()
{
	lnum++;
	sprintf(table[linecount],"L%d:",lnum);
	linecount++;
	label[ltop++] = lnum++;
}

//while_label2() will generate jump using goto based on condition inside a pair of parentheses.
while_label2()
{
 	sprintf(temp,"t%d",i);
 	sprintf(table[linecount],"%s = not %s",temp,st[top]);
 	linecount++;
 	sprintf(table[linecount],"if %s goto L%d",temp,lnum);
 	linecount++;
 	label[ltop++] = lnum;
 	i++;
}

//while_label3() will generate label at the end of loop where control needs to be transferred when condition becomes false.
while_label3()
{
	sprintf(table[linecount],"goto L%d",label[ltop-2]);
	linecount++;
	sprintf(table[linecount],"L%d:",label[ltop-1]);
	linecount++;
	ltop = ltop-2;
}
if_label1()
{
 	lnum++;
 	sprintf(temp,"t%d",i);
 	sprintf(table[linecount],"%s = not %s",temp,st[top]);
 	linecount++;
 	sprintf(table[linecount],"if %s goto L%d",temp,lnum);
 	linecount++;
 	i++;
 	label[++ltop]=lnum;
}
if_label2()
{
	int x;
	lnum++;
	x=label[ltop--];
	sprintf(table[linecount],"goto L%d",lnum);
	linecount++;
	sprintf(table[linecount],"L%d: ",x); 
	linecount++;
	label[++ltop]=lnum;
}
if_label3()
{
	int y;
	y=label[ltop--];
	sprintf(table[linecount],"L%d: ",y);
	linecount++;
}
switch_push()
{
	strcpy(switch_stack[switch_stack_top++],st[top]);
}
label_switch1()
{
	sprintf(table[linecount],"L%d :",lnum++);
	linecount++;
}
label_switch2()
{
	lnum++;
 	sprintf(temp,"t%d",i);
 	sprintf(table[linecount],"if %s != %s goto L%d ",switch_stack[switch_stack_top-1],yytext,lnum);
 	linecount++;
 	i++;
}
extra_label_switch()
{
	if(prev_break==0)
	sprintf(table[linecount],"L%d:",lnum-1);
	linecount++;
}
without_break()
{
	sprintf(table[linecount],"goto L%d ",lnum+1);
	linecount++;
	prev_break = 0;
}
switch_break()
{
	sprintf(table[linecount],"goto EL%d ",eslnum);
	linecount++;
	prev_break = 1;
}
exit_switch()
{
	sprintf(table[linecount],"EL%d",eslnum++);
	linecount++;
}


