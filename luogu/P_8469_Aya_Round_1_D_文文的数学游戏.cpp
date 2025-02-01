#include<bits/stdc++.h>
#define ll long long
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
    signed main()
    {
        std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
        int n=re();
        std::vector<int>A(n);
        int gcd=1e9;
        for(int i=0;i<n;++i)
        {
            A[i]=re();
            gcd=std::min(A[i],gcd);
        }
        int ans=1;
        const int mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            ans=ans*(A[i]/gcd)%mod;
        }
        std::cout<<gcd<< " "<<ans<<std::endl;
        return 0;
    }
}
signed main()
{
    return my::main();
}