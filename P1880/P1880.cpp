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
int A[202];
int dp_min[202][202];
int dp_max[202][202];
int sum[202];
signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
#endif
    int N = re();
    memset(dp_min, 0x3f, sizeof dp_min);
    // memset(dp_max, 0x3f, sizeof dp_max);
    for (int i = 1; i <= N; ++i)
    {
        A[i + N] = A[i] = re();
        sum[i] += A[i];
        sum[i + N] += A[i];
        // dp_max[i][i] = A[i];
        dp_min[i][i] = 0;
    }
    for (int len = 1; len < N; ++len)
    {
        // dp_min[i][i]=0;
        for (int i = 1; i <= 2 * N && i + len <= 2 * N; ++i)
        {
            int j = i + len;
            for (int k = i; k <= j; ++k)
            {
                dp_min[i][j] = min(dp_min[i][k], dp_min[k + 1][j] + sum[j] - sum[i]);
                dp_max[i][j] = max(dp_max[i][k], dp_max[k + 1][j] + sum[j] - sum[i]);
            }
        }
    }
    int ansmin = 923917391, ansmax = 0;
    // 然后开个O(2n)求最终答案（因为把环拉成链了）
    for (int i = 1; i < N; ++i)
        ansmin = min(ansmin, dp_min[i][i + N - 1]);
    for (int i = 1; i < N; ++i)
        ansmax = max(ansmax, dp_max[i][i + N - 1]);
    printf("%d\n", ansmin);
    printf("%d\n", ansmax);
    return 0;
}