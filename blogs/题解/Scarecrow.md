# sol

首先考虑抛去瞬间移动不看乌鸦的速度要么没有，要么为 $1$，不可能大于 $1$，然后，因为要走的路程已经给定了，而普通移动的速度恒定，那么就要让乌鸦瞬间移动的距离之和最大，就是让传送的距离尽可能长，那么首先可以肯定的是稻草人越往左越好，如果太密集，有一部分要往右走，然后，稻草人的移动路线不会相交，调整法易证。然后直接模拟就行了。

---
```cpp
#include <cstdio>
#include<bits/stdc++.h>
#define ll long long

const int N = 200005;
int a[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k, l;
        scanf("%d %d %d", &n, &k, &l);
        k *= 2;
        l *= 2;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            a[i] *= 2;
        }
        
        int pos = k, t = a[1], ans = pos <= l ? l - pos + t : t;
        
        for (int i = 2; i <= n; i++) {
            if (pos <= a[i]) {
                if (a[i] - t > pos) {
                    int dt = (a[i] - t - pos) / 2;
                    pos += dt + k;
                    t += dt;
                } else {
                    pos += k;
                }
            } else {
                pos = a[i] + t >= pos ? pos + k : a[i] + t + k;
            }
            
            ans = std::min(ans, int(pos <= l ? l - pos + t : t));
        }
        printf("%d\n", ans);
    }
    return 0;
}

```