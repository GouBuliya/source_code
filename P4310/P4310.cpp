#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
using namespace std;
int re()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*t;
}
int dp[51][51];
signed main()
{
	#ifndef ONLINE_JUDGE
	// freopen("in.txt","r",stdin);
	#endif
	string str;
	cin>>str;
	int N =str.size();
	memset(dp,0x7f,sizeof dp);
	for(int len=0;len<N;++len)
	{
		for(int l=1;l+len<=N;++l)
		{
			int r=l+len;
			if(r==l)
			{
				dp[l][r]=1;	
			}
			else if(str[r-1]==str[l-1])
			{
				dp[l][r]=min(dp[l+1][r],dp[l][r-1]);
			}
			else
			{
				for(int k=l;k<r;++k)
				{
					dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
				}
			}
		}
	}
	cout<<dp[1][N]<<endl;
	return 0;
}
																																												  
