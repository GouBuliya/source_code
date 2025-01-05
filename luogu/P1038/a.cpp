#include<bits/stdc++.h>
#include <cmath>
using namespace std;
#define ll long long 
const int INF=(1<<31);
ll re ()
{
    ll t;
    cin>>t;
    return t;
}
const int maxn=110;
vector<tuple<int,int>>G[maxn];
vector<tuple<int,int>>F[maxn];
int U[maxn];
int op[maxn];
int  in[maxn];
int  out[maxn];
int n,p;
vector<int>tll_in;
vector<int>tll_out;
int In[maxn];
bool topological()
{

    queue<int>q;
    for(int i=1;i<=n;++i)
        if(in[i]==0)q.push(i);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        tll_in.push_back(u);
        
        for(auto &V:G[u])
        {
            auto [v,w]=V;
            if(--in[v]==0)
                q.push(v);
        }
    }
    if(q.size()==n)
        return 1;
    else 
        return 0;
}
void solve()
{
    for(int k=0;k<=n;k++)
    {
        int i=tll_in[k];
        if(In[i]==0)
            continue;
        int ans=0;
        ans-=U[i];
        for(auto &j:F[i])
        {
            auto [v,w]=j;
            if(op[v]>0)
            ans+=w*op[v];
        }
        op[i]=ans;
        if(op[i]>0&&out[i]==0)
        {
            cout<<i<<" "<<op[i]<<endl;
        }
    }
}
signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    n=re(),p=re();
    for(int i=1;i<=n;i++)
        op[i]=re(),U[i]=re();
    for(int i=1;i<=p;++i)
        {
            int u=re(),v=re(),w=re();
            G[u].push_back(pair<int,int>{v,w});
            F[v].push_back(pair<int,int>{u,w});
            out[u]++;
            in[v]++;
            In[v]++;
        }
    topological();
//    for(int i=0;i<=n;++i)
//        cout<<tll_in[i]<<" ";
    solve();
    
    return 0;
}
