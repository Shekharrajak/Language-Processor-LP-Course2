%{
# define AUTHOR				"Avinash Yadav"
# define ROLL_NUMBER		"127210"
# define ENGG_BRANCH		"Computer Science And Engineering (CSE)"
# define CLASS_AND_SECTION	"B Tech, (3/4), CSE - B"
# define APP_NAME			"Language Processors Major Assignment: Intermediate Code Generation"
# define ACADEMIC_SESSION	"2014-2015"
# define INSTITUTE			"NIT Warangal"

void printBanner();									//-->This function prints the App Banner.

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "myStruct.h"

char code[MAX_CODE_LENGTH] = "\0";					//-->This variable stores the final generated intermediate code.
char tempCode[MAX_CODE_LENGTH / 1000 + 1] ="\0";	//-->This variable stores the temporary intermediate code for the currently
													//executing grammar rule.
int  tempIdCount = -1;								//-->This variable keeps count of number of temporary variables gernerated.
int  spaceCount = 0;								//-->This variable stores the count of spaces to be given during indentation
													//in the function 'indentCode()'.
int  isCommentVisible = 1;							//-->This variable acts as a flag for enabling (value = 1) or disabling (value = 0)
													//the comment adding functionality of the function 'addComment()'.
char tempComment[(MAX_CODE_LENGTH / 1000 + 1) / 2];	//-->This variable will hold any temporary comments if needed in 'addComment()'

int  calcPow(int, int);								//-->This function calculates the power of a given number (eg: 2 @ 3 = 8).
void genrateCode(YYSTYPE*, YYSTYPE*, YYSTYPE*, YYSTYPE*, char*);	//-->This function generates the intermediate code for a binary
																	//expression and stores it in the array 'tempCode'.
void indentCode();									//-->This function adds indentation to the intermediate code.
void concatCode();									//-->This function concatenates 'tempCode' to 'code'.
void addComment(const char*);						//-->This function adds comments to the intermediate code if 'isCommentVisible == 1'.

# define MAX_NUM_OF_LABELS 10
# define LABEL_STACK_SIZE 100
struct Labels
{	int l[MAX_NUM_OF_LABELS];	};					//-->Structure to hold a number of labels.
struct Labels labelStack[LABEL_STACK_SIZE];			//-->This variable acts like a stack of labels.
struct Labels tempLabels;							//-->This variable stores labels temporarily.
int  labelStackTop = -1;							//-->This variable acts as the iterator of the 'labelStack'.
int  labelCount = 0;								//-->This variable keeps a count of the number of labels generated.
void pushLabel(int, int);							//-->This function pushes a number of labels to the stack variable 'labelStack'.
void popLabel();									//-->This function pops the top of 'labelStack' and stores the labels in 'tempLabels'.

# define ID_STACK_SIZE 1000
char idStack[ID_STACK_SIZE][MAX_LENGTH_OF_ID_NAME];	//-->This variable acts like a stack of variable names.
char currentId[MAX_LENGTH_OF_ID_NAME];				//-->This variable stores the currently active variable name (used in 'switch'
													//grammar).
int  idStackTop = -1;								//-->This variable acts as the iterator of 'idStack'.
void pushId();										//-->This function pushes the identifier name stored in 'currentId' to the top of
													//'idStack'.
void popId();										//-->This function pops a variable name from the 'idStack' and stores it in 
													//'currentId'.
int  switchExitLabel;								//-->This variable stores the exit label of the currently active 'switch' statement.
int  fallThroughLabel;								//-->This variable stores the fall-through label for a 'case' statement.

# define MAX_FIELD_LEN 120
%}

/* declare tokens */
//Refer to 'lexfile.l' for the explanation of the tokens.
%token KW_BOOL KW_INT KW_U_INT
%token KW_VAL_TRUE KW_VAL_FALSE
%token KW_IF KW_ELSE
%token KW_SWITCH KW_CASE KW_DEFAULT KW_BREAK
%token KW_WHILE
%token IDENTIFIER
%token NUMBER
%token IS_ASSIGNED PLUS_ASSIGNED MINUS_ASSIGNED MULTIPLY_ASSIGNED DIVIDE_ASSIGNED
%token ADD SUB MUL DIV POW
%token BOOL_OR BOOL_AND BOOL_NOT
%token BITWISE_OR BITWISE_XOR BITWISE_AND BITWISE_NOT
%token IS_GREATER_THAN IS_GREATER_THAN_OR_EQUAL_TO IS_LESS_THAN IS_LESS_THAN_OR_EQUAL_TO IS_EQUAL_TO IS_NOT_EQUAL_TO
%token SEMI_COLON COLON COMMA OPEN_PARANTHESIS CLOSE_PARANTHESIS OPEN_BRACE CLOSE_BRACE

%%
block:				/* epsilon */
				|	block OPEN_BRACE statements CLOSE_BRACE
					{
						printf("\nINTERMEDIATE CODE:\n%s\n", code);
						
						//Resetting all int variables.
						tempIdCount = -1;
						labelCount = 0;
						spaceCount = 0;
						labelStackTop = -1;
						idStackTop = -1;
						
						//Resetting all structure and array variables.
						memset(code, 0, sizeof(code));
						memset(tempCode, 0, sizeof(tempCode));
						memset(&labelStack, 0, sizeof(labelStack));
						memset(&tempLabels, 0, sizeof(tempLabels));
						memset(&idStack, 0, sizeof(idStack));
						memset(tempComment, 0, sizeof(tempComment));
						
						//Resetting all usable pseudo-variables.
						memset(&$$, 0, sizeof($$));
						memset(&$1, 0, sizeof($1));
						memset(&$2, 0, sizeof($2));
						memset(&$3, 0, sizeof($3));
						memset(&$4, 0, sizeof($4));
						
						printf("\nEnter code in Subset-C language (Ctrl+C to exit)\n");
						printf("main()\n");
					}
				;


