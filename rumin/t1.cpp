#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1005;

int n, m;
vector<vector<int>> A(MAXN, vector<int>(MAXN));
vector<int> row_perm[MAXN], col_perm[MAXN];

void apply_perm(vector<int>& perm, int op, int x, int y) {
    // 注意操作的索引是从1开始的，数组索引从0开始
    swap(perm[x - 1], perm[y - 1]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }
    // 初始化置换数组，初始时行号i映射到i，列号j映射到j
    for (int i = 0; i < n; ++i) {
        row_perm[i] = col_perm[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 0) {
            apply_perm(col_perm, op, x, y);
        } else {
            apply_perm(row_perm, op, x, y);
        }
    }

    // 根据置换数组输出最终结果
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[row_perm[i]][col_perm[j]] << " ";
        }
        cout << endl;
    }

    return 0;
}