#include <bits/stdc++.h>
#define ll long long
#define INF = 0x7fffffff
const int POS_N = 10001;
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
inline int re()
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
int f[10000001];
int A[10000001];
bool vis[(int)1e9+10];
int N;
int mmax = -1;
inline void primennum(int x)
{
    int pos = 1;
    for (size_t i = 2; i <= N; ++i)
    {
        if (vis[i])
            continue;
        else
        {
            if (pos > x)
            {
                return;
            }
            f[pos] = i;
            pos++;
            for (int j = i; j <= (N / i); ++j)
            {
                vis[j * i] = 1;
            }
        }
    }
}
void solve()
{
    N = re();
    int Q = re();
    for (int i = 1; i <= Q; ++i)
    {
        A[i] = re();
        mmax = max(mmax, A[i]);
    }
    primennum(mmax);
    for(int i=1;i<=Q;++i)
    {
        printf("%d\n",f[A[i]]);
    }
}
signed main()
{
    solve();
    return 0;
}