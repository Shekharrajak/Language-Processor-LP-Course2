#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define numTerm 4+1 //plus 1 for $

stack<char> st;
//char term[][numTerm]{
//	//here terminals are id ,+,*,$
//				{'e', '>', '>', '>'},
//				{'<', '>', '<', '>'},
//				{'<', '>', '>', '>'},
//				{'<', '<', '<', 'A'}
//				
//};

map< char ,string > rtable;

int preced(char c){
	switch(c){
		case 'i':return 99;
		case '*':return 3;
		case '+':return 2;
		case '$':return 0;		
	}
}
int main(int argc, char** argv) {
//	list<char> id= {'e', '>', '>', '>'};
//	list<char> plus= {'<', '>', '<', '>'};
//	list<char> astr= {'<', '>', '>', '>'};
//	list<char> doller= {'<', '<', '<', 'A'};
//	list<char> id= "e>>>";
	string id = "e>>>";
	string plus= "<><>";
	string doller="<<<A" ;
	string astr="<>>>" ;
	rtable.insert(make_pair('i',id));
	rtable.insert(make_pair('+', plus));
	rtable.insert(make_pair('*', astr));
	rtable.insert(make_pair('$', doller));
	
	map<char,int> tint;
	tint.insert(make_pair('i',0));
	tint.insert(make_pair('+',1));
	tint.insert(make_pair('*',2));
	tint.insert(make_pair('$',3));
	
	cout<<"Operator Precedence parser ...\n";
	
	cout<<"\nOperator relation table is :\n";
//	cout<<"size of table is :"<<sizeof(term)/sizeof(term[0])<<endl;
//	for(int i=0;i<sizeof(term)/sizeof(term[0]) ;i++){
//		for(int j=0;j<sizeof(term)/sizeof(term[0]) ;j++){
//			cout<<term[i][j]<<"  ";		
//		}	
//		cout<<endl;
//	}
	
	cout<<" size of the relationsal table is : "<<rtable.size()<<endl;
	map<char,string>::iterator rit = rtable.begin();
	//cout<< (*rit).first<<endl;
	for( ; rit != rtable.end();rit++){
		cout<< (*rit).first <<" | ";
		string tmp = (*rit).second;
		for(int j=0;j<sizeof(tmp)/s    izeof(tmp[0]); j++){
			cout<<tmp[j]<<" ";
		}
		cout<<endl;
	}
	
	string w;
	cout<<"enter the string to pass ex: i+i*i$\n";
	cin>>w;
	st.push('$');
	int j=0;
	while(j<w.length()){
		cout<<"string w i/p pointer at j= "<<j+1<<" "<<w[j] <<endl;
		cout<<"and current stack :\t";
		stack<char> tmp(st);
		while(!tmp.empty()){
			cout<<tmp.top()<<"  ";
			tmp.pop();
		}
		cout<<endl;
		cout<< " rtable[st.top()][tint[w[j]]]  is " << rtable[st.top()][tint[w[j]]] <<endl;
		if(w[j] == '$' && st.top() == '$'){
			cout<<" Accepting..\n";
			break;
		}
		// TOS on + check etc..
		//else if( preced(w[j]) >= preced(st.top()) ){
		
		else if( rtable[st.top()][tint[w[j]]] == '<' ){
			cout<<"\n\npushing "<< w[j] <<" ..\n";
			st.push(w[j]);
			j++;
			continue;
		}
		else if(rtable[st.top()][tint[w[j]]] == '>'){
			//while( st.top() < preced(w[j])  ){
			while(rtable[st.top()][tint[w[j]]] == '>'){
			
				cout<<"\n\npoping out "<< st.top()<<" .. \t reducing into E\n";
				st.pop();
			}
		}
		else{
			cout<<"\n\nError occur..\n";
			break;
		}
		
	}
	
	
	
	return 0;
}

/*
input hint already print
*/
