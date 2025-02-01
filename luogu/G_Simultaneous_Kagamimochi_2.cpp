#include<bits/stdc++.h>
namespace my {
#define ll long long 
#define pn cout << "\n";
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
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
    
    unsigned N = re();
    std::vector<unsigned> A(N);
    for (auto&& a : A) std::cin >> a;

    using vt = std::pair<unsigned, unsigned>;
    atcoder::segtree<vt, [](const auto& lhs, const auto& rhs) {
        const auto& [l_len, l_dist] = lhs;
        const auto& [r_len, r_dist] = rhs;
        return vt{l_len + r_len, std::max(l_dist, r_dist)};
    }, [] { return vt{}; }> seg {
        [N](const auto& seq) {
            std::vector<vt> res(N);
            for (unsigned i = 0, j = 0; i < N; ++i) {
                while (j < N && seq[i] * 2 > seq[j]) ++j;
                res[i] = {1, j - i};
            }
            return res;
        }(A)
    };

    unsigned Q = re();
    while (Q--) {
        unsigned L = re(), R = re();
        --L;
        std::cout << seg.max_right(L, [L, R](const auto& itv) {
            const auto& [len, dist] = itv;
            return L + len + std::max(dist, len) <= R;
        }) - L << std::endl;
    }

    return 0;
}
}
signed main() {
    return my::main();
}
