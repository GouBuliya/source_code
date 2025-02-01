#include<bits/stdc++.h>
#define ll long long
#define pn cout<<'\n';
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
namespace my {
    const int INF = (1 << 30);
    ll re()
    {
        ll t; std::cin >> t;return t;
    }
    void solve()
    {
        int n=re();
        std::vector<int>A(n);
        for(int i=0;i<n;++i)
        {
            std::cin>>A[i];
        }
        std::vector<int>B(A);
        std::sort(A.begin(),A.end());
        auto p=std::unique(A.begin(),A.end());
        for(int i=0;i<n;++i)
        {
            std::cout<<std::lower_bound(A.begin(),p,B[i])-A.begin()+1<<" ";
        }
        std::pn;
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = my::re();while (t--)my::solve();return 0;
}