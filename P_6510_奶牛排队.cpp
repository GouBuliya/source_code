#include<bits/stdc++.h>
#define ll long long
#define pn cout<<'\n';
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
#define int long long
namespace my {
    const int INF = (1 << 30);
    ll re()
    {
        ll t; std::cin >> t;return t;
    }
    void solve()
    {
        int n = re();
        std::vector<int>A(n + 1);
        std::vector<int>sk1;
        std::vector<int>sk2;

        for (int i = 1;i <= n;++i)
        {
            std::cin >> A[i];
        }
        int ans = -INF * 2;
        for (int i = 1;i <= n;++i)
        {
            while (sk1.size() && A[sk1.back()] >= A[i])
                sk1.pop_back();
            while (sk2.size() && A[sk2.back()] < A[i])
                sk2.pop_back();
            int val = sk2.size() ? sk2.back() : 0;
            auto p = std::upper_bound(sk1.begin(), sk1.end(), val);
            if (p != sk1.end())
            {
                ans = std::max(ans, i - *p + 1);
            }

            sk1.push_back(i);
            sk2.push_back(i);

        }
        std::cout << (ans < 0 ? 0 : ans) << std::endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}