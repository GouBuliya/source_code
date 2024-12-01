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
char a[1010][1010];
void solve()
{
    int n=re(),m=re();
    getchar();
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            a[i][j]=getchar();
        }
        getchar();
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            printf("%c ",a[i][j]);
        }
        pn;
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