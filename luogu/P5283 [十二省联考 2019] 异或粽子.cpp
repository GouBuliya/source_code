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
    ll w;
    int x,y;
    bool operator<(const node &A)const {
        return w<A.w;
    }
};
signed main ()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    ll n=re();
    ll k=re();
    std::vector<ll>s(1);
    for(ll i=1;i<=n;++i)
        s.push_back(s[i-1]^re());
    std::vector<std::vector<int>>trie((n+1)*32,std::vector<int>(2));
    std::vector<int>size((n+1)*32);
    int tot=0;
    auto insert=[&](ll val){
        int u=0;
        for(ll i=31;i>=0;i--)
        {
            ll a=(val>>i)&1;
            if(!trie[u][a])
            {
                trie[u][a]=++tot;
            }
            u=trie[u][a];
            size[u]++;
        }
    };  
    for(int i=0;i<=n;++i)
        insert(s[i]);
    
    std::priority_queue<node>que;
    auto solve=[&](ll val,int t)
    {
        int u=0;
        ll ans=0;
        for(ll i=31;i>=0;i--)
        {
            ll a=(val>>i)&1;
            if(size[trie[u][a^1]]>=t)
            {
                u=trie[u][a^1];
                ans|=(1ll<<i);
            }
            else
            {
                t-=size[trie[u][a^1]];
                u=trie[u][a];
            }
        }
        return ans;
    };
    std::vector<node>d(n+1);
    node A;
    for(int i=0;i<=n;++i)
    {
        d[i].w=solve(s[i],1);
        d[i].x=i;
        d[i].y=1;
        que.push(d[i]);
    }
    ll ans=0;
    for(int i=1;i<=2*k;++i)
    {
        A=que.top();
        ans+=A.w;
        que.pop();
        d[A.x].y++;
        d[A.x].w=solve(s[A.x],d[A.x].y);
        que.push(d[A.x]);
    }
    ans/=2;
    std::cout<<ans<<std::endl;
    
    
    return 0;
}
}
signed main ()
{
    return my::main();
}
