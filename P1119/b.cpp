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
int t[maxn];
bool beedge[maxn];
int n,m;
int tlist[maxn];
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
            G[i][j]=G[j][i]=f[i][j]=f[j][i]=INT_MAX;
    for(int i=0;i<n;++i)
        t[i]=re();
    for(int i=1;i<=m;++i)
    {
        int u=re(),v=re(),w=re();
        G[u][v]=w;
        G[v][u]=w;
    }
        int Q=re();

        int k=0; 
        for(int i=0;i<=n;++i)
            for(int j=0;j<=n;++j)
             f[i][j]=(i==j)?0:INT_MAX;
    for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(beedge[i]&&beedge[j])
                    f[i][j]=f[j][i]=G[i][j];
    for(int l=1;l<=Q;++l)
    {
        int s=re(),e=re(),T=re();
            for(int k=0;k<n;++k)
                if(t[k]<=T&&!beedge[k])
                {beedge[k]=1;
                for(int i=0;i<n;++i)
                    for(int j=0;j<n;++j)
                        if(f[i][j]>f[i][k]+f[k][j]&&i!=j&&k!=i&&k!=j&&f[i][k]<INT_MAX&&f[k][j]<INT_MAX)
                        f[i][j]=f[i][k]+f[k][j];
                }
        if(f[s][e]==INT_MAX)
            cout<<-1<<endl;
        else
            cout<<f[s][e]<<endl;

    }
    return 0;
}
/*整体思路就是对于每个询问，由于t的单调性，可对每个询问取最大的t，遍历（弗洛伊德）小于t的edge*/
