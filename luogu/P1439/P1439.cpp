#include <bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
int re()
{
    int x = 0, t = 1;
    char ch = getchar();
    // printf("%c\n",ch);
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x * t;
}
int arr_A[100001];
int arr_B[100001];
int map_arr_A[100001];
int map_arr_B[100001];
int dp[100001];
signed main()
{
#ifndef ONLINE_JUDGE
// freopen("in.txt","r",stdin);
#endif
    // int N=re();
    int N;
    cin >> N;
    for (size_t i = 1; i <= N; ++i)
    {
        arr_A[i] = re();
        map_arr_A[arr_A[i]] = i;
        // arr_B[i]=re();
    }
    for (size_t i = 1; i <= N; ++i)
    {
        // arr_A[i]=re();
        arr_B[i] = re();
        map_arr_B[i] = map_arr_A[arr_B[i]];
    }
    // pn;pn;pn;

    for (int i = 0; i <= N; ++i)
    {
        dp[i] = 0x7fffffff;
    }
    int ans;
    int l = 0, mid;
    ans = 0;
    int r = ans;
    dp[0] = 0;
    for(int i=1;i<=N;i++)
	{
		int l=0,r=ans,mid;
		if(map_arr_B[i]>dp[ans])dp[++ans]=map_arr_B[i];
		else 
		{
		while(l<r)
		{	
		    mid=(l+r)/2;
		    if(dp[mid]>map_arr_B[i])r=mid;
			else l=mid+1; 
		}
		dp[l]=min(map_arr_B[i],dp[l]);
     	}
    }

    // for(int i=1;i<=N;++i)
    // {
    //     ans=max(ans,dp[i]);
    // }
    cout << ans;
    return 0;
}
