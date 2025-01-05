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
int n,w;
const int maxn=5*1e5+7;
int BIT[maxn];
int lowbit (int x){return x&(-x);}
void add(int x,int y){for(int i=x;i<=n;i+=lowbit(i))BIT[i]+=y;}
ll sum(int x)
{
    ll res=0;
    for(int i=x;i;i-=lowbit(i))res+=BIT[i];
    return res;
}
ll prefix(int x,int y)
{
    return sum(y)-sum(x-1);
}
signed main()
{
    n=re(),w=re();
    for(int i=1;i<=w;++i)
    {
        char mod;
        cin>>mod;
        if(mod=='x') add(re(),re());
        else printf("%lld\n",prefix(re(),re()));
    }
    return 0;
}
                                                                                                                                                                                  
 