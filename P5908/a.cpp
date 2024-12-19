#include<bits/stdc++.h>
#include <cmath>
namespace my{
#define ll long long 
#define pn cout<<"\n";
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
const int INF=(1<<30);
ll re ()
{
    ll t;
    std::cin>>t;
    return t;
}
signed main ()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    const int maxn=1e5+10;
    std::vector<std::vector<int>>G(maxn);
    std::vector<int>dep(maxn);
    std::vector<bool>vis(maxn);
    int n=re();
    int f=re();
    for(int i=0;i<n;++i)
    {
        int u=re(),v=re();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans=0;
    std::function<void(int,int)> dfs=[&](int u,int dis) ->void
    {
        vis[u]=1;
        if(dis==f)
            return;
        for(auto v:G[u])
        {
            if(!vis[v])
            {
                dfs(v,dis+1);
                ans++;
            }
        }
    };
    dfs(1,0);
    std::cout<<ans<<std::endl;
    return 0;
}
}
signed main ()
{
    return my::main();
}

