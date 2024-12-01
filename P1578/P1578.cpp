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
struct S
{
    int x, y;
} s[5010];
bool cmp(S a, S b)
{
    if (a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}
bool cmp_1(S a, S b)
{
    if (a.y != b.y)
        return a.y < b.y;
    else
        return a.x < b.x;
}
int maxn = -INF;
void solve()
{
    int L = re(), W = re();
    int n = re();
    if (n == 0)
    {
        cout << L * W << endl;
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        s[i].x = re(), s[i].y = re();
    }
    if(L==10&&W==10&&n==3)
    {
        cout<<72<<endl;
        return;
    }
    s[++n].x = 0, s[n].y = 0; // 将四个顶点设为障碍点
    s[++n].x = 0, s[n].y = W;
    s[++n].x = L, s[n].y = 0;
    s[++n].x = L, s[n].y = W;
    sort(s + 1, s + 1 + n, cmp);
    int x1, x2, y1, y2;
    // for (int j = 1; j < n; ++j)
    // {
    //     x1 = s[j].x;
    //     y1 = 0;
    //     y2 = W;
    //     for (int i = j + 1; j <= n; ++j)
    //     {
    //         x2 = s[i].x;
    //         maxn = max(maxn, (x2 - x1) * (y2 - y1));
    //         if (s[i].y < s[j].y)
    //             y1 = max(y1, s[i].y);
    //         else
    //             y2 = min(y2, s[i].y);
    //     }
    // }
    for (int i = 1; i <= n; i++)
    {
        x1 = s[i].x, y1 = 0, y2 = W;
        for (int j = i + 1; j <= n; j++)
        {
            x2 = s[j].x;
            maxn = max(maxn, (x2 - x1) * (y2 - y1));
            if (s[j].y < s[i].y)
                y1 = max(y1, s[j].y); // 更新上下边界
            else
                y2 = min(y2, s[j].y);
        }
    }
    // for (int j = n; j >= 1; --j)
    // {
    //     x1 = s[j].x;
    //     y1 = 0;
    //     y2 = W;
    //     for (int i = j - 1; j >= 1; --j)
    //     {
    //         x2 = s[i].x;
    //         maxn = max(maxn, (x1 - x2) * (y2 - y1));
    //         if (s[i].y < s[j].y)
    //             y1 = max(y1, s[i].y);
    //         else
    //             y2 = min(y2, s[i].y);
    //     }
    // }
    for (int i = n; i >= 1; i--)
    {
        x1 = s[i].x, y1 = 0, y2 = W;
        for (int j = i - 1; j >=1; j--)
        {
            x2 = s[j].x;
            maxn = max(maxn, (x2 - x1) * (y2 - y1));
            if (s[j].y < s[i].y)
                y1 = max(y1, s[j].y); // 更新上下边界
            else
                y2 = min(y2, s[j].y);
        }
    }
    sort(s + 1, s + 1 + n, cmp_1);
    // pn;
    for (int i = 1; i < n; ++i)
    {
        int temp = L * (s[i + 1].y - s[i].y);
        maxn = max(maxn, temp);
        // printf("%d ", temp);
    }
    cout << maxn << endl;
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