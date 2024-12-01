#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
#define in inline
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
#define ls ((q) << 1)
#define rs ((q) << 1 | 1)
// #define mid (((l) + (r)) / 2)
int M ;
ll n, m;
const int maxn = 1e5 + 10;
ll B[maxn * 4];
ll tagadd[maxn * 4];
ll tagmul[maxn * 4];
ll A[maxn];

void build(int q, int l, int r) // q is pos of sgt
{
	tagadd[q] =B[q]=0;
	tagmul[q] = 1;
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
void appty_mul(int q, int left, int right, int k)
{
	B[q] = (B[q] * k) % M;
	tagmul[q] = (tagmul[q] * k) % M;
	tagadd[q] = (tagadd[q] * k) % M;
}
void appty_add(int q, int left, int right, int k)
{
	tagadd[q] = (tagadd[q] + k) % M;
	B[q] = (B[q] + k * (right - left + 1)) % M;
}

void push_down(int q, int l, int r)
{
	if (!tagadd[q] && tagmul[q] == 1)
		return;
	int mid = (l + r) >> 1;
	appty_mul(ls, l, mid, tagmul[q]), appty_mul(rs, mid + 1, r, tagmul[q]);
	appty_add(ls, l, mid, tagadd[q]), appty_add(rs, mid + 1, r, tagadd[q]);
	tagadd[q] = 0, tagmul[q] = 1;
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

	// B[q] = (B[ls] * B[rs]) % q; // push
	B[q] = (B[ls] + B[rs]) % M; // push
}
void mul(const int ul, const int ur, int l, int r, int q, const int k)
{
	if (ul <= l && r <= ur)
	{
		appty_mul(q, l, r, k);
		return;
	}
	push_down(q, l, r);
	int mid = (l + r) >> 1;
	if (mid >= ul)
		mul(ul, ur, l, mid, ls, k);
	if (mid < ur)
		mul(ul, ur, mid + 1, r, rs, k);
	// B[q] = (B[ls] * B[rs]) % q; // push
	B[q] = (B[ls] + B[rs]) % M; // push
}
ll ask(const int ul, const int ur, int l, int r, int q)
{
	ll res = 0;
	if (ul <= l && r <= ur)
		return B[q];
	push_down(q, l, r);

	int mid = (l + r) >> 1;
	if (mid >= ul)
		res = (res + ask(ul, ur, l, mid, ls)) % M;
	if (mid < ur)
		res = (res + ask(ul, ur, mid + 1, r, rs)) % M;
	return res;
}

signed main()
{
	n = re(), m = re(), M = re();
	for (int i = 1; i <= n; ++i)
		A[i] = re();

	build(1, 1, n);

	while (m--)
	{
		int op = re();
		if (op == 1)
		{
			int x = re(), y = re(), k = re();
			mul(x, y, 1, n, 1, k);
		}
		if (op == 2)
		{
			int x = re(), y = re(), k = re();
			add(x, y, 1, n, 1, k);
		}
		if (op == 3)
		{
			int x = re(), y = re();
			printf("%lld\n", ask(x, y, 1, n, 1));
		}
	}
}