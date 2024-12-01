#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll start[20010], ending[20010];
ll axis[40020];
int n, m = 1;
bool flag[40020];
long long ans = 0;
inline int find(long long key) { // 找原来位置
    return lower_bound(axis + 1, axis + 1 + m, key) - axis;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> start[i] >> ending[i];
        axis[m++] = start[i];
        axis[m++] = ending[i];
    }
    sort(axis + 1, axis + m);
    m = unique(axis + 1, axis + m) - axis - 1; // 去除重复元素

    for (int i = 1; i <= n; ++i) {
        start[i] = find(start[i]);
        ending[i] = find(ending[i]);
        for (int j = start[i]; j < ending[i]; j++) {
            flag[j] = true;
        }
    }

    int last = 0;
    for (int i = 1; i <= m; ++i) {
        if (flag[i] && !last) {
            last = i;
        } else if (!flag[i] && last) {
            ans += axis[i] - axis[last];
            last = 0;
        }
        last |= flag[i];
    }
    if (last) {
        ans += axis[m] - axis[last];
    }

    cout << ans << endl;
}