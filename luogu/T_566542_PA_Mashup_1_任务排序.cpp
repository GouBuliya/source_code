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

struct Dinic {
    struct E {
        int t, r;
        ll c;
        E(int t, int r, ll c) : t(t), r(r), c(c) {}
    };
    int n;
    std::vector<std::vector<E>> g;
    std::vector<int> l, p;
    Dinic(int n) : n(n), g(n), l(n), p(n) {}
    void ae(int u, int v, ll c) {
        g[u].emplace_back(v, g[v].size(), c);
        g[v].emplace_back(u, g[u].size() - 1, 0);
    }
    bool bfs(int s, int t) {
        fill(all(l), -1);
        l[s] = 0;
        std::queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& e : g[u]) {
                if (e.c > 0 && l[e.t] == -1) {
                    l[e.t] = l[u] + 1;
                    q.push(e.t);
                    if (e.t == t) return true;
                }
            }
        }
        return l[t] != -1;
    }
    ll dfs(int u, int t, ll f) {
        if (u == t) return f;
        for (int& i = p[u]; i < g[u].size(); ++i) {
            auto& e = g[u][i];
            if (e.c > 0 && l[e.t] == l[u] + 1) {
                ll d = dfs(e.t, t, std::min(f, e.c));
                if (d > 0) {
                    e.c -= d;
                    g[e.t][e.r].c += d;
                    return d;
                }
            }
        }
        return 0;
    }
    ll mf(int s, int t) {
        ll f = 0;
        while (bfs(s, t)) {
            fill(all(p), 0);
            while (ll d = dfs(s, t, LLONG_MAX)) f += d;
        }
        return f;
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    struct T { int p, k, c; };
    std::vector<T> A(n);
    std::set<int> S;
    ll sum = 0;

    for (int i = 0; i < n; ++i) {
        int p, k, c;
        std::cin >> p >> k >> c;
        A[i] = {p, k, c};
        sum += c;
        S.insert(p);
        S.insert(k);
    }

    std::vector<int> E(all(S));
    std::vector<std::pair<int, int>> I;
    for (int i = 0; i < E.size() - 1; ++i)
        I.emplace_back(E[i], E[i + 1]);

    int sz = I.size();
    int s = 0, t = 1 + n + sz;
    Dinic D(t + 1);

    for (int i = 0; i < n; ++i)
        D.ae(s, i + 1, A[i].c);

    for (int j = 0; j < sz; ++j) {
        auto [a, b] = I[j];
        D.ae(1 + n + j, t, m * 1LL * (b - a));
    }

    for (int i = 0; i < n; ++i) {
        int p = A[i].p, k = A[i].k;
        for (int j = 0; j < sz; ++j) {
            auto [a, b] = I[j];
            int x = std::max(p, a), y = std::min(k, b);
            if (y > x)
                D.ae(i + 1, 1 + n + j, y - x);
        }
    }

    std::cout << (D.mf(s, t) == sum ? "TAK" : "NIE") << "\n";
    return 0;
}
}

signed main() {
    return my::main();
}