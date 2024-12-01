#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int re()
{
    int t;
    cin>>t;
    return t;
}
const int maxn=1e4+10;

vector<pair<int,int>>G[maxn];
vector<int>A[maxn];
vector<int>B[maxn];
bool F[maxn];
bool T[maxn];
bool vis[maxn];
int dis[maxn];
int cut[maxn];
int U[maxn],V[maxn];
signed main ()
{
    int n=re(),m=re();
    for(int i=1;i<=m;++i)
    {
        int u=re(),v=re();
        A[u].push_back(v);
        B[v].push_back(u);
        U[i]=u;
        V[i]=v;
    }
    //第一遍spFA
    queue<int>que;
    F[1]=1;
    que.push(1);
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        for(auto v:A[u])
            if(!F[v])
            {
                F[v]=true; 
                que.push(v);
            }
    }
    if(!F[n])
    {
        cout<<-1<<endl;
        return 0;
    }
    //第2遍spFA
    while(!que.empty())que.pop();
    T[n]=1;
    que.push(n);
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        for(auto v:B[u])
            if(!T[v])
            {
                T[v]=1;
                que.push(v);
            }
    }
    for(int i=1;i<=m;++i)
    {
        int u=U[i];int v=V[i];
        if(!F[u]||!T[u])
            continue;
        G[v].push_back(pair<int,int>{u,-1});
        G[u].push_back(pair<int,int>(v,9));
    }
    for(int i=1;i<=n;++i)
        G[0].push_back(pair<int,int>(i,0));
    for(int i=0;i<=n;++i)
        dis[i]=2147481666;
    while(!que.empty())que.pop();
    dis[0]=0;
    vis[0]=1;
    que.push(0);
    while(!que.empty())
    { 
        int u=que.front();
        vis[u]=0;
        cut[u]++;
        if(cut[u]>2*m)
        {
            cout<<-1<<endl;
            return 0;
        }
        que.pop();
        for(auto [v,w]:G[u])
        {
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(!vis[v])
                {
                    que.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    cout<<n<<" "<<m<<endl;
    for(int i=1;i<=m;++i)
    {
        int u=U[i];
        int v=V[i];
        cout<<u<<" "<<v<<" ";
        if(!F[u]||!T[u])
            cout<<9<<endl;
        else 
        {
            cout<<dis[v]-dis[u]<<endl;
        }
    }

}
