
#include<string.h>
#include<conio.h>
#include<iostream>
using namespace std;
char a[10];
int top=-1,i;
void error(){
printf("Syntax Error");
}
void push(char k[]) //Pushes The Set Of Characters on to the Stack
{
  for(i=0;k[i]!='\0';i++)
  {
    if(top<9)
    a[++top]=k[i];
  }
}
char TOS()        //Returns TOP of the Stack
{
  return a[top];
}
void pop()       //Pops 1 element from the Stack
{
  if(top>=0)
    a[top--]='\0';
}
void display()  //Displays Elements Of Stack
{
  for(i=0;i<=top;i++)
    printf("%c",a[i]);
}
void display1(char p[],int m) //Displays The Present Input String
{
  int l;
  printf("\t");
  for(l=m;p[l]!='\0';l++)
    printf("%c",p[l]);
}
char* stack(){
return a;
}
int main()
{
  char ip[20],r[20],st,an;
  int ir,ic,j=0,k;
  /*
grammewr is 
G=SS
S=(L)|a
l=SM
M=bSM

table is for this grammer

accepted string is a(a)
*/
  char t[4][5][10]={"SS","$","SS","$","$",
		   "(L)","$","a","$","$",
		   "SM","$","SM","$","$",
		   "$","&","$","$","bSM",
		   };
  
  printf("\nEnter any String(Append with $)");
  gets(ip);
  printf("Stack\tInput\tOutput\n\n");
  push("$G");
  display();
  printf("\t%s\n",ip);
  for(j=0;ip[j]!='\0';)
  {
  if(TOS()==an)
      {
	pop();
	display();
	display1(ip,j+1);
	printf("\tPOP\n");
	j++;
      }
    an=ip[j];
    st=TOS();
      if(st=='G')
	  {
	  	ir=0;
	  }
      else if(st=='S'){
      	ir=1;
      }
      else if(st=='L'){
      	ir=2;
      }
      else if(st=='M'){
      	ir=3;
      }
      
      else {
	    error();
	    break;
	    }
      if(an=='('){
      	ic=0;	
      }
      else if(an==')'){
      	ic=1;	
      }
      else if(an=='a'){
      	ic=2;	
      }
      else if(an=='b'){
      	ic=3;	
      }
//      else if((an>='a'&&an<='z')||(an>='A'&&an<='Z')){ic=2;an='i';}
      else if(an=='$'){
      	ic=4;
      }
      strcpy(r,strrev(t[ir][ic]));
      strrev(t[ir][ic]);
      pop();
      push(r);
      if(TOS()=='&')
      {
	pop();
	display();
	display1(ip,j);
	printf("\t%c->%c\n",st,238);//238 to display epsilon
      }
      else{
      display();
      display1(ip,j);
      printf("\t%c->%s\n",st,t[ir][ic]);
      }
      if(TOS()=='$'&&an=='$')
      break;
      if(TOS()=='$'){
	error();
	break;
	}
      }
      k=strcmp(stack(),"$");
      printf("\nk value %d\n",k);
      printf("\nj value %d\n",j);
      printf("string len value %d\n",strlen(ip));
      if(k==0 && j==strlen(ip)-1)
    		printf("\n Given String is accepted");
    	else
    		printf("\n Given String is not accepted");
  return 0;
}




