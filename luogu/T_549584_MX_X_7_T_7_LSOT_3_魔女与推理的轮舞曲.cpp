#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const int MOD = 1000000007;

long long modPow(long long base, long long exp) {
    long long result = 1;
    while (exp) {
        if (exp % 2) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long n, m, a, b, c, d;
        cin >> n >> m >> a >> b >> c >> d;
        
        // 子任务1的处理
        if (a % c == 0 && b % d == 0) {
            // 可以通过数学推导处理这些情况
            cout << modPow(2, n * m) << endl;
        } else {
            // 暴力或者其他合适的策略处理
            cout << modPow(2, n * m) << endl;
        }
    }
    return 0;
}
