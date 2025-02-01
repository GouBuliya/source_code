#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pn cout<<'\n';
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
#define int long long
namespace my {
    const int INF = (1 << 30);
    ll re()
    {
        ll t; std::cin >> t;return t;
    }
    void solve()
    {
        int n = re();
        int k = re();
        std::vector<int>A(n + 2);
        std::vector<int>dp(n + 2);
        int ans=0;
        for (int i = 1;i <= n;++i)
            std::cin >> A[i],ans+=A[i];
        std::deque<int>dq(1);
        
        for (int i = 1;i <= n+1;++i)
        {
            while (dq.size() && i-dq.front()>k+1)dq.pop_front();
            dp[i]=dp[dq.front()]+A[i];  

            while (dq.size() && dp[dq.back()] > dp[i])
                dq.pop_back();
            dq.push_back(i);
            
        } //单调上升
     
        std::cout<<ans-dp[n+1];

    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}
