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
    void solve()
    {
        int n = re();
        int m = re();
        std::vector<std::vector<int>>A(n + 2, std::vector<int>(n + 2));
        std::vector<std::vector<int>>pre(n + 2, std::vector<int>(n + 2));
        
        auto f = [&](int u, int v, int x, int y)
            {
                A[u][v]++;
                A[u][y+1]--;
                A[x+1][v]--;
                A[x +1][y +1]++;
            };
        while (m--)
        {
            int u = re();
            int v = re();
            int x = re();
            int y = re();
            f(u, v, x, y);
        }
        
        for (int i = 1;i <= n;++i)
            for (int j = 1;j <= n;++j)
                pre[i][j] = A[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                std::cout<<pre[i][j]<<" ";
            }std::pn;
        }

    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}