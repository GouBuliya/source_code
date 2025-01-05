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
int h[MAXN][MAXN];
int l[MAXN][MAXN];
int r[MAXN][MAXN];
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
                a[i][j] = 0;
            else
                a[i][j] = 1;
            h[i][j] = 1, r[i][j] = j, l[i][j] = j;
        }
        for (int j = 2; j <= m; ++j)
            if (a[i][j] && a[i][j - 1])
                l[i][j] = l[i][j - 1] ;

        for (int j = m-1; j > 0; --j)
            if (a[i][j] && a[i][j + 1])
                r[i][j] = r[i][j + 1] ;
    }
    int ans = 0;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j])
            {
                if (a[i - 1][j])
                {
                    h[i][j] = h[i - 1][j] + 1;
                    if (l[i - 1][j] > l[i][j])
                        l[i][j] = l[i - 1][j];
                    if (r[i - 1][j] < r[i][j])
                        r[i][j] = r[i - 1][j];
                }
                if ((r[i][j] - l[i][j] + 1) * h[i][j] > ans)
                    ans = (r[i][j] - l[i][j] + 1) * h[i][j];
            }
        }
    }
    cout << ans * 3 << endl;
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