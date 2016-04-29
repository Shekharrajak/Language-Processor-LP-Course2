#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
set<char>null;
vector<string>V[100];
map<char,int>M;
map<int,char>IM;
set<char>T;
set<char>First[100],Follow[100];
int vis[100];
int k;

void compute(int a)
{
    vis[a]=1;
    char ch;
    set<char> temp;
    int i,j;
    for(i=0;i<V[a].size();i++)
    {
        for(j=0;j<=V[a][i].length();j++)
        {
            if(j==V[a][i].length())
            {
                First[a].insert('@');
                continue;
            }
            if(T.find(V[a][i][j])!=T.end()){
                First[a].insert(V[a][i][j]);
                break;
            }
            else{
                ch=V[a][i][j];
                if(vis[M[ch]]==0)
                {
                    compute(M[ch]);
                }
                temp.clear();
                temp.insert(First[M[ch]].begin(),First[M[ch]].end());
                temp.erase('@');
                    First[a].insert(temp.begin(),temp.end());
                    if(null.find(ch)!=null.end())
                        continue;
                    else
                        break;
            }
        }
    }
}
void follow(char ch)
{
    cout<<"Computing Follow of "<<ch<<endl;
    vis[M[ch]]=2;
    int i,j,l,r;
    for(i=0;i<k;i++)
    {
        for(j=0;j<V[i].size();j++)
        {
            for(l=0;l<V[i][j].length();l++)
            {
                if(V[i][j][l]==ch)
                {
                    if(l+1==V[i][j].length())
                    {
                        if(vis[i]==1)
                        {
                            follow(IM[i]);
                        }
                            Follow[M[ch]].insert(Follow[i].begin(),Follow[i].end());
                    }
                    else
                    {
                        for(r=l+1;r<=V[i][j].length();r++)
                        {
                            if(r==V[i][j].length())
                            {
                                if(vis[i]==1)
                                    follow(IM[i]);
                                Follow[M[ch]].insert(Follow[i].begin(),Follow[i].end());
                                break;
                            }
                            if(T.find(V[i][j][r])!=T.end()){
                                Follow[M[ch]].insert(V[i][j][r]);
                                break;
                            }
                            else
                            Follow[M[ch]].insert(First[M[V[i][j][r]]].begin(),First[M[V[i][j][r]]].end());
                            if(null.find(V[i][j][r])!=null.end())
                            {
                                continue;
                            }
                            else
                                break;
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    char start;
    int n,j,i;
    k=0;
    char ch;
    string str;
    cout<<"Enter the no of Productions.. @ for epsilon and start ";
    cin>>n>>start;
    for(int i=0;i<n;i++)
    {
        cin>>ch>>str;
        if(M.find(ch)==M.end()){
            M.insert(mp(ch,k));
            IM.insert(mp(k,ch));
            k++;
        }
        V[M[ch]].pb(str);
        if(str=="@")
            null.insert(ch);
    }
    cout<<"No of terminal "<<endl;
    cin>>n;
    T.insert('@');
    for(i=0;i<n;i++){
        cin>>ch;
        T.insert(ch);
    }
    for(i=0;i<k;i++)
    {
        for(j=0;j<V[i].size();j++)
        {
            if(T.find(V[i][j][0])!=T.end())
            {
                First[i].insert(V[i][j][0]);
            }
        }
    }
    memset(vis,0,sizeof(vis));
    for(i=0;i<k;i++)
    {
        if(vis[i]==0)
        {
            compute(i);
        }
    }
    map<char,int>::iterator itr=M.begin();
    for(;itr!=M.end();itr++)
    {
        cout<<"First of "<<itr->first<<" { ";
        set<char>::iterator it=First[itr->second].begin();
        for(;it!=First[itr->second].end();it++)
            cout<<*it<<" ";
        cout<<endl;
    }
    cout<<"Computing Follow "<<endl;
    Follow[M[start]].insert('$');
    follow(start);
    cout<<"DONE "<<endl;
    itr=M.begin();
    for(;itr!=M.end();itr++)
    {
        if(vis[itr->second]==2)
            continue;
        else
            follow(itr->first);
    }
    for(i=0;i<k;i++)
    {
        cout<<"Follow of "<<IM[i]<<" { ";
        Follow[i].erase('@');
        set<char>::iterator it2=Follow[i].begin();
        for(;it2!=Follow[i].end();it2++)
            cout<<*it2<<" ";
        cout<<endl;
    }
}
/*
10
S
S ABCDE
A a
A @
B b
B @
C c
D d
D @
E e
E @
5 a b c d e

6
S
S Bb
S Cd
B aB
B @
C cC
C @
4 a b c d
*/
