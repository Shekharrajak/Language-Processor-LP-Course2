/*
	program is based on the table from copy after mid portion

*/
#include <iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;
#define NUM_PROD 3
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
map<int, vector<string> > slr_table_action;
map<int, vector<int> > slr_table_goto;

stack<string> s;
char str[10];

string productions[NUM_PROD];
void init_production(){
	productions[0] = "S=AA\0";
	productions[1] = "A=aA\0";
	productions[2] = "A=b\0";
	
	cout<<"\n\nProductions are :\n";
	for(int i =0 ;i<NUM_PROD;i++){
		cout<<productions[i]<<endl;
	}
}

void print_slr_table(){
	cout<<endl;
	cout<<"\taction"<<"\t\t\t goto\n";
	map<int, vector<string> >::iterator it = slr_table_action.begin();
	map<int, vector<int> >::iterator it2 = slr_table_goto.begin();
	while(it != slr_table_action.end()){
		cout<<endl;
		cout<<it->first<<"|\t";
		vector<string> v = it->second;
		vector<string>::iterator itv = v.begin();
		
		//goto
		vector<int> v2 = it2->second;
		vector<int>::iterator itv2 = v2.begin();
		
		while(itv != v.end()){
			//action
			cout<< *itv <<"\t";
			itv++;
		}
		
		cout<<" | ";//separate action and goto
		
		while(itv2 != v2.end()){
			//goto
			cout<< *itv2 <<"\t";
			itv2++;
		}
		
		it++;
		it2++;
	}
	return ;
}

void init(){
	//action part : a b $
	// a = 0 , b=1 , $=2
	vector<string> v0;
	v0.push_back("S3\0");
	v0.push_back("S4\0");
	v0.push_back("ER\0"); 
	slr_table_action[0] =  	v0;
	
	vector<string> v1;
	v1.push_back("ER\0");
	v1.push_back("ER\0");
	v1.push_back("AC\0");
	slr_table_action[1] = v1;
	
	vector<string> v2;
	v2.push_back("S3\0");
	v2.push_back("S4\0");
	v2.push_back("ER\0");//  = {"S3", "S4", "ER"};
	slr_table_action[2] = v2;
	
	vector<string> v3;
	v3.push_back("S3\0");
	v3.push_back("S4\0");
	v3.push_back("ER\0"); 
	// = {"S3", "S4", "ER"};
	slr_table_action[3] = v3;
	
	vector<string> v4;
	v4.push_back("R3\0");
	v4.push_back("R3\0");
	v4.push_back("R3\0"); 
	 //= {"R3", "R3", "R3"};
	slr_table_action[4] = v4;
	
	vector<string> v5;
	v5.push_back("R1\0");
	v5.push_back("R1\0");
	v5.push_back("R1\0"); 
	 //= {"R1", "R1", "R1"};
	slr_table_action[5] =v5;
	
	vector<string> v6;
	v6.push_back("R2\0");
	v6.push_back("R2\0");
	v6.push_back("R2\0"); 
	 //= {"R2", "R2", "R2"};
	slr_table_action[6] =  v6;
	
	// goto A and S
	vector<int> _v0;
	_v0.push_back(2);
	_v0.push_back(1);
	 //= {2,1};
	slr_table_goto[0] =  _v0;
	
	vector<int> _v1;
	_v1.push_back(-1);
	_v1.push_back(-1);
	// = {-1,-1};
	slr_table_goto[1] = _v1;
	
	vector<int> _v2;// = {5,-1};
	_v2.push_back(5);
	_v2.push_back(-1);
	slr_table_goto[2] = _v2;
	
	vector<int> _v3;// = {6 , -1};
	_v3.push_back(6);
	_v3.push_back(-1);
	slr_table_goto[3] = _v3;
	
	vector<int> _v4;// = {-1,-1};
	_v4.push_back(-1);
	_v4.push_back(-1);
	slr_table_goto[4] = _v4;
	
	vector<int> _v5;// = {-1,-1}
	_v5.push_back(-1);
	_v5.push_back(-1);
	slr_table_goto[5] =_v5;
	
	vector<int> _v6;// = {-1,-1};
	_v6.push_back(-1);
	_v6.push_back(-1);
	slr_table_goto[6] =  _v6;
	
	print_slr_table();
	return ;
}


void init_stack(){
	//string zero = "0";
	string z  = "0\0";
	cout<<"init_stack:"<<z<<endl;
	s.push(""+z);	
	//cout<<s.top()<<endl;
}

int convert_to_col_index(char c){
	switch(c){
		case 'a' : return 0;break;
		case 'b' : return 1;break;
		case '$' : return 2;break;
		case 'A' : return 0;break;
		case 'S' : return 1;break;
	}
}
string mapping(int top , char c){
	//mapping with table
	vector<string> vs; 
	if(slr_table_action.find(top) != slr_table_action.end()){
		vs = slr_table_action[top];
	}
	return vs[convert_to_col_index(c)];
}

int mapping_goto(int top , char c){
	//mapping with table
	vector<int> vi;// = slr_table_goto.find(top);
	if(slr_table_goto.find(top) != slr_table_goto.end()){
		vi = slr_table_goto[top];
	}
	return vi[convert_to_col_index(c)];
}
void parse(){
	
	for(int i =0 ;i < sizeof(str) ; i++){
		char c = str[i];
		cout<<"\n mapping "<<c <<" with "<<s.top();
		string map_res = mapping(atoi((s.top()).c_str()), c);
		cout<<"\t got:"<<map_res;
		if(map_res[0] == 'S'){
			string p ="" + str[i];
			cout<<"\t p:"<<p;
			s.push(p);
			s.push(""+map_res[1]);
		}
		else if(map_res[0] == 'R'){
			string prod = productions[map_res[1]];
			int rhs_len = prod.length() -2;
			//pop rhs element*2
			for(int i=0;i<rhs_len;i++){
				s.pop();
			}  
			int _goto = atoi((s.top()).c_str());
			char prod_lhs = prod[0];
			s.push("" + prod_lhs);
			int map_res_goto = mapping_goto(_goto, prod_lhs);
			char tmp[2];
			tmp[0] =map_res_goto;
			tmp[1] = '\0'; 
			s.push(tmp);
		}
		else if(map_res[0] == 'A'){
			if(str[i] == '$'){
				cout<<"Accepted..\n";
				exit(0);
			}
		}
		else{
			cout<<"error at "<< str[i] << s.top()<<"\n";
		}
	}
	return ;
}

int main(int argc, char** argv) {
	init();
	init_production();
	init_stack();
//string o = "" + 'o';
	char a = 's' ;
	int z = 0;
	//string o = z;
//	int aa = 48;
//	char ca = aa;
//	cout<<endl<<""+ca<<endl;
	cout<<"\n enter the string (eg.  aabb$ )\n";
	cin>>str;
	
	
	
	cout<<endl;
	
	parse();
	return 0;
}
