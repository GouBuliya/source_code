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
const int maxn=1e5+10;
int S[maxn];
int trie[maxn*31][2];

signed main ()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::vector<std::vector<std::tuple<int,int>>>G(maxn);
    int n=re();
    for(int i=0;i<n;++i)
    {
        int u=re();
        int v=re();
        int w=re();
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    std::function<void(int,int)> dfs=[&](int u,int fa) -> void
    {
        for(auto &[v,w]:G[u])
            if(v!=fa)
            {
                S[v]=S[u]^w;
                dfs(v,u);
            }
    };
    int tot=0;
    dfs(1,-1);
    std::function<void(int)> insert=[&](int val) -> void
    {
        int u=0;
        for(int i=(1<<30);i;i>>=1)
        {
            int a=bool(val&i);
            if(!trie[u][a])
            {
                trie[u][a]=tot++;
            }
            u=trie[u][a];
        }
    };
    std::function<int(int)> find =[&](int val) -> int 
    {
        int ans=0;
        int u=0;
        for(int i=(30<<1);i;i>>=1)
        {
            int a=bool(val&i);
            if(trie[u][!a])
            {
                ans+=i;
                u=trie[u][!a];
            }
            else {
                u=trie[u][a];
            }
        }
        return ans;
    };
    for(int i=1;i<=n;++i)
    {
        insert(S[i]);
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        ans=std::max(ans,find(S[i]));
    }
    std::cout<<ans<<"\n";
    return 0;
}
}
signed main ()
{
    return my::main();
}

