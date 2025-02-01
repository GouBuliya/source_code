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
        int n, t;
        std::cin >> n >> t;

        int size = 1 << n; 
        std::vector<int> a(size);
        for (int i = 0; i < size; i++) {
            std::cin >> a[i];
        }

        if (t % 2 == 1) {
            std::reverse(a.begin(), a.end());
        }

        for (int i = 0; i < size; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;

        return;
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}