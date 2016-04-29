>>>README.txt<<<
KINDLY GO THRUGH THE COMPLETE DOCUMENT.

FILES USED IN THE PROGRAM:
The program code consists of 4 files: 'yaccfile.y', 'lexfile.l', 'myStruct.h', and 'Makefile'.
1. 'yaccfile.y' contains the yacc/bison code. The code is extensively documented for ease of use.
2. 'lexfile.l' contains the flex/lex code. It has no extensive comments however the code can be easily understood from the context.
3. 'myStruct.h' contains the redefinition of the data type YYSTYPE for program specific implementation. YYSTYPE is redefined as a structure. It also contains the definition of some of the constatnts. The file is #include(d) in both 'lexfile.l' and 'yaccfile.y'. Errors may be raised if the file is missing.
4. 'Makefile' contains the code to generate the executable file named 'project'. Running the makefile compiles the yacc/bison code and the flex/lex code and produces this executable file.

EXECUTION INSTRUCTIONS:
1. Open the bash terminal and change the working directory to the location of the above files.
2. Issue the 'make' command to produce the executable file 'project'.
3. The compiling phase may show a warning about a shift-reduce conflict. Refer to the 'WARNING AND ERRORS' part for more details.
4. Execute the file using './project' command.
5. PLEASE RUN THE PROGRAM IN FULL SCREEN MODE FOR PROPER CODE VISIBILITY.

WARNING AND ERRORS:
1. yacc/bison reports a shift-reduce conflict during compilation: 'yaccfile.y: warning: 1 shift/reduce conflict [-Wconflicts-sr]'. This is due to the usage of an ambiguous grammar for the 'if-else' construct. The warning is of no major concern as the default action of yacc/bison carries out the intended task correctly. (ie It matches an 'else' to nearest 'if' that occurs before it.)

INPUT:
1. When the program is executed it first displays the App Banner and then asks the user to complete the definition of a 'main()' by providing a block of code.
2. DO NOT USE VARIABLE NAMES STARTING WITH THE LETTER 't' as it has been internally used to represent temporary variables. Such usage may lead to erroneous intermediate code.

OUTPUT:
1. When the block is completed and the enter key is pressed, the intermediate code is displayed.
2. Explanatory comments are also displayed with the code, wherever necessary.
3. IT IS ADVISED TO RUN THE PROGRAM IN FULL SCREEN MODE TO PROPERLY VIEW THE CODE AND THE COMMENTS.

GENERAL INFORMATION:
1. The program does NOT check if a variable has been declared or redeclared or not declared at all. No errors are raised in such situations. Variable declaration is allowed. However it does not generate any visible intermediate code.
2. The program does NOT check for variable types.
3. The generated intermediate code may be different from general textbook literature, but the differences are not drastic.
4. The generated intermediate code may not be optimal.
5. The program should work well even for nested 'if-else' and/or 'while' and/or 'switch-case' statements.

RESOLVING THE PROBLEM OF FORWARD REFERENCING:
Textbook literature suggests the use of BACKPATCHING to take care of forward referencing in a single pass. However this program uses a different approach to solve this problem. It takes the help of stack variables to keep track of label locations.
1. FORWARD REFERENCING IN || (boolean OR) and && (boolean AND) operators:
	1.1 expr -> expr1 || expr2
		The intermediate code is similar to as given below:
		
		1	<expr1.code>
		2	t0 = <expr1.truthValue>
		3	if t0 isFalse goto L0
		4		t1 = true
		5	goto L1
		6	L0:
		7		<expr2.code>
		8		t1 = <expr2.truthVal>
		9	L1:

As we can see from this general form of the statement, the locations of labels L0 and L1 are known. Hence these labels can be pre generated even before reaching these locations. The program generates these labels before hand and pushes them on to the 'labelStack' before entering a deeper level of code (ie expr2.code). The statements at lines 3, 5, 6 and 7 use these labels. Statemets 3, 5 and 6 can be generated on the spot even before pushing the labels on to the stack. However the statement 7 is generated after the control exits a deeper level of code (ie expr2.code) and the labels are popped back. The temporary variable t1 that represents the value of expr.truthVal is also pushed on to an 'idStack' before entering a deeper level of code. It can be retrieved when the control comes back.

	1.2 expr -> expr1 && expr2
		The intermediate code is similar to as given below:
		
		1	<expr1.code>
		2	t0 = <expr1.truthValue>
		3	if t0 isTrue goto L0
		4		t1 = false
		5	goto L1
		6	L0:
		7		<expr2.code>
		8		t1 = <expr2.truthVal>
		9	L1:

		The labels L0 and L1 are created in the same manner as in 1.1 above.

2. FORWARD REFERENCING IN 'if-else':
	2.1 conditional -> if (exp) { stmt1 } else { stmt2 }
		The intermediate code is similar to as given below:

		1	<expr.code>
		2	t0 = <expr.truthVal>
		3	if t0 isFalse goto L0
		4		<stmt1.code>
		5	goto L1
		6	L0:
		7		<stmt2.code>
		8	L1:

As we can see from the general code, the locations of labels L0 and L1 can be easily determined. In a way similar to 1.1 and 1.2 the labels are generated and pushed onto the stack 'labelStack' before entering a deeper level of code (ie stmt1.code or stmt2.code). This happens twice, once during the if part and once during the else part. The labels are popped back when the control returns to this level. One should note that the labels L0 and L1 are both created even if the else part is missing.

3. FORWARD REFERENCING IN 'while':
	3.1 loop -> while ( expr ) { stmt }
		The intermediate code is similar to as given below:

		1	L0:
		2	<expr.code>
		3	t0 = <expr.truthVal>
		4	if t0 isFalse goto L1
		5		<stmts.code>
		6	goto L0
		7	L1:

Again we can pre determine the label locations and use the stack push and pop operations to store and retrieve them just before entering a deeper level of code and just after returning to the current level respectively.

4. FORWARD REFERENCING IN 'switch-case':
	4.1 switch_stmt -> switch ( identifier ) { cases default_stmt }
		cases -> epsilon | cases case_stmt
		case_stmt -> case NUMBER : stmts break_stmt
		default_stmt -> default: stmts break_stmt
		break_stmt -> epsilon | break ;

		The intermediate code is similar to as follows:
		
		1	t0 = <identifier> == <case.val>
		2	if t0 isFalse goto <caseEndLabel>
		3	<fallThroughLabel>:
		4		<stmts.code>
		5	goto <exitLabel>			//only if 'break' appears
		6	goto <nextFallThroughLabel>
		7	<caseEndLabel>
		8	... <more_cases>
		.	...
		.	...
		.	...
		12	<exitLabel>
		
Each case of a switch is similar to an 'if-else' construct. The main 'switch' body requires one 'exitLabel'. This label refers to the location that a 'break' statement passes the control to. It is situated at the end of the switch. Each case has a 'fallThroughLabel' to ensure the fall-through behaviour of switch in the absence of a 'break' statement. A statement also has a 'caseEndLabel' that appears at the end of a case. These labels are generated and handled in a manner similar to the above cases discussed in points 1, 2 and 3.
