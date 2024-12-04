#include<bits/stdc++.h>
using namespace std;
#define ll long long
namespace goubuli{
const int INF=(1<<31);
ll re ()
{
    ll t;
    cin>>t;
    return t;
}
int nxt[7][100];
string rule[7];
string RULE[7];
int num=1;
void init ()
{
    for(int i=1;i<num;++i)
    {
        string P=rule[i];
        int len=P.length();
        int j=0,t=-1;
        nxt[i][0]=-1;
        while(j<len-1)
            if(t<0||P[t]==P[j])
                j++,t++,nxt[i][j]=t;
            else 
                t=nxt[i][t];
    }
}
pair<int,bool>spcpt(string& S,int n,int be)
{
    string P=rule[n];
    for(int i=be;i<S.length();++i)
        if(P[0]==S[i])
            return {i,1};
    return {0,0};
}
pair<int,bool> cpt(string& S,int n,int be)
{
    int lenS=S.length();
    int lenP=rule[n].length();
    if(lenP==1)
        return spcpt(S,n,be);
    int i=be,j=0;
    while(i<lenS&&j<lenP)
        if(j<0||S[i]==rule[n][j])
            i++,j++;
        else 
            j=nxt[n][j];
    if(j>=lenP)
        return pair<int,bool>{i-j,1};
    else 
        return {0,0};
}
string chenge(string S,int n,int p)
{
    int len=rule[n].length();
    S.erase(p,len);
    S.insert(p,RULE[n]);
    return S;
}
queue<pair<string,int>>que;
map<string,int>vis;
bool flag=1;
void BFS(string A,string B)
{
    que.push({A,0});
    while(!que.empty())
    {
        string S=que.front().first;
        int deep=que.front().second;
        que.pop();
        if(vis[S])
            continue;
        vis[S]=1;
        if(S==B)
        {cout<<deep<<endl;flag=0;return ;}
        for(int i=1;i<num;++i)
        {
            for(int j=0;j<S.length();++j){
            auto [p,m]=cpt(S,i,j);
            if(m)
            {
               que.push({chenge(S,i,p),deep+1});
            }}
        }           
    }

}
    
signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string A,B;
    cin>>A>>B;
    while(cin>>rule[num]>>RULE[num]){num++;}
    init();
    BFS(A,B);
    if(flag)cout<<"NO ANSWER!"<<endl;
    return 0;
}
}
signed main ()
{
    return goubuli::main();
}
