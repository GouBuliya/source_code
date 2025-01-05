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
const int MAXN = 1010;
int a[MAXN][MAXN];
ll drr[MAXN][MAXN];
void debug(int n, int m)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            printf("%5d ",drr[i][j]);
        }
        pn;
    }
}
void solve()
{
    int n = re();
    int m = re();
    getchar();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            char temp;
            scanf("%c ", &temp);
            if (temp == 'R')
            {
                a[i][j] = -1000;
            }
            else
            {
                a[i][j] = 1;
            }
            drr[i][j] = drr[i - 1][j] + drr[i][j - 1] - drr[i - 1][j - 1] + a[i][j];
        }
    }
    debug(n,m);
    ll ans = -INF * 1000;
    for (int i = 1; i <= n; ++i)
    {
        for (int i1 = i + 1; i1 <= n; ++i1)
        {
            for (int j = 1; j <= m; ++j)
            {
                for (int j1 = j + 1; j1 <= m; ++j1)
                {
                    ll temp = drr[i1][j1]-drr[i1][j-1]-drr[i-1][j1]+drr[i-1][j-1];
                    ans = max(ans, temp);
                }
            }
        }
    }
    cout << ans * 3 << endl;
    // cout<<drr[5][6]-drr[]
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