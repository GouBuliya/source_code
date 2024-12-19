
#include <bits/stdc++.h>
using namespace std;

namespace my {
    const int maxn = 1e6 + 10;
    int A[maxn];          // 存储输入数组
    deque<int> dq;        // 单调队列（存储索引）
    vector<int> mmax;     // 存储窗口最大值
    vector<int> mmin;     // 存储窗口最小值
    int n, m;             // 数组大小和窗口大小

    // 插入新元素到队列，同时维护单调性
    void push(int idx, bool (*cmp)(int, int)) {
        while (!dq.empty() && cmp(A[dq.back()], A[idx]))
            dq.pop_back();
        dq.push_back(idx);
    }

    // 获取当前窗口的最大/最小值
    int get_value() {
        return A[dq.front()];
    }

    // 移除过期的队首元素
    void update(int idx) {
        if (dq.front() < idx)
            dq.pop_front();
    }

    // 计算滑动窗口的最大值或最小值
    void get_vector(bool (*cmp)(int, int), vector<int>& arr) {
        dq.clear();  // 初始化队列
        // 初始化第一个窗口
        for (int i = 0; i < m; ++i)
            push(i, cmp);
        arr.push_back(get_value());

        // 滑动窗口
        for (int i = m; i < n; ++i) {
            push(i, cmp);            // 插入新元素
            update(i - m + 1);       // 移除过期元素
            arr.push_back(get_value());
        }
    }

    // 主函数
    signed main() {
        #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        #endif
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        // 输入
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        // 比较函数
        auto cmp_max = [](int a, int b) { return a <= b; };  // 最大值队列
        auto cmp_min = [](int a, int b) { return a >= b; };  // 最小值队列

        // 计算滑动窗口的最小值和最大值
        get_vector(cmp_min, mmin);
        get_vector(cmp_max, mmax);

        // 输出结果
        for (auto& i : mmin)
            cout << i << " ";
        cout << endl;
        for (auto& i : mmax)
            cout << i << " ";
        cout << endl;

        return 0;
    }
}

signed main() {
    return my::main();
}
