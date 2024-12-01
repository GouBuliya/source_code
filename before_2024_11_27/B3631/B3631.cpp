#include <bits/stdc++.h>
using namespace std;
int re() {
  int x = 0, t = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-')
      t = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * t;
}
const int maxn = 1e6 + 7;
struct Node {
  int nxt = 0, x = 0,pre=0;
} a[maxn];
void ins(int x, int y) {
    a[y].pre=x;a[y].nxt=a[x].nxt;
    a[a[x].nxt].pre=y;a[x].nxt=y;
}
void del(int x) {a[a[a[x].nxt].nxt].pre=x;
a[x].nxt=a[a[x].nxt].nxt;}
signed main() {
  int t = re();
  ins(0,1);
  while (t--) {
    int op = re();
    if (op == 1) {
      int x = re(), y = re();
      ins(x, y);
    } else if (op == 2) {
      int x = re();
      cout << a[x].nxt << endl;
    } else if (op == 3) {
      int x = re();
      del(x);
    }
  }
}