/* The Grammar Definition begins from here */

/* S -> S X | epsilon */
statements:			/* epsilon */
				|	statements exec_statements /* one or more exec_statments */
				;

/* X -> ( S ) | s */
exec_statements:		OPEN_BRACE statements CLOSE_BRACE	/* a block of statements */
					|	statement							/* a single statement */
					;


/* s -> ; | D ; | A ; | E ; | C | L | Sw */
statement:			SEMI_COLON								/* an empty statement */
				|	declaration SEMI_COLON					/* a declaration statement */
				|	assignment SEMI_COLON					/* an assignment statement */
				|	expression SEMI_COLON					/* an expression statement */
				|	conditional								/* a conditional statement: if-else */
				|	loop									/* a loop statement: while */
				|	switch									/* a switch statement: switch-case-default */
				;

/* D -> T Ids */
declaration:		type identifiers
					{
						$2.type = $1.type;
					}
				;

/* T -> bool | int | u_int */
type:				KW_BOOL
				|	KW_INT
				|	KW_U_INT
				;

/* Ids -> I | I , Ids */
identifiers:		IDENTIFIER						/* a single identifier */
					{
						$1.type = $$.type;
					}
				|	IDENTIFIER COMMA identifiers	/* list of identifiers */
					{
						$1.type = $$.type;
						$3.type = $$.type;
					}
				;
/* A -> I = E | I += E | I -= E | I *= E | I /= E */
assignment:			IDENTIFIER IS_ASSIGNED expression
					{	
						$1.val = $3.val;			//value assignment
						if($3.varName[0] == '\0')	//TRUE if 'expression' has no valid variable name
							sprintf(tempCode,"%s = %d\n", $1.varName, $3.val);		//eg: a = 10
						else						//TRUE if 'expression' has a valid variable name
							sprintf(tempCode,"%s = %s\n", $1.varName, $3.varName);	//eg: a = b
						concatCode();				//concatenate 'tempCode' with 'code'
					}
				|	IDENTIFIER PLUS_ASSIGNED expression
					{	
						$1.val += $3.val;										//value calculation and assignment
						$2.oprtr[1] = '\0';										//Convert the operator from += to +
						genrateCode(&$$, &$1, &$2, &$3, tempCode);				//generate code for addition in 'tempCode'
						concatCode();											//concatenate 'tempCode' with 'code'
						sprintf(tempCode, "%s = %s\n", $1.varName, $$.varName);	//generate code for assignment in 'tempCode'
						concatCode();											//concatenate 'tempCode' with 'code'
					}
				|	IDENTIFIER MINUS_ASSIGNED expression
					{
						$1.val -= $3.val;										//value calculation and assignment
						$2.oprtr[1] = '\0';										//Convert the operator from -= to -
						genrateCode(&$$, &$1, &$2, &$3, tempCode);				//generate code for subtraction in 'tempCode'
						concatCode();											//concatenate 'tempCode' with 'code'
						sprintf(tempCode, "%s = %s\n", $1.varName, $$.varName);	//generate code for assignment in 'tempCode'
						concatCode();											//concatenate 'tempCode' with 'code'
					}
				|	IDENTIFIER MULTIPLY_ASSIGNED expression
					{
						$1.val *= $3.val;										//value calculation and assignment
						$2.oprtr[1] = '\0';										//Convert the operator from *= to *
						genrateCode(&$$, &$1, &$2, &$3, tempCode);				//generate code for multiplication in 'tempCode'
						concatCode();											//concatenate 'tempCode' with 'code'
						sprintf(tempCode, "%s = %s\n", $1.varName, $$.varName);	//generate code for assignment in 'tempCode'
						concatCode();											//concatenate 'tempCode' with 'code'
					}
				|	IDENTIFIER DIVIDE_ASSIGNED expression
					{
						$1.val /= $3.val;										//value calculation and assignment
						$2.oprtr[1] = '\0';										//Convert the operator from /= to /
						genrateCode(&$$, &$1, &$2, &$3, tempCode);				//generate code for division in 'tempCode'
						concatCode();											//concatenate 'tempCode' with 'code'
						sprintf(tempCode, "%s = %s\n", $1.varName, $$.varName);	//generate code for assignment in 'tempCode'
						concatCode();											//concatenate 'tempCode' with 'code'
					}
				;

