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
const int maxn = 1e6 + 7;
struct Node
{
    int l, r, id;
} soider[2 * maxn];
int f[2 * maxn][20];
int res[2*maxn];
int n = re(), m = re();
bool cmp(Node a, Node b) { return a.l < b.l; }
void search(int k)
{
	int lmt = soider[k].l + m, ans = 1, p = k;
	for(int i = 19; i >= 0; i--) {
		if(f[k][i] != 0 && soider[f[k][i]].r < lmt) {
			ans += (1 << i);
			k = f[k][i];
		}
	}
	res[soider[p].id] = ans + 1;
}
signed main()
{
    
    for (int i = 1; i <= n; ++i)
    {
        soider[i].l = re(), soider[i].r = re();
        if (soider[i].l > soider[i].r)
            soider[i].r += m;
        soider[i].id = i;
    }
    sort(soider + 1, soider + 1 + n, cmp);
    for (int i = 1; i <= n; ++i)
    {
        soider[i + n] = soider[i];
        soider[i + n].l = soider[i].l + m;
        soider[i + n].r = soider[i].r + m;
    }
    for (int i = 1, p = i; i <= 2 * n; ++i)
    {
        while (p <= 2 * n && soider[p].l <= soider[i].r)
            ++p;
        int pos = p - 1;
        f[i][0] = pos;
    }
    for (int j = 1; j < 20; ++j)
        for (int i = 1; i <= 2 * n; ++i)
            f[i][j] = f[f[i][j - 1]][j - 1];
    for (int pos = 1; pos <= n; ++pos)
    {
        search(pos);
    }
    for(int i=1;i<=n;++i)
    {
        printf("%d ",res[i]);
    }
    return 0;
}
// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <cmath>
// #include <cstdlib>
// #include <algorithm>
// using namespace std;
// int n, m, res[200005];
// struct soldier {
// 	int id, l, r;
// } s[400005];
// int cmp(soldier a, soldier b)
// {
// 	return a.l < b.l; 
// }

// int go[400005][20];

// void pre()
// {
// 	for(int i = 1, p = i; i <= 2 * n; i++) {
// 		while(p <= 2 * n && s[p].l <= s[i].r)
// 			p++;
// 		int pos = p - 1;
// 		go[i][0] = pos;
// 	}
// 	for(int i = 1; i < 20; i++) {
// 		for(int j = 1; j <= 2 * n; j++) {
// 			go[j][i] = go[go[j][i - 1]][i - 1];
// 		}
// 	}
// }
// void search(int k)
// {
// 	int lmt = s[k].l + m, ans = 1, p = k;
// 	for(int i = 19; i >= 0; i--) {
// 		if(go[k][i] != 0 && s[go[k][i]].r < lmt) {
// 			ans += (1 << i);
// 			k = go[k][i];
// 		}
// 	}
// 	res[s[p].id] = ans + 1;
// }
// int main()
// {
// 	cin >> n >> m;
// 	for(int i = 1; i <= n; i++) {
// 		cin >> s[i].l >> s[i].r;
// 		if(s[i].r < s[i].l)
// 			s[i].r += m;
// 		s[i].id = i;
// 	}
// 	sort(s + 1, s + 1 + n, cmp);
// 	for(int i = 1; i <= n; i++) {
// 		s[i + n] = s[i];
// 		s[i + n].l = s[i].l + m;
// 		s[i + n].r = s[i].r + m;
// 	}
// 	pre();
// 	for(int i = 1; i <= n; i++)
// 		search(i);
// 	for(int i = 1; i <= n; i++)
// 		cout << res[i] << " ";
// 	return 0;
// }