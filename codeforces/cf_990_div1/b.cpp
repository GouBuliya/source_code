#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
namespace my{
#define ll long long 
const int INF=(1<<30);
ll re ()
{
    ll t;
    cin>>t;
    return t;
}
void solve()
{
   int n=re();
   vector<int>A,suf(n+1),B;
   vector<bool>vis(n,0);
   for(int i=1;i<=n;++i)
        A.push_back(re());
   suf[n]=1e9;
   for(int i=n-1;i>=0;i--)
       suf[i]=min(suf[i+1],A[i]);
   for(int i=0,mn=1e9;i<n;++i)
   {
       if(suf[i]==A[i])
       {
           if(A[i]>mn+1)
               break;
           vis[i]=1;
            cout<<A[i]<<" ";
       }
       else {
           mn=min(mn,A[i]);
       }
   }
   for(int i=0;i<n;++i)
       if(!vis[i])
            B.push_back(A[i]);
   sort(B.begin(),B.end());
   for(auto &i:B)
       cout<<i+1<<" ";
   cout<<'\n';
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
/*1 2 2 1 4
 *1 1 2 2 4
  
            
  1 2 3 6 5 4 
  1 2 3 5 4 7 
  1 2 3 6 4 3 6 5 4 
  1*/
