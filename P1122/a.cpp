    #include<bits/stdc++.h>
using namespace std;
namespace my{
#define ll long long 
ll re ()
{
    ll t;
    cin>>t;
    return t;
}
const int maxn=2e4;
vector<vector<int>>G(16000+19);
vector<int>W(1);

signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n=re();
    bool flag=0;
    for(int i=1;i<=n;++i)
    {
        int t=re();
        if(t>0)flag=1;
        W.push_back(t);
    }
    for(int i=1;i<n;++i)
    {
        int u=re(),v=re();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int>dp(maxn);
    std::function<void(int,int)> dfs=[&](int u,int fa)
    {
        dp[u]=W[u];
        for(auto &v:G[u])
        {
            if(v==fa) continue;
            dfs(v,u);
            dp[u]+=dp[v]>=1?dp[v]:0;
        }
    };
    dfs(1,0);
    int ans=INT_MIN;
    for(auto &i:dp)
        ans=max(ans,i);
    if(!flag)
    {
        ans=INT_MIN;
        for(auto &i:W)
            ans=max(ans,i==0?INT_MIN:i);
    }
    cout<<ans<<endl;
    return 0;
}
}
signed main ()
{
    return my::main();
}

