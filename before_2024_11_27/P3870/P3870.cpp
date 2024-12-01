#include <iostream>
#include <cstdio>
using namespace std;
#define int long long
const int maxn=1e5+7;
int ans[4*maxn];
int tag[4*maxn];
int n,m;
inline int re()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')
		{
			t=-1;
			break;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x*t;
}
inline int ls(int p)
{
	return p<<1;
}
inline int rs(int p)
{
	return (p<<1)|1;
}
inline void push_up(int p)
{
	ans[p]=ans[ls(p)]+ans[rs(p)];
}
void build(int l,int r,int p)
{
	tag[p]=0;
	if(l==r)
	{
		ans[p]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls(p));
	build(mid+1,r,rs(p));
	push_up(p);
}
inline void tag_aptty(int l,int r,int p,int k)
{
//	ans[p]+=(r-l+1);
//	tag[p]++;
	for(int i=1;i<=k;++i)
	{
		ans[p]=(r-l+1)-ans[p];
		tag[p]++;
	}
}
inline void push_down(int l,int r,int p)
{
	
		int mid=(l+r)>>1;
		tag_aptty(l,mid,ls(p),tag[p]);
		tag_aptty(mid+1,r,rs(p),tag[p]);
		tag[p]=0;
	
	
}
void update(int nl,int nr,int l,int r,int p)
{
	if(l>=nl&&r<=nr)
	{
		tag_aptty(l,r,p,1);
		return;
	}
	push_down(l,r,p);
	int mid =(l+r)>>1;
	if(nl<=mid)update(nl,nr,l,mid,ls(p));
	if(nr>mid)update(nl,nr,mid+1,r,rs(p));
	push_up(p);
}
int query(int nl,int nr,int l,int r,int p)
{
	int res=0;
	if(l>=nl&&r<=nr)
	{
		return ans[p];
	}
	int mid=(l+r)>>1;
	push_down(l,r,p);
	if(nl<=mid)res+=query(nl,nr,l,mid,ls(p));
	if(nr>mid)res+=query(nl,nr,mid+1,r,rs(p));
	return res;
}
signed main ()
{
	cin>>n>>m;
	build(1,n,1);
	while(m--)
	{
		int op;int x,y;
		scanf("%lld %lld %lld",&op,&x,&y);
		if(!op)
		{
			update(x,y,1,n,1);
		}
		else
		{
			printf("%lld\n",query(x,y,1,n,1));
		}
	}
}
