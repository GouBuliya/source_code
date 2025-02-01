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
        int t = re();
        int n = re();
        int m = re();
        int p = re();
        int ans = 1;
        for (int i = n - m + 1;i >= n - 2 * m + 2;i--)
            ans = (ans * i) % p;
        std::cout << ans << std::endl;
        return 0;
    }
}
signed main()
{
    return my::main();
}