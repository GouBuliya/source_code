#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int INF=(1<<30);
ll re ()
{
    ll t;
    cin>>t;
    return t;
}
const int maxn=1e4+10;
int dis[maxn];
int cnt[maxn];
bool vis[maxn];
vector<tuple<int,int>>G[maxn];
bool spfa(int begin,int n)
{
    for(int i=0;i<=n;++i)
        dis[i]=INF;
    queue<int>q;
    q.push(begin);
    vis[begin]=1;
    dis[begin]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(auto &i : G[u])
        {
            auto [v,w]=i;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u]+1;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
                if(cnt[v]>n)
                return 0;
            }
            
        }
    }
    return 1;
    }
signed main ()
{
#ifndef ONLINE_JUDGE
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n=re(),m=re(),s=re();
    for(int i=1;i<=m;++i)
    {
        int u=re(),v=re(),w=re();
        G[u].push_back({v,w});
    }
    if(spfa(s,n))
    for(int i=1;i<=n;++i)
        cout<<dis[i]<<" ";
    else 
        cout<<(1<<31)<<endl;
    return 0;
}

