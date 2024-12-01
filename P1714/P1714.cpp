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
const int MAXN=500010;
int arr[MAXN];
ll drr[MAXN];
deque<int> dq;
void solve()
{
    int n=re();
    int m=re();
    for(int i=1;i<=n;++i)
    {
        arr[i]=re();
        drr[i]=drr[i-1]+arr[i];
    }
    ll ans=-INF;
    dq.push_back(0);
    for(int i=1;i<=n;++i)
    {
        if(dq.front()+m<i)
        dq.pop_front();
        ans=max(ans,drr[i]-drr[dq.front()]);
        while (!dq.empty()&&drr[dq.back()]>=drr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    printf("%lld\n",ans);
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