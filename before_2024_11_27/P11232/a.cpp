#include <bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
#define int long long
int re()
{
    int t;
    cin >> t;
    return t;
}
const int maxn = 1e5 + 10;
struct car
{
    int d, l, r;
    int a, v;
    int L = -1;
    int R = -1;
} A[maxn];
int P[maxn];
int L;
int V;
int n, m;
bool cmp(car A, car B)
{
    if (A.r != B.r)
        return A.r < B.r;
    else
        return A.l <B.l;
}

void solve()
{
    n = re(), m = re(), L = re(), V = re();
    for (int i = 1; i <= n; ++i)
        A[i].d = re(), A[i].v = re(), A[i].a = re();
    for (int i = 1; i <= m; ++i)
        P[i] = re();
    for (int i = 1; i <= n; ++i)
    {
        if (A[i].a == 0)
        {
            if (A[i].v > V)
            {
                A[i].l = lower_bound(P + 1, P + m + 1, A[i].d) - P;
                A[i].r = m;
            }
            else
            {
                A[i].l = -1;
                A[i].r = -1;
            }
        }
        if (A[i].a > 0)
        {
            if (A[i].v > V)
            {
                A[i].l = lower_bound(P + 1, P + m + 1, A[i].d) - P;
                A[i].r = m;
            }
            else
            {
                int u = (V * V - A[i].v * A[i].v);
                int v = 2 * A[i].a;
                if (u / v > L - A[i].d)
                {
                    A[i].l = -1;
                }
                else
                {
                    A[i].l = lower_bound(P + 1, P + 1 + m, (A[i].d + (u / v))) - P;
                    A[i].r = m;
                }
            }
        }
        if (A[i].a < 0)
        {
            if (A[i].v > V)
            {
                int p = lower_bound(P + 1, P + 1 + m, A[i].d) - P;
                if (P[p] > (A[i].d + (double(V * V - A[i].v * A[i].v)) / 2 * A[i].a))
                {
                    A[i].l = -1;
                    A[i].r = -1;
                }
                else
                {
                    int t = P[p] - A[i].d;
                    int vf = (A[i].v * A[i].v + 2 * A[i].a * t);
                    if (double(V * V - vf) / 2 * A[i].a < 0)
                    {
                        A[i].l = -1;
                        A[i].r = -1;
                    }

                    else
                    {
                        A[i].l = p;
                        int v = (2 * A[i].a);
                        int u = (V * V - A[i].v * A[i].v);
                        A[i].r = lower_bound(P + 1, P + 1 + m, u / v -1) - P ;
                        int s = A[i].d + (u / v);
                        if (!(s >= A[i].r))
                            A[i].r = lower_bound(P + 1, P + 1 + m, u / v) - P;
                    }
                }
            }
            else
            {
                A[i].l = -1;
                A[i].r = -1;
            }
        }
    }
    for(int i=1;i<=n;++i)
        if(A[i].l>A[i].r)swap(A[i].l,A[i].r);
    sort(A + 1, A + 1 + n, cmp);
    for (int i = 1; i <= n; ++i)
    {
        cout << A[i].r << " " << A[i].l << endl;
    }
    int i = 0;
    while (A[i].l == -1)
    {
        i++;
    }

    int N = i;
    cout << n - i << " ";
    int T = -1;
    int ans=0;
    for (i = N + 1; i <= n; i++)
    {
            if (A[i].l > T)
            {
                // cout<<A[i].l<<endl;
                ans++;
                T = A[i].r;
            }
    }
    cout << n - ans << endl;
}
signed main()
{
#ifndef ONLINE_JUDGE
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("in", "r", stdin);
    int t = re();
    while (t--)
    {
        solve();
    }
    return 0;
}
