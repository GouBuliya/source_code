#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int maxn=5e5+10;
vector<int>G[maxn];
int dep[maxn];//每个店的深度
int anc[maxn][20];//anc[i][j]->i的第2^j个祖先
int n,m,s;
void dfs(int u,int fa)
{
    for(auto &i:G[u])
    {
        if(fa==i)continue;
        dep[i]=dep[u]+1;
        anc[i][0]=u;
        dfs(i,u);
    }
}
void init()
{
    for(int j=1;j<=18;j++)
    {
        for(int i=1;i<=n;++i)
        {
            anc[i][j]=anc[anc[i][j-1]][j-1];
        }
    }
}
int LCA(int u,int v)
{
    if(dep[u]<dep[v])swap(u,v);
    for(int i=18;i>=0;i--)
    {
        if(dep[anc[u][i]]>=dep[v])
        {
            u=anc[u][i];
        }
    }
    if(u==v)
    {
        return u;
    }
    for(int i=18;i>=0;i--)
    {
        if(anc[u][i]!=anc[v][i])
            u=anc[u][i],v=anc[v][i];
    }
    return anc[u][0];
}
signed main()
{
    freopen("in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dep[s]=1;
    dfs(s,0);
    init();
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        cout<<LCA(u,v)<<endl;
    }

}   

    
