#include <bits/stdc++.h>
namespace my {
#define ll long long
#define pn cout << "\n"
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

    int n;
    std::cin >> n;
    std::vector<ll> A(n);
    for (auto& x : A) std::cin >> x;

    ll cnt = 0;
    int l = 0;

    for (int r = 0; r < n; ++r) {
        while (l < r && A[l] <= A[r] / 2) ++l;
        cnt += l;
    }

    std::cout << cnt << "\n";
    return 0;
}
} // namespace my

signed main() {
    return my::main();
}
