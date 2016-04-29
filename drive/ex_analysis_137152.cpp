#include <iostream>
#include<string.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

string del="",oper="",id[10],keyword[10],constant="",*literals;
int id_c=0,key_c=0;
int del_n=0,oper_n=0,id_n=0,key_n=0,c_n=0,lit_n=0;
//int check_del(char c){
//	if(c == '('){
//		del_n++;
//		if(del.find(c)){
//			
//			return 0;	
//		}
//		
//		return 1;
//	}
//	else if(c == ')'){
//		del_n++;
//		if(del.find(c)){
//			
//			return 0;	
//		}
//		
//		return 1;
//	}
//	else if(c == '{'){
//		del_n++;
//		if(del.find(c)){
//			
//			return 0;	
//		}
//		
//		return 1;
//	}
//	else if(c == '}'){
//		del_n++;
//		if(del.find(c)){
//			
//			return 0;	
//		}
//		
//		return 1;
//		
//	}else if(c == ']'){
//		del_n++;
//		if(del.find(c)){
//			
//			return 0;	
//		}
//		
//		return 1;
//		
//	}
//	else if(c == '['){
//		del_n++;
//		if(del.find(c)){
//			
//			return 0;	
//		}
//		
//		return 1;
//		
//	}
//	else if(c == ';'){
//		del_n++;
//		if(del.find(c)){
//			
//			return 0;	
//		}
//		
//		return 1;
//		
//	}
//	return 0;
//}
int check_del(char c){
	if(c == '('||c == ')'||c == '{'||c == '}'||c == '['||c == ']'||c == ';'||c == ','){
		return 1;
	}
	return 0;
}

int check_oper(char c){
	if(c == '<'||c == '>'||c == '+'||c == '-'||c == '%'||c == '*'||c == '^'||c == '='){
		return 1;
	}
	return 0;
}

int check_constant(char c){
	if(c >='0' && c <= '9'){
		return 1;
	}
	return 0;
}

string str_id[5] ={"include","stdio.h","stdlib.h","printf","scanf"};

int check_id(string c){
	int size = 5;
	while(size--)
	if(str_id[size].compare(c)){
		return 1;
	}
	return 0;
}
string str_key[] ={"void","main","int","string","float"};
int check_keyword(string c){
	int size = 5;//str_key.length();
	while(size--)
	if(str_key[size].compare(c)){
		return 1;
	}
	return 0;
}
//void check_keyword(char c){
//	if(c = ''||c = ')'||c = '{'||c = '}'||c = ';'||c = ','||c = ']'||c = '['){
//		return 1;
//	}
//	return 0;
//}
//void check_del(char c){
//	if(c = '('||c = ')'||c = '{'||c = '}'||c = ';'||c = ','||c = ']'||c = '['){
//		return 1;
//	}
//	return 0;
//}
void analyse(string s){
	int i=0;
	int space1=0;
	int space2;
	cout<<"inside analyser"<<endl;
	while(s[i] != '\0'){
		if(check_del((char)s[i])){
			del+=s[i];
		//const char tmp = s[i];
		//	del.append(tmp);
			//del.append(s[i]);
			cout<<"\t del done\n";
		}
		else if(check_oper(s[i])){
			//oper.append(s[i]);
			oper+=s[i];
			cout<<"\t oper done\n";
		}
		else if(check_constant(s[i])){
				constant+=s[i];
				cout<<"\t const done\n";
		}
//		else if(s[i]=='"'){
//			string t =" ";
//			while(s[++i] != '"'){
//					t+=s[i];
//					
//			}
//			(*literals++) = t;
//			
//			cout<<"\t del done\n";
//		}
		else{
			
			int space3=space1;
			for(;space3<i;space3++){
				string tmp = s.substr(space3,i);
				for(int j=0;j<5;j++){
					if(tmp.compare(str_id[j])==0){
						id[id_c++] = tmp;
					}
					else if(tmp.compare(str_key[j])==0){
						keyword[key_c++] = tmp;
					}
				}
					
			}
			
		}
//		else {
//		
//		while(space2 < i ){
//			
//			
//			if(check_id(s.substr(space2,i))){
//				(*id++)=s.substr(space2,i);
//			}
//			else if(check_keyword(s.substr(space2,i))){
//				(*keyword++)=s.substr(space2,i);
//			}
//			
//			
//			space2++;
//		}
//		if(s[i]==' ')
//		{space2=i;}
//	}
//		if(s[i]==' ')
//		{space1=i;}
	i++;
	}
	return;
}
int main(int argc, char** argv) {
	string str;
	cout<<"Entered the string : \n";
	str = "#include<stdio.h> #include<stdlib.h> void main(){printf( \"Hello\");}";
	
	cout<<str<<endl;
	analyse(str);
	
	//cout<<"total delemeters : "<<del_n<<endl;
	cout<<"Delemeters are :\n";
	for(int i=0;i<del.length();i++){
		cout<<del[i]<<endl;
	}
	cout<<"Operators are :\n";
	for(int i=0;i<oper.length();i++){
		cout<<oper[i]<<endl;
	}
//	cout<<"literals are :\n";
//	for(int i=0;literals[i].compare('\0') ;i++){
//		cout<<literals[i]<<endl;
//	}
	
	
	cout<<"constants are :\n";
	if(constant.length()==0){
		cout<<"No constants\n";
	}
	else{
	
		for(int i=0;i<constant.length();i++){
			cout<<constant[i]<<endl;
		}
	}
	cout<<"keywords are :\n";
	for(int i=0;i<5;i++){
		cout<<keyword[i]<<endl;
	}
	cout<<"identifiers are :\n";
	for(int i=0;i<5;i++){
		cout<<id[i]<<endl;
	}
	
	
	
	
	return 0;
}
