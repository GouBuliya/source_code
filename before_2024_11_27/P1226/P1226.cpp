#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long
ll flow(int x,int y,int MOD)
{
    ll ans=1%MOD;
    while(y!=0)
    {
        if(y%2)
        {
            ans=(ans*x)%MOD;
        }
        x=(x*x)%MOD;
        y=y/2;
    } 
    return ans;
}
signed main ()
{
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();
    int a,b,p;
    cin>>a>>b>>p;
    cout<<a<<"^"<<b<<" mod "<<p<<"="<<flow(a,b,p)<<endl;
}