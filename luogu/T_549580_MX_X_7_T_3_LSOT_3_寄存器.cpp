#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<int> adj[6];
int a[6], b[6];  // a存储目标状态，b存储当前状态

// DFS函数：模拟通电操作，更新状态
void dfs(int u, int parent) {
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            // 如果当前v的状态与目标不同，进行一次通电
            if (b[v] != a[v]) {
                b[v] = 1 - b[v];  // 翻转
            }
        }
    }
    // 如果当前节点状态与目标不同，进行一次通电
    if (b[u] != a[u]) {
        b[u] = 1 - b[u];  // 翻转
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = 0;  // 初始时每个寄存器的信息为0
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int count = 0;
    // 从1号节点开始DFS
    dfs(1, -1);
    
    // 输出最少通电次数
    for (int i = 1; i <= n; i++) {
        if (b[i] != a[i]) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
