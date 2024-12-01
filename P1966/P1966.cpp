#include <bits/stdc++.h>
#define ll long long
#define INF 0x7fffffff
const int POS_N = 1e5 + 7;
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
int arr_a[POS_N];
int arr_b[POS_N];
int map_a[POS_N];
const int mod=1e8-3;
int map_b[POS_N];
int a[POS_N];
ll ans = 0;
int c[2 * POS_N];
void __m_sort(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    __m_sort(l, mid);
    __m_sort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            c[k++] = a[i++];
        else
        {
            c[k++] = a[j++], ans =(ans+ mid - i + 1)%mod;
        }
    }
    while (i <= mid)
        c[k++] = a[i++];
    while (j <= r)
        c[k++] = a[j++];
    for (int v = l; v <= r; ++v)
    {
        a[v] = c[v];
    }
}

void solve()
{
    int n = re();
    for (int i = 1; i <= n; ++i)
        arr_a[i] = re();
    for (int i = 1; i <= n; ++i)
        arr_b[i] = re();
    for (int i = 1; i <= n; ++i)
    {
        map_a[arr_a[i]] = i;
        map_b[arr_b[i]] = i;
    }
    for(int i=1;i<=n;++i)
    {
        a[map_b[i]]=map_a[i];
    }
    __m_sort(1,n);
    printf("%lld ",ans);
    // for (int i = 1; i <= n; ++i)
    // {
    //     printf("%d ", a[i]);
    // }pn;
    // for (int i = 1; i <= n; ++i)
    // {
    //     printf("%d ", map_b[i]);
    // }
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