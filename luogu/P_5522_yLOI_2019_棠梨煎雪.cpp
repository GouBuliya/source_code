#include<bits/stdc++.h>
#define ll long long
#define pn std::cout<<'\n'
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
#define int long long
namespace my {
    const int INF = (1 << 30);
    ll re()
    {
        ll t; std::cin >> t;return t;
    }
    #define ls (p<<1)
    #define rs (p<<1|1)
    std::vector<ll>tree;
    int n,m,Q;
    void push_up(int p)
    {
        tree[p]=tree[ls]|tree[rs];
    }
    void reset(int p)
    {
        std::string s;
        std::cin>>s;
        tree[p]=0;
        for(int i=0;i<m;++i)
        {
            if(s[i]!='?')
            {
                tree[p]|=(ll)(s[i]-'0'+1)<<2*i;
            }
        }
    }
    void build(int l,int r,int p)
    {
        if(l==r)
        {
            reset(p);
            return ;
        }
        int mid =l+r>>1;
        build(l,mid,ls);
        build(mid+1,r,rs);
        push_up(p);
    }
    void update(int p,int l,int r,int x)
    {
        if(l==r)
        {
            reset(p);
            return ;
        }
        int mid=l+r>>1;
        if(x<=mid)
            update(ls,l,mid,x);
        else
            update(rs,mid+1,r,x);
        push_up(p);
    }
    ll ask(int L,int R,int l,int r,int p)
    {
        if(L<=l&&r<=R)
        {
            return tree[p];
        }
        int mid=l+r>>1;
        int res=0;
        if(L<=mid)
            res|=ask(L,R,l,mid,ls);
        if(R>mid)
            res|=ask(L,R,mid+1,r,rs);

        return res;
    }
    signed main()
    {
        std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
        m=re();
        n=re();
        Q=re();
        tree.resize(n<<2+7);
        build(1,n,1);
        int anss=0;
        while(Q--)
        
        {
            int op=re();
            if(op)
            {
                int p=re();
                update(1,1,n,p);
                
            }
            else    
            {
                int l=re();
                int r=re();
                int ans=1;
                int res=ask(l,r,1,n,1);
                // std::cout<<"! "<<res<<std::endl;
                for(int i=0;i<m;++i)
                {
                    int t=res>>2*i&3;
                    // std::cout<< " ";
                    if(t==3)
                    {
                        ans=0;
                        break;
                    }
                    if(!t)
                    {
                        ans<<=1;
                    }
                }
                anss^=ans;
                // std::cout<<ans<<std::endl;
            }
        }
        std::cout<<anss<<std::endl;
        return 0;
    }
}
signed main()
{
    return my::main();
}