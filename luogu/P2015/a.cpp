#include<bits/stdc++.h>
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
signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n=re();
    int Q=re();
    const int maxn=110;
    vector<int>G[110];
    vector<int>W(maxn);
    for(int i=1;i<n;++i)
    {
        auto u=re();
        auto v=re();
        auto w=re();
        G[u].push_back(v);
        W[v]+=w;
    }
    vector<int>f(maxn);
    function<void(int,int)>dfs=[&](int u,int fa)
    {
        f[u]+=W[u];
        for(auto &v : G[u])
        {
            if(v!=fa)
            {
                dfs(v,u);
                f[u]+=f[v];
            }
        }
    };
    dfs(1,0);
    int ans=f[1];
    vector<bool>vis(maxn);
    function<bool(int,int)>cmp=[&](int a,int b){return f[a]<f[b];};
    function<int(int,int)>dfs1=[&](int u,int fa)
    {
        if(G[u].empty())
        {
            int t=f[u];
            f[u]=0;
            ans-=t;
            vis[u]=1;
            return t;
        }
        else {
            sort(G[u].begin(),G[u].end(),cmp);
            int V=0;
            for(auto &v:G[u])
            {
                if(!vis[v])
                {V=v;break;}
            }
            int t=dfs1(V,u);
            f[u]-=t;
            return t;
        }
    };
    for(int i=n;i>=Q;--i)
    {
        dfs1(1,0);
    }
    cout<<ans<<endl;
    return 0;
}
}
signed main ()
{
    return my::main();
}

