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
void debug(int n, int m,int arr[MAXN][MAXN])
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            printf("%d", arr[i][j]);
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
        for (int j = 1; j <= m; ++j)
        {
            char temp;
            scanf("%c ", &temp);
            if (temp == 'R')
                a[i][j] = 0;
            else
                a[i][j] = 1;
        }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == 0)
                h[i][j] = 0;
            else
            {
                if (i == 1)
                    h[i][j] = 1;
                else
                {
                    h[i][j] = h[i - 1][j] + 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i][1] == 0)
        {
            l[i][1] = 0;
        }
        else
            l[i][1] = 1;
        if (a[i][m] == 0)
        {
            r[i][m] = 0;
        }
        else
            r[i][m] = 1;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(a[i][j]==0)
            {
                l[i][j]=0;
            }
            else
            {
                l[i][j]=l[i][j-1]+1;
            }
        }
    }

    for(int i=1;i<=n;++i)
    {
        for(int j=m;j>=1;--j)
        {
            if(a[i][j]==0)
            {
                r[i][j]=0;
            }
            else
            {
                r[i][j]=r[i][j+1]+1;
            }
        }
    }
    // debug(n, m);
    // pn;
    // debug_1(n,m);
    
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