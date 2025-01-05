c#include <bits/stdc++.h>
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
int arr[1000001];
int drr[1000001];
int max(int x, int y)
{
    return x >= y ? x : y;
}
std::set<int> Set;
bool cheak (int m)
{   
    return Set.size()==m;
}
void solve()
{
    int n = re();
    int m = re();
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = re();
        drr[i] = drr[i - 1] + 1;
    }
    int ansx = 0;
    int ansy = 0;
    int maxn = INF;
    for (int i = n; i >= 1; --i)
    {
        Set.clear();
        Set.insert(arr[i]);
        for (int j = i + 1; j <= n; ++j)
        {
            // if(Set.find(j)!=Set.end())
            Set.insert(arr[j]);
            // printf("Set.size()=%d\n",(int)Set.size());
            if (cheak(m))
            {
                int x = drr[j] - drr[i];
                // printf("x:%d\n",x);
                if (x <= maxn)
                {
                    maxn = x;
                    ansx = i;
                    ansy = j;
                }
            }
        }
    }
    cout << ansx << " " << ansy;
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