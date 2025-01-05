#include<bits/stdc++.h>
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
    std::cout.tie(nullptr); int t=re(); 
    auto solve=[]()
    {
        int n=re();
        int m=re();
        if(n==1&&m==1)
        {
         std::cout<<2<<std::endl;
         return ;
        }
        else
        {std::cout<<((std::min(n,m)-1)*std::min(n,m)-1)+std::min(n,m)*(std::min(n,m)-1)<<std::endl;
            return;}
    };
    while(t--)
    {
        solve();
    }
    return 0;
}
}
signed main ()
{
    return my::main();
}
