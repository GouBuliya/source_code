#include<bits/stdc++.h>
using namespace std;
namespace my{
#define ll long long 
const int INF=(1<<31);
#define int long long
ll re ()
{
    ll t;
    cin>>t;
    return t;
}
void solve()
{
    int n=re();
    vector<int>A;
    for(int i=0;i<n;++i)
        A.push_back(re());
    map<int,vector<ll>>adj;
    for(int i=1;i<n;++i)
    {
        int u=A[i]+i;
        int v=u+i;
        adj[u].push_back(v);
    }
    set<int>vis;
    function<void(ll)> dfs=[&](int u)->void 
    {
        if(vis.count(u))
            return;
        vis.insert(u);
        for(auto &i:adj[u])
            dfs(i);
    };
    dfs(n);
    cout<<*vis.rbegin()<<'\n';
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
    {
        solve ();
    }
    return 0;
}
}
signed main ()
{
    return my::main();
}
