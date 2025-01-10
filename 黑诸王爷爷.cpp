#include <bits/stdc++.h>
using namespace std;

namespace my {
    using ll = long long;
    
    ll re() {
        ll t;
        cin >> t;
        return t;
    }
    
    ll modpow(ll a, ll b, ll m) {
        ll res = 1;
        a %= m;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }
    
    ll inv(ll a, ll m) {
        return modpow(a, m - 2, m);
    }
    
    ll calc_e2(ll n, ll p) {
        return (n * (n + 1) / 2) % p;
    }
    
    ll calc_e4(ll n, ll p) {
        ll term1 = 3 * n * n;
        ll term2 = (n + 1) * (n + 1);
        ll inv_4 = inv(4, p);
        return ((term1 * term2) * inv_4) % p;
    }
    
    signed main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        ll T = re();
        while (T--) {
            ll n = re(), p = re();
            cout << calc_e2(n, p) << ' ';
            cout << calc_e4(n, p) << '\n';
        }
        
        return 0;
    }
}

signed main() {
    return my::main();
}