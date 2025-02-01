#include<bits/stdc++.h>
#define ll long long
#define pn cout<<'\n';
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
#define int unsigned long long
namespace my {
    const int INF = (1 << 30);
    ll re()
    {
        ll t; std::cin >> t;return t;
    }
    void solve()
    {
        int n = re();
        int m = re();
        int t = re();
        std::vector<std::vector<int>>A(n + 1, std::vector<int>(m + 1));
        std::vector<std::vector<int>>pre(n + 1, std::vector<int>(m + 1));
        for (int i = 1;i <= n;++i)
            for (int j = 1;j <= m;++j)
                std::cin >> A[i][j];
        auto f = [&](int u, int v, int x, int y)
            {
                int sum1 = pre[x][y];
                int sum2 = pre[u - 1][y];
                int sum3 = pre[x][v - 1];
                int sum4 = pre[u - 1][v - 1];
                return sum1 - sum2 - sum3 + sum4;
            };
        for (int i = 1;i <= n;++i)
            for (int j = 1;j <= m;++j)
                pre[i][j] = A[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        int ans =0;
        while (t--)
        {
            int u = re();
            int v = re();
            int x = re();
            int y = re();
            ans^=f(u,v,x,y);
        }
        std::cout<<ans<<std::endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = my::re();while (t--)my::solve();return 0;
}