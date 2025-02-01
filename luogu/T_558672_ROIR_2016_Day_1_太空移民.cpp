#include<bits/stdc++.h>
namespace my {
#define ll long long
#define pn cout << "\n"
#define all(a) a.begin(),a.end()
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
const int INF = (1 << 30);
ll re() { ll t; std::cin >> t; return t; }

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    auto chk = [&](ll n, ll a, ll b, ll w, ll h, ll d) {
        if (a + 2 * d <= w && b + 2 * d <= h) {
            ll nx = w / (a + 2 * d), ny = h / (b + 2 * d);
            if (nx * ny >= n) return true;
        }
        if (b + 2 * d <= w && a + 2 * d <= h) {
            ll mx = w / (b + 2 * d), my = h / (a + 2 * d);
            if (mx * my >= n) return true;
        }
        return false;
    };
    
    ll n = re(), a = re(), b = re(), w = re(), h = re();
    ll mxd = std::min({(w - a + 1) / 2, (h - b + 1) / 2, (w - b + 1) / 2, (h - a + 1) / 2});
    if (mxd < 0) mxd = 0;
    
    ll l = 0, r = mxd;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (chk(n, a, b, w, h, mid)) l = mid;
        else r = mid - 1;
    }
    std::cout << l << "\n";
    return 0;
}
}
signed main() {
    return my::main();
}
