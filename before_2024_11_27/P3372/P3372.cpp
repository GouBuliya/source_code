
#include <bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
#define in inline
int re()
{
    int x=0,t=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*t;
}
#define ls ((q) << 1)
#define rs ((q) << 1|1)
// #define mid (((l) + (r)) / 2)

ll n, m;
const int maxn = 1e5 + 10;
ll B[maxn * 4];
ll tag[maxn * 4];
ll A[maxn];

void build(int q, int l, int r) // q is pos of sgt
{
	tag[q] = 0;
	if (l == r)
	{
		B[q] = A[l];
		return;
	}
	    int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	B[q] = B[ls] + B[rs]; // push_up
}
void apply_tag(int q, int left, int right, int k) {
    tag[q] += k;
    B[q] += k * (right - left + 1);
}

void push_down(int q, int l, int r) {
    if (tag[q]) {
	    int mid = (l + r) >> 1;
        apply_tag(ls, l, mid, tag[q]);
        apply_tag(rs, mid + 1, r, tag[q]);
        tag[q] = 0;
    }
}
void add(const int ul, const int ur, int l, int r, int q, const int k)
{
	if (ul <= l && r <= ur)
	{
		apply_tag(q,l,r,k);
		return;
	}
	push_down(q,l,r);
	    int mid = (l + r) >> 1;
	if (mid >= ul)
		add(ul, ur, l, mid, ls, k);
	if (mid < ur)
		add(ul, ur, mid + 1, r, rs, k);
	B[q] = B[ls] + B[rs]; // push
}
ll ask(const int ul, const int ur, int l, int r, int q)
{
	ll res = 0;
	if (ul <= l && r <= ur)
		return B[q];
	push_down(q,l,r);

	    int mid = (l + r) >> 1;
	if (mid >= ul)
		res += ask(ul, ur, l, mid, ls);
	if (mid < ur)
		res += ask(ul, ur, mid + 1, r, rs);
	return res;
}
signed main()
{
	n = re(), m = re();
	for (int i = 1; i <= n; ++i)
		A[i] = re();

	build(1, 1, n);

	while (m--)
	{
		int op = re();
		if (op == 1)
		{
			int x = re(), y = re(), k = re();
			add(x, y, 1, n, 1, k);
		}
		if (op == 2)
		{
			int x = re(), y = re();
			printf("%lld", ask(x,y,1,n,1));
		}
	}
}
