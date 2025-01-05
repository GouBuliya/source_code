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
const int maxn=220;
vector<tuple<int,int>>G[maxn];
vector<tuple<int,int>>F[maxn];
int n,m;
int Time[maxn];
int TTime[maxn];
priority_queue<tuple<int,int>,vector<tuple<int,int>>,greater<tuple<int,int>>>q;
int dis[maxn];
int vis[maxn];
int dij(int s,int e,int T)
{
    if(Time[s]>T)
        return INT_MAX;
    for(int i=0;i<=n;++i)
        dis[i]=INT_MAX,vis[i]=0;
    dis[s]=0;
    q.push({0,s});
    while(!q.empty())
    {
        auto [d,u]=q.top();
        q.pop();
        if(vis[u])
            continue;
        vis[u]=1;
        for(auto [v,w] : G[u])
        {
            if(dis[v]>dis[u]+w&&T>=Time[v])
            {
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
    return dis[e];

}
signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    n=re(),m=re();
    for(int i=0;i<n;++i)
       { cin>>Time[i];
       }
    for(int i=1;i<=m;++i)
    {
        int u=re(),v=re(),w=re();
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    int Q=re();
    int T=0;
    int last_t=0;
    while(Q--)
    {
            
        int x=re(),y=re(),t=re();
        
        int ans=dij(x,y,t);
        last_t=t;
        if(ans==INT_MAX)
            cout<<-1<<'\n';
        else
            cout<<ans<<'\n';
    }
        
    return 0;
}

