#include<bits/stdc++.h>
namespace my {
#define ll long long
#define pn cout << "\n";
#define mset(a, x) memset(a, x, sizeof a)
#define mcpy(a, b) memcpy(a, b, sizeof a)
#define all(a) a.begin(), a.end()
#define fls() fflush(stdout)
const int INF = (1 << 30);

ll re() {
    ll t;
    std::cin >> t;
    return t;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<std::pair<int, int>> A;
    std::set<int> S;

    auto chk = [&]() {
        std::vector<std::pair<int, int>> B;
        for (auto i : S) B.push_back(A[i]);
        sort(all(B));
        for (int i = 1; i < B.size(); ++i) {
            if (B[i].first < B[i - 1].second) return false;
        }
        return true;
    };

    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int l, r;
            std::cin >> l >> r;
            A.push_back({l, r});
            S.insert(A.size() - 1);
        } else {
            int x;
            std::cin >> x;
            S.erase(x - 1);
        }
        std::cout << (chk() ? "Yes\n" : "No\n");
    }

    return 0;
}
}

signed main() {
    return my::main();
}