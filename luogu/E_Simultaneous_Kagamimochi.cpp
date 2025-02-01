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

    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (auto& x : A) std::cin >> x;

    int i = 0, j = N / 2, K = 0;
    while (i < N / 2 && j < N) {
        if (A[i] <= A[j] / 2) {
            K++;
            i++; j++;
        } else {
            j++;
        }
    }

    std::cout << K << "\n";
    return 0;
}
} // namespace my

signed main() {
    return my::main();
}
