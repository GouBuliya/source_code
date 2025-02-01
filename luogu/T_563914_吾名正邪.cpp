#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pn cout << "\n";
#define mset(a, x) memset(a, x, sizeof a)
#define all(a) a.begin(), a.end()
#define fls() fflush(stdout)

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto re = []() {
        ll t;
        cin >> t;
        return t;
    };

    auto pw = [](ll a, ll b, ll m) {
        ll r = 1;
        a %= m;
        while (b) {
            if (b & 1) r = r * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return r;
    };

    string a, b;
    cin >> a >> b;

    if (b == "0") {
        cout << 0; pn
        return 0;
    }

    if ((a.back() - '0') % 2 == 1) {
        cout << a; pn
    } else {
        cout << (b == "1" ? a : "0"); pn
    }

    return 0;
}
