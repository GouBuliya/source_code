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
        int n = re(), m = re();
        std::vector<int>fc(n + 4);
        for (int i = 0;i < m;++i)
        {
            int l = re(), r = re(), s = re(), t = re();
            int d = (t - s) / (r - l);
            fc[l] += s;fc[l + 1] += d - s;fc[r + 1] -= d + t;fc[r + 2] += t;
        }

        for (int i = 1;i <= n + 1;i++)
            fc[i] = fc[i - 1] + fc[i];
        
        for (int i = 1;i <= n;++i)
        {
            fc[i] = fc[i - 1] + fc[i];
        }
        int ans=0;
        int maxn=-1e9;
        for (int i = 1;i <= n;++i)
        {
            ans^=fc[i];
            maxn=std::max(maxn,fc[i]);
        }
        std::cout<<ans<< " "<<maxn<<std::endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}