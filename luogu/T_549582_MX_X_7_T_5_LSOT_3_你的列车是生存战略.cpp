#include <bits/stdc++.h>
using namespace std;
namespace my{
#define ll long long 
#define pn cout<<"\n"
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
const ll INF=1e18;
ll re() {
    ll t;
    std::cin>>t;
    return t;
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    std::vector<int> c(n), d(n);
    for (auto& x : c) cin >> x;
    for (auto& x : d) cin >> x;

    std::vector<ll> A(1 << std::min(k, 20)), B(1 << std::min(k, 20)); // 限制 k
    for (auto& x : A) cin >> x;
    for (auto& x : B) cin >> x;

    std::vector<std::vector<std::pair<int, ll>>> G(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u; --v;
        G[u].emplace_back(v, w);
    }

    std::vector<ll> D(n, INF);
    D[0] = 0;

    using P = std::pair<ll, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.push({0, 0});

    std::vector<std::vector<ll>> T(n, std::vector<ll>(n, INF));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ll t = std::min(A[c[i] | c[j]], B[d[i] & d[j]]);
            T[i][j] = T[j][i] = t;
        }
    }

    while (!pq.empty()) {
        auto [t, u] = pq.top();
        pq.pop();
        if (t > D[u]) continue;

        for (int v = 0; v < n; ++v) {
            if (u == v) continue;
            ll time = T[u][v];
            if (D[u] + time < D[v]) {
                D[v] = D[u] + time;
                pq.push({D[v], v});
            }
        }

        for (auto [v, w] : G[u]) {
            if (D[u] + w < D[v]) {
                D[v] = D[u] + w;
                pq.push({D[v], v});
            }
        }
    }

    for (auto x : D) cout << x << " ";
    pn;
    return 0;
}
}
signed main() {
    return my::main();
}
