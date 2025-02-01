#include<bits/stdc++.h>
#define ll long long
#define pn cout<<'\n';
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
const int INF=(1<<30);
using namespace std;
ll re ()
{ ll t; std::cin>>t;return t;}
const int maxn=2e5+19;
std::vector<int>e[maxn];
void gx(int &x,int y){if(y>x)x=y;}
void lx(int &x,int y){if(y<x)x=y;}
int ans=0;
int dfs(int p,int fa)
{
    int mx=-1e9;
    for(int v:e[p])
    {
        int size=e[v].size();
        if(v==fa)
        continue;
        int t=dfs(v,p);
        gx(ans,e[p].size()+max((int)e[v].size()-1,t));
        gx(ans,mx+max(t,size));
        gx(mx,max(t,size));

    }
    return mx;

}
void solve()
{

    int n=re();
    for(int i=1;i<=n;++i)
    {
        e[i].clear();
    }
    for(int i=1;i<n;++i)
    {
        int u=re();
        int v=re();
        e[u].push_back(v);
        e[v].push_back(u);
    
    }
     ans=0;
    dfs(1,0);
    std::cout<<ans-1<<std::endl;
}
signed main()
{std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t=re();while(t--)solve();return 0;}