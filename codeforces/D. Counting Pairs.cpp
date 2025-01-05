#include<bits/stdc++.h>
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
signed main ()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::function<void()>solve=[]()
    {
        ll n=re();int x=re(),y=re();
        ll sum=0;
        std::vector<int>a;
        for(ll i=0;i<n;++i)
        {
            a.push_back(re());
            sum+=a[i];
        }
        std::sort(a.begin(),a.end());
        ll ans=0;
        for(auto &i:a)
        {
            sum-=i;
            auto lb = std::lower_bound(a.begin(),a.end(),sum-y);
            auto ub = std::upper_bound(a.begin(),a.end(),sum-x);
            ans+=std::abs(lb-ub);
            sum+=i;
        }
        std::cout<<ans<<"\n";
    };
    int t=re();
    while(t--) 
        solve();
    return 0;
}
}
signed main ()
{
    return my::main();
}
