#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ls (p<<1)
#define rs (p<<1|1)
const int maxn=1e5+19;
int tree[4*maxn];
int tag[4*maxn];
int A[maxn];
void push_up(int l,int r,int p)
{
    tree[p]=tree[ls]+tree[rs];
}
void build (int l,int r,int p)
{
    if(l==r)
    {
        tree[p]=A[l];
        return;
    }
    const int mid =(l+r)/2;
    build (l,mid,ls);
    build (mid+1,r,rs);
    push_up(l,r,p);
}
void tag_appty(int l,int r,int k,int p)
{
    tag[p]+=k;
    tree[p]+=(k*(r-l+1));
}
void push_down (int l,int r,int p)
{
    int mid =(l+r)/2;
    tag_appty(l,mid,tag[p],ls);
    tag_appty(mid+1,r,tag[p],rs);
    tag[p]=0;
}
void add(const int nl,const int nr,int l,int r,int p,const int k)
{
    if(nl<=l&&nr>=r)
    {
        tag_appty(l,r,k,p);
        return;
    }
     int mid =(l+r)/2;
    push_down(l,r,p);
    if(mid>=nl)add(nl,nr,l,mid,ls,k);
    if(mid<nr)add(nl,nr,mid+1,r,rs,k);
    push_up(l,r,p);
}
ll ask(const int nl,const int nr,int l,int r,int p)
{
    if(nl<=l&&nr>=r)
    {
        return tree[p];
    }
     int mid =(l+r)/2;
    push_down(l,r,p);
    ll ans=0;
    if(mid>=nl)ans+=ask(nl,nr,l,mid,ls);
    if(mid<nr)ans+=ask(nl,nr,mid+1,r,rs);
    return ans;
}
int re()
{
    int t;
    cin>>t;
    return t;
}
signed main ()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("in","r",stdin);
    int n=re(),m=re();

    build(1,n,1);
    for(int i=1;i<=n;++i)
        cin>>A[i];
    for(int i=1;i<=m;++i)
    {
        int op=re();
        if(op==1)
        {
            int x=re(),y=re(),k=re();
            add(x,y,1,n,1,k);
        }
        else 
        {
            int x=re(),y=re();
            cout<<ask(x,y,1,n,1)<<endl;
        }
    }
}
