#include <iostream>
#include <vector>

const int MOD = 998244353;

int mod_inverse(int x, int p) {
    int res = 1;
    for (int y = p - 2; y > 0; y >>= 1) {
        if (y & 1) res = static_cast<long long>(res) * x % p;
        x = static_cast<long long>(x) * x % p;
    }
    return res;
}

std::pair<std::vector<int>, std::vector<int>> precompute_factorials_and_inverses(int n, int mod) {
    std::vector<int> fact(n + 1);
    std::vector<int> inv_fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = static_cast<long long>(fact[i - 1]) * i % mod;
    }
    inv_fact[n] = mod_inverse(fact[n], mod);
    for (int i = n - 1; i >= 0; --i) {
        inv_fact[i] = static_cast<long long>(inv_fact[i + 1]) * (i + 1) % mod;
    }
    return {fact, inv_fact};
}

int combination(int n, int r, const std::vector<int>& fact, const std::vector<int>& inv_fact, int mod) {
    if (r > n) return 0;
    return static_cast<long long>(fact[n]) * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

std::vector<int> count_ways(int N, int a, int b, int Q, const std::vector<int>& k) {
    auto [fact, inv_fact] = precompute_factorials_and_inverses(N, MOD);

    // Initialize dynamic programming table
    std::vector<std::vector<std::vector<int>>> dp(N + 1, std::vector<std::vector<int>>(N + 1, std::vector<int>(N + 1, 0)));

    // Base case: single cell is a valid level 1 L-shape
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            dp[i][j][1] = 1;
        }
    }

    // Compute the number of ways to partition the grid
    for (int K = 2; K <= N; ++K) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (i + K - 1 <= N && j + K - 1 <= N) {
                    int ways = 0;
                    for (int x = i; x < i + K; ++x) {
                        for (int y = j; y < j + K; ++y) {
                            if (x == i || y == j) {
                                ways += dp[x][y][K - 1];
                            }
                            if (x == i + K - 1 || y == j + K - 1) {
                                ways -= dp[x][y][K - 1];
                            }
                            if (ways < 0) ways += MOD;
                        }
                    }
                    dp[i][j][K] = ways % MOD;
                }
            }
        }
    }

    // Answer for each query
    std::vector<int> answers(Q);
    for (int q = 0; q < Q; ++q) {
        int ki = k[q];
        int total_ways = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if ((i <= a && a <= i + ki - 1 && j <= b && b <= j + ki - 1) ||
                    (i <= a && a <= i + ki - 1 && j + ki - 1 <= b && b <= j + ki - 1)) {
                    total_ways = (total_ways + dp[i][j][ki]) % MOD;
                }
            }
        }
        answers[q] = total_ways;
    }

    return answers;
}

int main() {
    int N, a, b, Q;
    std::cin >> N >> a >> b >> Q;
    std::vector<int> k(Q);
    for (int i = 0; i < Q; ++i) {
        std::cin >> k[i];
    }

    std::vector<int> results = count_ways(N, a, b, Q, k);

    for (int result : results) {
        std::cout << result << "\n";
    }

    return 0;
}



