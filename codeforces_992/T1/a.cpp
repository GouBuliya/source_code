#include<bits/stdc++.h>
using namespace std;
namespace my{
#define ll long long 
#define int long long 
const int INF=INT64_MAX;
ll re ()
{
    ll t;
    cin>>t;
    return t;
}
int abs(int a)
{
    return a<0?-a:a;
}
void solve()
{
    int n=re();
    int k=re();
    vector<int>A(1);
    for(int i=1;i<=n;++i)
        A.push_back(re());
    bool flag=0;
    int ans=1;
    
    for(int i=1;i<=n;++i)
    {
        bool F=1;
        for(int j=1;j<=n;++j)
        {
            if(i==j)
                continue;
            if(abs(A[i]-A[j])%k==0)
                F=0;
        }
        if(F)
        {
            ans=i;
            flag=1;
        }
    }
    if(flag)
        cout<<"YES"<<endl<<ans<<endl;
    else
        cout<<"NO"<<endl;

}
signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=re();
    while(t--)
    {
        solve();
    }
    return 0;
}
}
signed main ()
{
    return my::main();
}

