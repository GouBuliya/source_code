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
const int maxn = 1e5 + 10;
int A[maxn];
int f[maxn];
int g[maxn];
int mmin[maxn];
int n, m;
class ddq {
private:
  deque<int> dq;

public:
  void push(int idx) {
    while (!dq.empty() && mmin[dq.back()] > mmin[idx])
      dq.pop_back();
    dq.push_back(idx);
  }
  int get_val() { return mmin[dq.front()]; }
  void update(int idx) {
    if (!dq.empty() && dq.front() < idx)
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
  int n = re();
  for (int i = 1; i <= n; ++i)
    cin >> A[i];
  for (int i = 1; i <= n; ++i)
    A[i + n] = A[i];
  for (int i = 1; i <= 2 * n; ++i)
    mmin[i] = mmin[i - 1] + A[i];
  for (int i = 1; i <= n; ++i)
    dq.push(i);
  for (int i = n + 1; i <= 2 * n; ++i) {
    dq.update(i - n + 1);
    dq.push(i);
    f[i] = mmin[n] - dq.get_val();
  }
  int ans = 0;
  for (int i = n + 1; i < 2 * n; ++i)
    ans = max(ans, f[i]);
  cout << max(ans, mmin[n]) << endl;
  return 0;
}
} // namespace my
signed main() { return my::main(); }
