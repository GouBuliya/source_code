#include <iostream>
#include <cstdio>
using namespace std;
#define int long long
const int maxn = 1e5 + 7;
int ans[4 * maxn];
struct Node
{
	int k;
	int d;
	 void add(Node t)
    {
        k+=t.k,d+=t.d;
    }
} tag[4 * maxn];

int arr[maxn];
int n, m;

inline int re()
{
	int x = 0, t = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0')
	{
		if (ch == '-')
		{
			t = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * t;
}
inline int ls(int p)
{
	return (p << 1);
}
inline int rs(int p)
{
	return (p << 1) | 1;
}
inline void push_up(int p)
{
	ans[p] = ans[ls(p)] + ans[rs(p)];
}
void build(int l, int r, int p)
{
	if (l == r)
	{
		ans[p] = arr[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls(p));
	build(mid + 1, r, rs(p));
	push_up(p);
	return;
}
void init()
{
	n = re(), m = re();
	for (int i = 1; i <= n; ++i)
		arr[i] = re();
	return;
}

void push_down(int l, int r, int p)
{
	int mid = (l + r) >> 1;
	tag[ls(p)].k += tag[p].k;
	tag[ls(p)].d += tag[p].d;
	tag[p].k += (mid + 1 - l) * tag[p].d;
	tag[rs(p)].d += tag[p].d;
	tag[rs(p)].k += tag[p].k;
	tag[p].d = 0;
	tag[p].k = 0;
	// int mid=l+r>>1;
    // tag[p<<1].add(tag[p]);
    // tag[p].k+=(mid-l+1)*tag[p].d;
    // tag[p<<1|1].add(tag[p]);
    // tag[p]={0,0};
}
void update(int nl, int nr, int l, int r, int p, Node t)
{
	if (nl <= l && nr >= l)
	{
		// // tag_attly(l,r,p,t);
		// tag[p].k += (l - nl) * t.d;
		// tag[p].d += t.d;
		// tag[p].k += t.k;
		t.k+=(l-nl)*t.d;
		tag[p].add(t);
		return;
	}
	push_down(l, r, p);
	int mid = (l + r) >> 1;
	if (nl <= mid)
		update(nl, nr, l, mid, ls(p), t);
	if (nr > mid)
		update(nl, nr, mid + 1, r, rs(p), t);
	// push_up(p);
}
int query(int x,int l, int r, int p)
{
	if (l == r)
	{
		return tag[p].k;
	}
	push_down(l, r, p);
	int mid = (l + r) >> 1;
	// int res = 0;
	// if(nl<=mid)res+=query(nl,nr,l,mid,ls(p));
	// if(nl>mid)res+=query(nl,nr,mid+1,r,rs(p));
	// return res;
	return x <= mid ? query(x,l,mid,ls(p)) : query(x,mid+1,r,rs(p));
}
void solve()
{
	int op = re();
	if (op == 1)
	{
		int l = re(), r = re(), K = re(), D = re();
		Node t;
		t.d = D;
		t.k = K;
		update(l, r, 1, n, 1, t);
	}
	else
	{
		int p = re();
		printf("%lld\n", query(p, 1, n, 1));
	}
}
signed main()
{
	init();
	build(1, n, 1);
	while (m--)
		solve();
}
