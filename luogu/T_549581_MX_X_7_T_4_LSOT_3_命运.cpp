#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

vector<int> adj[1000005], rev_adj[1000005];
bool visited[1000005];
vector<int> order, scc;
int n;
int p[1000005];

// Tarjan算法，找到所有强连通分量
void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs1(v);
    }
    order.push_back(u);
}

void dfs2(int u) {
    visited[u] = true;
    scc.push_back(u);
    for (int v : rev_adj[u]) {
        if (!visited[v]) dfs2(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        adj[i].push_back(p[i]);
        rev_adj[p[i]].push_back(i);
    }

    // Step 1: Topological sorting in the original graph
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs1(i);
    }

    fill(visited, visited + n + 1, false);

    long long result = 1;
    // Step 2: Reverse DFS to find SCCs
    reverse(order.begin(), order.end());
    for (int u : order) {
        if (!visited[u]) {
            scc.clear();
            dfs2(u);
            // For each SCC, the number of ways to arrange them is the factorial of its size
            long long ways = 1;
            int size = scc.size();
            for (int i = 1; i <= size; i++) {
                ways = (ways * i) % MOD;
            }
            result = (result * ways) % MOD;
        }
    }

    cout << result << endl;
    return 0;
}
