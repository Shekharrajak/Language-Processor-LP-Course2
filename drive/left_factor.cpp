#include <iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char gram[100];
	printf("\nEnter your production : A->");
	gets(gram);
	char part1[100];
	int i,j=0;
	for(i=0;gram[i] != '|';i++){
		part1[j++] = gram[i];
	}
	part1[j++]='$';
	part1[j]='\0';
	char part2[100];
	for(j= ++i,i=0; gram[j] != '\0'; j++,i++){
		part2[i] = gram[j];
	} 
	part2[i++]='$';
	part2[i]='\0';
	printf("part 1 = %s\n",part1);
	printf("part 2 = %s\n",part2);
	
	char modify[200];
	for(i=0;;i++){
		if(part1[i] == part2[i]){
			printf("\ncomparing %c %c",part1[i],part2[i]);
			continue;
		}
		else{
			break;
		}
	}
	int pos=i;
	int k=0;
	for(j=i;part1[j] != '$';j++){
		modify[k++] = part1[j];
	}
	modify[k++] = '$';
	
	modify[k++] = '|';
	for(j=i;part2[j] != '$';j++){
		modify[k++] = part2[j];
	}
	modify[k++] = '$';
	modify[k++] = '\0';
	printf("\nmodify %s\n",modify);
	
	printf("after Left foctoring :\n");
	printf("\nA->");
	for(i=0;i<pos;i++){
		printf("%c", part1[i]);
	}
	printf("%c\n",'X');
	printf("%s","X->");
	puts(modify);
	return 0;
}
/*
input
A=iEtS|iEtSeS
*/
