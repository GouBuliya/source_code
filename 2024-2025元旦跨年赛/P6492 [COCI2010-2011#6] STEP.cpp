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
}   class Sgt { // 线段树 sgt xds
    private:
        int ls(int x) { return x << 1; }
        int rs(int x) { return x << 1 | 1; }

        void push_up(int p) 
        {
            if(tree[ls(p)].tag||tree[rs(p)].tag)
            {
                if(tree[ls(p)].tag&&tree[rs(p)].tag)
                {
                    if(tree[ls(p)].rval==tree[rs(p)].lval)
                    {
                    tree[p].lmaxlong=tree[ls(p)].lmaxlong*2;
                    tree[p].rmaxlong=tree[rs(p)].rmaxlong*2;
                    tree[p].rval=tree[p].lval=tree[ls(p)].lval;
                    tree[p].tag=1;
                    tree[p].maxlong=tree[p].lmaxlong;
                    }
                    else
                    {
                        tree[p].lmaxlong=tree[p].rmaxlong=tree[ls(p)].lmaxlong;
                        tree[p].maxlong=tree[ls(p)].maxlong;
                        tree[p].tag=0;
                        tree[p].lval=tree[ls(p)].lval;
                        tree[p].rval=tree[rs(p)].rval;
                    }
                }
                else if(tree[ls(p)].tag&&tree[rs(p)].tag==0)
                {
                    if(tree[ls(p)].rval==tree[rs(p)].lval)
                    {
                    tree[p].lmaxlong=tree[ls(p)].lmaxlong+tree[rs(p)].lmaxlong;
                    tree[p].rmaxlong=tree[rs(p)].rmaxlong;
                    tree[p].rval=tree[rs(p)].rval;tree[p].lval=tree[ls(p)].lval;
                    tree[p].tag=0;
                    tree[p].maxlong=tree[p].lmaxlong;
                    }
                    else
                    {
                        tree[p].lmaxlong=tree[ls(p)].lmaxlong;tree[p].rmaxlong=tree[rs(p)].rmaxlong;
                        tree[p].maxlong=tree[ls(p)].maxlong;
                        tree[p].tag=0;
                        tree[p].lval=tree[ls(p)].lval;
                        tree[p].rval=tree[rs(p)].rval;
                    }
                }
                else if(tree[ls(p)].tag==0&&tree[rs(p)].tag)
                {
                    if(tree[ls(p)].rval==tree[rs(p)].lval)
                    {
                    tree[p].rmaxlong=tree[ls(p)].rmaxlong+tree[rs(p)].lmaxlong;
                    tree[p].lmaxlong=tree[ls(p)].lmaxlong;
                    tree[p].rval=tree[rs(p)].rval;tree[p].lval=tree[ls(p)].lval;
                    tree[p].tag=0;
                    tree[p].maxlong=tree[p].rmaxlong;
                    }
                    else
                    {
                        tree[p].lmaxlong=tree[ls(p)].lmaxlong;tree[p].rmaxlong=tree[rs(p)].rmaxlong;
                        tree[p].maxlong=tree[rs(p)].maxlong;
                        tree[p].tag=0;
                        tree[p].lval=tree[ls(p)].lval;
                        tree[p].rval=tree[rs(p)].rval;
                    }
                }
            }
            else{
            tree[p].lmaxlong=tree[ls(p)].lmaxlong;
            tree[p].lval=tree[ls(p)].lval;
            tree[p].rval=tree[rs(p)].rval;
            tree[p].rmaxlong=tree[rs(p)].rmaxlong;
            int temp=tree[ls(p)].rval==tree[rs(p)].lval?tree[ls(p)].rmaxlong+tree[rs(p)].lmaxlong:0;
            tree[p].maxlong=std::max(tree[ls(p)].maxlong,std::max(tree[rs(p)].maxlong,temp));
            }
        }
        bool Inrange(int L, int l, int R, int r) { return (l <= L) && (R <= r); }
        bool Ontorange(int L, int l, int R, int r) { return (R < l) || (L > r); }
    public:
        class node 
        {
            public:
            bool lval;
            bool rval;
            int lmaxlong=0;
            int rmaxlong=0;
            int maxlong=0;
            bool tag;//判断是不是全是1或1
        };
        std::vector<node> tree;
        std::vector<int> tag;
        std::vector<bool> A;

        void init(int n) {
            tree.resize(4 * n + 1);
            tag.resize(4 * n + 1);
            A.resize(n + 1);
            for(int i=1;i<=n;++i)
            {
                A[i]=i%2;
            }
            std::function<void(int, int, int)> build = [&](int p, int l, int r) {
                if (l == r) {
                tree[p] = {A[l],A[l],1,1,1,1};
                }
                else {
                    int mid = (l + r) >> 1;
                    build(ls(p), l, mid);
                    build(rs(p), mid + 1, r);
                    push_up(p);
                }
                };
            build(1, 1, n);
        }
        void add(int p,int l,int r,int u)
        {
            if(l==r)
            {
                bool temp=tree[p].lval;
                tree[p]={!temp,!temp,1,1,1,1};

            }
            else {
                int mid=(l+r)>>1;
                if(mid>=u)
                    add(ls(p),l,mid,u);
                else
                    add(rs(p),mid+1,r,u);
                push_up(p);
            }
        }
        int ans()
        {
            return tree[1].maxlong;
        }
    };

signed main ()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    Sgt A;
    int n=re();int q=re();
    A.init(n);
    for(int i=1;i<=q;++i)
    {
        int t=re();
        A.add(1,1,n,t);
        std::cout<<A.ans()<<std::endl;
    }
    return 0;
}
}
signed main ()
{
    return my::main();
}
