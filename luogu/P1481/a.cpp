#include<bits/stdc++.h>
#include <pthread.h>
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
const int maxn=2100*75;
int tree[maxn][26];
int word[maxn];
int max(int a,int b)
{return a>b?a:b;}
int ans=0;
int tot=0;
void insert(string& S)
{
    int len=S.length();
    int u=0;
    int cnt=0;
    for(auto i:S)
    {
        i-='a';
        if(tree[u][i]==0)
        {
            tree[u][i]=++tot;
        }
        u=tree[u][i];
        cnt+=word[u];
    }
    word[u]++;
    ans=max(ans,cnt+1);
    
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
    cout<<ans<<endl;
    return 0;
}
}
signed main ()
{
    return my::main();
}

