#include<cstdio>
#include<iostream>
#include<algorithm>
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
int n,m=60;
int f[60][60][60][60];
int A[60][60];

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    n=re();
    m=re();
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            A[i][j]=re();
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            for(int k=1;k<=n;++k)
            {
                for(int l=1;l<=m;++l)
                {
                    f[i][j][k][l]=(max(max(f[i-1][j][k-1][l],f[i-1][j][k][l-1]),max(f[i][j-1][k-1][l],f[i][j-1][k][l-1]))+A[i][j]+A[k][l])*(i==k&&j==l)*-1;
                }
            }
        }
    }
    cout<<f[n][m][n][m];
    return 0;
}