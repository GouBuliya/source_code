#include <bits/stdc++.h>
using namespace std;
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) / 2)
#define int long long
const int maxn = 2e5 + 7;
struct b
{
    int n;
    int tg;
} B[maxn * 4];
int A[maxn];
int drr[maxn];
void push_up(int p)
{
    B[p].n = B[ls].n + B[rs].n;
}
void apply_tag(int l, int r, int k, int p)
{
    B[p].tg += k;
    B[p].n += k * (r - l + 1);
}
void push_down(int l, int r, int p)
{
    if (B[p].tg )
    {
        apply_tag(l, mid, B[p].tg, ls);
        apply_tag(mid + 1, r, B[p].tg, rs);
        B[p].tg = 0;
        
    }
}
void build(int ul, int ur, int l, int r, int p)
{
    if (l == r)
    {
        B[p].n = A[l];
        // cout<<"l:"<<l<<" "<<B[p].n<<endl;
      
        return;
    }
    build(ul, ur, l, mid, ls);
    build(ul, ur, mid + 1, r, rs);
    push_up(p);
  
}

void add(int ul, int ur, int l, int r, int p, int k)
{
    if (ul <= l && ur >= r)
    {
        apply_tag(l, r, k, p);
        return;
    }
    push_down(l, r, p);
    if (mid >= ul)
        add(ul, ur, l, mid, ls, k);
    if (mid < ur)
        add(ul, ur, mid + 1, r, rs, k);
    push_up(p);
}

int find(int l, int r, int p, int tag, int k)
{

    if(l==r)
    {
        return B[p].n*tag<k?l:l-1;
    }
    push_down(l,r,p);
    // cout<<"m"<<B[ls].maxn*tag<<endl;
    if(k>B[ls].n*tag)
    {
        return find(mid+1,r,rs,tag,k-B[ls].n*tag);
    }
    else 
    {
        return find(l,mid,ls,tag,k);
    }
}
int re()
{
    int x=0,t=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*t;
}
signed main()
{
    // ios::sync_with_stdio(0),cin.tie(nullptr);cout.tie(nullptr);
    int n = re(), q = re(), W = re();int Ask=0;
    for (int i = 1; i <= n; ++i)
        A[i] = re(),Ask+=A[i];
    build(1, n, 1, n, 1);
    // cout<<ask(1,1,1,n,1);
    while (q--)
    {
        int l = re(), r = re(), d = re();
        add(l, r, 1, n, 1, d);
        // debug(1,n,1);
        Ask+=(r-l+1)*d;
        int tt=Ask;
        int w = W;
        int tag = 1;
        int t = 0;
        int ans=0;
        for(;tt<w;w-=tt,tt*=2)ans++,tag*=2;
        // cout << ans*n+find(1,n,1,tag,w) << endl;
        printf("%lld\n",ans*n+find(1,n,1,tag,w));
    }
}
