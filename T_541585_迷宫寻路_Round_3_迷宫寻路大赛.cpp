#include <bits/stdc++.h>
using namespace std;

// 树状数组（Fenwick Tree）实现
class FenwickTree {
private:
    vector<int> tree;
    int n;

public:
    FenwickTree(int size) : n(size), tree(size + 1, 0) {}

    // 更新树状数组
    void update(int idx, int delta) {
        while (idx <= n) {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }

    // 查询前缀和
    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

// 主函数
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c, d;
    cin >> n >> c >> d;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        queries[i].first--; // 转换为 0-based
        queries[i].second--;
    }

    // 离散化处理
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    sorted_a.erase(unique(sorted_a.begin(), sorted_a.end()), sorted_a.end());

    // 将 a 中的元素映射到离散化后的值
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(sorted_a.begin(), sorted_a.end(), a[i]) - sorted_a.begin() + 1;
    }

    // 处理每个查询
    for (const auto& query : queries) {
        int l = query.first, r = query.second;
        int res = 0;

        FenwickTree ft(n);
        for (int y = l; y <= r; ++y) {
            // 计算当前元素 a[y] 的逆序对数目
            int inv = ft.query(n) - ft.query(a[y]);
            ft.update(a[y], 1);

            // 统计满足条件的子区间数目
            if (inv >= c && inv <= d) {
                res++;
            }
        }

        cout << res << '\n';
    }

    return 0;
}