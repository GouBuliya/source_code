#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e4+10;

vector<int>G[maxn];
int d [maxn];
int ct[2];
int sz[maxn];
int wt[maxn];
int n;
void getcenter(int u,int fa)
{
    sz[u]=1;
    wt[u]=n-sz[u];
    for(auto &v:G[u])
    {
        if(v!=fa)
        {
            getcenter(v,u);
            wt[u]=max(wt[u],sz[v]);
            sz[u]+=sz[v];
        }
    }
    wt[u]=max(wt[u],n-sz[u]);
    if(wt[u]<=n/2)
    {
        ct[ct[0]!=0]=u;
    }
}
signed main ()
{
    ios::sync_with_stdio(0);
    freopen("in","r",stdin);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    getcenter(1,0);
    int ans=99999999;
    int ansi=0 ;
    for(int i=1;i<=n;++i)
    {
        if(ans>wt[i])
        {
            ans=wt[i];
            ansi=i;
        }
    }
    cout<<ansi<<endl;
    fclose(stdin);
}
