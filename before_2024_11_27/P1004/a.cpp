#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp1 cout<<1<<endl;
int re()
{
        int t;
        cin>>t;
        return t;
}
const int maxn=10;
int A[maxn][maxn];
int f[maxn][maxn];
int g[maxn][maxn];

signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n=re();
    int x,y,v;
    while(cin>>x&&cin>>y&&cin>>v&&x&&y&&v)
    {
        A[x][y]+=v;
    }
        
    for(int i=1;i<=n;++i)
    {
        for(int j=n;j>=1;--j)
        {
            f[i][j]=max(f[i-1][j],f[i][j+1])+A[i][j];
        }
    }

    return 0;
}
