#include <bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define POS_N 10001
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
int pre[POS_N];
int root(int x)
{
    return pre[x] = pre[x] == x ? x : root(pre[x]);
}
void merge(int x, int y)
{
    x = root(x), y = root(y);
    if (x == y)
    {
        return;
    }
    else
    {
        pre[x] = y;
    }
}
void solve(int N, int M)
{
    for (int i = 1; i <= M; ++i)
    {
        int X = re(), Y = re();
        merge(X, Y);
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {

        for (int j = i + 1; j <= N; ++j)
        {
            int x = root(i);
            int y = root(j);
            if (x == y)
            {
                break;
            }
            else
            {
                ans++;
                merge(x, y);
            }
        }
    }
    printf("%d\n", ans);
}
signed main()
{
    int n, m;

    while (scanf("%d", &n) && n != 0)
    {
        for (int i = 1; i <= 1001; ++i)
        {
            pre[i] = i;
        }
        scanf("%d", &m);
        if (!m)
        {
            printf("%d", n - 1);
            break;
        }
        solve(n, m);
    }
    return 0;
}