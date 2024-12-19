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
    vector<int>ans;
    for(int i=2;i<=2*n;i+=2)
        ans.push_back(i);
    for(int i=1;i<=2*n-1;i+=2)
        ans.push_back(i);
    for(auto &i:ans)
        cout<<i<<" ";
}
signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   cout.tie(nullptr);
   int t=re();
   while(t--)
       solve();
    return 0;
}
}
signed main ()
{
    return my::main();
}

