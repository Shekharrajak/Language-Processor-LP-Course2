#include<bits/stdc++.h>
using namespace std;

void LR(map<string,string> myMap,int size)
{
	
}

map<string,string> rearrange(map<char,string> myMap,int size)
{
	char ch='A';
	char ch1;
	map<string,string> newMap;
	map<char, string>::iterator it;
	map<string,string>::iterator it2;
	
	for(it=myMap.begin();it!=myMap.end();it++)
	{
			ch1=it.first();
			
			
			cout<<ch<<endl;
			ch++;
	}
	return newMap;	
}

int main()
{
	int np;
	char ch;
	map<char,string>myMap;
	map<string,string>newMap;
	string production="";
	cout<<"Enter the number of production:";
	cin>>np;
	for(int i=0;i<np;i++)
	{
		cout<<"Enter the satrting character of the production i.e. LHS of the production:";
		cin>>ch;
		cout<<"\nNow Enter the RHS of the production :";
		cin>>production;
		myMap[ch]=production;
		cout<<endl;
	}
	newMap=rearrange(myMap,np);
	LR(newMap,np);
	// now remove immediate LR
	
	
	return 0;
}
