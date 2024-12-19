
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, c;
    cin >> n >> m >> c;
    
    vector<int> s(n + 1); // 第 i 天骑行的分钟数
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    
    vector<vector<int>> cards(m, vector<int>(3));
    for (int i = 0; i < m; ++i) {
        cin >> cards[i][0] >> cards[i][1] >> cards[i][2]; // w, d, t
    }
    
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, LLONG_MAX)); // dp[i][j] 表示从第 i 天到第 j 天的最小总支出
    
    // 初始化单天的情况
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = (long long)s[i] * c;
    }
    
    // 区间长度从 2 到 n
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            
            // 不购买任何新的骑行卡
            dp[i][j] = dp[i][j - 1] + (long long)s[j] * c;
            
            // 考虑购买每种骑行卡的情况
            for (const auto& card : cards) {
                int w = card[0];
                int d = card[1];
                int t = card[2];
                
                if (j - i + 1 >= d) {
                    long long cost = dp[i][j - d] + w;
                    int currentMaxFreeTime = 0;
                    
                    for (int k = j - d + 1; k <= j; ++k) {
                        currentMaxFreeTime = max(currentMaxFreeTime, t);
                        cost += max(0, s[k] - currentMaxFreeTime) * c;
                    }
                    
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
    }
    
    cout << dp[1][n] << "\n";

    return 0;
}
