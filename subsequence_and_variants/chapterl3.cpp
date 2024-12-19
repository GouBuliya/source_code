#include <bits/stdc++.h>
using namespace std;
namespace my {
#define ll long long
const int INF = (1 << 31);
ll re() {
  ll t;
  cin >> t;
  return t;
}
int n, m;
const int maxn = 1e5;
int f[maxn];
int g[maxn];
int A[maxn];
int sum[maxn];

signed main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    sum[i] = sum[i - 1] + A[i];
  }
  f[1] = A[1];
  for (int i = 2; i <= n; ++i)
    f[i] = max(f[i - 1] + A[i], 0);
  for (int i = m; i <= n; ++i)
    g[i] = max(f[i - 1], 0) + sum[i] - sum[i - m];
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, g[i]);
  }
  cout << ans << endl;
  return 0;
}
} // namespace my
signed main() { return my::main(); }