/* E -> T1 | E || T1 */
expression:		term01
			|	expression
				{
					//Whenever there is a possibility of going into a nested level, the currently allocated labels are
					//pushed into the stack: 'labelStack'
						
					pushLabel(labelCount, 2);	//2 labels starting at the number 'labelCount' are created and pushed to the 'labelStack'
					labelCount += 2;			//'labelCount' incremented by 2
					
					sprintf($$.varName, "t%d", ++tempIdCount);	//assigning a variable name to the LHS
					
					strcpy(currentId, $$.varName);				//The variable name of the LHS is stored in 'currentId' and
					pushId();									//pushed on to the 'idStack' for future reference.
					
					if($1.varName[0] != '\0')	//TRUE if operand1 has a valid variable name
						sprintf(tempCode, "if %s isFalse goto L%d", $1.varName, labelStack[labelStackTop].l[0]);
					else						//TRUE if operand1 has no valid variable name
						sprintf(tempCode, "if %d isFalse goto L%d", $1.val, labelStack[labelStackTop].l[0]);
					//'labelStack[labelStackTop].l[0]' contains the label referring to the start of the second term
					
					addComment(" /* to_start_of_second_term */");			//adding comments to code
					strcat(tempCode,"\n");
					
					concatCode();											//concatenate 'tempCode' with 'code'
					
					++spaceCount;											//increment 'spaceCount' for indentation
																			//when going in a deeper block
					
					sprintf(tempCode, "%s = true\n", $$.varName);			//if the first term is TRUE the second term need not be 
																			//evaluated. The expression is assigned TRUE and control is 
																			//transferred to the end of the expression.
																			
					concatCode();											//concatenate 'tempCode' with 'code'
					
					--spaceCount;											//decrement 'spaceCount' for indentation
																			//when coming out of a deeper block
					
					sprintf(tempCode, "goto L%d", labelStack[labelStackTop].l[1]);
					//'labelStack[labelStackTop].l[1]' contains the label referring to the end of the expression
					
					
					addComment(" /* to_end_of_expression */");				//adding comments to code
					strcat(tempCode,"\n");
					
					concatCode();											//concatenate 'tempCode' with 'code'
					
					sprintf(tempCode, "L%d:", labelStack[labelStackTop].l[0]);
					//'labelStack[labelStackTop].l[0]' contains the label referring to the start of the second term
					
					addComment(" /* start_of_second_term */");				//adding comments to code
					strcat(tempCode,"\n");
					
					concatCode();											//concatenate 'tempCode' with 'code'
					
					++spaceCount;											//increment 'spaceCount' for indentation
																			//when going in a deeper block
				}
				BOOL_OR term01
				{
					//The labels that were pushed are popped back into the 'tempLabels' variable when coming out of a
					//nested level and they can be reused from the position at which they were pushed
						
					popLabel();
					
					//The identifier name that was pushed is popped back into the 'currentId' variable when coming out of a
					//nested level and it can be reused from the position at which it was pushed
						
					popId();
					strcpy($$.varName, currentId);							//The name is copied back to the LHS variable name
					
					sprintf(tempCode, "%s = %s\n", $$.varName, (($4.varName[0] == '\0')?($4.val == 0?"false":"true"):$4.varName));
					//If $4 (operand2) has a variable name, it is printed, else its value is checked and 'true'/'false' is
					//printed accordingly.
					concatCode();											//concatenate 'tempCode' with 'code'
					
					--spaceCount;											//decrement 'spaceCount' for indentation
																			//when coming out of a deeper block
					
					sprintf(tempCode, "L%d:", tempLabels.l[1]);				//'tempLabels.l[0]' contains the label referring to 
																			//the end of the expression
					
					addComment(" /* end_of_expression */");					//adding comments to code
					strcat(tempCode,"\n");
					
					concatCode();											//concatenate 'tempCode' with 'code'
					
					$$.val = $1.val || $3.val;								//value calculation and assignment
				}
				/*{
					$$.val = $1.val || $3.val;								//value calculation and assignment
					genrateCode(&$$, &$1, &$2, &$3, tempCode);				//generate code for Boolean OR in 'tempCode'
					concatCode();											//concatenate 'tempCode' with 'code'
				}*/
			;

/* T1 -> T2 | T1 && T2 */
term01:			term02
			|	term01
				{
					//Whenever there is a possibility of going into a nested level, the currently allocated labels are
					//pushed into the stack: 'labelStack'
						
					pushLabel(labelCount, 2);	//2 labels starting at the number 'labelCount' are created and pushed to the 'labelStack'
					labelCount += 2;			//'labelCount' incremented by 2
					
					sprintf($$.varName, "t%d", ++tempIdCount);	//assigning a variable name to the LHS
					
					strcpy(currentId, $$.varName);				//The variable name of the LHS is stored in 'currentId' and
					pushId();									//pushed on to the 'idStack' for future reference.
					
					if($1.varName[0] != '\0')	//TRUE if operand1 has a valid variable name
						sprintf(tempCode, "if %s isTrue goto L%d", $1.varName, labelStack[labelStackTop].l[0]);
					else						//TRUE if operand1 has no valid variable name
						sprintf(tempCode, "if %d isTrue goto L%d", $1.val, labelStack[labelStackTop].l[0]);
					//'labelStack[labelStackTop].l[0]' contains the label referring to the start of the second term
					
					addComment(" /* to_start_of_second_term */");			//adding comments to code
					strcat(tempCode,"\n");
					
					concatCode();											//concatenate 'tempCode' with 'code'
					
					++spaceCount;											//increment 'spaceCount' for indentation
																			//when going in a deeper block
					
					sprintf(tempCode, "%s = false\n", $$.varName);			//if the first term is FALSE the second term need not be 
																			//evaluated. The expression is assigned FALSE and control is 
																			//transferred to the end of the expression.
																			
					concatCode();											//concatenate 'tempCode' with 'code'
					
					--spaceCount;											//decrement 'spaceCount' for indentation
																			//when coming out of a deeper block
					
					sprintf(tempCode, "goto L%d", labelStack[labelStackTop].l[1]);
					//'labelStack[labelStackTop].l[1]' contains the label referring to the end of the expression
					
					
					addComment(" /* to_end_of_expression */");				//adding comments to code
					strcat(tempCode,"\n");
					
					concatCode();											//concatenate 'tempCode' with 'code'
					
					sprintf(tempCode, "L%d:", labelStack[labelStackTop].l[0]);
					//'labelStack[labelStackTop].l[0]' contains the label referring to the start of the second term
					
					addComment(" /* start_of_second_term */");				//adding comments to code
					strcat(tempCode,"\n");
					
					concatCode();											//concatenate 'tempCode' with 'code'
					
					++spaceCount;											//increment 'spaceCount' for indentation
																			//when going in a deeper block
				}
				BOOL_AND term02
				{
					//The labels that were pushed are popped back into the 'tempLabels' variable when coming out of a
					//nested level and they can be reused from the position at which they were pushed
						
					popLabel();
					
					//The identifier name that was pushed is popped back into the 'currentId' variable when coming out of a
					//nested level and it can be reused from the position at which it was pushed
						
					popId();
					strcpy($$.varName, currentId);							//The name is copied back to the LHS variable name
					
					sprintf(tempCode, "%s = %s\n", $$.varName, (($4.varName[0] == '\0')?($4.val == 0?"false":"true"):$4.varName));
					//If $4 (operand2) has a variable name, it is printed, else its value is checked and 'true'/'false' is
					//printed accordingly.
					concatCode();											//concatenate 'tempCode' with 'code'
					
					--spaceCount;											//decrement 'spaceCount' for indentation
																			//when coming out of a deeper block
					
					sprintf(tempCode, "L%d:", tempLabels.l[1]);				//'tempLabels.l[0]' contains the label referring to 
																			//the end of the expression
					
					addComment(" /* end_of_expression */");					//adding comments to code
					strcat(tempCode,"\n");
					
					concatCode();											//concatenate 'tempCode' with 'code'
					
					$$.val = $1.val && $3.val;								//value calculation and assignment
					
				}
				/*{
					$$.val = $1.val && $3.val;								//value calculation and assignment
					genrateCode(&$$, &$1, &$2, &$3, tempCode);				//generate code for Boolean AND in 'tempCode'
					concatCode();											//concatenate 'tempCode' with 'code'
				}*/
			;

