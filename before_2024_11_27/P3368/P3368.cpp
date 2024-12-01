#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
using namespace std;
#define in inline 
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in int re()
	{
		int x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
		x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*ny;
	}
}
using namespace fast_io;
const int maxn=500000+10;
int b[maxn];
int a[maxn];
int  n,m;
inline int lowbit(int x){return x&(-x);}
void add(int x,int y)
{
    for(;x<=n;x+=lowbit(x))
        b[x]+=y;
}
void add(int t,int l,int r)
{
    add(l,t),add(r+1,-t);
}
int ask(int x)
{
    int y=0;
    for(;x;x-=lowbit(x))
        y+=b[x];
    return y;
}
signed main()   
{
    n=re(),m=re();
    int t,lt=0;
    for(int i=1;i<=n;++i)
    {
        a[i]=re();
    }   
    for(int i=1;i<=m;++i)
    {
        t=re();
        if(t==1)
        {
            int x=re(),y=re(),k=re();
            add(k,x,y);
        }
        else 
        {
            int x=re();
            int ans=0;
            printf("%d\n",a[x]+ask(x));
        }
    }
    return 0;
}
                                                                                                                                                                                  
