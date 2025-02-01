#include<bits/stdc++.h>
namespace my {
#define ll long long
#define pn cout << "\n"
#define mset(a, x) memset(a, x, sizeof a)
#define mcpy(a, b) memcpy(a, b, sizeof a)
#define all(a) a.begin(), a.end()
#define fls() fflush(stdout)
const int INF = (1 << 30);

std::string f(int k) {
    if (k == 1) return "1";
    for (int i = 2; i * i <= k; ++i) {
        if (k % i == 0) {
            auto a = f(i), b = f(k / i);
            if (a != "NIE" && b != "NIE") return "(" + a + ")*(" + b + ")";
        }
    }
    if (k <= 100) {
        std::string s;
        for (int i = 0; i < k; ++i) s += (i ? "+1" : "1");
        return s;
    }
    return "NIE";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        int k;
        std::cin >> k;
        std::cout << f(k) << "\n";
    }
    return 0;
}
}

signed main() {
    return my::main();
}