#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 5005;
long long mod;
 
// 快速幂
long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
 
// 预处理 n^(n-2)
long long tree_count[MAXN];
 
void preprocess_tree() {
    for (int i = 1; i < MAXN; ++i) {
        tree_count[i] = power(i, i - 2);
    }
}
 
// 动态规划计算一般连通图的数量
long long dp[MAXN];
 
void preprocess_general() {
    dp[1] = 1;
    for (int n = 2; n < MAXN; ++n) {
        dp[n] = power(n, n - 1);
        for (int k = 1; k < n; ++k) {
            dp[n] = (dp[n] - comb(n, k) * dp[k] % mod * power(n - k, n - k - 1) % mod + mod) % mod;
        }
    }
}
 
// 计算组合数
long long comb(int n, int k) {
    if (k > n) return 0;
    long long res = 1;
    for (int i = 0; i < k; ++i) {
        res = res * (n - i) % mod;
        res = res * power(i + 1, mod - 2) % mod;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr); 
 
    int T, t;
    cin >> T >> mod >> t;
 
    if (t == 0) {
        preprocess_tree();
    } else {
        preprocess_general();
    }
 
    while (T--) {
        int n;
        cin >> n;
        if (t == 0) {
            cout << tree_count[n] << '\n';
        } else {
            cout << dp[n] << '\n';
        }
    }
 
    return 0;
}