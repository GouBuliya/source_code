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
    int ksm(int x,int y,int mod)
    {
        int res=1;
        while(y)
        {
            if(y&1)
                res=(res*x)%mod;
            x=(x*x)%mod;
            y>>=1;
        }
        return res%mod;
    }
    
    signed main()
    {
        std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
        const int mod=6662333;
        std::cout<<ksm(2,re()-1,mod)%mod<<std::endl;
        return 0;
    }
}
signed main()
{
    return my::main();
}