/* T2 -> T3 | T2 | T3 */
term02:			term03
			|	term02 BITWISE_OR term03
				{
					$$.val = $1.val | $3.val;								//value calculation and assignment
					genrateCode(&$$, &$1, &$2, &$3, tempCode);				//generate code for Bitwise OR in 'tempCode'
					concatCode();											//concatenate 'tempCode' with 'code'
				}
			; 

/* T3 -> T4 | T3 ^ T4 */
term03:			term04
			|	term03 BITWISE_XOR term04
				{	$$.val = $1.val ^ $3.val;								//value calculation and assignment
					genrateCode(&$$, &$1, &$2, &$3, tempCode);				//generate code for Bitwise XOR in 'tempCode'
					concatCode();											//concatenate 'tempCode' with 'code'
				}
			; 

/* T4 -> T5 | T4 & T5 */
term04:			term05
			|	term04 BITWISE_AND term05
				{	$$.val = $1.val & $3.val;								//value calculation and assignment
					genrateCode(&$$, &$1, &$2, &$3, tempCode);				//generate code for Bitwise AND in 'tempCode'
					concatCode();											//concatenate 'tempCode' with 'code'
				}
			; 

/* T5 -> T6 | T5 == T6 | T5 != T6 */
term05:			term06
			|	term05 IS_EQUAL_TO term06
				{
					$$.val = $1.val == $3.val;								//value calculation and assignment
					genrateCode(&$$, &$1, &$2, &$3, tempCode);				//generate code for == in 'tempCode'
					concatCode();											//concatenate 'tempCode' with 'code'
				}
			|	term05 IS_NOT_EQUAL_TO term06
				{
					$$.val = $1.val != $3.val;								//value calculation and assignment
					genrateCode(&$$, &$1, &$2, &$3, tempCode);				//generate code for != in 'tempCode'
					concatCode();											//concatenate 'tempCode' with 'code'
				}
			; 

/* T6 -> T7 | T6 < T7 | T6 <= T7 | T6 > T7 | T6 >= T7 */
term06:			term07
			|	term06 IS_LESS_THAN term07
				{
					$$.val = $1.val < $3.val;								//value calculation and assignment
					genrateCode(&$$, &$1, &$2, &$3, tempCode);				//generate code for < in 'tempCode'
					concatCode();											//concatenate 'tempCode' with 'code'
				}
			|	term06 IS_LESS_THAN_OR_EQUAL_TO term07
				{
					$$.val = $1.val <= $3.val;								//value calculation and assignment
					genrateCode(&$$, &$1, &$2, &$3, tempCode);				//generate code for <= in 'tempCode'
					concatCode();											//concatenate 'tempCode' with 'code'
				}
			|	term06 IS_GREATER_THAN term07
				{
					$$.val = $1.val > $3.val;								//value calculation and assignment
					genrateCode(&$$, &$1, &$2, &$3, tempCode);				//generate code for > in 'tempCode'
					concatCode();											//concatenate 'tempCode' with 'code'
				}
			|	term06 IS_GREATER_THAN_OR_EQUAL_TO term07
				{
					$$.val = $1.val >= $3.val;								//value calculation and assignment
					genrateCode(&$$, &$1, &$2, &$3, tempCode);				//generate code for >= in 'tempCode'
					concatCode();											//concatenate 'tempCode' with 'code'
				}
			; 

/* T7 -> T8 | T7 + T8 | T7 - T8 */
term07:			term08
			|	term07 ADD term08
				{	
					$$.val = $1.val + $3.val;								//value calculation and assignment
					genrateCode(&$$, &$1, &$2, &$3, tempCode);				//generate code for addition in 'tempCode'
					concatCode();											//concatenate 'tempCode' with 'code'
				}
			|	term07 SUB term08
				{	
					$$.val = $1.val - $3.val;								//value calculation and assignment
					genrateCode(&$$, &$1, &$2, &$3, tempCode);				//generate code for subtraction in 'tempCode'
					concatCode();											//concatenate 'tempCode' with 'code'
				}
			; 

/* T8 -> T9 | T8 * T9 | T8 / T9 */
term08:			term09
			|	term08 MUL term09
				{
					$$.val = $1.val * $3.val;								//value calculation and assignment
					genrateCode(&$$, &$1, &$2, &$3, tempCode);				//generate code for multiplication in 'tempCode'
					concatCode();											//concatenate 'tempCode' with 'code'
				}
			|	term08 DIV term09
				{	
					if($3.val != 0)
						$$.val = $1.val / $3.val;							//value calculation and assignment
					genrateCode(&$$, &$1, &$2, &$3, tempCode);				//generate code for division in 'tempCode'
					concatCode();											//concatenate 'tempCode' with 'code'
				}
			; 

