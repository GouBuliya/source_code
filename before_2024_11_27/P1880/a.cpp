#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp1 cout<<1<<endl;
int re()
{
        int t;
        cin>>t;
        return t;
}
const int maxn=300+10;
int f[maxn][maxn];
int g[maxn][maxn];
int A[maxn];
int S[maxn];
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    #endif
    int n=re();
    for(int i=1;i<=n;++i)
    {
        A[i]=re();
    }
    for(int i=1;i<=n;++i)
    {
        A[i+n]=A[i];
    }
    n*=2;
    for(int i=1;i<=n;++i)
    {
        S[i]=S[i-1]+A[i];
    }
    for(int len=1;len<=n/2;++len)
        for(int l=1;l+len-1<=n;++l)
        {
            int r=l+len-1;
            if(len==1)
            {
                f[l][r]=0;
                g[l][r]=0;
                continue;
            }
            f[l][r]=1e9;
            g[l][r]=-1e9;
            for(int k=l;k<r;++k)
            {
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+S[r]-S[l-1]);
                g[l][r]=max(g[l][r],g[l][k]+g[k+1][r]+S[r]-S[l-1]);
            }
        }
    int ans1=1e9;
    int ans2=-1e9;
    for(int i=1;i<=n/2;++i)
    {
        ans1=min(ans1,f[i][i+n/2-1]);
        ans2=max(ans2,g[i][i+n/2-1]);
    }
    cout<<ans1<<endl<<ans2<<endl;
    return 0;
}
