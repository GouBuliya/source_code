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
    int ksm(int x,int y,const int mod)
    {
        int ret=1;
        while(y)
        {
            if(y&1)ret=ret*x%mod;
            x=x*x%mod,y>>=1;
        }
        return ret;
    }
    void solve()
    {
        int n=re(),m=re(),mod=re();
        std::cout<<n<<"^"<<m<<" mod "<<mod<<"="<<ksm(n,m,mod)%mod<<std::endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}