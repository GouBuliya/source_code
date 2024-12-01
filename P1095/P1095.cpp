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
const int maxn = 300000 + 10;
int f[maxn];
void solve()
{
    int M = re();
    int s = re();
    int T = re();
    
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= T; ++i)
    {
        // if(f[i-1]>)
        s1 += 17;
        if (M >= 10)
        {
            s2 += 60;
            M -= 10;
        }
        else
        {
            M += 4;
        }
        if (s1 > s2)
        {
            s1 = s2;
        }
        if (s1 > s)
        {
            printf("Yes\n%d\n", i);
            return;
        }
    }
    printf("No\n%d", s1);
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