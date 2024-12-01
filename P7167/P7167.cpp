#include <bits/stdc++.h>
#define ll long long
#define INF 0x7fffffff
const int POS_N = 10001;
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
#define ck cout << "ok" << endl;
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
const int maxn = 1e5 + 7;
struct node
{
    int D, C;
} A[maxn];
int f[maxn][25]; //
int g[maxn][25];
int stk[maxn];    int top = 0;
void solve()
{
    int n = re(), q = re();
    for (int i = 1; i <= n; ++i)
        A[i].D = re(), A[i].C = re();
    for (int i = n; i >= 1; --i)
    {
        while (top && A[stk[top]].D <= A[i].D)
            top--;
        f[i][0] = stk[top];
        stk[++top] = i;
    }
    // 倍增
    for ( int i = 1; i <= 23; ++i)
        for ( int j = 1; j <= n; ++j)
            f[j][i] = f[f[j][i - 1]][i - 1];
    for (int i = 1; i <= n; ++i)
        g[i][0] = A[f[i][0]].C;
    for (int i = 1; i <= n; ++i)
        if (f[i][0] == 0)
            g[i][0] = INF;
    for ( int i = 1; i <= 23; ++i)
        for ( int j = 1; j <= n; ++j)
            g[j][i] = g[j][i - 1] + g[f[j][i - 1]][i - 1]; 
    while (q--)
    {
        int r = re(), v = re();
        if (v <= A[r].C)
        {
            cout << r << '\n';
            continue;
        }
        v -= A[r].C;
        for (int i = 23; i >= 0; --i)
            if (g[r][i] <= v)
                v -= g[r][i], r = f[r][i];
        if (v)
            r = f[r][0];
        cout << r << '\n';
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