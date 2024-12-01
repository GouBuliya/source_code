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
struct cmp
{
    /* data */
    bool operator()(const int &a,int &b)
    {
        return a>b;
    }
};

void solve()
{
    priority_queue<int,vector<int>,greater<int>> prquDui;
    prquDui.
    int n = re();
    for (int i = 1; i <= n; ++i)
    {
        int iMod = re();
        if(iMod==1)
            prquDui.push(re());
        if(iMod==2)
        {
            int i_top=prquDui.top();
            printf("%d\n",i_top);
        }
        if(iMod==3)
            prquDui.pop();
    }
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