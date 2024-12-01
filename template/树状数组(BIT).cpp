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
const int maxn = 5 * 1e5 + 7;
int arr[maxn];
ll prefix[maxn];
int n = re();
int m = re();
int BIT[maxn];
int lowbit(int x) { return x & (-x); }
void add_BIT(int x, int k)
{
    for (int i = x; i <= n; i += lowbit((i)))
        BIT[i] += k;
}
ll sum(int x)
{
    ll res = 0;
    for (int i = x; i <= n; i -= lowbit(i))
        res += BIT[i];
}
ll pre(int x, int y)
{
    return sum(y) - sum(x);
}
signed main()
{
    for (int i = 1; i <= n; ++i)
        arr[i] = re();
    for (int i = 1; i <= n; ++i)
    {
        prefix[i] = prefix[i - 1] + arr[i];
        BIT[i] = prefix[i] - prefix[i - lowbit(i)];
    }
    for (int i = 1; i <= m; ++i)
    {
        int mod = re();
        if (mod == 1)
            add_BIT(re(), re());
        else
            printf("%lld\n",pre(re(),re()));
    }
    return 0;
}
