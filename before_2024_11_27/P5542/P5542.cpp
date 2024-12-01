#include <bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
    const int maxn = 1005;
    int NN, KK;
    int diff[maxn][maxn];
    int A[maxn][maxn];
signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> NN >> KK;
    int x1, y1, x2, y2;
    int fx,fy,tx,ty;
    for (int i = 1; i <= NN; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        // x1++;y1++;
        // diff[x1 ][y1 ]++;
        // diff[x2+1 ][y2+1 ]++;
        // diff[x1 ][y2+1 ]--;
        // diff[x2+1 ][y1 ]--;
        fx = x1+1; fy = y1+1; tx = x2; ty = y2;
		diff[fx][fy]++;
		diff[tx + 1][ty + 1]++;
		diff[fx][ty + 1]--;
		diff[tx + 1][fy]--;
    }
    ll ans = 0;
    for (int i = 1; i <= 1000; ++i)
    {
        for (int j = 1; j <= 1000; ++j)
        {
            // diff[i][j]+=diff[i-1][j]+diff[i][j-1]-diff[i-1][j-1];
            // A[i][j]=A[i][j-1]+A[i-1][j]-A[i-1][j-1]+diff[i][j];
            A[i][j] = A[i][j - 1] + A[i - 1][j] - A[i - 1][j - 1] + diff[i][j];
            if (A[i][j] = KK)
                ans++;
            cout<<diff[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << ans << endl;
    return 0;
}
// #include<iostream>
// using namespace std;
// int n,k,ans,c[1010][1010],a[1010][1010];
// //n,k意义如题，ans是答案，c是差分数组，a是原数组
// int main()
// {
// 	cin>>n>>k;
// 	for(int i=1;i<=n;i++)
// 	{
// 		int x1,y1,x2,y2;
// 		cin>>x1>>y1>>x2>>y2;
// 		c[x1][y1]++;//二维差分区间加
// 		c[x2][y2]++;//
// 		c[x1][y2]--;//
// 		c[x2][y1]--;//
// 	}
// 	for(int i=0;i<=1005;i++)
// 		for(int j=0;j<=1005;j++)
// 		{
// 			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+c[i][j];//前缀和的递推式
// 			if(a[i][j]==k)ans++;//恰被覆盖k次，统计
// 		}
// 	cout<<ans<<endl;
// 	return 0;
// }
// #include<iostream>
// #include<cstdio>

// using namespace std;

// const int maxn = 1005;

// int n, k, ans;
// int fx, tx, fy, ty;
// int a[maxn][maxn], sum[maxn][maxn];

// inline int read(void)
// {
// 	int s = 0, w = 1;
// 	char ch = getchar();
// 	for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') w = -1;
// 	for(; ch <= '9' && ch >= '0'; ch = getchar()) s = s * 10 + ch - '0';
// 	return s * w;
// }

// int main()
// {
// 	n = read(); k = read();
// 	for(register int i = 1; i <= n; i++)
// 	{
// 		fx = read() + 1; fy = read() + 1; tx = read(); ty = read();
// 		a[fx][fy]++;
// 		a[tx + 1][ty + 1]++;
// 		a[fx][ty + 1]--;
// 		a[tx + 1][fy]--;
// 	}
// 	for(register int i = 1; i <= 1001; i++)
// 	{
// 		for(register int j = 1; j <= 1001; j++)
// 		{
// 			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
// 			if(sum[i][j] == k) ans++;
//             cout<<a[i][j]<<" ";
// 		}
//         cout<<endl;
// 	}
// 	cout << ans << '\n';
// 	return 0;
// }