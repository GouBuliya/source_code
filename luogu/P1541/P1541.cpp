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
    int dp[41][41][41][41];
    int g[5];
    int num[400];
    int card[130];
    int N, M;
    inline void init()
    {
        N = re();
        M = re();
        for (int i = 1; i <= N; ++i)
        {
            num[i] = re();
        }
        for (int i = 1; i <= M; ++i)
        {
            card[i] = re();
            g[card[i]]++;
        }
        dp[0][0][0][0] = num[1];
        return;
    }
    inline void DP()
    {
        for (int a = 0; a <= g[1]; ++a)
        {
            for (int b = 0; b <= g[2]; ++b)
            {
                for (int c = 0; c <= g[3]; ++c)
                {
                    for (int d = 0; d <= g[4]; ++d)
                    {
                        int r = 1 + a * 1 + b * 2 + c * 3 + d * 4;
                        if (a != 0)
                            dp[a][b][c][d] = max(dp[a][b][c][d], dp[a - 1][b][c][d] + num[r]);
                        if (b != 0)
                            dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b - 1][c][d] + num[r]);
                        if (c != 0)
                            dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c - 1][d] + num[r]);
                        if (d != 0)
                            dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c][d - 1] + num[r]);
                    }
                }
            }
        }
        cout<<dp[g[1]][g[2]][g[3]][g[4]];
    }
    signed main()
    {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
        init();
        DP();
        return 0;
    }
