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
const int maxn=1e5;
int A[maxn];

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
        A[i]=re();
    int ans=-1e9;
    for(int k=1;k<=n;++k)
        for(int l=1;l+k<=n;++l)
        {
            int r=l+k;
            int sum=0;
            for(int i=l;i<=r;++i)
                sum+=A[i];
            ans=max(ans,sum);
        }
    cout<<ans<<endl;
    
    return 0;
}

