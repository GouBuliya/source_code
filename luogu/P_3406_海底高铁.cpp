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
        int n = re();
        int m = re();
        std::vector<int>fc(n + 1);
        int l1 = re();
        int l2;
        for (int i = 1;i < m;++i)
        {
            l2 = re();
            if (l1 > l2) 
            {
                fc[l2]++;
                fc[l1 ]--;
            }
            else
             {
                fc[l1]++;
                fc[l2 ]--;
            }
         

            l1 = l2;
        }
        
        std::vector<int>pre(n + 1);
        std::partial_sum(fc.begin(), fc.end(), pre.begin());
        int ans=0;
        for(int i=1;i<n;++i)
        {
            int a=re(),b=re(),c=re();
            
            ans+=std::min(pre[i]*a,c+pre[i]*b);
        }
        std::cout<<ans<<std::endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}