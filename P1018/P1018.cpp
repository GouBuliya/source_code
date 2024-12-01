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
void pt(__uint128_t n)
{
    string str;
    while (n)
    {
        int tmp=n%10;
        n/=10;
        str.push_back(tmp^48);
    }
    reverse(str.begin(),str.end());
    cout<<str;
    
}
__uint128_t num[100][100];
__uint128_t dp[100][100];
__uint128_t ANS;
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int N, K;
    cin >> N >> K;
    getchar();
    for (int i = 1; i <= N; ++i)
    {
        char ch = getchar();
        // cout<<ch<<endl;
        num[i][i] = ch ^ 48;
    }
    for (int i = 1; i <= N; ++i)
    {
        for (int j = i + 1; j <= N; ++j)
        {
            num[i][j] = num[i][j - 1] * 10 + num[j][j];
        }
    }
    for(int i=1;i<=N;++i)
    {
        dp[i][0]=num[1][i];
    }
    for (int i = 2; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            for(int k=j;k<=i;++k)
            {
                dp[i][j]=max(dp[i][j],dp[k-1][j-1]*num[k][i]);
                
                
            }
        }
    }ANS=dp[N][K];
    pt(ANS);
    // cout<<1;
    return 0;
}