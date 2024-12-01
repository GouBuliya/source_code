/*
dp[n][m];前n项使用了m'个单位的空间的最大值
两个选择:选第n项dp[i-1][j-w[i]]+v[i];
不选：dp[i-1][j];
*/
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
int n,m;
const int maxn=1e3+7;
int dp[maxn][maxn];
int ans[maxn];
struct Node
{
    int w,l,r;
    /* data */
}arr[maxn];

signed main()
{
    n=re(),m=re();
    for(int i=1;i<=n;++i)
    {
        arr[i].w=re();arr[i].l=re();arr[i].r=re();
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=m;j>=0;--j)
        {
            if(j>=arr[i].r)
            {
                if(dp[i-1][j]>dp[i-1][j-arr[i].r]+arr[i].w)
                {
                    ans[i]=0;
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    ans[i]=1;
                    dp[i][j]=dp[i-1][j-arr[i].r]+arr[i].w;
                }
            }
            else
            {
                ans[i]=0;
                dp[i][j]=dp[i-1][j];
            }
        } 
    }
    cout<<dp[n][m]<<endl;
    int i=n,j=m;
    while (i>0&&j>0)
    {
        /* code */
        if(dp[i][j]!=dp[i-1][j])
        {
            ans[i]=1;
            j-=arr[i].r;
        }
        --i;
    }
    for(int i=1;i<=n;++i)
        printf("%d ",ans[i]);
    return 0;
}
