#include<bits/stdc++.h>
using namespace std;

int main()
{
	char *dataType[]={"int","float","char","string"};
	char *Operator[] = { "+","-","*","/","%","<","<=",">",">=","==","!=","++","--","="};
	char *keyword[]={"if","else","while","do","for","struct","class","union","cout","cin","return","main"};
	char *symbol[]={"(",")","{","}","[","]",",",";"};
	char *str=new char();
	char *ptr;
	char x=' ';
	cout<<"Enter the X to stop: ";
	cout<<"Enter the program statements:\n";
	while(x!='X' || x!='x')
	{
		if(x=='X' || x=='x')
			exit(1);
		cin.getline(str,80);
		fflush(stdin);
		ptr=strtok(str," ");
		while(ptr!=NULL)
		{
			cout<<ptr;
			if(strcmp(ptr,dataType[0])==0||strcmp(ptr,dataType[1])==0||strcmp(ptr,dataType[2])==0||strcmp(ptr,dataType[3])==0)
			{
				cout<<"\t"<<"Data Type\n";
			}
			else if(strcmp(ptr,Operator[0])==0||strcmp(ptr,Operator[1])==0||strcmp(ptr,Operator[2])==0||strcmp(ptr,Operator[3])==0||strcmp(ptr,Operator[4])==0||strcmp(ptr,Operator[5])==0||strcmp(ptr,Operator[6])==0||strcmp(ptr,Operator[7])==0||strcmp(ptr,Operator[8])==0||strcmp(ptr,Operator[9])==0||strcmp(ptr,Operator[10])==0||strcmp(ptr,Operator[11])==0||strcmp(ptr,Operator[10])==0|| strcmp(ptr,Operator[11])==0|| strcmp(ptr,Operator[12])==0|| strcmp(ptr,Operator[13])==0)
			{
				cout<<"\t"<<"Operator\n";
			}
			else if(strcmp(ptr,keyword[0])==0||strcmp(ptr,keyword[1])==0||strcmp(ptr,keyword[2])==0||strcmp(ptr,keyword[3])==0||strcmp(ptr,keyword[4])==0||strcmp(ptr,keyword[5])==0||strcmp(ptr,keyword[6])==0||strcmp(ptr,keyword[7])==0||strcmp(ptr,keyword[8])==0||strcmp(ptr,keyword[9])==0||strcmp(ptr,keyword[10])==0||strcmp(ptr,keyword[11])==0)
			{
				cout<<"\t"<<"Keyword\n";
			}
			else if(atoi(ptr)>0 || atoi(ptr)<0)
			{
				cout<<"\t"<<"Number\n";
			}
			else if(strcmp(ptr,symbol[0])==0||strcmp(ptr,symbol[1])==0||strcmp(ptr,symbol[2])==0||strcmp(ptr,symbol[3])==0||strcmp(ptr,symbol[4])==0||strcmp(ptr,symbol[5])==0||strcmp(ptr,symbol[6])==0||strcmp(ptr,symbol[7])==0)
			{
				cout<<"\t"<<"Symbol\n";
			}
			else
			{
				cout<<"\t"<<"Identifier\n";
			}
			ptr=strtok(NULL," ");	
		}
		cin>>x;
	}
	return 0;
}
