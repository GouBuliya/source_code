#include<bits/stdc++.h>
namespace my {
#define ll long long
#define pn cout<<"\n"
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

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n = re(), m = re();
    std::vector<std::vector<int>> d(n, std::vector<int>(n, INF));
    for (int i = 0; i < n; ++i) d[i][i] = 0;
    for (int i = 0; i < m; ++i) {
        int u = re(), v = re(), w = re();
        --u; --v;
        d[u][v] = std::min(d[u][v], w);
    }

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (d[i][k] != INF && d[k][j] != INF)
                    d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);

    auto check = [&](int mid) {
        for (int x = 0; x < n; ++x) {
            std::vector<bool> S(n, false);
            for (int t = 0; t < n; ++t)
                if (d[x][t] <= mid) S[t] = true;

            std::vector<int> T;
            for (int t = 0; t < n; ++t)
                if (!S[t]) T.push_back(t);

            if (T.empty()) return true;

            for (int b = 0; b < n; ++b) {
                bool ok = true;
                for (int t : T)
                    if (d[b][t] > mid) { ok = false; break; }
                if (ok) return true;
            }
        }
        return false;
    };

    int l = 0, r = 1e9, ans = r;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) { ans = mid; r = mid - 1; }
        else l = mid + 1;
    }

    std::cout << ans << "\n";
    return 0;
}
}

signed main() {
    return my::main();
}