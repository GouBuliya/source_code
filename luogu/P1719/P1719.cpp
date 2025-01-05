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
int drr[121][121],arr[121][121];

signed main()
{
    int n=re();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;++j)
        {
            arr[i][j]=re();
            drr[i][j]=drr[i][j-1]+drr[i-1][j]+arr[i][j]-drr[i-1][j-1];
        }
    } 
    ll ans=-INF;
    for(int il=1;il<=n;++il)
    {
        for(int ir=il;ir<=n;++ir)
        {
            for(int js=1;js<=n;++js)
            {
                for(int jx=js;jx<=n;++jx)
                {
                    ll mat=drr[ir][jx]-drr[il][jx]-drr[ir][js]+drr[il][js];
                    ans=max(ans,mat);
                }
            }
        }
    }   
    cout<<ans<<endl;
    return 0;
}