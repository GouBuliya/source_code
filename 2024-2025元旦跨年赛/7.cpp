#include<bits/stdc++.h>
namespace my {
    #define ll long long
    #define pn std::cout << "\n";
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

    std::vector<int> dfs(int n, const std::vector<std::vector<int>>& g, int cur, std::vector<int>& path, std::vector<bool>& vis) {
        if (path.size() == n) {
            if (std::find(all(g[cur]), path[0]) != g[cur].end()) {
                path.push_back(path[0]);
                return path;
            }
            return {};
        }

        auto nei = std::vector<int>{};
        for (auto v : g[cur]) if (!vis[v]) nei.push_back(v);

        if (nei.empty()) return {};

        std::sort(all(nei), [&](int a, int b) {
            return g[a].size() < g[b].size();
        });

        std::random_device rd;
        std::mt19937 rng(rd());
        std::shuffle(all(nei), rng);

        for (auto v : nei) {
            vis[v] = true;
            path.push_back(v);
            auto res = dfs(n, g, v, path, vis);
            if (!res.empty()) return res;
            path.pop_back();
            vis[v] = false;
        }

        return {};
    }

    signed main() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        auto re = []() { ll t; std::cin >> t; return t; };
        int n = re(), m = re();
        std::vector<std::pair<int, int>> e(m);
        for (int i = 0; i < m; ++i) std::cin >> e[i].first >> e[i].second;

        std::vector<std::vector<int>> g(n + 1);
        for (auto& p : e) {
            g[p.first].push_back(p.second);
            g[p.second].push_back(p.first);
        }

        std::vector<std::vector<int>> res;
        for (int start = 1; start <= n; ++start) {
            std::vector<bool> vis(n + 1, false);
            vis[start] = true;
            std::vector<int> path = {start};
            auto cycle = dfs(n, g, start, path, vis);
            if (!cycle.empty()) res.push_back(cycle);
        }

        for (auto& cycle : res) {
            for (auto& node : cycle) std::cout << node << " ";
            pn;
        }

        return 0;
    }
};

signed main() {
    return my::main();
}
