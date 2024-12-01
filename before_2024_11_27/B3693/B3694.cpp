#include <bits/stdc++.h>
using namespace std;
#define int uint64_t
int a[1007][1007];
int sum[1007][1007];
signed main()
{
    int T, n, m;
    int ans = 0;

    scanf("%lld", &T);
    while (T--)
    {
        int q = 0;
        ans = 0;
        scanf("%lld %lld %lld", &n, &m, &q);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                int temp = 0;
                scanf("%lld", &temp);
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + temp;
            }
        for (int i = 1; i <= q; ++i)
        {
            int u, v, x, y;
            scanf("%lld %lld %lld %lld ", &u, &v, &x, &y);
            ans ^= sum[x][y] + sum[u - 1][v - 1] - sum[u - 1][y] - sum[x][v - 1];
        }
        cout << ans << endl;
    }
}