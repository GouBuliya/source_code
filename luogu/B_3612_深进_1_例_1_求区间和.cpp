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
            A[i]=re();
        std::vector<int>pre(n);
        int m=re();
        std::partial_sum(A.begin(),A.end(),pre.begin());
        while(m--)
        {
            int l=re();
            int r=re();
            std::cout<<pre[r-1]-pre[l-2]<<std::endl;
        }
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}