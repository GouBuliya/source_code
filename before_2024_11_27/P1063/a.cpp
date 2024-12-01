#include <bits/stdc++.h>
using namespace std;
int re ()
{
    int t;
    cin>>t;
    return t;
};
#define ll long long 
const int maxn=200+10;
int A[maxn];
ll f[maxn][maxn];
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n=re();
    for(int i=1;i<=n;++i)
    {
        cin>>A[i];
    }
    for(int i=1;i<=n;++i)
    {
        A[i+n]=A[i];
    }

    
    for(int len=2;len<=n+1;++len)
        for(int l=1;l+len-1<=n*2;++l)
        {
            int r=l+len-1;
            if(len==1)
            {
                f[l][r]=0;
                continue;
            }
            for(int k=l+1;k<=l+len-2;++k)
            {
                f[l][r]=max(f[l][r],f[l][k]+f[k][r]+A[l]*A[k]*A[r]);
            }
        }
    ll ans=0;
    for(int i=1;i<=n;++i)
    {
        ans=max(ans,f[i][i+n]);
    }
    cout<<ans<<endl;



}
