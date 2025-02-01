#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long countValidPairs(int n, vector<int>& parents) {
    // 构建树结构
    vector<vector<int>> children(n + 1); // 节点从1到n
    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (parents[i - 1] == i) {
            root = i; // 根节点的父节点是它自己
        } else {
            children[parents[i - 1]].push_back(i);
        }
    }

    // 遍历每一条路径，统计节点数
    long long result = 0;
    stack<pair<int, int>> stk; // (node, depth)
    stk.push({root, 1}); // 根节点的深度为1
    while (!stk.empty()) {
        auto [node, depth] = stk.top();
        stk.pop();
        result += (long long)depth * depth; // 累加k^2
        for (int child : children[node]) {
            stk.push({child, depth + 1}); // 子节点深度加1
        }
    }

    return result;
}

int main() {
    // 读取输入
    int n;
    cin >> n;
    vector<int> parents(n);
    for (int i = 0; i < n; i++) {
        cin >> parents[i];
    }

    // 计算并输出结果
    cout << countValidPairs(n, parents) << endl;
    return 0;
}