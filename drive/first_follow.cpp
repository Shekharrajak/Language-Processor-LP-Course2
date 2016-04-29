#include<stdio.h>
#include<conio.h>
#define max 10
#define MAX 15
 
void ffun(int,int);
void fun(int,int[]);
void follow(int i);
char array[max][MAX],temp[max][MAX];
int c,n,t;
int fun2(int i,int j,int p[],int key)
{
    int k;
    //key =0 for non terminal
    if(!key){
        for(k=0;k<n;k++)
        {//finding A1 in LHS , that should be there in production rule
        	if(array[i][j]==array[k][0])
        	{
        		break;
        	}	
        }
        
        p[0]=i;p[1]=j+1;//saving where we was in original production
        fun(k,p);//applying the same rule for A1 = alpha etc ...
    return 0;
    }
    else{
        for(k=0;k<=c;k++){
            if(array[i][j]==temp[t][k])//checking if that terminal is already counted in that row (t) of temp array
            	break;
        }
        if(k>c)return 1;//if not found then it will be at c+1 index, should be added.
        else return 0;//not add
    }
}
 //& =  epsilon symbol.
void fun(int i,int p[])
{
    int j,k,key;
    for(j=2;array[i][j]!='\0';j++)//after the = sign index is 2nd
    {
        if(array[i][j-1]=='='){
            if(array[i][j]>='A'&&array[i][j]<='Z'){
            	key=0;//if non terminal is there A1A2A3....
            fun2(i,j,p,key);
            }
            
        else{//only terminal is there 
            key=1;
            if(fun2(i,j,p,key))//terminal is there then add.
            	{
            		
            	printf("Adding in %d row and %d col : %c\n",t,c+1,array[i][j]);
                temp[t][++c]=array[i][j];
                }
            if(array[i][j]=='&' && p[0]!=-1){ // if epsilon came A= a|$ then vanish A in S=ABCDE go to B means array[p[0]][p[1]]
                if(array[p[0]][p[1]]>='A'&&array[p[0]][p[1]]<='Z'){
                    key=0;//non terminal B comes index row = p[0] and col = p[1]
                    fun2(p[0],p[1],p,key);
                }
            else
                if(array[p[0]][p[1]]!='|'&&array[p[0]][p[1]]!='\0'){//if A=a|@ then firstA) is a and @ here p[0] = -1 and p[1] =-1
                    if(fun2(p[0],p[1],p,key))
                    temp[t][++c]=array[p[0]][p[1]];
                }
            }
        }
        
        }
        else if(array[i][j] =='|')
        {
        	continue;
        }
    }
}
 
char fol[max][MAX],ff[max];int f,l,ff0;
void follow(int i)
{
    int j,k;
    for(j=0;j<=ff0;j++)
        if(array[i][0]==ff[j])
            return;
        if(j>ff0)ff[++ff0]=array[i][0];
            if(i==0)fol[l][++f]='$';
    for(j=0;j<n;j++)
    {//searhcing Non terminal in all productions RHS side
    	for(k=2;array[j][k]!='\0';k++)
                if(array[j][k]==array[i][0])
                    ffun(j,k);//got that Non terminal 
    }
            
}
 
void ffun(int j,int k)
{
    int ii,null=0,tt,cc;
    if(array[j][k+1]=='|'||array[j][k+1]==NULL)//if afeter non terminal nothing then follow it's LHS
    {
    	null=1;
    }
        
    for(ii=k+1;array[j][ii]!='|'&&array[j][ii]!='\0';ii++){
        if(array[j][ii]<='Z'&&array[j][ii]>='A')
        {
            for(tt=0;tt<n;tt++)//find the frist of that non terminal 1st index contains non terminal then aftr it's first elements
                if(temp[tt][0]==array[j][ii])
					{
						break;
					}//got the nont terminal first
					//checking all first elemnt
                    for(cc=1;temp[tt][cc]!=NULL;cc++)
                    {
                        if(temp[tt][cc]=='$')
						{
							null=1;
						}
                        else 
						{//add to follow
							fol[l][++f]=temp[tt][cc];
						}
                    }
        }
        else 
		{
			//terminal then sil=mply add
			fol[l][++f]=array[j][ii];
		}
    }
    if(null)
	{
		follow(j);
	}
}
 
int main()
{
    int p[2],i,j;
    //clrscr();
    printf("Enter the no. of productions :");
    scanf("%d",&n);
    printf("Enter the productions :\n");
    for(i=0;i<n;i++)
        {
        	scanf("%s",array[i]);
        }
        printf("\n");
    for(i=0;i<n;i++)
        {
        	printf("%s\n",array[i]);
        }
    for(i=0,t=0;i<n;i++,t++){
        c=0,p[0]=-1,p[1]=-1;// pointer to manage if A=A1A2A3 .. is there.
        temp[t][0]=array[i][0];
        //temp contains answer t th row 0 th col.
        fun(i,p);
        temp[t][c+1]=NULL;
        printf("First(%c) : [ ",temp[t][0]);
        for(j=1;j<c+1;j++)
            printf("%c,",temp[t][j]);
        printf("\b ].\n");
    }
/* Follow Finding */
    for(i=0,l=0;i<n;i++,l++)
    {
        f=-1;ff0=-1;
        fol[l][++f]=array[i][0];
        follow(i);
        fol[l][++f]=NULL; //we can add '\0' or NULL
    }
    for(i=0;i<n;i++)
    {
        printf("\nFollow[%c] : [ ",fol[i][0]);
        for(j=1;fol[i][j]!=NULL;j++)
            printf("%c,",fol[i][j]);
        printf("\b ]");
    }
    getch();
    return 0;
}
