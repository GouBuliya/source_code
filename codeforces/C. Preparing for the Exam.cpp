#include<bits/stdc++.h>
using namespace std;
namespace my{
#define ll long long 
#define pn cout<<"\n";
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
const int INF=(1<<30);
ll re ()
{
    ll t;
    std::cin>>t;
    return t;
}
signed main ()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::function<void()>solve=[]()
    {
        int n=re(),m=re(),k=re();

        std::vector<int>M(m);
        std::vector<int>K(n);
        std::vector<bool>vis(n+1);
        for(int i=0;i<m;++i)
        {
            std::cin>>M[i];
        }
        for(int i=0;i<k;++i)
        {
            std::cin>>K[i];
            vis[K[i]]=1;
        }        
        if(k<n-1)
        {
            for(int i=0;i<m;++i)
                std::cout<<0;
            std::cout<<std::endl;
            return;
        } 
        if(k==n)
        {
            for(int i=0;i<m;++i)
            {
                std::cout<<1;
            }
            std::cout<<std::endl;
            return;
        }
        int p=-1;
        for(int i=1;i<=n;++i)
        {
            if(vis[i]==0)
            {
                p=i;
                break;
            }
        }

        for(int i=0;i<m;++i)
        {
            if(M[i]==p)
            {
                std::cout<<1;
                continue;
            }
            std::cout<<0;
        }
        std::cout<<std::endl;
        return;
    };
    int t=re();
    while(t--)
        solve();
    return 0;
}
}
signed main ()
{
    return my::main();
}
