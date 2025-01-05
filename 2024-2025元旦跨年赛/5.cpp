#include <cstdio>
using namespace std;
#define ll long long
inline ll read() {
  ll x = 0, ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    ;
  for (; ch >= '0' && ch <= '9'; ch = getchar())
    x = (x << 1) + (x << 3) + (ch ^ 48);
  return x;
}

int main() {
  int T = read(); 
  while (T--) {
    ll n = read(), k = read();
    ll bit_count[64] = {0};
    for (ll i = 0; i < n; i++) {
      ll x = read();
      for (int bit = 0; bit < 64; bit++) {
        bit_count[bit] += (x >> bit) & 1; 
      }
    }
    ll result = 0;
    for (int bit = 0; bit < 64; bit++) {
      if (bit_count[bit] % (k + 1) == k) {
        result |=(1LL<< bit);
      }
    }

    printf("%lld\n", result); 
  }
  return 0;
}
