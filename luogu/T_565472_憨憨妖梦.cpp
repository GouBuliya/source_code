#include<bits/stdc++.h>
namespace my {
#define ll long long
#define pn cout << "\n"
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

bool cmp(int a1, int b1, int a2, int b2) {
    return a1 == a2 ? b1 < b2 : a1 < a2;
}

bool chk(int x, int y, const std::vector<int>& A, const std::vector<int>& B, ll k) {
    int p = 1;
    ll cnt = 0;
    for (int i = A.size() - 1; i >= 0; --i) {
        while (p <= B.size() && !cmp(x, y, A[i] / B[p - 1], A[i] % B[p - 1])) ++p;
        cnt += p - 1;
    }
    return cnt < k;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n = re(), m = re();
    ll k = re();
    std::vector<int> A(n), B(m);
    for (auto& a : A) a = re();
    for (auto& b : B) b = re();

    std::sort(all(A));
    std::sort(all(B), std::greater<int>());

    int a1 = 0, a2 = 0;
    for (int i = 30; i >= 0; --i) if (chk(a1 | (1 << i), a2, A, B, k)) a1 |= (1 << i);
    for (int i = 30; i >= 0; --i) if (chk(a1, a2 | (1 << i), A, B, k)) a2 |= (1 << i);

    if (a2 == INT_MAX) {
        a1++;
        a2 = 0;
    } else {
        a2++;
    }

    std::cout << a1 << " " << a2 << "\n";
    return 0;
}
}

signed main() {
    return my::main();
}