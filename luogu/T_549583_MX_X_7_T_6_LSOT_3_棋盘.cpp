#include <bits/stdc++.h>
namespace my {
#define ll long long
#define pn cout << "\n";
#define mset(a,x) memset(a, x, sizeof a)
#define mcpy(a,b) memcpy(a, b, sizeof a)
#define all(a) a.begin(), a.end()
#define fls() fflush(stdout)
    const int INF = (1 << 30);

    std::map<std::array<ll, 3>, ll> mp;

    ll dfs(int op, int x, int y) {
        if (!x && !y) return 0;
        if (mp.count({ op, x, y })) return mp[{op, x, y}];
        int X = y + x / 4, Y = x / 4, d = x % 2;
        x %= 4;
        ll ans = 0;
        if (x <= 1) {
            ans = dfs(op, X, Y);
        }
        else if (op == 1) {
            if (x >= 2) {
                ans = std::max(dfs(2, X + 1, Y), dfs(2, X, Y + 1));
            }
            else {
                --X, --Y;
                ans = std::max(std::min(dfs(1, X + 2, Y), dfs(1, X + 1, Y + 1)),
                    std::min(dfs(1, X + 1, Y + 1), dfs(1, X, Y + 2)));
            }
        }
        else {
            if (x >= 2) {
                ans = std::min(dfs(1, X + 1, Y), dfs(1, X, Y + 1));
            }
            else {
                --X, --Y;
                ans = std::min(std::max(dfs(2, X + 2, Y), dfs(2, X + 1, Y + 1)),
                    std::max(dfs(2, X + 1, Y + 1), dfs(2, X, Y + 2)));
            }
        }
        return mp[{op, x, y}] = ans + d;
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
        int t = re();
        while (t--) {
            ll n = re();
            std::cout << n - dfs(1, n, 0) << std::endl;
            mp.clear();
        }
        return 0;
    }
}

signed main() {
    return my::main();
}
