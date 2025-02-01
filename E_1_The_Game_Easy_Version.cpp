#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> w, in, out;
int dfs_time = 0;

void dfs(int u, int parent) {
    in[u] = ++dfs_time;
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
        }
    }
    out[u] = dfs_time;
}

struct SegmentTree {
    int n;
    vector<int> tree;
    SegmentTree(int size, const vector<int>& values) {
        n = 1;
        while (n < size) n <<= 1;
        tree.resize(2 * n, 0);
        for (int i = 0; i < size; ++i) tree[n + i] = values[i];
        for (int i = n - 1; i > 0; --i) tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }
    int query(int l, int r) {
        if (l > r) return 0; // 无效区间直接返回
        l += n - 1;
        r += n - 1;
        int res = 0;
        while (l <= r) {
            if (l % 2 == 1) res = max(res, tree[l++]);
            if (r % 2 == 0) res = max(res, tree[r--]);
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        w.resize(n + 1);
        adj.assign(n + 1, vector<int>());
        in.resize(n + 1);
        out.resize(n + 1);
        dfs_time = 0;
        for (int i = 1; i <= n; ++i) cin >> w[i];
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, -1);
        vector<int> pos(n + 1);
        vector<int> values(n + 1);
        for (int i = 1; i <= n; ++i) {
            pos[i] = in[i];
            values[pos[i]] = w[i];
        }
        SegmentTree st(n + 1, values);
        int found = 0;
        for (int u = 1; u <= n; ++u) {
            int left1 = 1, right1 = in[u] - 1;
            int left2 = out[u] + 1, right2 = n;
            int max_val = 0;
            if (left1 <= right1) {
                max_val = max(max_val, st.query(left1, right1));
            }
            if (left2 <= right2) {
                max_val = max(max_val, st.query(left2, right2));
            }
            if (max_val > w[u]) {
                found = u;
                break;
            }
        }
        cout << found << '\n';
    }
    return 0;
}