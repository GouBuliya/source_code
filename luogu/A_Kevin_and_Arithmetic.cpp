#include<bits/stdc++.h>
namespace my {
#define ll long long
#define pn cout << "\n"
#define all(a) a.begin(), a.end()

ll re() {
    ll t; std::cin >> t; return t;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto solve = [&]() {
        int t = re();
        while (t--) {
            int n = re();
            std::vector<int> A(n);
            int e = 0, o = 0;
            for (auto& x : A) {
                std::cin >> x;
                e += x % 2 == 0;
                o += x % 2 != 0;
            }
            std::cout << (e ? 1 + o : std::max(0, o - 1)) << "\n";
        }
    };

    solve();
    return 0;
}
}

signed main() {
    return my::main();
}
