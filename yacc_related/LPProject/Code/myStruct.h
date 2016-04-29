/*
# define AUTHOR				"Avinash Yadav"
# define ROLL_NUMBER		"127210"
# define ENGG_BRANCH		"Computer Science And Engineering (CSE)"
# define CLASS_AND_SECTION	"B Tech, (3/4), CSE - B"
# define APP_NAME			"Language Processors Major Assignment: Intermediate Code Generation"
# define ACADEMIC_SESSION	"2014-2015"
# define INSTITUTE			"NIT Warangal"
*/

# define MAX_CODE_LENGTH 1000001
# define MAX_LENGTH_OF_ID_NAME 101

# define YYSTYPE struct myStruct
struct myStruct
{
	char varName[MAX_LENGTH_OF_ID_NAME];
	char oprtr[MAX_LENGTH_OF_ID_NAME];
	int type;
	int val;
};

//This file contains the overridden definition of YYSTYPE.
//The variable 'yylval' used in 'lexfile.l' is defined in-situ
//in the code generated and it has the type YYSTYPE.
//The pseudo-variables $$, $1, $2 etc used in the 'yaccfile.y'
//also have the type YYSTYPE.