#include<bits/stdc++.h>
using namespace std;

#define SIZE 100

string G[SIZE][SIZE]; // to store entered grammer
string dpr[SIZE];
int p,np;  	//np=no of productions

//check LHS of "->" for CNF form
inline int lcheck(string a)
{
	if(a.length()==1 && a[0]>='A' && a[0]<='Z')
		return 1;
	return 0;
}
//check RHS of "->" for CNF form,checks each token
inline int rcheck(string a)
{
	if(a.length()==2 && a[0]>='A' && a[0]<='Z' && a[1]>='A' && a[1]<='Z')
		return 1;
	if(a.length()==1 && a[0]>='a' && a[0]<='z')
		return 1;
	return 0;
}

// separates RHS of grammer into tokens by checking "/" symbol
inline void break_grammer(string a)
{
	int i;
	p=0;
	while(a.length())
	{
		i=a.find("/");
		if(i>a.length())
		{
			dpr[p++]=a;
			a="";
		}
		else
		{
			dpr[p++]=a.substr(0,i);
			a=a.substr(i+1,a.length() +1);
		}
	}
}
// concatenate two strings
inline string join(string a,string b)
{
	int i;
	string r=a;
	for(i=0;i<a.length();i++)
	{
		if(r.find(b[i])>r.length())
			r+=b[i];
	}
	return (r);
}
// returns concatenated string of variables that can generate production p
inline string search_production(string p)
{
	int j,k;
	string r="";
	for(j=0;j<np;j++)
	{
		k=1;
		while(G[j][k]!="")
		{
			if(G[j][k] ==p)
			{
				r=join(r,G[j][0]);
				k++;
			}
		}
	}
	return r;
}

inline string combine(string a,string b)
{
	int i,j;
	string pri=a,re="";
	for(i=0;i<a.length();i++)
	{
		for(j=0;j<b.length();j++)
		{
			pri=" ";
			pri=pri+a[i]+b[j];
			re=re+search_production(pri); //search if production can be generated or not
		}
	}
	return re;
}

int main()
{
	int i,j,k,pt,l;
	string a,start,str,r,pr;
	cout<<"\nEnter Start symbol : ";
	cin>>start;
	cout<<"\nEnter no of productions:  ";
	cin>>np;
	cout<<"\nEnter the productions :\n";
	for(i=0;i<np;i++)
	{
		cin>>a;
		pt=a.find("->");
		G[i][0]=a.substr(0,pt);                  // a.substr(1,pt);
		cout<<"\n";
		if(lcheck(G[i][0])==0)
		{
			cout<<"Not in CNF";
			abort();
		}
		a=a.substr(pt+2,a.length());
		break_grammer(a);
		for(int j=0;j<p;j++)
		{
			G[i][j+1]=dpr[j];
			if(rcheck(dpr[j])==0)
			{
				cout<<"not in CNF";
				abort();
			}
		}
	}
	string A[SIZE][SIZE], st;  //A to store matrix element
	cout<<"\nEnter string to be checked:";
	cin>>str;

	// assign values to principle diagonal elements
	for(int i=0;i<str.length();i++)
	{
		r="";
		st="";
		for(j=0;j<np;j++)
		{
			k=1;
			while(G[j][k]!="")
			{
				if(G[j][k]==st)
				{
					r=join(r,G[j][0]);
				}
				k++;
			}
		}
		A[i][i]=r;
	}
	// assign values to the uper half of matrix
	for(int k=1;k<str.length();k++)
	{
		for(int j=k;j<str.length();j++)
		{
			r="";
			for(int l=j-k;l<j;l++)
			{
				pr=combine(A[j-k][l],A[l+1][j]);
				r=join(r,pr);
			}
			A[j-k][j]=r;
		}
	}
	
	// print matrix A
	for(i=0;i<str.length();i++)
	{
		k=0;
		l=str.length()-i-1;
		for(j=l;j<str.length();j++)
		{
			cout<<setw(5)<<A[k++][j]<<"  ";
		}
		cout<<endl;
	}
	
	
	for(i=0;i<start.length();i++)
	{
		if(A[0][str.length()-1].find(start[i])<=A[0][str.length()-1].length())
		{
			cout<<"\nString can be generated";
			return 0;
		}
		else
			cout<<"\nString can not be generated";
	}
	return 0;	
}
