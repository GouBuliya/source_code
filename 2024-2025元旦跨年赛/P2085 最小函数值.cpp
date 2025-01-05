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
#define int long long
signed main ()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n=re();
    int m=re();
    std::vector<std::tuple<int,int,int>>A(n);
    for(int i=0;i<n;++i)
    {
        A[i]={re(),re(),re()};
    }
    int t=0;
    int x=1;
    std::priority_queue<int,std::vector<int>,std::greater<int>>q;
    while(t<m)
    {
        for(int i=0;i<n;++i)
        {
            auto [a,b,c]=A[i];
            q.push({a*x*x+b*x+c});
            t++;
        }
        x++;
    }
    t=0;
    while(t<m)
    {
        std::cout<<q.top()<<" ";
        q.pop();
        t++;
    }
    return 0;
}
}
signed main ()
{
    return my::main();
}
