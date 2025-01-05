#include <bits/stdc++.h>
#define ll long long
#define INF = 0x7fffffff
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
int a[100000];
int b[100000];
void bf(int n, int mode)
{
    if (mode == 1)
    {
        for (int i = 1; i <= n; ++i)
        {
            b[i] = a[i];
        }
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            a[i] = b[i];
        }
    }
}
bool cmp(int x, int y)
{
    return x < y;
}
void solve()
{
    int N = re();
    int Q = re();
    for (int i = 1; i <= N; ++i)
    {
        a[i] = re();
    }
    for (int i = 1; i <= Q; ++i)
    {
        int mode = re();
        if (mode == 1)
        {
            int x = re();
            int v = re();
            a[x] = v;
        }
        else
        {
            int x = re();
            int tmp = a[x];
            bf(N, 1);
            sort(a+1,a+1+N,cmp);
            // for (int i = 1; i <= N; i++)
            //     for (int j = i; j >= 2; j--)
            //         if (a[j] < a[j - 1])
            //         {
            //             int t = a[j - 1];
            //             a[j - 1] = a[j];
            //             a[j] = t;
            //         }

            int ans = lower_bound(a + 1, a + 1 + N, tmp) - a;
            bf(N, 2);
            printf("%d\n", ans);
        }
    }
}

signed main()
{
    solve();
    return 0;
}