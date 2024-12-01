#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
using namespace std;
int re()
{
    int x=0,t=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*t;
}
const int maxn=2e5+10;
ll n,q,x[maxn],y[maxn],ql[maxn],qr[maxn];
ll tp;
ll st[4*maxn];
ll sum [4*maxn];
signed main()
{
    n=re();
    for(int i=1;i<=n;++i)
    {
        x[i]=re();st[++tp]=x[i];
    }
    for(int i=1;i<=n;++i)
    {
        y[i]=re(),st[++tp]=y[i];
    }
    q=re();
    for(int i=1;i<=q;++i)
    {
        ql[i]=re();qr[i]=re();
        st[++tp]=ql[i];
        st[++tp]=qr[i];
    }
    std::sort(st+1,st+tp+1);
    tp=std::unique(st+1,st+tp+1)-st-1;
    for(int i=1;i<=n;++i)
    {
        x[i]=std::lower_bound(st+1,st+tp+1,x[i])-st;
        sum[x[i]]+=y[i];       
    }
    for(int i=1;i<=tp;++i)
    {
        sum[i]+=sum[i-1];
    }
    for(int i=1;i<=q;++i)
    {
        int l=std::lower_bound(st+1,st+tp+1,ql[i])-st;
        int r=std::lower_bound(st+1,st+tp+1,qr[i])-st;
        printf("%lld\n",sum[r]-sum[l-1]);
    }
}    
