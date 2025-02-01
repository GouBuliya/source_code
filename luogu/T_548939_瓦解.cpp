#include<bits/stdc++.h>
namespace my {
#define ll long long
#define pn cout << "\n"
#define mset(a, x) memset(a, x, sizeof a)
#define mcpy(a, b) memcpy(a, b, sizeof a)
#define all(a) a.begin(), a.end()
#define fls() fflush(stdout)
    const int INF = (1 << 30);
    const int MOD = 998244353;
    const int MAX_N = 1e7 + 10;

    ll inv[MAX_N];

    void pre() {
        inv[1] = 1;
        for (int i = 2; i < MAX_N; ++i)
            inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    }

    ll qpow(ll a, ll b) {
        ll r = 1;
        while (b) {
            if (b & 1) r = r * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return r;
    }
    ll re()
    {
        ll t;
        std::cin>>t;
        return t;
    }
    signed main() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        pre();

        auto solve = [&]() {
            int T = re();
            while (T--) {
                int n = re(), m = re();
                std::vector<int> A(n);
                for (auto& x : A) x = re();

                int s = 1;
                for (int i = 1; i < n; ++i)
                    if (A[i] <= A[i - 1]) s++;

                if (s > m) {
                    std::cout << "0\n";
                    continue;
                }

                int k = m - s;
                int t = n - s;

                if (k < 0 || t < 0) {
                    std::cout << "0\n";
                    continue;
                }

                if (k >= t) {
                    std::cout << qpow(2, t) << "\n";
                }
                else {
                    auto calc = [&](int x) {
                        ll r = 1, c = 1;
                        for (int i = 1; i <= x; ++i) {
                            c = c * (t - i + 1) % MOD * inv[i] % MOD;
                            r = (r + c) % MOD;
                        }
                        return r;
                        };

                    if (k <= t / 2) {
                        std::cout << calc(k) << "\n";
                    }
                    else {
                        int x = t - k - 1;
                        ll sum = x < 0 ? 0 : calc(x);
                        ll ans = (qpow(2, t) - sum + MOD) % MOD;
                        std::cout << ans << "\n";
                    }
                }
            }
            };

        solve();
        return 0;
    }
}

signed main() {
    return my::main();
}