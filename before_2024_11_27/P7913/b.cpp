#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int n, M1, M2;

struct range {
    int x, y;
} qm1[maxn], qm2[maxn];

int drr1[maxn];
int drr2[maxn];

void solve(int m, range* A, int* arr) {
    priority_queue<int, vector<int>, greater<int>> que1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que2;

    for (int i = 1; i <= n; ++i) {
        que1.push(i);
    }

    for (int i = 1; i <= m; ++i) {
        while (!que2.empty() && A[i].x > que2.top().first) {
            que1.push(que2.top().second);
            que2.pop();
        }
        if (que1.empty()) continue;

        int d = que1.top();
        que1.pop();
        arr[d]++;
        que2.push({A[i].y, d});
    }

    for (int i = 1; i <= n; ++i) {
        arr[i] += arr[i - 1];
    }
}

auto cmp = [](const range &a, const range &b) {
    return a.x < b.x;
};

signed main() {
    scanf("%d %d %d", &n, &M1, &M2);
    for (int i = 1; i <= M1; ++i) {
        scanf("%d %d", &qm1[i].x, &qm1[i].y);
    }
    for (int i = 1; i <= M2; ++i) {
        scanf("%d %d", &qm2[i].x, &qm2[i].y);
    }
    
    sort(qm1 + 1, qm1 + 1 + M1, cmp);
    sort(qm2 + 1, qm2 + 1 + M2, cmp);
    
    solve(M1, qm1, drr1);
    solve(M2, qm2, drr2);
    
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        int j = n - i;
        ans = max(ans, drr1[i] + drr2[j]);
    }

    printf("%d", ans);
}
