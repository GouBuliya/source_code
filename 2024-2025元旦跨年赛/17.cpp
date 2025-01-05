#include <bits/stdc++.h>
namespace my{
#define ll long long
#define pn cout<<"\n";
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
const int INF=(1<<30);

ll re () {
    ll t;
    std::cin >> t;
    return t;
}

signed main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n;
    ll m;
    std::cin >> n >> m;

    if (n == 0) { 
        std::cout << 0 << "\n";
        return 0;
    }

    std::vector<ll> v(n), w(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i] >> w[i];
        if (v[i] == 0 && w[i] != 0) {
            std::cout << -1 << "\n";
            return 0;
        }
    }

    std::vector<ll> dp(101, 0);
    for (int vol = 1; vol <= 100; ++vol) {
        for (int i = 0; i < n; ++i) {
            if (v[i] <= vol && v[i] > 0) {
                dp[vol] = std::max(dp[vol], dp[vol - v[i]] + w[i]);
            }
        }
    }

    ll res = 0;
    if (m <= 100) {
        res = dp[m];
    } else {
        for (ll i = 100; i > 0 && m > 0; --i) {
            ll cnt = m / i;
            res += dp[i] * cnt;
            m -= cnt * i;
        }
        if (m > 0) res += dp[m];
    }

    std::cout << res << "\n";
    return 0;
}
}
signed main () {
    return my::main();
}
