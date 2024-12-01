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
const int maxn=1e3+10;
ll A[maxn][maxn];
ll f[maxn][maxn][2];

signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    #endif
	int n=re(),m=re();
	for(int j=1;j<=n;++j)
		for(int i=1;i<=m;++i)
			A[j][i]=re();

	for(int j=1;j<=n;++j)
	{
		f[j][1][1]=f[j-1][1][1]+A[j][1];
        f[j][1][0]=-1e18;
	}
	// }for(int i=1;i<=n;++i)
	// 	for(int j=1;j<=m;++j)
	// 		cout<<f[i][j][0]<<" "<<f[i][j][1]<<endl;
	for(int i=2;i<=m;++i)
	{

		for(int j=n;j>=1;--j)
		{
			ll w1=max(f[j][i-1][1],f[j][i-1][0]);
			ll w2=j==n?-1e18:f[j+1][i][0];
			f[j][i][0]=max(w1,w2)+A[j][i];
		}
		for(int j=1;j<=n;j++)
		{
			ll w1=max(f[j][i-1][1],f[j][i-1][0]);
			ll w2=j==1?-1e18:f[j-1][i][1];
			f[j][i][1]=max(w1,w2)+A[j][i];
		}
	}
	
	
// cout<<"i:";
// 	for(int i=1;i<=n;++i)
// 		printf("向上 %4lld 向下 %4lld",i,i);
// cout<<endl;
// 	for(int i=1;i<=n;i++)
// 	{
// 		cout<<i<<":";
// 		for(int j=1;j<=m;++j)
// 		{
// 			printf("向上 %4lld 向下 %4lld",f[i][j][0],f[i][j][1]);
// 		}
// cout<<endl;
// 	}
	cout<<f[n][m][1]<<endl;
    return 0;
}
