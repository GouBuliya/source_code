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
// 变量
const int mod = 10007;
const int maxn = 1e5 + 10;
int a[maxn];
int s1[maxn][2], s2[maxn][2];
int ans;
int b[maxn];
//---
void solve()
{
    int n = re();
    int m = re();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = re();
    }
    for (int i = 1; i <= m; ++i)
    {
        b[i] = re();
        s1[b[i]][i % 2]++;
        s2[b[i]][i % 2] = (s2[b[i]][i % 2] + a[i]) % mod;
    }
    for (int i = 1; i <= n; ++i)
    {
        int y = b[i];
        ans += i * (s2[y][i % 2] + a[i] * (s1[y][i % 2] - 2) % mod) % mod;
        ans %= mod;
    }
    cout << ans << endl;
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