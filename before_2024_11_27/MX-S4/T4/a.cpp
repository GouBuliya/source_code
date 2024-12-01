#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// 转换为三进制表示
string toTernary(int num) {
    if (num == 0) return "0";
    string result;
    while (num > 0) {
        result = to_string(num % 3) + result;
        num /= 3;
    }
    return result;
}

// 检查是否存在完美的序列
bool isPerfectSequence(int x, int y, int z, const unordered_set<int>& z_set) {
    return (z_set.find(x) != z_set.end() && z_set.find(y) != z_set.end());
}

int main() {
    int n, w;
    cin >> n >> w;

    vector<int> result(n + 1, 0);

    // 存储 0 到 n 的三进制表示
    vector<string> ternary(n + 1);
    for (int i = 0; i <= n; ++i) {
        ternary[i] = toTernary(i);
    }

    // 对于每个 z 值
    for (int z = 0; z <= n; ++z) {
        unordered_set<int> z_set;

        // 统计有效的 (x, y) 对
        for (int x = 0; x <= n; ++x) {
            if (x == z) continue;
            for (int y = 0; y <= n; ++y) {
                if (y == x || y == z) continue;

                // 检查是否可以构造完美序列
                if (isPerfectSequence(x, y, z, z_set)) {
                    result[z]++;
                }
            }
        }
    }

    // 输出结果
    for (int i = 0; i <= n; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
