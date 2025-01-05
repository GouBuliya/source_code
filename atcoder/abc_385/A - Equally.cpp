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
    std::cout.tie(nullptr);
    std::function<void()>solve =[]()
    {
        std::vector<int>a(3);
        for(int i=0;i<3;++i)
        {
            std::cin>>a[i];
        }
            if(a[0]==a[1]&&a[1]==a[2])
            {
                std::cout<<"Yes"<<std::endl;
                return;
            }
            if(a[0]+a[1]==a[2]||a[1]+a[2]==a[0]||a[0]+a[2]==a[1])
            {
                std::cout<<"Yes"<<std::endl;
                return;
            }
        std::cout<<"No"<<std::endl;
    };
        solve();
    return 0;
}
};
signed main ()
{
    return my::main();
}
