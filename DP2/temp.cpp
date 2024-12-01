#include<bits/stdc++.h>
using namespace std;
const int N = 200010; int dp[N + N], a[N + N], n, l, r;
int main() {
	scanf("%d%d%d", &n, &l, &r); for(int i = 0; i <= n; i++) scanf("%d", &a[i]);
	memset(dp, -0x3f, sizeof dp); dp[0] = 0;
	for(int i = 0; i <= n; i++) {
		for(int j = i + l; j <= i + r; j++) {
			dp[j] = max(dp[j], dp[i] + a[j]);
		}
	}
	int mx = -1e9; for(int i = n + 1; i <= n + r; i++) mx = max(mx, dp[i]); cout << mx;
	return 0;
}