/* T9 -> T10 | T10 @ T9 */
term09:			term10
			|	term10 POW term09
				{	
					$$.val = calcPow($1.val, $3.val);						//value calculation and assignment
					genrateCode(&$$, &$1, &$2, &$3, tempCode);				//generate code for exponentiation in 'tempCode'
					concatCode();											//concatenate 'tempCode' with 'code'
				}
			; 

/* T10 -> T11 | ! T10 | ~ T10 */
term10:			term11
			|	BOOL_NOT term10
				{	
					$$.val = ! $2.val;								//value calculation and assignment
					++tempIdCount;									//increment 'tempIdCount'
					sprintf($$.varName,"t%d", tempIdCount);			//create new temporary variable
					if($2.varName[0] == '\0')						//TRUE if 'term10' has no valid variable name
						sprintf(tempCode,"%s = %s %d\n", $$.varName, $1.oprtr, $2.val);//eg: a = ! b
					else											//TRUE if 'term10' has a valid variable name
						sprintf(tempCode,"%s = %s %s\n", $$.varName, $1.oprtr, $2.varName);//eg: a = ! 10
					concatCode();									//concatenate 'tempCode' with 'code'
				}
			|	BITWISE_NOT term10
				{	
					$$.val = ~ $2.val;								//value calculation and assignment
					++tempIdCount;									//increment 'tempIdCount'
					sprintf($$.varName,"t%d", tempIdCount);			//create new temporary variable
					if($2.varName[0] == '\0')						//TRUE if 'term10' has no valid variable name
						sprintf(tempCode,"%s = %s %d\n", $$.varName, $1.oprtr, $2.val);//eg: a = ~ b
					else											//TRUE if 'term10' has a valid variable name
						sprintf(tempCode,"%s = %s %s\n", $$.varName, $1.oprtr, $2.varName);//eg: a = ~ 10
					concatCode();									//concatenate 'tempCode' with 'code'
				}
			; 

/* T11 -> I | N | true | false | ( E ) */
term11:			IDENTIFIER
			|	NUMBER
				{
					$$.val = $1.val;
				}
			|	KW_VAL_TRUE			
				{	
					$$.val = $1.val;
				}
			|	KW_VAL_FALSE
				{
					$$.val = $1.val;
				}
			|	OPEN_PARANTHESIS expression CLOSE_PARANTHESIS
				{
					$$.val = $2.val;
					strcpy($$.varName, $2.varName);
				}
			;

/* C -> if ( E ) X ELSE */
conditional:		KW_IF OPEN_PARANTHESIS expression CLOSE_PARANTHESIS
					{	
						//Whenever there is a possibility of going into a nested level, the currently allocated labels are
						//pushed into the stack: 'labelStack'
						
						pushLabel(labelCount, 2);//2 labels starting at the number 'labelCount' are created and pushed to the 'labelStack'
						labelCount += 2;//the 'labelCount' is incremented by 2
						if($3.varName[0] != '\0')//TRUE if 'expression' has a valid variable name
							sprintf(tempCode,"if %s isFalse goto L%d", $3.varName, labelStack[labelStackTop].l[0]);
						else//TRUE if 'expression' has no valid variable name
							sprintf(tempCode,"if %d isFalse goto L%d", $3.val, labelStack[labelStackTop].l[0]);
						//The label in 'l[0]' of 'labelStack[labelStackTop]' is the start label of the
						//else part of the conditional statement.
						addComment(" /* to_start_of_else */");					//adding comments to code
						strcat(tempCode,"\n");
						concatCode();											//concatenate 'tempCode' with 'code'
						++spaceCount;											//increment 'spaceCount' for indentation
																				//when going in a deeper block
					}
					exec_statements /* replace with 'OPEN_BRACE statements CLOSE_BRACE' to remove SR conflict*/
					{	
						popLabel();//the labels stored at the top of 'labelStack' are popped into 'tempLabels'
						sprintf(tempCode,"goto L%d", tempLabels.l[1]);
						//The label in 'l[1]' of 'tempLabels' is the end label of the
						//of the conditional statement.
						--spaceCount;											//decrement 'spaceCount' for indentation
																				//when coming out of a deeper block
						addComment(" /* to_end_of_if */");						//adding comments to code
						strcat(tempCode,"\n");
						concatCode();											//concatenate 'tempCode' with 'code'
					}
					{	
						//Whenever there is a possibility of going into a nested level, the currently allocated labels are
						//pushed into the stack: 'labelStack'
						
						pushLabel(tempLabels.l[0], 2);//the same labels that were created at the beginning of the conditional statement
						//and are currently also available in the 'tempLabels' are pushed back again
						sprintf(tempCode,"L%d:", labelStack[labelStackTop].l[0]);
						//The label in 'l[0]' of 'labelStack[labelStackTop]' is the start label of the
						//else part of the conditional statement.
						addComment(" /* start_of_else */");						//adding comments to code
						strcat(tempCode,"\n");
						concatCode();											//concatenate 'tempCode' with 'code'
						++spaceCount;											//increment 'spaceCount' for indentation
																				//when going in a deeper block
					}
					else
					{	
						//The labels that were pushed are popped back into the 'tempLabels' variable when coming out of a
						//nested level and they can be reused from the position at which they were pushed
						
						popLabel();//the labels stored at the top of 'labelStack' are popped into 'tempLabels'
						sprintf(tempCode,"L%d:", tempLabels.l[1]);
						//The label in 'l[1]' of 'tempLabels' is the end label of the
						//of the conditional statement.
						--spaceCount;											//decrement 'spaceCount' for indentation
																				//when coming out of a deeper block
						addComment(" /* end_of_if */");							//adding comments to code
						strcat(tempCode,"\n");
						concatCode();											//concatenate 'tempCode' with 'code'
					}
				;

