#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
#define max(a,b) (a)>(b)?(a):(b)
using namespace std;
const int maxn=1e4;

int A[maxn][maxn];
int B[maxn][maxn];
int C[maxn][maxn];
signed main()
{

    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>A[i][j];
    B[1][1]=A[1][1];
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            B[i][j]=B[i-1][j]+B[i][j-1]-B[i-1][j-1]+A[i][j];
        }
    }
    int temp=0;
    int ans=-0x3f;
    for(int i1=1;i1<=n;++i1)
    {
        for(int j1=1;j1<=n;++j1)
        {
            for(int i2=1;i2<=i1;++i2)
            {
                for(int j2=1;j2<=j1;++j2)
                {
                    temp=B[i1][j1]-B[i2-1][j1]-B[i1][j2-1]+B[i2-1][j2-1];
                    ans=max(ans,temp);  
                }
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
                                                                                                                                                                                  
