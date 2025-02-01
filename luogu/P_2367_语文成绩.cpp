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
        int p=re();
        std::vector<int>A(n+1);
        for(int i=1;i<=n;++i)
        {
            std::cin>>A[i];
        }
        std::vector<int>fc(n+1);
        std::adjacent_difference(A.begin()+1,A.end(),fc.begin()+1);
        for(int i=1;i<=p;++i)
        {
            int l=re();
            int r=re();
            int k=re();
            fc[l]+=k;
            fc[r+1]-=k;
            
        }
        int ans=1e9;
        std::partial_sum(fc.begin()+1,fc.end(),A.begin());
        A.resize(n);
        for(auto &i:A)
        {
            ans=std::min(i,ans);
        }
        std::cout<<ans<<std::endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}