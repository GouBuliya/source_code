#include<bits/stdc++.h>
#define ll long long
#define pn cout<<'\n';
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
namespace my {
    const int INF = (1 << 30);
    ll re()
    {
        ll t; std::cin >> t;return t;
    }
    void solve()
    {
        int n = re();
        std::vector<std::vector<int>>A(n + 1, std::vector<int>(n + 1));
        std::vector<std::vector<int>>pre(n + 1, std::vector<int>(n + 1));
        for (int i = 1;i <= n;++i)
        {
            for (int j = 1;j <= n;++j)
            {
                std::cin >> A[i][j];
            }
        }
        for (int i = 1;i <= n;++i)
        {
            for (int j = 1;j <= n;++j)
            {
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + A[i][j];
            }
        }
        std::vector<std::vector<int>>G(n,std::vector<int>(0));
        auto dfs=[&](auto self,int fa,int u)->void
        {
            for(auto &i:G[u])
            {
                if(fa==u)
                continue;
                self(self,u,i);
            }
        };
        dfs(dfs,1,1);
        int maxn = -1e9;
        for (int x = 1;x <= n;++x)
        {
            for (int y = 1;y <= n;++y)
            {
                for(int u=1;u<x;++u)
                {
                    for(int v=1;v<y;++v)
                    {
                        int ans=pre[x][y]-pre[u-1][y]-pre[x][v-1]+pre[u-1][v-1];
                        maxn=std::max(maxn,ans);
                    }
                }
            }
        }
        std::cout<<maxn<<std::endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}