#include <bits/stdc++.h>
namespace my {
#define ll long long
#define pn cout << "\n";
#define mset(a, x) memset(a, x, sizeof a)
#define mcpy(a, b) memcpy(a, b, sizeof a)
#define all(a) a.begin(), a.end()
#define fls() fflush(stdout)

    ll re() {
        ll t;
        std::cin >> t;
        return t;
    }

    signed main() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        auto n = re(), q = n / 3, r = n % 3;
        auto [a, b, c] = r == 0 ? std::tuple<ll, ll, ll>{q - 1, q, q + 1} :
            r == 1 ? std::tuple<ll, ll, ll>{q - 1, q, q + 2} :
            std::tuple<ll, ll, ll>{ q - 1, q + 1, q + 2 };
        std::cout << a << ' ' << b << ' ' << c;
        return 0;
    }
}
signed main() {
    return my::main();
}
