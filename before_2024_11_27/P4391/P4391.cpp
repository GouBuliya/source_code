#include <bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
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
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 7;
const int base = 13331;
// char str[maxn];
pair<int, int> hashs[maxn];
int P1[maxn];
int P2[maxn];

pair<int, int> get_hash(int l, int r)
{
    int p1 = (hashs[r].first - 1ll * hashs[l - 1].first * P1[r - l + 1] % mod1 + mod1) % mod1;
    int p2 = (hashs[r].second - 1ll * hashs[l - 1].second * P2[r - l + 1] % mod2 + mod2) % mod2;
    return pair<int, int>{p1, p2};
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int len;
    cin >> len;
    P1[0] = P2[0] = 1;
    char c;
    for (int i = 1; i <= len; ++i)
    {
        cin >> c;
        hashs[i].first = (1ll * hashs[i - 1].first * base + c) % mod1;
        hashs[i].second = (1ll * hashs[i - 1].second * base + c) % mod2;
        P1[i] = (1ll * P1[i - 1] * base) % mod1;
        P2[i] = (1ll * P2[i - 1] * base) % mod2;
    }
    for (int i = 1; i <= len; ++i)
    {
        auto prefix = get_hash(1, len - i);
        auto suffix = get_hash(i + 1, len);
        if (suffix == prefix)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
