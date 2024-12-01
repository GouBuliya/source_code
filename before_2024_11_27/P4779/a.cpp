#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=2e5+10;
int n,m,x;
vector<pair<int,int>>G[maxn];
int dis[maxn];
void dijkstra(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>que;
    memset(dis,0x3f,sizeof(dis));
    dis[start]=0;
    que.push(pair<int,int>(0,start));//frist->起点到其他端点的最短距离,second->顶点的编号
    while(!que.empty())
    {
        pair<int,int> p=que.top();
        que.pop();
        int v=p.second;
        if(dis[v]<p.first)
            continue;
        for(auto &[to,cost]:G[v])
        {
            if(dis[to]>dis[v]+cost)
            {
                dis[to]=dis[v]+cost;
                que.push(pair<int,int>(dis[to],to));
            }
        }
    }
}
int re ()
{
    int t;
    cin>>t;
    return t;
}
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n=re(),m=re(),start=re();
    for(int i=1;i<=m;++i)
    {
        int u=re(),v=re(),w=re();
        G[u].push_back(pair<int,int>(v,w));
    }
    dijkstra(start);
    for(int i=1;i<=n;++i)
    {
        cout<<dis[i]<<" ";
    }
}

