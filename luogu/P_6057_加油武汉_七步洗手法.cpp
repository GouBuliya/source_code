#include<bits/stdc++.h>
#define ll long long
#define pn cout<<'\n';
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
#define int  long long
namespace my {
    const int INF = (1 << 30);
    ll re()
    {
        ll t; std::cin >> t;return t;
    }
    int how_c(int n, int m)
    {
        if (n == 0 || m > n)return 0;
        if (n == m || m == 0)return 1;
        return how_c(n, m - 1) * (n - m + 1) / m;
    }
    const int maxn=1e5+7;
    std::vector<int>G[maxn];
    signed main()
    {
        std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
        int n = re();
        int m = re();
        int ans = how_c(n, 3);
        for (int i = 0;i < m;++i)
        {
            int u = re();
            int v = re();
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int res = 0;
        for (auto u=1;u<=n;++u)
        {
            int w=G[u].size();
            int b=n-1-G[u].size();
            res+=b*w;
        }
        std::cout << ans-(res/2) << std::endl;
        return 0;
    }
}
signed main()
{
    return my::main();
}