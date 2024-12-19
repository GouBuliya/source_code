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
const int maxn = 1e5;
int n, m;
int sum[maxn];
int f[maxn];
int mmin[maxn];
int A[maxn];
class ddqe {
private:
  deque<int> dq;

public:
  void push(int idx) {
    while (!dq.empty() && mmin[dq.back()] <= mmin[idx])
      dq.pop_back();
    dq.push_back(idx);
  }
  int get_val() { return mmin[dq.front()]; }
  void update(int idx) {
    if (dq.front() > idx)
      dq.pop_front();
  }

} dq;
signed main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
    sum[i] = sum[i - 1] + A[i];
  }
  for (int i = 1; i <= m; ++i)
    dq.push(i);
  for (int i = m + 1; i <= n; ++i) {
    dq.update(i - m);
    f[i] = sum[n] - dq.get_val();
  }
  int ans = 0;
  for (int i = m; i <= n; ++i)
    ans = max(ans, f[i]);
  cout << ans << endl;
  return 0;
}
} // namespace my
signed main() { return my::main(); }
