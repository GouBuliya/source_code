bool _Start;
#include <bits/stdc++.h>
using namespace std;
#define il inline
#define pb push_back
#define debug printf("How can I become successful?\n")
#define Tp template<typename T>
#define Ts template<typename T,typename... _T>
Tp il void read(T& x) {
	x=0;bool f=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}Ts il void read(T& x,_T&... y) {read(x),read(y...);}
#define int long long
using ll=long long;
const int N=2e5+5;
int n,Q;
ll W,a[N],sum,pw[70];
struct Segtr {
	int ls,rs;
	ll sum,lz;
}seg[N<<1];int trlen;
il void pushup(int p) {seg[p].sum=seg[seg[p].ls].sum+seg[seg[p].rs].sum;}
il void pushdown(int l,int r,int p) {
	if(!seg[p].lz) return ;
	ll mid=(l+r)>>1,ls=seg[p].ls,rs=seg[p].rs,lz=seg[p].lz;
	seg[ls].sum+=(mid-l+1)*lz,seg[rs].sum+=(r-mid)*lz;
	seg[ls].lz+=lz,seg[rs].lz+=lz;
	seg[p].lz=0;
}
int bt(int l,int r) {
	int p=++trlen;
	seg[p].lz=0;
	if(l==r) return seg[p].sum=a[l],p;
	int mid=(l+r)>>1;
	seg[p].ls=bt(l,mid);
	seg[p].rs=bt(mid+1,r);
	pushup(p);
	return p;
}
void change(int l,int r,int p,int x,int y,ll k) {
	if(l>=x&&r<=y) {
		seg[p].sum+=(r-l+1)*k;
		seg[p].lz+=k;
		return ;
	}
	pushdown(l,r,p);
	int mid=(l+r)>>1;
	if(x<=mid) change(l,mid,seg[p].ls,x,y,k);
	if(y>mid) change(mid+1,r,seg[p].rs,x,y,k);
	pushup(p);
}
int query(int l,int r,int p,int x,ll k) {
	if(l==r) return seg[p].sum*pw[x]<k?l:l-1;
	pushdown(l,r,p);
	int mid=(l+r)>>1,ls=seg[p].ls,rs=seg[p].rs;
	if(seg[ls].sum*pw[x]<k) return query(mid+1,r,rs,x,k-seg[ls].sum*pw[x]);
	return query(l,mid,ls,x,k);
}
bool _End;
signed main() {
	fprintf(stderr,"Memory: %.4lf Mib\n",(&_End-&_Start)/1048576.0);
	pw[0]=1;for(int i=1;i<=62;i++) pw[i]=pw[i-1]*2;
	read(n,Q,W);
	for(int i=1;i<=n;i++) read(a[i]),sum+=a[i];
	bt(1,n);
	while(Q--) {
		ll l,r,d;read(l,r,d);
		change(1,n,1,l,r,d);
		sum+=(r-l+1)*d;
		ll t=sum,tw=W;
		int ans=0;
		for(;t<tw;tw-=t,t*=2) ans++;
		printf("%lld\n",ans*n+query(1,n,1,ans,tw));
	}
	return 0;
}