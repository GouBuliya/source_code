#include <bits/stdc++.h>
using namespace std;
const int maxn=5e4+10;
int n;
vector<int>G[maxn];
int m[maxn];
int sz[maxn];
void dfs_size(int u,int fa)
{
    sz[u]=1;
    for(auto &v:G[u])
    {
        if(v!=fa)
        {
            dfs_size(v,u);
            sz[u]+=sz[v];
        }
    }

   // cout<<u<<":"<<sz[u]<<endl;
}
void dfs_m(int u,int fa)
{
    m[u]=0;
    for(auto &v:G[u])
    {
        if(v!=fa)
        {
            dfs_m(v,u);
            m[u]=max(m[u],sz[v]);
        }
    }
    m[u]=max(m[u],n-sz[u]);

 }
long long ans;
void dfs_ans(int u,int fa,int d)
{
    ans+=d;
    for(auto &v:G[u])
    {
        if(v!=fa)
        {
            dfs_ans(v,u,d+1);
        }
    }
}
signed main ()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("in","r",stdin);
    cin>>n;
    for(int i=2;i<=n;++i)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs_size(1,0);
    dfs_m(1,0);
    int center=INT_MAX;
    int centerpos=0;
    for(int i=1;i<=n;++i)
        if(center>m[i])
        {
            center=m[i];
            centerpos=i;
        }
    dfs_ans(centerpos,0,0);
    cout<<centerpos<<" "<<ans<<endl;
    fclose(stdin);
}
    
