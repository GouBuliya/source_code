    
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define int long long 
const int INF=(1<<31);
ll re ()
{
    ll t;
    cin>>t;
    return t;
}
const int maxn=2e5+10;
int A[maxn];
int f[maxn];
int g[maxn];
int F[maxn];
int G[maxn];
int n;
int solve ()
{
    const ll zero=0;
    int res=-1e9;
    for(int i=1;i<=n;++i)
        f[i]=max(f[i-1],0ll)+A[i];
    for(int i=n;i>0;i--)
        g[i]=max(g[i+1],0ll)+A[i];
    for(int i=1;i<=n;++i)
        f[i]=max(f[i-1],f[i]);
    for(int i=n;i>0;--i)
        g[i]=max(g[i+1],g[i]);
    for(int i=1;i<n;++i)
        res=max(f[i]+g[i+1],res);
    return res;
}
signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int sum=0;
    n=re();
    int tot=0;
    for(int i=1;i<=n;++i)
        A[i]=re(),sum+=A[i],f[i]=g[i]=-1e9,tot+=(A[i]>0);
    
    int ans=-1e9;
    int t1=0;
    t1=solve();
    if(tot==1)
    {
        cout<<t1<<endl;
        return 0;
    }
    for(int i=1;i<=n;++i)
        A[i]=(-A[i]);
    int t=sum+solve();
    if(t==0)t=INF;
    ans=max(t,t1);
    if(ans==0)ans=-200;
    cout<<ans<<endl;
    return 0;
}
/*对于环状子序列，have two cases 
1 cases is two subseq all in seq [1,n]
2 casse is not all subseq in [1,n]

1:ans=max(f[i]+g[n-i]);
2:ans=sum-min(f[i],g[n-i]);
*/
