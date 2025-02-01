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
    void solve()
    {
        int n=re();
        int k=re();
        std::vector<int>A;
        for(int i=0;i<n;++i)
        {
            A.push_back(re());
        }
        std::sort(A.begin(),A.end());
        int l=0;int r1=0;
        int r2=0;int ans=0;
        for(;l<n;++l)
        {
            while(r1<n&&A[r1]-A[l]<k)r1++;
            while(r2<n&&A[r2]-A[l]<=k)r2++;
           
            if(A[r1]-A[l]==k&&A[r2-1]-A[l]==k)
                ans+=r2-r1;
        }
        std::cout<<ans<<std::endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}