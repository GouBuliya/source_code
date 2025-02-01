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
    signed main()
    {
        std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
        int n = re();
        int ans = 0;
        n--;
        for (int i = 1;i <= n;i++) {
            ans = (ans + (n - i + 1) * (n - i + 1) * i) % 1000000007;
        }
        std::cout << ans << std::endl;
        return 0;
    }
}
signed main()
{
    return my::main();
}
