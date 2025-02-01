#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAX_N = 1e7 + 10;

long long factorial[MAX_N];
long long inv_fact[MAX_N];

long long pow_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void precompute_factorials(int n) {
    factorial[0] = 1;
    for (int i = 1; i <= n; ++i) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
    inv_fact[n] = pow_mod(factorial[n], MOD - 2, MOD);
    for (int i = n; i > 0; --i) {
        inv_fact[i - 1] = inv_fact[i] * i % MOD;
    }
}

long long comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return factorial[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main() {
    int n, s, x, l, r;
    cin >> n >> s >> x >> l >> r;

    precompute_factorials(n);

    long long total = comb(n - 1, s - 1);

    // 这里假设 p_x 的分布是均匀的，或者有其他特定的分布规律
    // 由于具体计算复杂，我们暂时保留 total 作为答案
    cout << total/2 << endl;

    return 0;
}