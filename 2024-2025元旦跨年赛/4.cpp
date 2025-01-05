#include <iostream>
using namespace std;

// 快速幂算法
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) { // 如果exp是奇数
            result = (result * base) % mod;
        }
        exp = exp >> 1; // 相当于整除2
        base = (base * base) % mod;
    }
    return result;
}

// 计算期望值
void calculate_expectations(int T) {
    for (int i = 0; i < T; ++i) {
        long long n, p;
        cin >> n >> p;

        // 计算C(n + 1, 2)，即从n+1个位置中选择2个位置的方法数
        long long C_n_2 = ((n + 1) * n / 2) % p;
        
        // 计算E(X^2)
        long long sum_X2 = 0;
        for (long long d = 1; d <= n; ++d) {
            sum_X2 = (sum_X2 + (d * d % p) * ((n + 1 - d) % p)) % p;
        }
        long long E_X2 = (sum_X2 * mod_pow(C_n_2, p-2, p)) % p; // 使用费马小定理求逆元
        
        // 计算E(X^4)
        long long sum_X4 = 0;
        for (long long d = 1; d <= n; ++d) {
            sum_X4 = (sum_X4 + (d * d % p) * (d * d % p) * ((n + 1 - d) % p)) % p;
        }
        long long sum_X2_squared = (sum_X2 * sum_X2) % p;
        long long correction_term = 0;
        for (long long d = 1; d <= n; ++d) {
            correction_term = (correction_term + (d * d % p) * ((n + 1 - 2 * d) % p)) % p;
        }
        correction_term = (2 * correction_term * sum_X2) % p;
        long long E_X4 = (sum_X4 + correction_term) % p;
        E_X4 = (E_X4 * mod_pow(C_n_2, p-2, p)) % p; // 使用费马小定理求逆元
        
        cout << E_X2 << " " << E_X4 << endl;
    }
}

int main() {
    int T;
    cin >> T;
    calculate_expectations(T);
    return 0;
}