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
        int n = re();
        std::vector<int>A(1);
        for (int i = 1;i <= n;++i)
        {
            A.push_back(re());
        }
        std::vector<int>sk1;
        std::vector<int>sk2;

        int res = -1e9;
        for (int i = 1;i <= n;++i)
        {
            while (sk1.size() && A[sk1.back()] < A[i])//下降
            {
                sk1.pop_back();
            }
            while (sk2.size() && A[sk2.back()] >=  A[i])
            {
                sk2.pop_back();
            }
            int val=sk1.size()?sk1.back():0; 
            int p=lower_bound(sk2.begin(),sk2.end(),val)-sk2.begin();   
            
            if(p!=sk2.size())
			res=std::max(res,i-sk2[p]+1);
            sk1.push_back(i);
            sk2.push_back(i);
           
            
        }
        std::cout<<res<<std::endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}