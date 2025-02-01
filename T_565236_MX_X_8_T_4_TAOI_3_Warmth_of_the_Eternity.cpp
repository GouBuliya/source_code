#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 998244353;
const int MAXN = 3e5 + 5;
 
int n;
vector<int> blocks[MAXN];
int deg[MAXN];
long long fact[MAXN], inv_fact[MAXN];
 
// 快速幂 
long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
 
// 预处理阶乘和逆元
void preprocess() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        inv_fact[i] = power(fact[i], MOD - 2);
    }
}
 
// 计算组合数
long long comb(int n, int k) {
    if (k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}
 
// 计算总方案数
long long count_ways() {
    long long ways = fact[n - 1];
    for (int i = 1; i <= n; ++i) {
        ways = ways * inv_fact[deg[i] - 1] % MOD;
    }
    return ways;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr); 
 
    preprocess();
 
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int d;
        cin >> d;
        deg[i] = d;
        for (int j = 0; j < d; ++j) {
            int size;
            cin >> size;
            blocks[i].push_back(size);
        }
    }
 
    // 计算总方案数 
    long long result = count_ways();
    cout << result << '\n';
 
    return 0;
}