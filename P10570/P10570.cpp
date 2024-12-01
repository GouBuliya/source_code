#include <bits/stdc++.h>
#define ll long long
#define int long long
#define INF 0x7fffffff
const int POS_N = 10001;
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
long long re()
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
inline void solve()
{
    int a = re(), b = re(), c = re();
    int g = __gcd(a, b);
    a = a / g;
    b = b / g;

    long long k = ceil((double)c /(double) (min(a, b)*1.0));
    cout << (long long)k * (a + b) << endl;
}
signed main()
{
    int N = re();
    while (N--)
    {
        solve();
    }

    return 0;
}