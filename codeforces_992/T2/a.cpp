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
void solve ()
{
    int n=re();
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    int ans=1,tot=1;
    while(tot<n)
    {
        tot=tot*2+2;
        ans++;
    }
    cout<<ans<<endl;
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

