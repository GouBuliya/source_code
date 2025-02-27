#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long LL;
struct SGT{
	LL tag1,tag2;
	LL max_;
	int l,r;
	bool used;
}tree[N<<2];
int n,m;
LL a[N];
void pushup(int p){
	tree[p].max_=max(tree[p<<1].max_,tree[p<<1|1].max_);
}
void pushdown(int p){
	if(tree[p].used){
		tree[p<<1].tag1=tree[p].tag1;
		tree[p<<1|1].tag1=tree[p].tag1;
		tree[p<<1].tag2=tree[p].tag2;
		tree[p<<1|1].tag2=tree[p].tag2; 
		tree[p<<1].max_=tree[p].tag1+tree[p].tag2;
		tree[p<<1|1].max_=tree[p].tag1+tree[p].tag2;
		tree[p<<1].used=tree[p<<1|1].used=1;
	}else{
		tree[p<<1].tag2+=tree[p].tag2;
		tree[p<<1|1].tag2+=tree[p].tag2;
		tree[p<<1].max_+=tree[p].tag2;
		tree[p<<1|1].max_+=tree[p].tag2;
	}
	tree[p].used=tree[p].tag1=tree[p].tag2=0;
}
void build(int p,int l,int r){
	tree[p].l=l,tree[p].r=r;
	tree[p].max_=-1e18;
	if(l==r){
		tree[p].max_=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	pushup(p);
}
void change(int p,int l,int r,LL vl){
	if(l<=tree[p].l&&tree[p].r<=r){
		tree[p].tag1=vl;
		tree[p].tag2=0;
		tree[p].max_=vl;
		tree[p].used=1;
		return;
	}
	pushdown(p);
	int mid=(tree[p].l+tree[p].r)>>1;
	if(l<=mid) change(p<<1,l,r,vl);
	if(mid+1<=r) change(p<<1|1,l,r,vl);
	pushup(p);
}
void update(int p,int l,int r,LL vl){
	if(l<=tree[p].l&&tree[p].r<=r){
		tree[p].tag2+=vl;
		tree[p].max_+=vl;
		return;
	}
	pushdown(p);
	int mid=(tree[p].l+tree[p].r)>>1;
	if(l<=mid) update(p<<1,l,r,vl);
	if(mid+1<=r) update(p<<1|1,l,r,vl);
	pushup(p);
}
LL query(int p,int l,int r){
	if(l<=tree[p].l&&tree[p].r<=r){
		return tree[p].max_;
	}
	pushdown(p);
	int mid=(tree[p].l+tree[p].r)>>1;
	LL res=-1e18;
	if(l<=mid) res=max(res,query(p<<1,l,r));
	if(mid+1<=r) res=max(res,query(p<<1|1,l,r));
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int opt,l,r;
		LL vl;
		scanf("%d%d%d",&opt,&l,&r);
		if(opt==1||opt==2) scanf("%lld",&vl);
		if(opt==1){
			change(1,l,r,vl);
		}else if(opt==2) update(1,l,r,vl);
		else printf("%lld\n",query(1,l,r));
	}
	return 0;
}
