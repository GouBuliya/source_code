#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int n,K;
const int maxn=5e5+10;
vector<int>G[maxn];
int d[maxn];
int anc[maxn][20];
int C[maxn];
void dfs(int u,int fa)
{
    if(!G[u].empty())
    for(auto &i: G[u])
    {
                if(i==fa)
            continue;
                d[i]=d[u]+1;
               anc[i][0]=u;
                dfs(i,u);
            }
}
void init()
{
    for(int j=1;j<=18;j++)
        for(int i=1;i<=n;++i)
            anc[i][j]=anc[anc[i][j-1]][j-1];
}
 int LCA(int u,int v)
{
    if(d[u]<d[v])swap(u,v);
    for(int i=18;i>=0;i--)
        if(d[anc[u][i]]>=d[v])
            u=anc[u][i];
            if(u==v)
    {
        ;return u;}
    for(int i=18;i>=0;--i)
        if(anc[u][i]!=anc[v][i])
            u=anc[u][i],v=anc[v][i];
    return anc[u][0];
}
int maxans=0;
void dfs1(int u)
{
    for(auto &i:G[u])
    {
        if(i==anc[u][0])
            continue;
        dfs1(i);
        C[u]+=C[i];
       // cout<<"DFS查询："<<" u="<<u<<endl<<"成功"<<endl;
    }
    maxans=std::max(maxans,C[u]);
}

signed main ()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("in","r",stdin);
    cin>>n>>K;
    for(int i=1;i<=n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
        dfs(1,0);
        init();
        while(K--)
    {
        int u,v;
        cin>>u>>v;
        int lca=LCA(u,v);
        C[lca]--;
        C[anc[lca][0]]--;
        C[u]++;
        C[v]++;
    }
       dfs1(1);
    cout<<maxans<<endl;

}

