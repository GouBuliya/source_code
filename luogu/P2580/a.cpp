#include<bits/stdc++.h>
#include <cmath>
using namespace std;
namespace my{
#define ll long long 
const int INF=(1<<31);
ll re ()
{
    ll t;
    cin>>t;
    return t;
}
const int maxn=1e4*50+10;
int tree[maxn][26];
int word[maxn];
vector<bool>vis(maxn);
int ans=0;
int tot=0;
void insert(string &S)
{
    int u=0;
    for(auto i:S)
    {
        i-='a';
        if(!tree[u][i])
            tree[u][i]=++tot;
        u=tree[u][i];
    }
    word[u]++;
}
int ask(string& S)
{
    int u=0;
    for(auto i:S)
    {
        i-='a';
        if(!tree[u][i])
            return 2;
        u=tree[u][i];
    }
    if(!vis[u])
    {
        vis[u]=1;
        return 1;
    }
    else 
        return 0;
}
signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n=re();
    while(n--)
    {
        string S;
        cin>>S;
        insert(S);
    }
    int m=re();
    while(m--)
    {
        string S;
        cin>>S;
        int op=ask(S);
        if(op==2)
            cout<<"WRONG"<<'\n';
        else if (op==1)
            cout<<"OK"<<'\n';
        else 
            cout<<"REPEAT"<<'\n';
    }
    return 0;
}
}
signed main ()
{
    return my::main();
}

