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
        std::vector<int>A(n+1);
        A[0]=0;A[1]=0;A[2]=1;
        for(int i=3;i<=n;++i)
        {
            A[i]=(i-1)*(A[i-1]+A[i-2]);
        }
        int res=1;
        for(int i=1;i<=n;++i)
        {
            res*=1;
        }
        std::cout<<A[n]<<std::endl;
        return 0;
    }
}
signed main()
{
    return my::main();
}