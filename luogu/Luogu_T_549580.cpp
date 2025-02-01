#include<bits/stdc++.h>
namespace my {
#define ll long long
#define pn cout << "\n"
#define mset(a, x) memset(a, x, sizeof a)
#define mcpy(a, b) memcpy(a, b, sizeof a)
#define all(a) a.begin(), a.end()
#define fls() fflush(stdout)
const int INF = (1 << 30);

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n), deg(n + 1), choose(n + 1), par(n + 1);
    for (auto& x : a) std::cin >> x;

    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }

    std::deque<int> q;
    for (int u = 1; u <= n; ++u) {
        if (deg[u] == 1) q.push_back(u);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop_front();
        int cnt = 0;
        for (auto v : adj[u]) {
            if (v != par[u]) cnt += choose[v];
        }
        cnt %= 2;
        choose[u] = (cnt != a[u - 1]);

        for (auto v : adj[u]) {
            if (v != par[u]) {
                par[v] = u;
                deg[v]--;
                if (deg[v] == 1) q.push_back(v);
            }
        }
    }

    int ops = std::accumulate(all(choose), 0);
    std::cout << ops << "\n";
    return 0;
}
}
signed main() {
    return my::main();
}
