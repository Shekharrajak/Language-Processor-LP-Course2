#include <iostream>
#include<bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int non_term;
	cout<<"enter the number of non terminals.\n";
	cin>>non_term;
	//considering A B C D E as non terminals
	//considering n,i,+,-,/,* as terminals
	//$ as epsilon
	char var[] = {'G','S','L','M'};
	string first[non_term];
	string follow[non_term];
	for(int i=0;i<non_term;i++){
		cout<<"Enter the first element for "<<i<<"th " <<var[i]<< " non terminal\n";
		cin>>first[i];
		cout<<"Enter the follow element for "<<i<<"th " <<var[i]<< " th non terminal\n";
		cin>>follow[i];
	}
	
	for(int i=0;i<non_term;i++){
		cout<<first[i];
	}
	
	for(int i=0;i<non_term;i++){
		cout<<follow[i];
	}
	
	string gram[]={
						"G=SS",
						"S=(L)",
						"S=a",
						"L=SM",
						"M=bSM"
						
					};
	for(int i =0;i<4;i++){
		cout<<gram[i]<<endl;
	}
	char term[5] ={
					'(',')','a','b','$'
					};
	
	int num_term = 4;
	string mat[4][5];
	non_term=4;
	for(int i=0;i<4;i++){
		char temp = gram[i][2];
		for(int k=0;k<non_term;k++){
			int l;
			for( l=0;l<non_term;l++){
				if(first[l][0] == temp){
					break;
				}
			}
			
			
			for(int j1=0;first[l][j1] != '\0'; j1++){
			int k1;
				if(k1=0; k1<5;k1++){
					if(first[l][j1] == term[k1]){
						break;
					}
				}
				mat[i][k1] = gram[i];
			}
		}
		
	}
	
	//printing
	for(int u=0;u<non_term;u++){
		for(int v =0;v<num_term;v++){
			printf(" %s ",mat[u][v]);
		}
		printf("\n");
	}
	return 0;
	
}


