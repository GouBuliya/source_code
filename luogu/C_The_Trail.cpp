#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 2005;

struct Number {
    ll k, b;
    Number(ll k_ = 0, ll b_ = 0) : k(k_), b(b_) {}
    ll calc(ll x) const { return k * x + b; }
};

Number operator - (Number a, const Number& b) {
    return {a.k - b.k, a.b - b.b};
}

Number& operator += (Number& a, const Number& b) {
    a.k += b.k;
    a.b += b.b;
    return a;
}

void add(int x, int y, Number w) {
    sum1[x] += w;
    sum2[y] += w;
    a[x][y] += w;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        scanf("%s", s + 1);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%lld", &a[i][j].b);
                a[i][j].k = 0;
                sum1[i] += a[i][j];
                sum2[j] += a[i][j];
            }
        }

        add(1, 1, Number(1, 0));

        Number sum = (s[1] == 'D') ? sum1[1] : sum2[1];
        int x = 1, y = 1;
        for (int i = 1; i < n + m - 2; i++) {
            int p = x, q = y;
            if (s[i] == 'D') p++;
            else q++;

            add(p, q, (s[i + 1] == 'D') ? sum - sum1[p] : sum - sum2[q]);
            x = p;
            y = q;
        }

        add(n, m, sum - sum1[n]);
        Number eee = sum2[m] - sum1[n];
        ll x_val = (eee.k == 0) ? 0 : -eee.b / eee.k;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                printf("%lld ", a[i][j].calc(x_val));
            }
            printf("\n");
        }

        fill(sum1 + 1, sum1 + n + 1, Number());
        fill(sum2 + 1, sum2 + m + 1, Number());
    }

    return 0;
}
