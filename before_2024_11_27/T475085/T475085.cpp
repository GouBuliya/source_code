/*************************************************************************
	> File Name: T475085.cpp
	> Author: ma6174
	> Mail: ma6174@163.com
	> Created Time: Fri Jul 12 13:15:36 2024
 ************************************************************************/
#include <bits/stdc++.h>
#define ll long long
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
int n, m, k;
const int maxn = 1e5;
struct Node
{
	int mod, ans;
} arr[100 * maxn];
bool cmp(Node a, Node b)
{
	if (a.ans == b.ans)
		return a.mod < b.mod;
	return a.ans < b.ans;
}
int a[5 * maxn];
int b[5 * maxn];
signed main()
{
	n = re(), m = re(), k = re();
	for (int i = 1; i <= n; ++i)
		a[i] = re();
	for (int i = 1; i <= m; ++i)
		b[i] = re();
	ll pos = 1;
	if (k == 1)
	{
		ll Min = 1e9;
		ll Mmod =1e9;
		ll Mans = 1e9;
		int ans,mod;
		for (int i = 1; i <= n-1000; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				ans= a[i] / b[j];
				mod = a[i] % b[j];
				if(ans==Mans)
				{
					Mmod=min(Mmod,mod);
				}
				else
				{
					Mans=min(ans,Mans);
					Mmod=mod;
				}
			}
		}
		printf("%lld %lld",Mans,Mmod);
		return 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			arr[pos].ans = a[i] / b[j];
			arr[pos++].mod = a[i] % b[j];
		}
	}
	sort(arr + 1, arr + pos, cmp);
	// for(int i=1;i<=pos;++i)
	// {
	// 	printf("%lld %lld\n",arr[i].ans,arr[i].mod);
	// }
	printf("%lld %lld", arr[k].ans, arr[k].mod);
	return 0;
}
