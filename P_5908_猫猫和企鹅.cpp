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
    signed main()
    {
        std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
        int n = re();
        int d = re();
        std::vector<std::vector<int>>G(n + 1, std::vector<int>(0));
        std::vector<int>dis(n + 1);
        for (int i = 1;i < n;++i)
        {
            int u, v;
            std::cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        std::queue<int>que;
        std::vector<int>fa(n + 1);
        que.push(1);
        int ans = 0;
        while (!que.empty())
        {
            int u = que.front();

            que.pop();
            if (dis[u] <= d)
            {
                ans++;
            }
            for (auto& v : G[u])
            {
                if (v == fa[u])
                    continue;
                fa[v] = u;
                dis[v] = dis[u] + 1;
                que.push(v);
            }
        }
        std::cout << ans-1 << std::endl;
        return 0;
    }
}
signed main()
{
    return my::main();
}