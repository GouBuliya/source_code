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
const int maxn = 10010;
int seek[maxn][maxn];
int ans[maxn];
int dis[maxn];
void di(int s,int n)
{
    for(int i=1;i<=n;++i)
    {
        seek[s][i]
    }
}
void solve()
{
    int n = re(), m = re(), s = re(); // 包含三个整数 n,m,s，分别表示点的个数、有向边的个数、出发点的编号。
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            seek[i][j]=i==j?0:INF;
        }
    }
    for (int i = 1; i <= m; ++i)
        seek[re()][re()] = re();
    
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