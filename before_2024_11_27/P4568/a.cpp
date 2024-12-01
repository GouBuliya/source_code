#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long 
int re ()
{
    int t;
    cin>>t;
    return t;
}
const int maxn=1e5+10;
const int INF=1e18;
vector<tuple<int,int>>G[maxn];
int dis[maxn];

void dijkstra(int st)
{
    priority_queue<tuple<int,int>,vector<tuple<int,int>>,greater<tuple<int,int>>>que;
    memset(dis,0x7f,sizeof(dis));
    dis[st]=0;
    que.push(tuple<int,int>{0,st});
    while(!que.empty())
    {
        tuple<int,int> p=que.top();
        que.pop();
        int v=get<1>(p);
        if(dis[v]<get<0>(p)) 
            continue;
        for(auto [to,cost]:G[v])
            if(dis[to]>dis[v]+cost)
            {
                dis[to]=dis[v]+cost;
                que.push(tuple<int,int>{dis[to],to});
            }
    }
}
signed main ()
{
    int n=re();
    int m=re();
    int k=re();
    int start=re(),end=re();
    for(int i=1;i<=m;++i)
    {
        int u=re(),v=re(),w=re();
        G[u].push_back(tuple<int,int>(v,w));
        G[v].push_back(tuple<int,int>(u,w));
        for(int j=0;j<=k;++j)
        {
        G[u+j*n].push_back(tuple<int,int>(v+j*n,w));
        G[u+j*n-n].push_back(tuple<int,int>(v+j*n,0));
        G[v+j*n].push_back(tuple<int,int>(u+j*n,w));
        G[v+j*n-n].push_back(tuple<int,int>(u+j*n,0));
        }
    }
    dijkstra(start);
    ll ans=1*INF;
    for(int j=0;j<=k;++j)
        ans=min(ans,dis[end+j*n]);
    cout<<ans<<endl;
}
