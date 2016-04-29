#include<bits/stdc++.h>
using namespace std;

map<char,set<string> > FIRST(map<char,set< string> > production)
{
	map <char,set<string> > first;
	map <char, set<string> > :: iterator it1,it2; // it1 for production and it2 for first
	set < string > s1;
	set < string > :: iterator st1;
	//it1=production.begin();
	//st1=s1.begin();
	
	string str; // to store the string of set s1
	for(it1=production.begin(); it1!=production.end(); it1++)
	{
			char ch=it1.first;
			s1=it1.second;
			
	}
	

	return first;	
}

map<char, set<string> > FOLLOW(map<char,set< string> > production)
{
	
}


int main()
{	
	
	map <char, set < string > > production;
	map <char,set<string> > first;
	map <char,set<string> > follow;
	char ch='y';
	char lhs; // LHS of production;
	string rhs; // RHS of production 
	int cnt=0;
	int np;
	// input 
	while(ch=='y'|| ch=='Y')
	{
		cout <<"\nEnter the LHS of the production: ";
		cin >>lhs;
		cout<<"Number of productions of "<<lhs<< " :";
		cin>> np;
		set<string> s1;
		while(np>0)
		{
			cout <<"\nEnter the RHS of the productions separately: ";
			cin >> rhs;
			s1.insert(rhs);
			np--;
		}
		production[lhs]=s1;
		cnt++;
		cout<<"\nAny more production(y/n)?";
		cin>>ch;
	}
	
	set<string>::iterator st2;
	map<char,set<string> > ::iterator it1,it2,it3;
	/*
	it1=production.begin();   //it1 -> for production map
	it2=first.begin();       //it2 -> for first map
	it3=follow.begin();      //it3 -> for follow map
	*/
	
	char start;
	for(it1=production.begin(); it1!=production.end(); it1++)
	{
		cout<< it1->first  << "->" ;
		set<string > s2=it1->second;
		st2=s2.begin();
		while(st2!=s2.end())
		{
			cout<<*st2<<"  ";
			st2++;
		}
		cout<<endl;
	}

	first=FIRST(production);
	follow=FOLLOW(production);
	
	return 0;
}
