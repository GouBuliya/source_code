#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // 图的邻接表表示
    vector<vector<int>> graph(n + 1);
    vector<int> inDegree(n + 1, 0);

    // 存储限制条件
    unordered_map<int, vector<int>> constraints_T; // T 条件
    unordered_map<int, vector<int>> constraints_N; // N 条件

    // 输入处理
    for (int i = 0; i < m; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'T') {
            constraints_T[x].push_back(y);
        } else {
            constraints_N[x].push_back(y);
        }
    }

    // 构建图
    for (const auto& pair : constraints_T) {
        int x = pair.first;
        for (int y : pair.second) {
            graph[y].push_back(x); // y 是 x 的祖先，所以 y -> x
            inDegree[x]++;
        }
    }

    // 拓扑排序
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);
        for (int v : graph[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // 如果拓扑排序结果不包含所有节点，说明有环，输出 NIE
    if (topoOrder.size() != n) {
        cout << "NIE" << endl;
        return 0;
    }

    // 确定父节点
    vector<int> parent(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (constraints_T.find(i) != constraints_T.end()) {
            for (int y : constraints_T[i]) {
                parent[i] = y; // y 是 i 的祖先
                break;
            }
        }
    }

    // 检查 N 条件
    for (const auto& pair : constraints_N) {
        int x = pair.first;
        for (int y : pair.second) {
            // 如果 y 是 x 的祖先，则违反条件
            bool isAncestor = false;
            for (int ancestor : constraints_T[x]) {
                if (ancestor == y) {
                    isAncestor = true;
                    break;
                }
            }
            if (isAncestor) {
                cout << "NIE" << endl;
                return 0;
            }
        }
    }

    // 输出结果
    for (int i = 1; i <= n; i++) {
        cout << parent[i] << endl;
    }

    return 0;
}



