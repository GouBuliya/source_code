#include<bits/stdc++.h>
#include <sched.h>
namespace my{
#define ll long long 
#define pn cout<<"\n";
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
const int INF=(1<<30);
signed main ()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    auto re=[]()
    {
        ll t;
        std::cin>>t;
        return t;
    };
    int n=re();
    int m=re();
    std::vector<int>A;
    for(int i=0;i<n;++i)
    {
        A.push_back(re());
    }
    std::vector<std::vector<int>>trie(31*(n+1),std::vector<int>(2));
    int tot=0;
    int h=0;
    std::vector<std::vector<int>>p(31*(n+1),std::vector<int>(2));//记录这个点是什么时候进入的trie
    std::vector<int>s;
    struct node
    {
        int l;
        int r;
        int id;
        int val;
    };
    std::vector<node>Q;
    int t=0;
    for(int i=0;i<m;++i)
    {
        std::string str;
        std::cin>>str;
        if(str=="A")
        {
            int x=re();
            A.push_back(x);
        }
        else {
            int l=re();
            int r=re();
            int id=re();
            Q.push_back({l,r,id,0});
            t++;
        }

    }
    m=Q.size();
    s.resize(A.size()+1);
    for(int i=A.size()-1;i>=0;i--)
    {
        s[i]=s[i+1]^A[i];
    }
    for(int i=0;i<m;++i)
    {
        Q[i].val=s[Q[i].id]^Q[i].id;
        Q[i].id=i;
    }
    std::sort(Q.begin(),Q.end(), [](node a,node b){return a.r<b.r;});
    for(auto [l,r,id,val]:Q)
    {
        std::cerr<<l<<" "<<r<<" "<<id<<" "<<val<<std::endl;

    }
    auto insert=[&](int val,int t)
    {
        int u=0;
        for(int i=(30<<1);i;i>>=1)
        {
            int a=bool(val&i);
            if(!trie[u][a])
            {
                trie[u][a]=++tot;
                p[u][a]=t;
            }
            else {
                p[u][a]=std::max(p[u][a],t);
            }
            u=trie[u][a];
        }
    };
    auto solve=[&](int val,int t)
    {
        int u=0;
        int ans=0;
        for(int i=(30<<1);i;i>>=1)
        {
            int a=bool(val&i);
            if(trie[u][a^1]&&p[u][a^1]>=t)
            {
                u=trie[u][a^1];
                ans|=i;
            }
            else {
                u=trie[u][a];
            }
        }
        return ans;
    };
    
    std::vector<int>ans(m);h=0;
    for(int i=0;i<m;++i)
    {
        while(h<=Q[i].r)
        {
            insert(s[h],h);
            h++;
        }
        ans[Q[i].id]=solve(Q[i].val,Q[i].l);
    }
    for(auto &i:ans)
        std::cout<<i<<"\n";
    return 0;
}
}
signed main ()
{
    return my::main();
}
