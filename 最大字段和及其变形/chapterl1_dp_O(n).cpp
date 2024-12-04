#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int INF=(1<<31);
ll re ()
{
    ll t;
    cin>>t;
    return t;
}
const int maxn=1e5+10;
int A[maxn];
int sum[maxn];
int sum_min[maxn];
int dp[maxn];
signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    /*
    for(int i=1;i<=n;++i)
        cin>>A[i];
    for(int i=1;i<=n;++i)
        A[i+n]=A[i];
    dp[1]=A[1];
    for(int i=2;i<=2*n;++i)
       dp[i]=max(dp[i-1]+A[i],0);
    int ans=-1e9;
    for(int i=1;i<=n*2;++i)
        ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
*/  
    int n=re();
    for(int i=1;i<=n;++i)
    {
        A[i]=re();
        sum[i]=sum[i-1]+A[i];
        sum_min[i]=min(sum_min[i-1],sum[i]);
    }
    for(int i=1;i<=n;++i)
    {
        dp[i]=sum[i]-sum_min[i];
    }
    int ans=-1e9;
    for(int i=1;i<=n;++i)
        ans=max(ans,dp[i]);
    cout<<ans<<endl;
}

