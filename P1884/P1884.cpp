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
const int maxn = 1e3 + 10;
ll a[4 * 1001][5];
ll dtop = 0, ctop;
ll d[4 * maxn];
ll c[4 * maxn];
map<int, int> Map;
int f[4 * maxn][4 * maxn];
void solve()
{

    int n = re();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 4; ++j)
        {
            a[i][j] = re();
            d[++dtop] = a[i][j];
        }
    }
    sort(d + 1, d + dtop + 1);
    d[0] = -10000007;
    for (int i = 1; i <= dtop; ++i)
    {
        if (d[i] != d[i - 1])
        {
            c[++ctop] = d[i];
            Map[d[i]] = ctop;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 4; ++j)
        {
            a[i][j] = Map[a[i][j]];
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = a[k][1]; i < a[k][3]; ++i)
        {
            f[i][a[k][4]]++, f[i][a[k][2]]--;
        }
    }
    for (int i = 1; i < ctop; ++i)
    {
        for (int j = 1; j < ctop; ++j)
        {
            f[i][j] += f[i][j - 1];
        }
    }
    ll ans = 0;
    for (int i = 1; i < ctop; ++i)
    {
        for (int j = 1; j < ctop; ++j)
        {
            if (f[i][j])
                ans += (ll)(c[i + 1] - c[i]) * (c[j + 1] - c[j]);
        }
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