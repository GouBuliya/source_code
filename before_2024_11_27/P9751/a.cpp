#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
const int maxm=2e4+19;
vector<pair<int,int>>G[maxn];
int dis[maxn][110];
bool vis[maxn][110];
int n,m,k;
int re ()
{
    int t;
    cin>>t;
    return t;
}
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    n=re(),m=re(),k=re();
    for(int i=1;i<=m;++i)
    {
        int u=re(),v=re(),w=re();
        G[u].push_back(pair<int,int>(v,w));
    }
    memset(dis,0x7f,sizeof(dis));
    priority_queue<pair<int ,int >,vector<pair<int,int>>,greater<pair<int,int>>>que;
    dis[1][0]=0;

    que.push(pair<int,int>{0,1});//seconed 是端点，first是w
    while(!que.empty())
    {
        int p=que.top().first;int u=que.top().second;
        que.pop();
        if(vis[u][p%k])
            continue;
        vis[u][p%k]=1;
        for(auto i:G[u])
        {
            int v=i.first;
            int w=i.second;
            if(p>=w)
            {
                dis[v][(p+1)%k]=min(p+1,dis[v][(p+1)%k]);
                que.push(pair<int,int>(p+1,v));
            }
            else 
            {
                int t=((w-p+k-1)/k)*k+p;
                dis[v][(t+1)% k]=min(t+1,dis[v][(t+1)% k]);
                que.push(pair<int,int>(t+1,v));
            }
        }
    }
    if(!vis[n][0])
    {
        cout<<"-1"<<endl;
    }
    else 
    {
        cout<<dis[n][0]<<endl;
    }
}
//对于每个点,
//if(p>=w)即当前时刻这个点开放
//{
//dis[i][(p+1)modk]=min(p+1,dis[i][(p+1)mod k];
//}
//else 即当前时刻这个点不开放
//{
//等待j个k时刻
//令t=((w-p+k-1)/k)*k+p;
//则dis[i][(t+1)mod k]=min(t+1,dis[i][(t+1)mod k]
//
