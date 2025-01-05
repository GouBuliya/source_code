#include<bits/stdc++.h>
using namespace std;
namespace my{
#define ll long long 
const int INF=(1<<31);
const int maxn=5e5+10;
#define int long long
int dp[maxn];
int num[maxn];
vector<pair<int,int>>G[maxn];
int n;
bool vis[maxn];
bool ais[maxn];
int ans=0;
void dfs(int u,int fa)
{
    
    for(auto [v,w]:G[u])
    {
        if(vis[v]||v==fa)
            continue;
        dfs(v,u);
        num[u]=max(num[u],w+num[v]);
    }
    for(auto [v,w]:G[u])
    {
        if(ais[v]||v==fa)
            continue;
        dp[u]+=dp[v];
        dp[u]+=num[u]-(num[v]+w);
    }

}
signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int start;
    cin>>n>>start;
    
for (int i = 1; i < n; ++i) {
    int u  , v , w ;
    cin>>u>>v>>w;
    G[u].push_back({v, w});
    G[v].push_back({u, w});  // 对于无向图需要双向添加边
}
    dfs(start,0);
    cout<<dp[start]<<endl;
    return 0;
}
}
signed main ()
{
    return my::main();
}

