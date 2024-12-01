#include<bits/stdc++.h>
#define ll long long
#define INF 0x7fffffff
const int POS_N=10001;
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
int arr[100001];
ll drr[100001];
long long setction(int l,int r)
{
    ll ans=0;
    if(drr[r])
    {return drr[r]-drr[l-1];}
    for(int i=l;i<=r;++i)
    {
        
        ans+=arr[i];
        drr[i]=drr[i-1]+arr[i];
    }
    return ans;

}
signed main()
{
    // freopen("ans.b","w",stdout);
    // freopen("data.in","r",stdin);

    int n=re();
    for(int i=1;i<=n;i++)
    {
        arr[i]=re();
    }
    int m=re();
    for(int i=1;i<=m;++i)
    {
        int l=re();
        int r=re(); 
        printf("%d\n",setction(l,r));
    }
    // for(int i=1;i<=11;++i)
    // {
    //     printf("%d\n",drr[i]);
    // }
    fclose(stdin);
    fclose(stdout);
    return 0;
}