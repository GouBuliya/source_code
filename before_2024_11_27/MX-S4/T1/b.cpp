#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
#define in inline
#define ls ((q) << 1)
#define rs ((q) << 1 | 1)
const ll M = 1e18;
ll n, m, W, q;
const int maxn = 2e5 + 10;
ll B[maxn * 4], tagadd[maxn * 4], tagmul[maxn * 4];
ll A[maxn];
int re()
{
    int x=0,t=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*t;
}
void build(int q, int l, int r) // q is pos of sgt
{
    tagadd[q] = 0;
    tagmul[q] = 1;
    B[q] = 0;
    if (l == r)
    {
        B[q] = A[l];
        return;
    }
    int mid = (l + r) / 2;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    B[q] = (B[ls] + B[rs]); // push_up
}

void appty_mul(int q, int left, int right, int k)
{
    B[q] = (B[q] * k);
    tagmul[q] = (tagmul[q] * k) ;
    tagadd[q] = (tagadd[q] * k) ;
}

void appty_add(int q, int left, int right, int k)
{
    tagadd[q] = (tagadd[q] + k) ;
    B[q] = (B[q] + k * (right - left + 1)) ;
}

void push_down(int q, int l, int r)
{
    if (!tagadd[q] && tagmul[q] == 1)
        return;
    int mid = (l + r) >> 1;
    appty_mul(ls, l, mid, tagmul[q]);
    appty_mul(rs, mid + 1, r, tagmul[q]);
    appty_add(ls, l, mid, tagadd[q]);
    appty_add(rs, mid + 1, r, tagadd[q]);
    tagadd[q] = 0;
    tagmul[q] = 1;
}

void add(const int ul, const int ur, int l, int r, int q, const int k)
{
    if (ul <= l && r <= ur)
    {
        appty_add(q, l, r, k);
        return;
    }
    push_down(q, l, r);
    int mid = (l + r) >> 1;
    if (mid >= ul)
        add(ul, ur, l, mid, ls, k);
    if (mid < ur)
        add(ul, ur, mid + 1, r, rs, k);
    B[q] = (B[ls] + B[rs]); // push
}

ll ask(const int ul, const int ur, int l, int r, int q)
{
    if (ul <= l && r <= ur)
        return B[q];
    push_down(q, l, r);
    int mid = (l + r) >> 1;
    ll res = 0;
    if (mid >= ul)
        res = (res + ask(ul, ur, l, mid, ls)) ;
    if (mid < ur)
        res = (res + ask(ul, ur, mid + 1, r, rs)) ;
    return res;
}

int32_t main()
{
    ios::sync_with_stdio(0);cout.tie(0);
	// freopen("wxyt3.in","r",stdin);
	// freopen("wxyt.ans","w",stdin);
    // cin >> n >> q >> W;
    n=re(),q=re(),W=re();
    for (int i = 1; i <= n; ++i)
    {
        A[i]=re();
    }
    build(1, 1, n);
    ll w = W;
    while (q--)
    {
        int l, r, d;
        // cin >> l >> r >> d;
        l=re(),r=re(),d=re();
        add(l, r, 1, n, 1, d);
        int t = 0, p = 0, tag = 1;
        while (w)
        {
            ll Ask = ask(1, n, 1, n, 1) ;
            p++;
            if (w > Ask * tag)
            {
                w -= Ask * tag;
                t += n;
            }
            else
            {
                int nl = 1, nr = n;
                while (nl < nr)
                {
                    int mid = (nl + nr + 1) >> 1;
                    if (w > ask(1, mid, 1, n, 1) * tag)
                        nl = mid;
                    else
                        nr = mid - 1;
                }
                t += nl;
                w = 0;
            }
            tag *= 2;
        }
        cout << t << endl;
        w =W;
    }
    return 0;
}