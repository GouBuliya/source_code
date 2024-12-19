#include<bits/stdc++.h>
using namespace std;
namespace my{
#define ll long long 
const int INF=(1<<31);
ll re ()
{
    ll t;
    cin>>t;
    return t;
}
const int maxn=1e5;
int A[maxn];
int f[maxn];
int g[maxn];
int G[maxn];
int sum[maxn];
signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n=re();
    
    for(int i=1;i<=n;++i)
        cin>>A[i],sum[i]=sum[i-1]+A[i];
    for(int i=1;i<=n;++i)
        f[i]=min(g[i-1]+A[i],0);
    for(int i=1;i<=n;++i)
        g[i]=sum[n]-f[i];
    int ans=0;
    for(int i=1;i<=n;++i)
        ans=max(ans,g[i]);
    for(int i=1;i<=n;++i)
        G[i]=max(G[i-1]+A[i],0);
    for(int i=1;i<=n;++i)
        ans=max(ans,G[i]);
    cout<<ans<<endl;
    return 0;
}
}
signed main ()
{
    return my::main();
}

