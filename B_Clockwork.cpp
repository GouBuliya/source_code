#include<bits/stdc++.h>
namespace my {
#define ll long long
#define pn cout << "\n"
#define mset(a, x) memset(a, x, sizeof a)
#define mcpy(a, b) memcpy(a, b, sizeof a)
#define all(a) a.begin(), a.end()
#define fls() fflush(stdout)
const int INF = (1 << 30);
#define int long long
ll re() {
    ll t;
    std::cin >> t;
    return t;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    auto solve = [&]() {
        int t = re();
        while (t--) {
            int n = re();
            std::vector<int> A(n);
            for (auto& x : A) x = re();

            auto ok = [&]() {
                for (int i = 0; i < n; ++i) {
                    int d = std::max(i, n - 1 - i);
                    if (A[i] < 2 * d + 1) return false;
                }
                return true;
            };

            std::cout << (ok() ? "YES\n" : "NO\n");
        }
    };

    solve();
    return 0;
}
}

signed main() {
    return my::main();
}