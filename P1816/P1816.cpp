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
const int maxn = 1e6 + 7;
int arr[maxn];
int lg[maxn];
int f[maxn][30];
void solve()
{
    int m = re();
    int n = re();
    for (int i = 1; i <= m; ++i)
        f[i][0] = re();
    for (int i = 2; i <= m; ++i)
        lg[i] = lg[i >> 1] + 1;
    for (int j = 1; j <= lg[m]; ++j)
        for (int i = 1; i <= m; ++i)
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    for(int i=1;i<=n;++i)
        {
            int a=re();int b=re();
            int l=lg[b-a+1];
            printf("%d ",min(f[a][l],f[b-(1<<l)+1][l]));
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