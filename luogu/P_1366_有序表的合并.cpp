#include<bits/stdc++.h>
#define ll int
#define pn cout<<'\n';
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
#define unsigned long long
namespace my {
    const int INF = (1 << 30);
    ll re()
    {
        ll t; std::cin >> t;return t;
    }
    void solve()
    {
        int n=re();
        int m=re();
        std::vector<int>A(n);
        std::vector<int>B(m);
        for(int i=0;i<n;++i)
            std::cin>>A[i];
        for(int i=0;i<m;++i)
            std::cin>>B[i];
            int j=0;
            int Ans=0;
        for(int i=0;i<n;++i)
        {
            int ans=0;
            while(A[i]==B[j])
            {
                j++;
                ans++;
                
            }
            // std::cout<<ans<<std::endl;
            if(ans)
                Ans^=ans;
        }
        std::cout<<Ans<<std::endl;
        return ;
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    int t = my::re();while (t--)my::solve();return 0;
}