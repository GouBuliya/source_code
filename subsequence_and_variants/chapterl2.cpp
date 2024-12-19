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
int n, k;
const int maxn = 1e5 + 10;
int f[maxn];
int A[maxn];
int sum[maxn];
class ddque {
protected:
  deque<int> dq;

public:
  void push(int idx) {
    while (!dq.empty() && sum[dq.back()] > sum[idx])
      dq.pop_back();
    dq.push_back(idx);
  }
  void update(int idx) {
    if (!dq.empty() && dq.front() < idx)
      dq.pop_front();
  }
  int get_val() { return sum[dq.front()]; }

} dq;
signed main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  n = re(), k = re();
  for (int i = 0; i < n; ++i) {
    A[i] = re();
    sum[i] = sum[i - 1] + A[i];
  }
  for (int i = 0; i < k; ++i)
    dq.push(i);
  for (int i = k; i < n; ++i) {
    dq.update(i - k + 1);
    dq.push(i);
    f[i] = sum[i] - dq.get_val();
  }
  int ans = 0;
  for (int i = 0; i < n; ++i)
    ans = max(ans, f[i]);
  cout << ans << endl;
  return 0;
}
} // namespace my
signed main() { return my::main(); }
