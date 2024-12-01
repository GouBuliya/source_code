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
int a[100001];
void solve()
{
    int n = re();
    for (int i = 1; i <= n; ++i)
    {
        a[i]=re();
    }
    
    for(int i=1;i<=n;++i)
    {

        if (i == 2)
            continue;
        a[2] /=  __gcd(a[2], a[i]);
    }
    if (a[2] == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
signed main()
{
    int N = re();
    while (N--)
    {
        solve(); /* code */
    }

    return 0;
}