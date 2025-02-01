#include <iostream>
#include <vector>

const int MOD = 998244353;

int count_balanced_sequences(int n) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
    dp[0][0] = 1;
    
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (i > 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
            if (j > 0 && j <= i) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }
    
    return dp[n][n];
}

std::vector<std::vector<int>> apply_clue(const std::vector<std::vector<int>>& dp, int l, int r, int n) {
    std::vector<std::vector<int>> new_dp(n + 1, std::vector<int>(n + 1, 0));
    
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (dp[i][j] == 0) continue;
            
            if (i < l || j < r) {
                if (i < l) {
                    new_dp[i + 1][j] = (new_dp[i + 1][j] + dp[i][j]) % MOD;
                }
                if (j < r && i > j) {
                    new_dp[i][j + 1] = (new_dp[i][j + 1] + dp[i][j]) % MOD;
                }
            } else if (i == l && j == r) {
                new_dp[i][j] = (new_dp[i][j] + dp[i][j]) % MOD;
            }
        }
    }
    
    return new_dp;
}

int main() {
    int t;
    std::cin >> t;
    
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::pair<int, int>> clues(n);
        
        for (auto& clue : clues) {
            std::cin >> clue.first >> clue.second;
        }
        
        int total_sequences = count_balanced_sequences(n);
        std::cout << total_sequences % MOD << " ";
        
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
        dp[0][0] = 1;
        
        for (const auto& [l, r] : clues) {
            dp = apply_clue(dp, l - 1, r - 1, n);
            int current_sequences = 0;
            for (int i = 0; i <= n; ++i) {
                current_sequences = (current_sequences + dp[i][i]) % MOD;
            }
            std::cout << current_sequences << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}