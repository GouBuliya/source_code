#include<bits/stdc++.h>
namespace my {
#define ll long long
#define pn cout << "\n"
#define mset(a, x) memset(a, x, sizeof a)
#define mcpy(a, b) memcpy(a, b, sizeof a)
#define all(a) a.begin(), a.end()
#define fls() fflush(stdout)
    const int INF = (1 << 30);

    ll re() {
        ll t;
        std::cin >> t;
        return t;
    }

    void solve() {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> A(n + 1), B(m + 1);
        for (int i = 1; i <= n; ++i) std::cin >> A[i];
        for (int i = 1; i <= m; ++i) std::cin >> B[i];
        sort(A.begin() + 1, A.end());
        sort(B.begin() + 1, B.end());
        int k = std::min({ n, m, (n + m) / 3 });
        std::cout << k << "\n";
        if (k == 0) return;

        ll ans = 0;
        int l = 1, r = 1;
        auto f = [&](int x, int y) { return A[n - x + 1] - A[x] > B[m - y + 1] - B[y]; };

        for (int i = 1; i <= k; ++i) {
            if (2 * l + r == n + 3) {
                l--;
                ans -= (A[n - l + 1] - A[l]);
                ans += (B[m - r + 1] - B[r]);
                r++;
            }
            if (2 * r + l == m + 3) {
                r--;
                ans -= (B[m - r + 1] - B[r]);
                ans += (A[n - l + 1] - A[l]);
                l++;
            }
            if (2 * r + l > m + 1 || (2 * l + r <= n + 1 && f(l, r))) {
                ans += A[n - l + 1] - A[l];
                l++;
            }
            else {
                ans += B[m - r + 1] - B[r];
                r++;
            }
            std::cout << ans << " ";
        }
        std::pn;
    }

    signed main() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        int t;
        std::cin >> t;
        while (t--) solve();
        return 0;
    }
}

signed main() {
    return my::main();
}