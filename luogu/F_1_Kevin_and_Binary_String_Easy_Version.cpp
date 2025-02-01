#include <bits/stdc++.h>
using namespace std;
#define vv vector
#define ll long long
#define lll __int128
const int N = 5e5 + 5;
const int P = 998244353;
const ll inf = 1e18;

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> rd(0, 1e9);
inline ll rnd() { return rd(gen); }

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return res;
}

void qfl_zzz() {
    string s, t;
    cin >> s >> t;
    ll n = s.size();
    s = " " + s;
    t = " " + t;

    vv<pair<ll, ll>> a, b;
    ll len = 1;
    for (ll i = 2; i <= n; ++i) {
        if (s[i] == s[i - 1])
            ++len;
        else {
            a.push_back({s[i - 1] - '0', len});
            len = 1;
        }
    }
    a.push_back({s[n] - '0', len});

    len = 1;
    for (ll i = 2; i <= n; ++i) {
        if (t[i] == t[i - 1])
            ++len;
        else {
            b.push_back({t[i - 1] - '0', len});
            len = 1;
        }
    }
    b.push_back({t[n] - '0', len});

    if (a.size() < b.size()) {
        cout << -1 << "\n";
        return;
    }

    ll ans = 0, j = -1;
    for (ll i = 0; i < b.size(); ++i) {
        ll c[2] = {0, 0}, res = 0;
        if (j + 1 < a.size() && a[j + 1].first == b[i].first)
            res = -1;
        while (j + 1 < a.size() && c[b[i].first] < b[i].second) {
            ++j;
            c[a[j].first] += a[j].second;
            res += (a[j].first == b[i].first);
        }
        if (c[b[i].first] != b[i].second) {
            cout << -1 << "\n";
            return;
        }
        if (j + 1 < a.size())
            a[j + 1].second += c[1 - b[i].first];
        ans += res;
    }
    if (j + 1 < a.size()) {
        cout << -1 << "\n";
        return;
    }
    cout << ans << "\n";
}

void pre_work() {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    pre_work();
    int T = 1;
    cin >> T;
    while (T--)
        qfl_zzz();
    return 0;
}