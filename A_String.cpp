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
        std::string A;
        std::cin>>A;
        int ans=0;
        for(auto &i:A)
        {
            ans+=i=='1';
        }
        std::cout<<ans<<endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = my::re();while (t--)my::solve();return 0;
}