#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int INF=(1<<31);
ll re ()
{
    ll t;
    cin>>t;
    return t;
}
const int maxn=220;
int G[maxn][maxn];
int f[maxn][maxn];
int n,m;
int t[maxn];
int b[maxn];
signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    n=re(),m=re();
    for(int i=0;i<=n;++i)
        for(int j=0;j<=n;++j)
            G[i][j]=f[i][j]=(i==j)?0:INT_MAX;
    for(int i=0;i<n;++i)
        cin>>t[i];
    for(int i=1;i<=m;++i)
    {
        int u=re(),v=re(),w=re();
        G[u][v]=G[v][u]=w;
        f[u][v]=f[v][u]=w;
    }
    int Q=re();
    for(int l=1;l<=Q;++l)
    {
        int u=re(),v=re(),T=re();
        for(int k=0;k<n;++k)
            if(t[k]<=T&&!b[k])
            {
                b[k]=1;
                for(int i=0;i<n;++i)
                    for(int j=0;j<n;++j)
                        if(f[i][j]>f[i][k]+f[k][j]&&i!=k&&j!=k&&i!=j&&f[i][k]<INT_MAX&&f[k][j]<INT_MAX)
                            f[i][j]=f[i][k]+f[k][j];
            }
        if(f[u][v]==INT_MAX||t[u]>T||t[v]>T)
            cout<<-1<<endl;
        else 
            cout<<f[u][v]<<endl;
    }

    
    return 0;
}

