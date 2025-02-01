#include <bits/stdc++.h>
int re() { int t; std::cin>>t; return t; }
signed main() {
    for (int T = re(); T--; ) {
        int n = re(), k = re(), l = re();
        k *= 2; l *= 2; std::vector<int> A(n+1);
        for (int i = 1; i <= n; i++) A[i] = re() * 2;
        int pos = k, t = A[1], ans = (pos <= l) ? l - pos + t : t;
        for (int i = 2; i <= n; i++) {
            if (pos <= A[i]) {
                if (A[i] - t > pos) { int dt = (A[i] - t - pos) / 2; pos += dt + k; t += dt; }
                else pos += k;
            } else pos = (A[i] + t >= pos) ? pos + k : A[i] + t + k;
            ans = std::min(ans, (pos <= l) ? l - pos + t : t);
        }
        std::cout << ans << "\n";
    }
}