/* ELSE -> epsilon | else X */
else:				/* epsilon */
				|	KW_ELSE exec_statements  /* OPEN_BRACE statements CLOSE_BRACE */
				;

/* L -> while ( E ) X */
loop:				KW_WHILE 
					{
						//Whenever there is a possibility of going into a nested level, the currently allocated labels are
						//pushed into the stack: 'labelStack'
						
						pushLabel(labelCount, 2);//2 labels starting at the number 'labelCount' are created and pushed to the 'labelStack'
						labelCount += 2;//the 'labelCount' is incremented by 2
						sprintf(tempCode,"L%d:", labelStack[labelStackTop].l[0]);
						//The label in 'l[0]' of 'labelStack[labelStackTop]' is the start label of the
						//looping statement.
						addComment(" /* start_of_loop */");						//adding comments to code
						strcat(tempCode,"\n");
						concatCode();											//concatenate 'tempCode' with 'code'
					}
					OPEN_PARANTHESIS expression CLOSE_PARANTHESIS
					{	
						if($4.varName[0] != '\0')//TRUE if 'expression' has a valid variable name
							sprintf(tempCode,"if %s isFalse goto L%d", $4.varName, labelStack[labelStackTop].l[1]);
						else					//TRUE if 'expression' has no valid variable name
							sprintf(tempCode,"if %d isFalse goto L%d", $4.val, labelStack[labelStackTop].l[1]);
						//The label in 'l[1]' of 'labelStack[labelStackTop]' is the end label of the
						//looping statement.
						addComment(" /* to_end_of_loop */");					//adding comments to code
						strcat(tempCode,"\n");
						concatCode();											//concatenate 'tempCode' with 'code'
						++spaceCount;											//increment 'spaceCount' for indentation
																				//when going in a deeper block
					}
					exec_statements
					{	
						//The labels that were pushed are popped back into the 'tempLabels' variable when coming out of a
						//nested level and they can be reused from the position at which they were pushed
						
						popLabel();//the labels stored at the top of 'labelStack' are popped into 'tempLabels'
						--spaceCount;											//decrement 'spaceCount' for indentation
																				//when coming out of a deeper block
						sprintf(tempCode,"goto L%d", tempLabels.l[0]);
						//The label in 'l[0]' of 'tempLabels' is the start label of the
						//loop statement.
						addComment(" /* to_start_of_loop */");					//adding comments to code
						strcat(tempCode,"\n");
						concatCode();											//concatenate 'tempCode' with 'code'
						sprintf(tempCode,"L%d:", tempLabels.l[1]);
						//The label in 'l[1]' of 'tempLabels' is the end label of the
						//loop statement.
						addComment(" /* end_of_loop */");						//adding comments to code
						strcat(tempCode,"\n");
						concatCode();											//concatenate 'tempCode' with 'code'
					} 
				;				

/* Sw -> switch ( I ) { CASES DEFAULT } */
switch:				KW_SWITCH OPEN_PARANTHESIS IDENTIFIER CLOSE_PARANTHESIS
					{
						//Whenever there is a possibility of going into a nested level, the currently active switch 
						//identifier in 'currentId' is pushed on to the 'idStack'
						
						strcpy(currentId, $3.varName);
						pushId();
						
						//Whenever there is a possibility of going into a nested level, the currently allocated labels are
						//pushed into the stack: 'labelStack'
						
						pushLabel(labelCount, 2);//2 labels starting at the number 'labelCount' are created and pushed to the 'labelStack'
						labelCount += 2;//the 'labelCount' is incremented by 2
						
						switchExitLabel  = labelStack[labelStackTop].l[0];
						//The label in 'l[0]' of 'labelStack[labelStackTop]' is the exit label of the
						//switch statement.
						
						fallThroughLabel = labelStack[labelStackTop].l[1];
						//The label in 'l[1]' of 'labelStack[labelStackTop]' is a dummy fall-through
						//label for the first case statement.
						
					}					
					OPEN_BRACE  cases default_case CLOSE_BRACE
					{
						//The identifier name that was pushed is popped back into the 'currentId' variable when coming out of a
						//nested level and it can be reused from the position at which it was pushed
						
						popId();
						
						//The labels that were pushed are popped back into the 'tempLabels' variable when coming out of a
						//nested level and they can be reused from the position at which they were pushed
						
						popLabel();//the labels stored at the top of 'labelStack' are popped into 'tempLabels'
						
						switchExitLabel = tempLabels.l[0];
						//The label in 'l[0]' of 'tempLabels' is the exit label of the
						//switch statement.
						
						sprintf(tempCode, "L%d:", switchExitLabel);
						//'switchExitLabel' is the exit label for the switch
						addComment(" /* switch_exit */");						//adding comments to code
						strcat(tempCode,"\n");
						concatCode();											//concatenate 'tempCode' with 'code'
					}
				;

/* CASES -> epsilon | CASE */				
cases:				/* epsilon */
				|	cases case
				;
				
