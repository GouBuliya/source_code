#include<bits/stdc++.h>
#include <features.h>
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
    int n=re();
    int m=re();
    std::vector<int>fa(n+1);
    for(int i=1;i<=n;++i)
    {
        fa[i]=i;
    }
    std::function<ll(ll)> find=[&](ll x){return fa[x]==x?x:fa[x]=find(fa[x]);};
    std::function<void(ll,ll)> unite=[&](ll x,ll y){x=find(x),y=find(y);fa[x]=y;};
    std::vector<std::tuple<ll,ll>>p(m+1);
    for(int i=1;i<=m;++i)
        p[i]={re(),re()};
    for(int i=1;i<=m;i++)
    {
        auto [s,t]=p[i];
        int fu=find(s);
        int fv=find(t);
        if(fu==fv)
        {
           std::cout<<"No"<<std::endl;
            return 0;
        }
        fa[fu]=fv;
    }
    std::cout<<"Yes"<<std::endl;
    for(int i=2;i<=m;++i)
    {
        auto [x,y]=p[i];
        std::cout<<x<<" "<<y<<std::endl;
    }
    int t=std::get<0>(p[1]);
    
    for(int i=2;i<=m-1;++i)
    {
        std::cout<<t<<" "<<std::get<0>(p[i])<<std::endl;
        t=std::get<0>(p[i]);
    }

    for(int i=1;i<=n;++i)
    {
        if(find(i)==i&&find(i)!=find(std::get<0>(p[1])))
        {
            std::cout<<t<<" "<<i<<std::endl;
            t=i;
        }
    }
    std::cout<<t<< " "<<std::get<1>(p[1]);
    return 0;
}
}
signed main ()
{
    return my::main();
}

