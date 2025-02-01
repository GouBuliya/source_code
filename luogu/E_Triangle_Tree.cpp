#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pn cout<<"\n";
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto re = []() -> ll { 
        ll x; cin >> x; 
        return x; 
    };

    ll T = re();
    while (T--) {
        ll n = re();
        vector<vector<int>> G(n + 1);
        for (ll i = 1; i < n; ++i) {
            auto u = re(), v = re();
            G[u].push_back(v);
            G[v].push_back(u);
        }

        vector<ll> dep(n + 1), len(n + 1), son(n + 1), id(n + 1), sz(n + 1), f(n + 1);
        ll idx = 0, ans = 0;

        function<void(int, int)> init = [&](int x, int p) {
            son[x] = 0;
            for (auto y : G[x]) {
                if (y == p) continue;
                dep[y] = dep[x] + 1;
                init(y, x);
                if (len[y] > len[son[x]]) son[x] = y;
            }
            len[x] = len[son[x]] + 1;
        };

        function<void(int, int)> rinit = [&](int x, int p) {
            id[x] = ++idx;
            if (son[x]) rinit(son[x], x);
            for (auto y : G[x]) {
                if (y == p || y == son[x]) continue;
                rinit(y, x);
            }
        };

        function<void(int, int)> dfs = [&](int x, int p) {
            if (son[x]) dfs(son[x], x);
            sz[x] = sz[son[x]];
            auto u = id[x];
            f[u] = 1;
            for (auto y : G[x]) {
                if (y == p || y == son[x]) continue;
                dfs(y, x);
                auto k = id[y] - 1;
                ans -= sz[x] * sz[y];
                ll s1 = 0, s2 = 0;
                for (ll i = 1; i <= len[y]; ++i) {
                    s1 += f[u + i];
                    s2 += f[u + i] * i;
                    f[u + i] += f[k + i];
                    ans += 2 * f[k + i] * (s2 + i * (sz[x] - s1));
                }
                sz[x] += sz[y];
            }
            sz[x]++;
        };

        init(1, 0);
        rinit(1, 0);
        dfs(1, 0);

        cout << ans << "\n";
    }

    return 0;
}
