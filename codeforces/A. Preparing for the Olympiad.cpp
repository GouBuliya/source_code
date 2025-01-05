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
        int n=re();
        vector<int>m(n),s(n);
        for(int i=0;i<n;++i)
            std::cin>>m[i];
        int t=re();
        for(int i=0;i<n-1;++i)
        {
            std::cin>>s[i];
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            if(m[i]>=s[i])
            {
                ans+=m[i]-s[i];
            }
            else {
                continue;
            }
        }
        cout<<ans<<endl;
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
