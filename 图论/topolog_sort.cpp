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
const int maxn=1e4+19;
vector<int>G[maxn];
int in[maxn];
int n,p;
vector<int>tll_seq;
bool tll()
{
    queue<int>q;
    for(int i=1;i<=n;++i)
        if(in[i]==0)
            q.push(i);
    while(!q.empty())
        {
            int u=q.front();
            q.pop();tll_seq.push_back(u);
            cout<<u<<endl;
            for(auto &i: G[u])
                if(--in[i]==0)
                    q.push(i);
        }
    if(q.size()==n)
        return 1;
    else 
        return 0;
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
    for(int i=1;i<=p;++i)
    {
        int u=re();
        int v=re();
        G[u].push_back(v);
        in[v]++;
    }
    tll();
    for(auto &i:tll_seq)
        cout<<i<<" "<<endl;
    return 0;
}

