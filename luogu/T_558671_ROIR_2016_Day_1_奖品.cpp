#include<bits/stdc++.h>
namespace my {
#define ll long long
#define pn std::cout << "\n"
#define all(a) a.begin(),a.end()
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
const int INF = (1 << 30);
ll re() { ll t; std::cin >> t; return t; }

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    auto n = re();
    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;

    auto mx = a[0], sec = -1;
    for (auto k = 2; k <= n; k++) {
        auto cur = a[k - 1];
        if (cur > mx) {
            sec = mx;
            mx = cur;
        } else if (cur > sec) sec = cur;
        std::cout << sec << " ";
    }
    pn;
    return 0;
}
}
signed main() {
    return my::main();
}
