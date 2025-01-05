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
struct node
    {
        ll w,h;
    };

  bool operator<(node A,node B)
         {
            if(A.w!=B.w)
            {
                return  A.w>B.w;
            }
            else {
                return A.h>B.h;
            }
        };

signed main ()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    ll n=re();
    ll k=re();
    std::priority_queue<node>que ;
    if((n-1)%(k-1)!=0)
    {
        for(int i=1;i<=k-1-(n-1)%(k-1);i++)
            que.push({0,1});
    }
    ll ans=0;
    for(int i=1;i<=n;++i)
        {
            que.push({re(),1});
        }
    while(que.size()!=1)
    {

        ll sum=0;
        ll maxh=0;
        for(int i=0;i<k;++i)
        {
            node temp=que.top();
            sum+=temp.w;
            maxh=std::max(maxh,temp.h);
            que.pop();
        }
        ans+=sum;
        que.push({sum,maxh+1});
    }
    std::cout<<ans<<std::endl<<que.top().h-1<<std::endl;
    return 0;
}
}
signed main ()
{
    return my::main();
}
