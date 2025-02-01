#include<bits/stdc++.h>
namespace my {
#define ll long long
#define pn cout << "\n"
#define all(a) a.begin(), a.end()

const int maxn = 2e5 + 5, mod = 998244353;

ll re() {
    ll t; std::cin >> t; return t;
}

void dq(int& x) {
    if (x >= mod) x -= mod;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    auto solve = [&]() {
        int n = re();
        std::vector<int> A(n + 1);
        for (int i = 1; i <= n; i++) A[i] = re();

        int ans1 = 0, ans2 = 1;
        if (!A[1]) ans1 = 1;

        for (int i = 2; i <= n; i++) {
            int t1 = ans1, t2 = ans2;
            ans1 = ans2 = 0;

            if (A[i] == A[i - 1]) ans1 += t1;
            if (A[i] == A[i - 2] + 1) dq(ans1 += t2);

            ans2 = t1;
        }

        int ans = ans1 + ans2;
        dq(ans);
        std::cout << ans << std::endl;
    };

    int T = re();
    while (T--) solve();
    
    return 0;
}
}

signed main() {
    return my::main();
}
