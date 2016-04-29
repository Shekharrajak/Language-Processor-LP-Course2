#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

//Structure Declaration

struct production
{
            char lf;
            char rt[10];
            int prod_rear;
            int fl;
};
struct production prodn[20],prodn_new[20];     //Creation of object

//Variables Declaration

int b=-1,d,f,q,n,m=0,c=0;
char terminal[20],nonterm[20],alpha[10],extra[10];
char epsilon='^';

//Beginning of Main Program

void main()
{
   clrscr();

   //Input of Special characters
   cout<<"\nEnter the number of Special characters(except non-terminals): ";
   cin>>q;
   cout<<"Enter the special characters for your production: ";
   for(int cnt=0;cnt<q;cnt++)
   {
     cin>>alpha[cnt];
   }

   //Input of Productions

   cout<<"\nEnter the number of productions: ";
   cin>>n;
   for(cnt=0;cnt<=n-1;cnt++)
   {
     cout<<"Enter the "<< cnt+1<<" production: ";
     cin>>prodn[cnt].lf;
     cout<<"->";
     cin>>prodn[cnt].rt;
     prodn[cnt].prod_rear=strlen(prodn[cnt].rt);
     prodn[cnt].fl=0;
   }

   //Condition for left factoring

   for(int cnt1=0;cnt1<n;cnt1++)
   {
     for(int cnt2=cnt1+1;cnt2<n;cnt2++)
     {
            if(prodn[cnt1].lf==prodn[cnt2].lf)
            {
              cnt=0;
              int p=-1;
              while((prodn[cnt1].rt[cnt]!='\0')&&(prodn[cnt2].rt[cnt]!='\0'))
              {
                if(prodn[cnt1].rt[cnt]==prodn[cnt2].rt[cnt])
                {
                  extra[++p]=prodn[cnt1].rt[cnt];
                  prodn[cnt1].fl=1;
                  prodn[cnt2].fl=1;
                }
                else
                {
                  if(p==-1)
                          break;
                  else
                  {
                          int h=0,u=0;
                          prodn_new[++b].lf=prodn[cnt1].lf;
                          strcpy(prodn_new[b].rt,extra);
                          prodn_new[b].rt[p+1]=alpha[c];
                          prodn_new[++b].lf=alpha[c];
                          for(int g=cnt;g<prodn[cnt2].prod_rear;g++)
                           prodn_new[b].rt[h++]=prodn[cnt2].rt[g];
                           prodn_new[++b].lf=alpha[c];
                          for(g=cnt;g<=prodn[cnt1].prod_rear;g++)
                           prodn_new[b].rt[u++]=prodn[cnt1].rt[g];
                           m=1;
                           break;
                   }
                 }
                 cnt++;
               }
               if((prodn[cnt1].rt[cnt]==0)&&(m==0))
               {
                         int h=0;
                         prodn_new[++b].lf=prodn[cnt1].lf;
                         strcpy(prodn_new[b].rt,extra);
                         prodn_new[b].rt[p+1]=alpha[c];
                         prodn_new[++b].lf=alpha[c];
                         prodn_new[b].rt[0]=epsilon;
                         prodn_new[++b].lf=alpha[c];
                         for(int g=cnt;g<prodn[cnt2].prod_rear;g++)
                         prodn_new[b].rt[h++]=prodn[cnt2].rt[g];
               }
               if((prodn[cnt2].rt[cnt]==0)&&(m==0))
               {
                 int h=0;
                 prodn_new[++b].lf=prodn[cnt1].lf;
                 strcpy(prodn_new[b].rt,extra);
                 prodn_new[b].rt[p+1]=alpha[c];
                 prodn_new[++b].lf=alpha[c];
                 prodn_new[b].rt[0]=epsilon;
                 prodn_new[++b].lf=alpha[c];
                 for(int g=cnt;g<prodn[cnt1].prod_rear;g++)
                  prodn_new[b].rt[h++]=prodn[cnt1].rt[g];
               }
               c++;
               m=0;
             }
       }
    }

   //Display of Output

    cout<<"\n\n********************************";
    cout<<"\n      AFTER LEFT FACTORING      ";
    cout<<"\n********************************";
    cout<<endl;
    for(int cnt3=0;cnt3<=b;cnt3++)
            {
                        cout<<"Production "<<cnt3+1<<" is: ";
                        cout<<prodn_new[cnt3].lf;
                        cout<<"->";
                        cout<<prodn_new[cnt3].rt;
                        cout<<endl<<endl;
            }

    for(int cnt4=0;cnt4<n;cnt4++)
    {
    if(prodn[cnt4].fl==0)
    {
    cout<<"Production  "<<cnt3++<<" is: ";
    cout<<prodn[cnt4].lf;
    cout<<"->";
    cout<<prodn[cnt4].rt;
    cout<<endl<<endl;
    }
  }
 getche();
}    //end of main program

