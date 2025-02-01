#include<bits/stdc++.h>
#define ll long long
#define pn cout<<'\n'
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
using namespace std;

namespace my {
    const int INF = (1 << 30);
    const int N = 1e5 + 5;
    const int M = 10;

    ll re() {
        ll t; cin >> t; return t;
    }

    int n, m, t;
    int a[N], b[M], f[1 << M], g[M];
    vector<int> c;
    ll ans;

    void solve() {
        n = re(), m = re(), t = re();
        for (int i = 1; i <= n; i++) a[i] = re();
        for (int i = 0; i < m; i++) b[i] = re();

        f[0] = (1 << 30) - 1;
        for (int i = 1; i < (1 << m); i++) {
            int j = i & -i;
            f[i] = f[i ^ j] & b[__lg(j)];
        }

        ans = 0;
        for (int i = 1; i <= n; i++) ans += a[i];

        c.clear();
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) g[j] = a[i];
            for (int S = 0; S < (1 << m); S++) {
                int cnt = __builtin_popcount(S);
                g[cnt] = min(g[cnt], a[i] & f[S]);
            }
            for (int j = 1; j <= m; j++) {
                c.push_back(g[j - 1] - g[j]);
            }
        }

        sort(all(c));
        reverse(all(c));
        for (int i = 1; i <= t && i <= c.size(); i++) {
            ans -= c[i-1];
        }
        printf("%lld\n", ans);
    }

    signed main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int T = re();
        while (T--) solve();
        return 0;
    }
}

signed main() {
    return my::main();
}