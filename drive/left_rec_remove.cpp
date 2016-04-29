#include <iostream>
#include<string.h>
#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class prod{
	public :
			char S[10],A[10];
			char temp1[20],temp2[20];
			int t1=0,t2=0;
			char left1,left2;
			
			int a1=0,b1=0;
			char alpha[20],beta[20];
			bool flag_alpha = false;
			bool flag_beta = false;
			bool flag_indirect = false;

	void direct(char rec[]){
		int rlen = strlen(rec);
		char left = rec[0];
		//2nd char is =
		int c;
		cout <<"Recursion is : \t "<<rec<<endl;		
		for(int i=2;i<rlen;i++){
			if(rec[i] == left){
				// left most is S means form S->Salpha1|Salpha2|....
				flag_alpha = true;
				c =i+1;
				
				while(rec[c] != '|' && rec[c] != '\0'){
					alpha[a1++] =rec[c++];
				}
				alpha[a1++] = '|';
				i=c;
			}
			else{
				//beta form S->beta1|beta2| ....
				flag_beta =true;
				 c =i;
				while(rec[c] != '|' && rec[c] != '\0'){
					beta[b1++] = rec[c++];
				}
				beta[b1++] = '|';
				i=c;
			}
				
			}
		
		alpha[a1++]='\0';
		beta[b1++]='\0';
			
			cout<<"Alpha is : \t"<<alpha<<endl;
			cout<<"Beta is : \t"<<beta<<endl;
			
			cout<<"After removal recursion is :\n";
			// S->beta1S'|beta2S'|beta3S' ..
			//S'->alpha1S'|alpha2S'|alpha3S' .. 
			cout<<"\tS = ";
			for(int i=0;beta[i] != '\0' ; i++){
				if(beta[i] != '|'){
					cout<<beta[i];	
				}
				else{
					cout<<"S' | ";
				}
				
			}
			cout<<endl;
			cout<<"\tS' = ";
			for(int i=0;alpha[i] != '\0' ; i++){
				if(alpha[i] != '|'){
					cout<<alpha[i];	
				}
				else{
					cout<<"S' | ";
				}
			}
		
	}

};
int main(int argc, char** argv) {
	
	int n;
	prod r;
	memset(r.temp1,0,sizeof r.temp1);
	memset(r.temp2,0,sizeof r.temp2);
	cout<<"Program for removal of left recursion maxi production..\n";
	cout<<"Usage : S=AB|a etc..\n";
	cout<<"Enter number of production :\n";
	cin>>n;
	if(n>1){
		cout<<"------- Indirect left recursion.........\n";
		cout<<"Enter production 1 :\n";
		cin>>r.S;
		cout<<"Enter Production 2 :\n";
		cin>>r.A;
		
		int len1  = strlen(r.S);
		int len2 = strlen(r.A);
		cout << "Length of 1st production is : "<<len1<<endl;
		cout<<"Length of 2nd production is :"<<len2<<endl;
		r.S[len1]='\0';
		r.A[len2]='\0';
		
		cout<<"Entered Production 1 is : "<<r.S<<endl;
		cout<<"Entered Production 2 is : "<<r.A<<endl;
		
		r.left1 = r.S[0];
		r.left2 = r.A[0];
		
		cout<<"LHS of first production : "<<r.left1<<endl;
		cout<<"LHS of second production : "<<r.left2<<endl;
		
		r.t2=0;
		r.t1=0;
		//temp2 contains real modified directed left recursion
		//r.temp2[r.t2++] = (char)r.left1;
			r.temp2[r.t2++] = 'S';
		r.temp2[r.t2++] = '=';
		
		
		int h;
		for(int i=2;i<len1;i++){
			r.t1 =0;
				if(r.S[i] == r.left2){
					cout<<r.S[i]<<endl;
					h =i;
					r.flag_indirect = true;
					//found A left
				
			
				//storing after A.left rest in S production in r.temp1 till '|' 
				while(r.S[h] != '|' && h < len1){
					
					r.temp1[r.t1++] = r.S[h];
					
					h++;
					// index of | is h next time we'll start from i =h
				}
				cout<<"Your temp1 is : "<<r.temp1<<endl;
				cout<<"done 1";
				int i2;
				for(i2=2;i2<len2;i2++){
					// A production RHS 1st one should be A = Sapha|etc|etc..
					while(r.A[i2] != '|' && r.A[i2] != '\0' )
					{
						//replacing A.left with A production RHS
						r.temp2[r.t2++] = (char)r.A[i2++];	
					}
				
					//now rest of the production adding into temp2 which was stored into temp1
					for(int g =0;g<strlen(r.temp1);g++){
						r.temp2[r.t2++] = (char)r.temp1[g];	
					}
					
					r.temp2[r.t2++] = (char)'|';
					//i2--;//since 1 increament already there
				}
				i =h;
			}
			else if(r.S[i] != r.left2){
				r.temp2[r.t2++] = (char)r.S[i];
			}
		}
		r.temp2[r.t2] = '\0';
		cout<<endl;
		int length =strlen(r.temp2);
		for(int i=0;i<length;i++){
			cout<<r.temp2[i];
		}
		cout<<endl;
			r.direct(r.temp2);
		
	}
	else{
		cout<<"------- Direct left recursion.........\n";
		cout<<"Enter production 1 :\n";
		cin>>r.temp2;
		cout<<"\n entered production is " << r.temp2<<endl;
		r.direct(r.temp2);
	}
		
	return 0;
}
/*
i/p

1
S=Sab|Sc|dx|e
*/

