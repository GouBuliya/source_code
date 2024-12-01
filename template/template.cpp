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
vector<int>arr;
deque<int>dq;
void solve()
{
    int n=re();
    int m=re();
    for(int i=1;i<=n;++i)
    {
        arr[i]=re();
    }
    for(int i=1;i<=n;++i)
    {
        if(dq.front()+m<i)
            dq.pop_front();
        while (!dq.empty()&&arr[dq.back()]<=arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
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