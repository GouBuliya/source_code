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
} A[maxn];
struct TTT
{
    int l, r;
} B[maxn];
int P[maxn];
int L;
int V;
int n, m;

bool cmp(TTT A, TTT B)
{
    if (A.r != B.r)
        return A.r < B.r;
    else
        return A.l < B.l;
}
inline int fl(double x)
{
    if(x-(int)x<eps)return (int)x-1;
    else return (int)x;
}
inline int ce(double x)
{
    if((int)x+1-x<eps)return (int)x+2;
    else return (int)x+1;
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
        if (A[i].a > 0)
        {
            if (A[i].v > V)
            {
                A[i].l = A[i].d;
                A[i].r = L;
            }
            else
            {
                double tt=(V-A[i].v)*1.0/A[i].a;
                A[i].l = min(L+1,ce(A[i].d+A[i].v*tt+0.5*A[i].a*tt*tt));
                A[i].r = L;
            }
        }
        if (A[i].a > 0)
        {
            // if (A[i].v > V)
            // {
            //     A[i].l = A[i].d;
            //     A[i].r = L;
            // }
            // else
            // {
            //     int u = (V * V - A[i].v * A[i].v);
            //     int v = 2 * A[i].a;
            //     if (u / v > L - A[i].d)
            //     {
            //         A[i].l = -1;
            //         A[i].r = -1;
            //     }
            //     else
            //     {
            //         A[i].l = (A[i].d + (u / v));
            //         A[i].r = L;
            //     }
            // }
             if(A[i].v>V)
                {
                    b[i].l=d[i];
                    b[i].r=l;
                }
                else
                {
                    b[i].l=1;
                    b[i].r=0;
                }
        }
        if (A[i].a < 0)
        {
            if (A[i].v > V)
            {
                int p = A[i].d;
                if (p > (A[i].d + (double(V * V - A[i].v * A[i].v)) / 2 * A[i].a))
                {
                    A[i].l = -1;
                    A[i].r = -1;
                }
                else
                {
                    int t = p - A[i].d;
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
                        A[i].r = u / v - 1;
                        int s = A[i].d + (u / v);
                        if (!(s >= A[i].r))
                            A[i].r = u / v;
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
    int pos = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (A[i].l != -1&&A[i].r!=-1)
        {
            B[++pos].l = lower_bound(P + 1, P + 1 + m, A[i].l) - P;
            B[pos].r = upper_bound(P + 1, P + 1 + m, A[i].r) - P - 1;
        }
    }

    sort(B + 1, B + 1 + pos, cmp);
    // for (int i = 1; i <= pos; ++i)
    // {
    //     cout << B[i].r << " " << B[i].l << endl;
    // }

    cout << pos << " ";
    int T = -1;
    int ans = 0;
    for (int i = 1; i <= pos; i++)
    {
        if (P[B[i].l] > A[i].r)
            continue;
        if (B[i].l > T)
        {
            // cout<<A[i].l<<endl;
            ans++;
            T = B[i].r;
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
