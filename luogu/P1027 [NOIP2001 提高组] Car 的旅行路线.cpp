#include <bits/stdc++.h>
#define ll long long
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
const int maxn = 440;
int x[maxn];
int y[maxn];
int T[maxn];
double f[maxn][maxn];
double pf(int x)
{
    return x * x;
}
double how_v(int x1, int y1, int x2, int y2)
{
    return sqrt(pf(x1 - x2) + pf(y1 - y2));
}
void how_d(int i)
{
    int ab = pf(x[i + 0] - x[i + 1]) + pf(y[i + 0] - y[i + 1]);
    int ac = pf(x[i + 0] - x[i + 2]) + pf(y[i + 0] - y[i + 2]);
    int bc = pf(x[i + 1] - x[i + 2]) + pf(y[i + 1] - y[i + 2]);
    if (ab + bc == ac)
    {
        x[i + 3] = x[i + 0] + x[i + 2] - x[i + 1];
        y[i + 3] = y[i + 0] + y[i + 2] - y[i + 1];
    }
    else if (ab + ac == bc)
    {
        x[i + 3] = x[i + 2] + x[i + 1] - x[i + 0];
        y[i + 3] = y[i + 2] + y[i + 1] - y[i + 0];
    }
    else if (ac + bc == ab)
    {
        x[i + 3] = x[i + 0] + x[i + 1] - x[i + 2];
        y[i + 3] = y[i + 0] + y[i + 1] - y[i + 2];
    }
}
void solve()
{
    int S, t, A, B;
    cin >> S >> t >> A >> B;
    for (int i = 0; i <= 4 * S; i++)
        for (int j = 0; j <= 4 * S; ++j)
            f[i][j] = i == j ? 0 : 1e9;
    for (int i = 0; i < S; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            x[4 * i + j] = re();
            y[4 * i + j] = re();
        }
        T[i] = re();
        how_d(4 * i);
    }
    for (int i = 0; i < 4 * S; ++i)
        for (int j = 0; j < 4 * S; ++j)
            if (i / 4 == j / 4)
                f[i][j] = how_v(x[i], y[i], x[j], y[j]) * T[i / 4];
            else
                f[i][j] = how_v(x[i], y[i], x[j], y[j]) * t;
    for (int k = 0; k < 4 * S; ++k)
        for (int i = 0; i < 4 * S; ++i)
            for (int j = 0; j < 4 * S; ++j)
            {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
    double ans = 1e9;
    for (int i = 0; i <= 3; ++i)
        for (int j = 0; j <= 3; ++j)
        {
            ans = min(ans, f[(A - 1) * 4 + i][(B - 1) * 4 + j]);
        }
    printf("%.1f\n",ans);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = re();
    while (t--)
        solve();
    return 0;
}
