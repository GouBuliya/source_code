#include <bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;

int re() {
    int x = 0, t = 1; char ch = getchar();
    while (ch > '9' || ch < '0') { if (ch == '-') t = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x * t;
}

const int N = 6005;
int n, A[N][N], f[N][2];

void DFS(int u, int parent) {
    // 初始化当前节点的两种状态：选中或不选中
    f[u][0] = 0; // 不选u
    f[u][1] = A[u][0]; // 选u

    // 遍历当前节点的所有子节点
    for (int i = 1; i <= A[u][5999]; ++i) {
        int v = A[u][i];
        if (v == parent) continue; // 跳过父节点
        DFS(v, u); // 对子节点进行DFS

        // 更新当前节点的最大快乐指数，考虑选择或不选择子节点的情况
        f[u][0] += max(f[v][0], f[v][1]); // 不选u，子节点可选可不选
        f[u][1] += f[v][0]; // 选u，则子节点不能选
    }
}

signed main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    n = re();
    for (int i = 1; i <= n; ++i) {
        A[i][0] = re(); // 快乐值
    }
    for (int i = 1; i < n; ++i) {
        int l = re(), k = re();
        A[k][5999]++;
        A[k][A[k][5999]] = l;   
    }

    // 从根节点开始DFS
    DFS(1, 0);

    // 输出最大快乐指数，根节点可能被选也可能不被选，取较大者
    printf("%d\n", max(f[1][0], f[1][1]));

    return 0;
}