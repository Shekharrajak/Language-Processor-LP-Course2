// Code :-

#include<stdio.h>
#include<string.h>
#include<ctype.h>

/* SLR parser for the grammar
   E->E+T (1)
   E->T (2)
   T->T*F (3)
   T->F (4)
   F->(E) (5)
   F->ID (6)
*/

/* Stack structure and fuctions */

/* The only thing important here is that the value associated
with each name of the macro should be unique. They have no realtion to 
the states in the dfa */

#define S4 1
#define S5 2
#define S6 3
#define S7 4
#define R1 5
#define R2 6
#define R3 7
#define R4 8
#define R5 9
#define R6 10
#define S11 11
#define AC 11            /* ACCEPT */
#define ER -1            /* ERROR */

/* the parsing table  */
int table[][9]= {
  {S5,ER,ER,S4,ER,ER,1,2,3},
  {ER,S6,ER,ER,ER,AC,ER,ER,ER},
  {ER,R2,S7,ER,R2,R2,ER,ER,ER},
  {ER,R4,R4,ER,R4,R4,ER,ER,ER},
  {S5,ER,ER,S4,ER,ER,8,2,3},
  {ER,R6,R6,ER,R6,R6,ER,ER,ER},
  {S5,ER,ER,S4,ER,ER,ER,9,3},
  {S5,ER,ER,S4,ER,ER,ER,ER,10},
  {ER,S6,ER,ER,S11,ER,ER,ER,ER},
  {ER,R1,S7,ER,R1,R1,ER,ER,ER},
  {ER,R3,R3,ER,R3,R3,ER,ER,ER},
  {ER,R5,R5,ER,R5,R5,ER,ER,ER}
};
#define STRING_SIZE 20

char string[STRING_SIZE];
int i=0;
int save;

#define STACK_SIZE 40

typedef struct {
  int list[STACK_SIZE];
  int top;
}Stack;

void initialize(Stack *s) {
  s->top=-1;
}
void push(int value,Stack *s) {
  s->list[++(s->top)]=value;
}
int pop(Stack *s) {
  return(s->list[(s->top)--]);
}
int isempty(Stack *s) {
  return(s->top==-1);
}
int peek(Stack *s) {
  return(s->list[s->top]);
}
int stacksize(Stack *s) {
  return((s->top)+1);
}

#define ID 0
#define ADD 1
#define MULT 2
#define OPBR 3
#define CLBR 4
#define DOLLAR 5
#define E 6
#define T 7
#define F 8

short int gettoken() {
  /* ignore blanks */
  while(string[i]==' ')
    i++;
  /* definition for identifier */
  if(isalpha(string[i])) {
    save=i;
    i++;
    while(string[i]!=0 && string[i]!='*' && string[i]!='+' && string[i]!=')' && string[i]!='(') {
      if(!isalnum(string[i++]))
    error();
    }
    return ID;
  }
  else if(string[i]=='+') {
    save=i;
    i++;
    return ADD;
  }
  else if(string[i]=='*') {
    save=i;
    i++;
    return MULT;
  }
  else if(string[i]=='(') {
    save=i;
    i++;
    return OPBR;
  }
  else if(string[i]==')') {
    save=i;
    i++;
    return CLBR;
  }
  else if(string[i]==0) {
    return DOLLAR;
  }
}
error() {
  printf("error.\n");
  return;
}
int parse() {
  int token;
  Stack stack;
  int state;
  int j;
  int action;
  int previous;
  initialize(&stack);
  push(0,&stack);
  token=0;
  while(1) {
    token=gettoken();
    action=table[peek(&stack)][token];
    switch(action) {
    case S4:
      push(token,&stack);
      push(4,&stack);
      break;
    case S5:
      push(token,&stack);
      push(5,&stack);
      break;
    case S6:
      push(token,&stack);
      push(6,&stack);
      break;
    case S7:
      push(token,&stack);
      push(7,&stack);
      break;
    case AC:
      return 1;
    case ER:
      error();
   
    }
    if(action>=5 && action <=10) {
      while(action>=5 && action <=10) {
    action=table[peek(&stack)][token];
    switch(action) {
    case R1:
      for(j=0;j<6;j++)
        pop(&stack);
      state=table[peek(&stack)][E];
      if(state!=ER) {
        push(E,&stack);
        push(state,&stack);
      }
      else 
        error();
      break;
    case R2:
      pop(&stack);
      pop(&stack);
      state=table[peek(&stack)][E];
      if(state!=ER) {
        push(E,&stack);
        push(state,&stack);
      }
      else 
        error();
      break;
    case R3:
      for(j=0;j<6;j++)
        pop(&stack);
      state=table[peek(&stack)][T];
      if(state!=ER) {
        push(T,&stack);
        push(state,&stack);
      }
      else 
        error();
      break;
    case R4:
      pop(&stack);
      pop(&stack);
      state=table[peek(&stack)][T];
      if(state!=ER) {
        push(T,&stack);
        push(state,&stack);
      }
      else 
        error();
      break;
    case R5:
      for(j=0;j<6;j++)
        pop(&stack);
      state=table[peek(&stack)][F];
      if(state!=ER) {
        push(F,&stack);
        push(state,&stack);
      }
      else 
        error();
      break;
    case R6:
      pop(&stack);
      pop(&stack);
      state=table[peek(&stack)][F];
      if(state!=ER) {
        push(F,&stack);
        push(state,&stack);
      }
      else 
        error();
      break;
    case AC:
      return 1;
    case ER:
      error();
    }
      }
      i=save;
    }
  }
  return 0;
}
int main() {
  printf("Enter the string: ");
  scanf("%s",string);
  if(parse()) {
    printf("Success in parsing.\n");
  }
  else 
    error();
}