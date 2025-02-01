#include<bits/stdc++.h>
namespace my {
#define ll long long
#define pn cout << "\n";
#define mset(a, x) memset(a, x, sizeof a)
#define mcpy(a, b) memcpy(a, b, sizeof a)
#define all(a) a.begin(), a.end()
#define fls() fflush(stdout)
const int INF = (1 << 30);
ll re() {
    ll t; std::cin >> t; return t;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n = re(), m = re();
    const int N = 1e3 + 7;
    int dp[N][N], ans[N], w[N], l[N], r[N];
    mset(dp, 0); mset(ans, 0);

    for (int i = 1; i <= n; ++i) {
        w[i] = re(); l[i] = re(); r[i] = re();
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 0; --j) {
            if (j >= r[i]) {
                if (dp[i - 1][j] > dp[i - 1][j - r[i]] + w[i]) {
                    ans[i] = 0;
                    dp[i][j] = dp[i - 1][j];
                } else {
                    ans[i] = 1;
                    dp[i][j] = dp[i - 1][j - r[i]] + w[i];
                }
            } else {
                ans[i] = 0;
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    std::cout << dp[n][m] << "\n";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            ans[i] = 1;
            j -= r[i];
        }
        --i;
    }
    for (int i = 1; i <= n; ++i) {
        std::cout << ans[i] << " ";
    }
    std::pn;
    return 0;
}
}

signed main() {
    return my::main();
}
