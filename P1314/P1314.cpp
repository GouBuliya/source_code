#include <bits/stdc++.h>
#define ll long long
#define INF 0x7fffffff
const int POS_N = 200001;
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
#define int long long
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

struct minelral
{
    int w, v;
} node[POS_N];

struct ctction
{
    int l, r;
} cset[POS_N];

int s;
int pren[POS_N];
int pre_v[POS_N];

int f(int n, int m, int W)
{
    mclear(pre_v);
    mclear(pren);
    for (int i = 1; i <= n; ++i)
    {
        if (node[i].w >= W)
        {
            pre_v[i] = pre_v[i - 1] + node[i].v;
            pren[i] = pren[i - 1] + 1;
        }
        else
        {
            pre_v[i] = pre_v[i - 1];
            pren[i] = pren[i - 1];
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        ans += (pre_v[cset[i].r] - pre_v[cset[i].l - 1]) * (pren[cset[i].r] - pren[cset[i].l - 1]);
    }

    return abs(ans - s);
}

void solve()
{
    int n = re();
    int m = re();
    s = re();
    int L = INF;
    int R = -1;

    for (int i = 1; i <= n; ++i)
    {
        node[i].w = re();
        node[i].v = re();
        L = std::min(L, node[i].w);
        R = std::max(R, node[i].w);
    }

    for (int i = 1; i <= m; ++i)
    {
        cset[i].l = re();
        cset[i].r = re();
    }

    L -= 1;
    R += 1;
    int ans = LLONG_MAX;

    while (L < R)
    {
        int mid = (L + R) / 2;
        int current_ans = f(n, m, mid);
        if (current_ans < ans)
            ans = current_ans;

        // 检查 mid 和 mid+1 的值，但主要基于 mid 更新答案
        if (f(n, m, mid + 1) < f(n, m, mid))
        {
            L = mid + 1;
        }
        else
        {
            R = mid;
        }
    }

    cout << ans << endl;
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