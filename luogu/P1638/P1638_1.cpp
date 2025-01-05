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
int arr[1000010];
int sum[2010];
void solve()
{
    int n = re();
    int m = re();
    for (int i = 1; i <= n; ++i)
    {
        arr[i]=re();
    }
    
    int l = 1;
    int r = l;
    int num = 0; // num  记录有多少个画师的画
    int ans = INF;
    int ans_l = 0;
    int ans_r = 0;
    // 证明变量
    while (l <= r && r <= n + 1)
    {
        if (num < m)
        {
            r++;
            sum[arr[r - 1]]++;
            if (sum[arr[r - 1]] == 1)
            {
                num++;
            }
        }
        else
        {
            if (r - l < ans)
            {
                ans = r - l;
                ans_l = l;
                ans_r = r - 1;
            }
            sum[arr[l]]--;
            if (sum[arr[l]] == 0)
            {
                num--;
            }
            l++;
        }
    }
    printf("%d %d",ans_l,ans_r);
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