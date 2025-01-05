#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF=(1<<31);
namespace goubuli{
ll re ()
{
    ll t;
    cin>>t;
    return t;
}
    int n,k;
const int maxn=500+10;
struct edge 
{
    int x,y;
}E[maxn];

struct Mit {
    int lx,rx;int ly,ry;
    int empty =1;
    int abs(int x){return x<0?-x:x;}
    int how_S(){return (abs(rx-lx)*abs(ry-ly));}
void join(int u)//将第u个点加入矩形
	{
		if(empty)
			lx=rx=E[u].x,ly=ry=E[u].y;
		empty=0;
		lx=min(lx,E[u].x),rx=max(rx,E[u].x);
		ly=min(ly,E[u].y),ry=max(ry,E[u].y);
	}
    }mit[6];
int ans=9999999;
int is_intersect(int a,int b,int c,int d)//ab/cd四条边分属两个矩形，判断是否有其他边夹在ab/cd之间
{
	return (a<=c&&c<=b)||(a<=d&&d<=b)||(c<=a&&a<=d)||(c<=b&&b<=d);
}
    bool f(int num)
    {
        for(int i=1;i<=k;++i)
           if(  num!=i&&is_intersect(mit[num].lx,mit[num].rx,mit[i].lx,mit[i].rx)&&is_intersect(mit[num].ly,mit[num].ry,mit[i].ly,mit[i].ry))
               return 1;
        return 0;
    }

int is_intersect(int num)//判断矩形之间是否相交
{
	for(int i=0;i<=k;i++)
		if(num!=i&&is_intersect(mit[num].lx,mit[num].rx,mit[i].lx,mit[i].rx)&&is_intersect(mit[num].ly,mit[num].ry,mit[i].ly,mit[i].ry))
			return 1;
	return 0;
}
int sum=0;
void DFS(int pos)
{
   if(pos==n+1)
   {
       sum=0;
       for(int i=1;i<=k;++i)
       sum+=mit[i].how_S();
        ans=min(ans,sum);
        return ;
   }
   for(int i=1;i<=k;++i)
   {
       Mit t=mit[i];
        mit[i].join(pos);
       if(!f(i))
           DFS(pos+1);
       mit[i]=t;
   }
}
signed main ()
{
#ifndef ONLINE_JUDGE
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>E[i].x>>E[i].y;
    DFS(1);
    cout<<ans<<endl;
   return 0;
}
};
signed main ()
{return goubuli::main();}

/*与处理所有长方形S 排序 扫一遍*/
