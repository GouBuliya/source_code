
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
void read (long long &x) { 
	long long f = 1; x = 0; char s = getchar (); while (s < '0' || s > '9') {if (s == '-') f = -1; s = getchar ();}
	while (s >= '0' && s <= '9') {x = x * 10 + s - '0'; s = getchar ();} 
	x *= f;
}//不加会死的很惨
struct st {
	long long l, r, id;
}k[1000005];
long long a[1000005], bit[1000005], n;
bool cmp (st x, st y) {
	return x.r < y.r;
}
long long lowbit (long long x) {
	return x & (-x);
}
void add (long long x, long long y) {
	for (long long i = x; i <= n; i += lowbit (i)) bit[i] += y;
}
long long sum (long long x) {
	long long cnt = 0;
	for (long long i = x; i >= 1; i -= lowbit (i)) cnt += bit[i];
	return cnt;
}
long long vis[1000005], ans[1000005];
int main () {
	read (n);
	for (long long i = 1; i <= n; i++) read (a[i]);
	long long m;
	read (m);
	for (long long i = 1; i <= m; i++) read (k[i].l), read (k[i].r), k[i].id = i;
	sort (k + 1, k + 1 + m, cmp);
	long long last = 1;
	for (long long i = 1; i <= m; i++) {
		for (long long j = last; j <= k[i].r; j++) {
			if (vis[a[j]]) add (vis[a[j]], -1);
			add (j, 1);
			vis[a[j]] = j;
		}
		last = k[i].r + 1;
		ans[k[i].id] = sum (k[i].r) - sum (k[i].l - 1);
	}
	for (long long i = 1; i <= m; i++) printf ("%lld\n", ans[i]);//按标号输出
	return 0;
}