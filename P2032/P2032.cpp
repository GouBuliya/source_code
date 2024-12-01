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
int arr[2000010];
void solve()
{
    int n=re();
    int k=re();
    for(int i=1;i<=n;++i)
        arr[i]=re();
    deque<int>dq;
    for(int i=1;i<=n;++i)
    {
        if(dq.empty())
            dq.push_back(i);
        else
        {
            if(dq.front()<=i-k)
                dq.pop_front();
            if(dq.size()>k)
                dq.pop_back();
            while (!dq.empty()&&arr[i]>arr[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k)cout<<arr[dq.front()]<<endl;
        }        
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