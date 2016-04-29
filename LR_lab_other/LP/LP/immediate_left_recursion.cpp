/*
left recursion form
A->Aa/b
then 
A->bA'
A'->aA'/e
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int np;
	string production,alpha,beta,newProduction;
	string rhs,lhs;
	production="";
	cout<<"Enter the number of production:";
	cin>>np;
	
	for(int i=0;i<np;i++)
	{
		cout<<"\nEnter the production in the form A -> A{aplha} / {beta} : ";
		cin>>production;
		cout<<"\n";
		lhs=production[0];
		rhs=production[3];
		
		if(lhs==rhs)
		{
			cout<<"Immediate Left recursion exist in production:"<<production<<endl;
			int k=production.find("/");
			alpha=production.substr(4,abs(k-4));
			int end=production.find("");
			beta=production.substr(k+1,abs(end-(k-1)));
			cout<<"Alpha="<<alpha<<" and beta="<<beta<<endl;
			cout<<"New production ="<<"\n";
			cout<<lhs<<"->"<<beta<<lhs<<"'"<<endl;
			cout<<lhs<<"'->"<<alpha<<lhs<<"'/"<<"e"<<endl<<endl;
		}
		else
		{
			cout<<"no immediate left recursion in "<<production<<endl;
		}
	}
	return 0;
}
