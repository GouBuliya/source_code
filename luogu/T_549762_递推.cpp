#include<bits/stdc++.h>
namespace my {
#define ll long long
#define pn cout<<"\n"
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
    const int MOD = 998244353;

    ll qpow(ll a, ll b) {
        ll r = 1;
        for (; b; b >>= 1, a = a * a % MOD)
            if (b & 1) r = r * a % MOD;
        return r;
    }
    ll re() {
        ll t;
        std::cin >> t;
        return t;
    }
    signed main() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int n = re();
        std::vector<int> A(n), B(n + 1);
        for (auto& x : A) std::cin >> x;
        for (auto& x : B) std::cin >> x;

        auto calc = [&]() {
            ll s = 0;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j <= i; ++j)
                    s = (s + 1LL * B[j] * A[i - j]) % MOD;
            return s;
            };

        ll s = calc(), sb = std::accumulate(all(B), 0LL) % MOD;
        ll inv = qpow(sb, MOD - 2);
        ll ans = (s * inv % MOD + MOD) % MOD;
        std::cout << ans << "\n";

        return 0;
    }


}

signed main() {
    return my::main();
}