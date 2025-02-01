#include<bits/stdc++.h>
namespace my {
#define ll long long 
#define pn cout << "\n"
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
#define int long long
    const int INF = (1 << 30);

    ll re() {
        ll t;
        std::cin >> t;
        return t;
    }

    signed main() {
        int t = re();
        while (t--) {
            int n = re();
            std::vector<ll> A(n);
            for (auto& x : A) std::cin >> x;
            ll mx = std::accumulate(all(A), 0LL);
            std::unordered_map<std::string, ll> m;

            auto toStr = [](const std::vector<ll>& v) {
                std::string s;
                for (ll x : v) s += std::to_string(x) + ",";
                return s;
                };

            auto dfs = [&](auto&& self, std::vector<ll> a, ll s) -> void {
                if (a.size() == 1) {
                    mx = std::max(mx, a[0]);
                    return;
                }
                if (s > mx) mx = s;

                std::string key = toStr(a);
                if (m.count(key) && m[key] >= s) return;
                m[key] = s;

                auto diff = [](const std::vector<ll>& a) {
                    std::vector<ll> b;
                    for (int i = 0; i < a.size() - 1; ++i)
                        b.push_back(a[i + 1] - a[i]);
                    return b;
                    };

                auto B = diff(a);
                self(self, B, std::accumulate(all(B), 0LL));
                std::reverse(all(a));
                auto C = diff(a);
                self(self, C, std::accumulate(all(C), 0LL));
                };

            dfs(dfs, A, mx);
            std::cout << mx << "\n";
        }
        return 0;
    }
}
signed main() {
    return my::main();
}
