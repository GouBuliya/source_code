```cpp
#include <bits/stdc++.h>
#define ll long long
#define INF 0x7fffffff
const int POS_N = 10001;
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
int re()
{
    int x = 0, t = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x * t;
}
const int maxn = 100000 + 7;
int arr[maxn];
int f[maxn][20];
int log_2[maxn];
int query(int A, int B)
{
    int Log = log_2[B - A + 1];
    return max(f[A][Log], f[B - (1 << Log) + 1][Log]);
}
void solve()
{
    int n = re();
    int m = re();
    log_2[1]=0;
    for (int i = 2; i <= n; ++i)
        log_2[i] = log_2[i >> 1] + 1;
    for (int i = 1; i <= n; ++i)
        f[i][0] =re();
    for (int j = 1; j<=log_2[n]; ++j)
        for (int i = 1; i <= n - (1 << j) + 1; ++i)
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    for (int i = 1; i <= m; ++i)
    {
        int x=re(),y=re();
        int l=log_2[y-x+1];
        printf("%d\n", max(f[x][l],f[y-(1<<l)+1][l]));
    }
}
signed main()
{
    int N = 1;
    while (N--)
    {
        solve();
    }
    return 0;
}
```