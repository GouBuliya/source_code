#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int maxn =250;
int A[maxn];
int dp[maxn][maxn];

signed main ()
{
    int n;

    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&A[i]);
    }int ans=0;
    for(int len=1;len<=n;++len)
    {
        for(int l=1;l+len-1<=n;++l)
        {
            int r=l+len-1;
            if(len==1)
            {
                dp[l][r]=A[l];
                ans=max(ans,dp[l][r]);
                continue;
            }
            for(int k=l;k<r;++k)
            {
                if(dp[l][k]==dp[k+1][r]&&dp[l][k])
                {
                    dp[l][r]=max(dp[l][r],dp[k+1][r]+1);
                    ans=max(ans,dp[l][r]);
                }
            }
        }
    }
    cout<<ans<<endl;
}