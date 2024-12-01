#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int re()
{
    int t;
    cin>>t;
    return t;
}
int n,m;
const int maxn=5e3+10;
vector<pair<int,int>>G[maxn];
int dis[maxn];
int vis[maxn];
int cut[maxn];
signed main ()
{
    n=re();m=re();
    for(int i=1;i<=m;++i)
    {
        int u=re(),v=re(),w=re();
        G[v].push_back(pair<int,int>(u,w));
    }
    for(int i=1;i<=n;++i)
        G[0].push_back(pair<int,int>(i,0));
    for(int i=0;i<=n;++i)
        dis[i]=2147481166;
    queue<int>que;
    que.push(0);
    dis[0]=0;
    vis[0]=1;
    while(!que.empty())
    {
        int u=que.front();
        vis[u]=0;
        que.pop();
        for(auto [v,w]:G[u])
        {
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(!vis[v])
                {
                que.push(v);
                vis[v]=true;
                cut[v]++;
                if(cut[v]>=n)
                {
                    cout<<"NO"<<endl;return 0;
                }
                }
            }
        }
    }
    for(int i=1;i<=n;++i)
        cout<<dis[i]<<" ";
                
}
