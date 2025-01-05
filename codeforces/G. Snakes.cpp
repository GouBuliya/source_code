#include<bits/stdc++.h>
#include <cctype>
namespace my{
#define ll long long 
#define pn cout<<"\n";
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
const int INF=(1<<30);
ll re ()
{
    ll t;
    std::cin>>t;
    return t;
}
void solve()
{
    int n=re();
    std::vector<int>a(n),b(n);
    for(int i=0;i<n;++i)
        a[i]=re();
    for(int i=0;i<n;++i)
        b[i]=re();  
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2, 0));
        dp[0][0] = 0; // 第一天 Monocarp 不训练，差距为 0
        dp[0][1] = a[0]; // 第一天 Monocarp 训练，差距为 a[0]

        for (int i = 1; i < n; ++i) {
            dp[i][0] = std::max(dp[i-1][0] - b[i], dp[i-1][1] - b[i]);
            dp[i][1] = std::max(dp[i-1][0] + a[i], dp[i-1][1] + a[i]);
        }
        std::cout << std::max(dp[n-1][0], dp[n-1][1]) << std::endl;
}
signed main ()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t=re();
    while(t--)
    {
        solve();
    }
    return 0;
}
}
signed main ()
{
    return my::main();
}
