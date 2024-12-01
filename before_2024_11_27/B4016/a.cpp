#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+10;
vector<int> ga[maxn];
int n;
int k=0;
int maxdef=0;
bool vis[maxn];
void dfs(int def,int u)
{
    vis[u]=1;
    if(maxdef<def)
    {
        maxdef=def;
        k=u;
    }
    for(auto &i:ga[u])
    {
        if(!vis[i])
        {
            dfs(def+1,i);
        }
    }
}
signed main ()
{
    freopen("./in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    int u,v;
    for(int i=1;i<=(n-1);++i)
    {cin>>u>>v;
        ga[u].push_back(v),
        ga[v].push_back(u);
    }
   dfs(0,1);
    maxdef=0;
    memset(vis,0,sizeof(vis));
    dfs(0,k);
    cout<<maxdef<<endl;
    fclose(stdin);
}
