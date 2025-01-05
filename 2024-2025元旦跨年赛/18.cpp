#include<bits/stdc++.h>
namespace my {
#define ll long long
#define pn cout<<"\n";
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
const int MOD = 1e9 + 7;

ll mod_pow(ll b, ll e, ll m) {
    ll r = 1;
    while (e) {
        if (e & 1) r = (r * b) % m;
        b = (b * b) % m;
        e >>= 1;
    }
    return r;
}

ll solve(int n, const std::vector<std::pair<int, int>>& edges) {
    std::unordered_map<int, std::vector<int>> g;
    for (auto& e : edges) {
        g[e.first].push_back(e.second);
        g[e.second].push_back(e.first);
    }

    std::vector<int> sz(n + 1, 0), dep(n + 1, 0), con(n + 1, 0);

    std::function<void(int, int)> dfs = [&](int u, int d) {
        sz[u] = 1;
        dep[u] = d;
        for (int v : g.at(u)) {
            if (!sz[v]) {
                dfs(v, d + 1);
                sz[u] += sz[v];
            }
        }
    };

    dfs(1, 1);

    for (int i = 1; i <= n; ++i) {
        con[i] = mod_pow(2LL, sz[i], MOD) - 1;
        for (int v : g[i]) {
            if (dep[v] > dep[i]) {
                con[i] = (con[i] - (mod_pow(2LL, sz[v], MOD) - 1) + MOD) % MOD;
            }
        }
    }

    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        res = (res + (ll)dep[i] * con[i]) % MOD;
    }

    return res;
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
    std::vector<std::pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        edges[i] = {u, v};
    }
    std::cout << solve(n, edges) << "\n";
    return 0;
}
}
signed main() {
    return my::main();
}
