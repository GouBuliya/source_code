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
        int k = re();
        std::deque<int>dq;
        std::vector<int>A(n + 1);
        for (int i = 1;i <= n;++i)
            std::cin >> A[i];
        int ans = 0;
        for (int i = 1;i <= n;++i)
        {

            if (!dq.empty() && dq.front() + k - 1 < i)dq.pop_front();
            while (dq.size() && A[dq.back()] < A[i]) { dq.pop_back(); }
            dq.push_back(i);
            if (i >= k)std::cout << dq.size() << std::endl;

        }
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}