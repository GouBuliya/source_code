#include<bits/stdc++.h>
namespace my {
#define ll long long
#define pn cout << "\n"
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
    const int INF = (1 << 30);
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
        std::vector<int> A(n + 1), B(n + 1);
        for (int i = 1; i <= n; ++i)
            A[i] = re();
        for (int k = 1; ; ++k) {
            int m = 1 + k * (k - 1) / 2;
            if (m > n) break;
            int d = n - m + 1, p = 1;
            B[p] += 1,B[p + d] -= 1;
            for (int i = 1; i < k; ++i) {
                p += i;
                if (i % 2)
                    B[p] -= 1, B[p + d] += 1;
                else
                    B[p] += 1, B[p + d] -= 1;
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++i)
            B[i] += B[i - 1], ans += 1ll * B[i] * A[i];
        std::cout << ans << "\n";
        return 0;
    }
}

signed main() {
    return my::main();
}
