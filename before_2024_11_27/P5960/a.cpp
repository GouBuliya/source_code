#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
const int maxm=5e5+10;
struct edge
{
    int v;
    int w;
};
vector<edge>G[maxn];
int dis[maxn];
int vis[maxn];
int cut[maxn];
bool spfa(int st,int n)
{
    for(int i=0;i<=n;++i)
        dis[i]=0x7fffffff;
    queue<int>que;
    dis[st]=0;vis[st]=1;
    que.push(st);
    while(!que.empty())
    {
        int u=que.front();
        que.pop(),vis[u]=0;
        for(auto &[v,w]:G[u])
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                cut[v]=cut[u]+1;
                if(cut[v]>=n)return false;
                if(!vis[v])que.push(v),vis[v]=true;
            }
    }
    return true;
}
int re ()
{
    int t;
    cin>>t;
    return t;
}
signed main ()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n=re(),m=re(),s=re();
    for(int i=1;i<=m;++i)
    {
        int u=re(),v=re(),w=re();
        G[u].push_back({v,w});
    }
    if(spfa(s,n))
        for(int i=1;i<=n;++i)
            cout<<dis[i]<<" ";
}