/* CASE -> case N : S BREAK */
case:				KW_CASE NUMBER COLON
					{
						sprintf(tempCode, "t%d = %s == %d\n", ++tempIdCount, currentId, $2.val);//checking whether the switch variable
						//value matches with the case value.
						concatCode();											//concatenate 'tempCode' with 'code'
						
						//Whenever there is a possibility of going into a nested level, the currently allocated labels are
						//pushed into the stack: 'labelStack'
						
						pushLabel(labelCount, 2);//2 labels starting at the number 'labelCount' are created and pushed to the 'labelStack'
						labelCount += 2;//the 'labelCount' is incremented by 2
						
						sprintf(tempCode, "if t%d isFalse goto L%d", tempIdCount, labelStack[labelStackTop].l[0]);
						//If the result of the matching statement is false jump to the next case statement that comes after the exit
						//label of the 'case'. The exit labeL of the case is stored in 'labelStack[labelStackTop].l[0]'
						addComment(" /* to_end_of_case */");					//adding comments to code
						strcat(tempCode,"\n");
						concatCode();											//concatenate 'tempCode' with 'code'
						sprintf(tempCode, "L%d:", fallThroughLabel);
						//'fallThroughLabel' currently contains the label to which the previous 'case' will fall-through if no 'break'
						//is encountered.
						addComment(" /* fall_through */");						//adding comments to code
						strcat(tempCode,"\n");
						concatCode();											//concatenate 'tempCode' with 'code'
						++spaceCount;											//increment 'spaceCount' for indentation
																				//when going in a deeper block
					} 
					statements break_statement
					{
						//The labels that were pushed are popped back into the 'tempLabels' variable when coming out of a
						//nested level and they can be reused from the position at which they were pushed
						
						popLabel();//the labels stored at the top of 'labelStack' are popped into 'tempLabels'
						--spaceCount;											//decrement 'spaceCount' for indentation
																				//when coming out of a deeper block
						
						fallThroughLabel = tempLabels.l[1];
						//Now 'falThroughLabel' is assigned the fall-through label value of the next case, i.e. the present case will
						//fall-through to this location if no 'break' is encountered.
						sprintf(tempCode, "goto L%d", fallThroughLabel);
						addComment(" /* goto_fall_through */");					//adding comments to code
						strcat(tempCode,"\n");
						concatCode();											//concatenate 'tempCode' with 'code'
						
						sprintf(tempCode, "L%d:", tempLabels.l[0]);
						//The exit labeL of the case is stored in 'tempLabels.l[0]'
						addComment(" /* end_of_case */");						//adding comments to code
						strcat(tempCode,"\n");
						concatCode();											//concatenate 'tempCode' with 'code'
					}
				;

/* DEFAULT -> default : S BREAK */
default_case:		KW_DEFAULT COLON
					{
						sprintf(tempCode, "L%d:", fallThroughLabel);
						//'fallThroughLabel' currently contains the label to which the previous 'case' will fall-through if no 'break'
						//is encountered.
						addComment(" /* fall_through */");						//adding comments to code
						strcat(tempCode,"\n");
						concatCode();											//concatenate 'tempCode' with 'code'
						++spaceCount;											//increment 'spaceCount' for indentation
																				//when going in a deeper block
					} 
					statements break_statement
					{
						--spaceCount;											//decrement 'spaceCount' for indentation
																				//when coming out of a deeper block
					}
				;

/* BREAK -> epsilon | break ; */
break_statement:	/* epsilon */
				|	KW_BREAK
					{
						--spaceCount;											//decrement 'spaceCount' for indentation
																				//when coming out of a deeper block
						sprintf(tempCode,"goto L%d", switchExitLabel);
						//If a 'break' is encountered after any 'case' the control should exit the switch
						//through this 'switchExitLabel'
						addComment(" /* to_switch_exit */");					//adding comments to code
						strcat(tempCode,"\n");
						concatCode();											//concatenate 'tempCode' with 'code'
						++spaceCount;											//increment 'spaceCount' for indentation
																				//when going in a deeper block
					}
					SEMI_COLON
				;
%%

main(int argc, char **argv)
{
	printBanner();
	printf("\nEnter code in Subset-C language (Ctrl+C to exit)\n");
	printf("main()\n");
	yyparse();
}

yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}

void printBanner()
{
	printf("\n");
	printf("\tNAME        : %s\n", AUTHOR);
	printf("\tROLL NUMBER : %s\n", ROLL_NUMBER);
	printf("\tCLASS       : %s\n", CLASS_AND_SECTION);
	printf("\tBRANCH      : %s\n", ENGG_BRANCH);
	printf("\tPROJECT     : %s\n", APP_NAME);
	printf("\n");
	
	printf("\n>>>PLEASE RUN THE PROGRAM IN A FULL SCREEN BASH TERMINAL ON LINUX FOR BETTER CODE VISIBILITY!!!.<<<\n");
	
	printf("\nPlease refer to the README.txt file for execution instructions.\n");
}

int calcPow(int base, int exponent)
{
	//Calculates and returns the value of 'base' to the power 'exponent' ('base @ exponent')
	//in logarithmic time complexity. Variable names are self explanatory.

	int tempBase, tempExponent, ans;
	if(base == 0)
	{
		if(exponent > 0)
			return 0;
		
		printf("ILLEGAL POWER OF ZERO !!!\n");
		exit(-1);
	}
	
	if(base == 1 || exponent == 0)
		return 1;
	
	tempBase = base;
	tempExponent = 2;
	ans = base;
	
	while(tempExponent < exponent)
	{
		ans = ans * tempBase;
		tempBase = tempBase * tempBase;
		tempExponent = tempExponent * 2;
	}
	
	tempExponent = tempExponent / 2;
	
	while(tempExponent < exponent)
	{
		ans = ans * base;
		++tempExponent;
	}
	
	//At the end of this function 'ans' contains the value of 'base @ exponent'.
	
	return ans;
}

