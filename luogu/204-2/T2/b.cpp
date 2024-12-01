#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

void dfs(int u, vector<vector<int>>& g, vector<bool>& vis, stack<int>& stk) {
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v, g, vis, stk);
        }
    }
    stk.push(u);
}

void dfs_rev(int u, vector<vector<int>>& rg, vector<bool>& vis, int& size) {
    vis[u] = true;
    size++;
    for (int v : rg[u]) {
        if (!vis[v]) {
            dfs_rev(v, rg, vis, size);
        }
    }
}

int count_happier_pairs(int n, const string& cmp) {
    vector<vector<int>> g(n), rg(n);
    
    // 构建图
    for (int i = 0; i < n - 1; ++i) {
        if (cmp[i] == '<') {
            g[i].push_back(i + 1);
            rg[i + 1].push_back(i);
        } else if (cmp[i] == '>') {
            g[i + 1].push_back(i);
            rg[i].push_back(i + 1);
        }
    }
    
    vector<bool> vis(n, false);
    stack<int> stk;
    
    // 正向 DFS 获取完成顺序
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i, g, vis, stk);
        }
    }
    
    vis.assign(n, false);
    vector<int> sizes;
    
    // 反向 DFS 计算强连通分量
    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();
        if (!vis[u]) {
            int size = 0;
            dfs_rev(u, rg, vis, size);
            sizes.push_back(size);
        }
    }
    
    // 计算有效对数
    int total_pairs = 0;
    int total = 0;
    for (int size : sizes) {
        total_pairs += size * (total); // 这里应为总的连接数
        total += size; // 更新总大小
    }
    
    return total_pairs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string cmp;
        cin >> cmp;
        cout << count_happier_pairs(n, cmp) << '\n';
    }
    
    return 0;
}

