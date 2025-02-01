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
        std::vector<std::pair<int,int>>A;
        std::vector<int>dis;
        while(n--)
        {
            std::pair<int,int>p={re(),re()};
            A.push_back(p);
            dis.push_back(p.first);
            dis.push_back(p.second);
        }
        std::sort(dis.begin(),dis.end());
        auto p=std::unique(dis.begin(),dis.end())-dis.begin();
        dis.resize(p); 

        std::vector<bool>vis(p+10, false); 

        for(int i=0;i<A.size();++i)
        {
            A[i].first=std::lower_bound(dis.begin(),dis.end(),A[i].first)-dis.begin()+1;
            A[i].second=std::lower_bound(dis.begin(),dis.end(),A[i].second)-dis.begin()+1;
            for(int j=A[i].first;j<A[i].second;++j)
                vis[j]=true;
        }

        int ans=0;
        for(int i=1;i<=p;++i)
        {
            if(vis[i])
            {
                ans+=dis[i]-dis[i-1]; 
            }
        }
        std::cout<<ans<<std::endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}