void genrateCode(YYSTYPE *yy, YYSTYPE *y1, YYSTYPE *y2, YYSTYPE *y3, char *tempCode)
{
	//This function generates the intermediate code for a binary expression of the
	//type: lhs = opearnd1 operator operand2, and prints it in the global array named 'tempCode'.

	//'yy' represents Left Hand Side (LHS) of the binary expression.
	//'y1' represents operand1, y3 represents operand2.
	//'y2' represents the operator.
	
	int c1,c2,c3,c4;										//Variables to store outcomes of various boolean conditions.
	
	c1 = yy->varName[0] == '\0';							//TRUE if LHS does not already have a valid varName.
	c2 = yy->varName[0] == 't' && isdigit(yy->varName[1]);	//TRUE if LHS has a temporary variable's name eg: 't0', 't1', 't2', ... etc.
	c3 = y2->oprtr[1] != '=';								//TRUE if the operator is not any of these: +=, -=, *=, /=, ==, <=, !=, or >=.
	c4 = y2->oprtr[1] == '=' && (y2->oprtr[0] == '<' || y2->oprtr[0] == '>' || y2->oprtr[0] == '=' || y2->oprtr[0] == '!');
	//TRUE if Operator is <=, >=, == or !=.
	
	if(c1 || c2 || c3 || c4)								//TRUE if any of 'c1', 'c2', 'c3', or 'c4' is TRUE.
		sprintf(yy->varName,"t%d", ++tempIdCount);			//Create a new temporary variable name and copy it in varName of LHS.
	
	c1 = y1->varName[0] == '\0';	//TRUE if operand1 has no variable name
	c2 = y3->varName[0] == '\0';	//TRUE if operand2 has no variable name.
	
	//If an operand does not have a variable name (eg: when the operand is a NUMBER) its value is printed instead of its name in the
	//intermediate code.
	
	if(c1 && c2)	//TRUE if both operand1 and operand2 don't have variable names.
		sprintf(tempCode,"%s = %d %s %d\n", yy->varName, y1->val, y2->oprtr, y3->val);
	else if(c1)		//TRUE if operand1 doesn't have a variable name.
		sprintf(tempCode,"%s = %d %s %s\n", yy->varName, y1->val, y2->oprtr, y3->varName);
	else if(c2)		//TRUE if operand2 doesn't have a variable name.
		sprintf(tempCode,"%s = %s %s %d\n", yy->varName, y1->varName, y2->oprtr, y3->val);
	else			//TRUE if both operands have variable names.
		sprintf(tempCode,"%s = %s %s %s\n", yy->varName, y1->varName, y2->oprtr, y3->varName);
		
	//At the end of this function 'tempCode' contains the intermediate code of the expression being considered.
}

void concatCode()
{
	//This function concatenates the current 'tempCode' content to the intermediate code stored in 'code'.	
	
	indentCode();			//Indents the Intermediate code.
	strcat(code, tempCode);	//Concatenate the content of global array 'tempCode' to contents of global array 'code'.
	
	//At the end of this function 'code' contains the latest intermediate code.
}

void indentCode()
{
	//This function adds indentation to the intermediate code using the global variable 'spaceCount'.
	//A '\' symbol followed by 3 spaces is added in each iteration.
	//The '\' symbol generates vertical lines joining the start and the end of a block of statements.

	int i = 0;
	for(i = 0; i < spaceCount; ++i)
		strcat(code, "|   ");
	
	//At the end of this function 'code' contains the latest intermediate code with indentation.
}

void addComment(const char *comment)
{
	//This function adds explanatory comments in the intermediate code when the global variable 'isCommentVisible' has the value 1.

	int emptyFieldLength = 0, i;
	if(isCommentVisible)
	{
		emptyFieldLength = MAX_FIELD_LEN - strlen(tempCode) - strlen(comment) - spaceCount * 4;
		if(emptyFieldLength < 5)
			emptyFieldLength = 5;
		for(i = 0; i < emptyFieldLength; ++i)
			strcat(tempCode," ");
		strcat(tempCode, comment);
	}
		
	//At the end of this function the 'tempCode' has a comment appended to it, if 'isCommentVisible' has the value 1.
}

void pushLabel(int start, int count)
{
	//This function generates 'count' number of labels starting from the number 'start' and pushes them in the stack
	//variable named 'labelStack'.
	
	int i = 0;
	
	++labelStackTop;
	if(labelStackTop == LABEL_STACK_SIZE)
	{
		printf("labelStack OVERFLOW !!!\n");
		exit(0);
	}
	
	if(count > MAX_NUM_OF_LABELS)
	{
		printf("MAX_LABEL_COUNT exceeded !!!\n");
		exit(0);
	}
	
	for(i = 0; i < count; ++i)
		labelStack[labelStackTop].l[i] = start + i;
		
	//At the end of this function 'count' number of labels starting from the number 'start' have been pushed into
	//the stack variable named 'labelStack'.
}

void popLabel()
{
	//This function pops the labels at the top of the stack variable 'labelStack' and stores them in the variable
	//'tempLabels'.

	if(labelStackTop == -1)
	{
		printf("labelStack UNDERFLOW !!!\n");
		exit(0);
	}
	tempLabels = labelStack[labelStackTop];
	--labelStackTop;
	
	//At the end of this function 'tempLabels' contains the labels that were at the top of the stack variable 'labelStack'.
}

void pushId()
{
	//This function pushes the identifier name stored in the variable 'currentId' on to the stack variable 'idStack'.

	++idStackTop;
	if(idStackTop == ID_STACK_SIZE)
	{
		printf("idStack OVERFLOW !!!\n");
		exit(0);
	}
	strcpy(idStack[idStackTop], currentId);
	
	//At the end of this function the top of the stack variable 'idStack' contains the variable name that was stored in
	//'currentId'.
}

void popId()
{
	//This function pops the top of the stack variable 'idStack' and stores the identifier name obtained in the variable
	//'currentId'.
		
	if(idStackTop == -1)
	{
		printf("idStack UNDERFLOW !!!\n");
		exit(0);
	}
	strcpy(currentId, idStack[idStackTop]);
	--idStackTop;
	
	//At the end of this function 'currentId' has the variable name that was at the top of the stack variable 'idStack'.
}
