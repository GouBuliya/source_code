#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
using namespace std;
int re()
{
    int x=0,t=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*t;
}
const int maxn=1e5;
vector<pair<int,int>>G[maxn];
queue <int>q;
bool vis[maxn];
int ans=0;
void BFS(int u)
{
    q.push(u);
    vis[u]=1;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(auto [v,k]:G[u])
        {
            if(!vis[v])
            {
                ans=max(ans,k);
                q.push(v);
            }
        }
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int m=re();
    for(int i=1;i<=m;++i)
    {
        int u=re();
        int v=re();
        int k=re();
        G[u].push_back({v,k});
    }
    BFS(1);
    cout<<ans<<endl;
    return 0;
}
                                                                                                                                                                                  
