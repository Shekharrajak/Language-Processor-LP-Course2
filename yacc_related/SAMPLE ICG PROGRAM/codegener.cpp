#include "rule.h"
int quadIndex=0;
int tempGenerated=0;
int labelGenerated = 0;
struct Quadruple{
	char *result;
	char *addr1;
	char *op;
	char *addr2;
	char *addr3;
	int  label;
};
Quadruple quad[1000];
typedef YYSTYPE::BackpatchList patchList;

patchList *makelist(int i){
 patchList *temp =  new patchList();
 temp->ins  = i;
 temp->next = NULL;
 return temp;
}
patchList *mergeList(patchList *p1,patchList *p2){
    if(p1==NULL)return p2;
    if(p2==NULL)return p1;
    patchList *t = p1;
    while(t->next!=NULL);
    t->next=p2;
    return p1;
}
void backpatch(patchList *p,int i){
    patchList *t = p;
    while(t!=NULL){
        quad[t->ins].label = i;
        t=t->next;
    }
}
char* newtemp(){
	char *temp= new char[10];
	snprintf(temp,10,"t%d",tempGenerated);
	tempGenerated++;
	return temp;
}
char* newlabel(){
	char *temp=new char[10];
	snprintf(temp,10,"L%d",labelGenerated);
	labelGenerated++;
	return temp;
}

void printCode(){
	for(int i=0;i<quadIndex-1;i++){
	     printf("\n");
        if(!strcmp(quad[i].result,"if")){
            printf("%d : %s\t%s\t%s\t%s\t%s\t%d",i,quad[i].result,quad[i].addr1,quad[i].op,quad[i].addr2,quad[i].addr3,quad[i].label);
            continue;
        }
        if(!strcmp("goto",quad[i].result)){
             printf("%d : %s\t%d",i,quad[i].result,quad[i].label);
        }
	    else{
            printf("%d : %s\t=\t%s",i,quad[i].result,quad[i].addr1);
            if(quad[i].op!=NULL)
                printf("\t%s",quad[i].op);
            else continue;
            if(quad[i].addr2!=NULL)
                printf("\t%s",quad[i].addr2);
            else continue;
            if(quad[i].addr3!=NULL)
                printf("\t%s",quad[i].addr3);
            else continue;
            if(quad[i].label!=0)
                printf("\t%d",quad[i].label);
	    }
	}
	 printf("\n%d : %s\n",quadIndex-1,quad[quadIndex-1].result);
	 printf("\n");
}

void gencode(const char *result,const char*addr1,const char *op,const char *addr2){
        quad[quadIndex].result=(char*)result;
		quad[quadIndex].addr1=(char*)addr1;
        quad[quadIndex].op=(char*)op;
		quad[quadIndex].addr2=(char*)addr2;
		quad[quadIndex].addr3=NULL;
		quad[quadIndex].label=0;
		quadIndex++;
}
void gencode(const char *result,const char *unop,const char*addr1){
        quad[quadIndex].result=(char*)result;
		quad[quadIndex].addr1=NULL;
        quad[quadIndex].op=(char*)unop;
		quad[quadIndex].addr2=(char*)addr1;
		quad[quadIndex].addr3=NULL;
		quad[quadIndex].label=0;
		quadIndex++;
}
void gencode(const char*result,const char *addr1,const char *op,const char *addr2,const char *addr3,int label){

		quad[quadIndex].result=(char*)result;
		quad[quadIndex].addr1=(char*)addr1;
		quad[quadIndex].op=(char*)op;
		quad[quadIndex].addr2=(char*)addr2;
		quad[quadIndex].addr3=(char*)addr3;
		quad[quadIndex].label=label;
		quadIndex++;
}
void gencode(const char *result,const char *addr1){
		quad[quadIndex].result = (char*)result;
		quad[quadIndex].addr1 = (char*)addr1;
		quad[quadIndex].addr2 = NULL;
		quad[quadIndex].addr3 = NULL;
		quad[quadIndex].label =0;
		quadIndex++;
}
void gencode(const char *result,int label){
		quad[quadIndex].result = (char*)result;
		quad[quadIndex].addr1 = NULL;
		quad[quadIndex].addr2 = NULL;
		quad[quadIndex].addr3 = NULL;
		quad[quadIndex].label = label;
		quadIndex++;
}


