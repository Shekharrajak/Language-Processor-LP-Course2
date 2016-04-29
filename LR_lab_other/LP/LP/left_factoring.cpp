/*

left factoring form
A->ab1/ab2
then 
A->aA'
A'->b1/b2

*/

#include<bits/stdc++.h>
using namespace std;

#define MAX 20
int main()
{
	int np;
	string production="";
	string alpha;
	string beta[MAX];
	cout<<"Enter the number of production:";
	cin>>np;
	int count=1; // position[0]=0 filled
	int position[MAX];
	
	
	
	for(int i=0;i<np;i++)
	{
		cout<<"Enter the production :";
		cin>>production;
		string str;
		int l=production.length();
		str=production.substr(3,l-3);
		cout<<str;
		position[0]=0;
		
		
		for(int k=1;str[k]!='\0';k++)
		{
				if(str[k]=='/')
				{
					//cout<<"j";
					position[count++]=k+1 ; // to store position of '/' +1
				}
		}
		
	
		cout<<"\ncount="<<count<<endl;
		
		int v[count];
		int charMatched[count];
		
		for(int l=0;l<count;l++) // settting v and charMatched =0
		{
			v[l]=0;
			charMatched[l]=0;
		}
		
		int next,current;
		for(int a=0; a<count-1; a++)
		{
				current=position[a];
				next=position[a+1];
				while(str[current]==str[next] && next <= position[a+2])
				{
					v[a]=1;
					charMatched[a]++;
					current++;
					next++;
				}
		}
		
		//cout<<"gvdsk\n\n";
		int min=10;
		for(int b=0;b<count;b++)
		{
			if(charMatched[b]<min && v[b]==1)
				min=charMatched[b];
		}
		
		// v and charMatched
		alpha=str.substr(0,min);
		cout<<"alpha="<<alpha<<endl;
		
		
		// fill beta[]
		for(int j=0;j<count; j++)
		{
			if((position[j+1]-position[j])==min && v[j]==1)
			{
				beta[j]="@";
			}	
			else if((position[j+1]-position[j])>min && v[j]==1)
			{
				beta[j]=str.substr(position[j]+min-1,(position[j+1]-position[j]-min-1));
			}
			else
			{
				beta[j]=str.substr(position[j],(position[j+1]-position[j-2]));
			}
		}
		
		//cout<<"gvdskkkjhfdslikhfsalkh";
		
		 //check v and charMatched
		for(int j=0;j<count; j++)
		{
			cout<<v[j]<<"  "<<charMatched[j]<<endl;
		}		
		
		cout<<"\n\nProduction after left factoring:\n";
		cout<<production[0]<<"->"<<alpha<<production[0]<<"'"<<endl;
		cout<<production[0]<<"'->";
		for(int i=0;i<count;i++)
		{
			cout<<beta[i]<<"/";
		}
		cout<<endl;	
	}
	return 0;
}
