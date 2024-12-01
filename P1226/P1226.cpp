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
ll binpow(const ll a, ll b, const ll p)
{
    if (b == 0)
        return 1;
    __int128_t temp = binpow(a, b / 2, p) % p;
    if (b % 2 == 1)
        return (temp * temp * a) % p;
    else
        return (temp * temp) % p;
}
void solve()
{
    int a = re();
    int b = re();
    int p = re();
    printf("%d^%d mod %d=%ld", a, b, p, binpow(a, b, p));
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