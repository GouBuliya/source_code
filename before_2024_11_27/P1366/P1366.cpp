#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long 
const int maxn = 10000005;
uint64_t A[10000001], B[10000001];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{

		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			cin >> A[i];
	for (int i = 1; i <= m; ++i)
			cin >> B[i];


		int j=1;
		int ANS=0;
		int i=1;
		for(int i=1;i<=n;++i)
		{
			int ans=0;
			while(j<=m&&A[i]>=B[j])
			{
				ans+=(A[i]==B[j]);
				j++;
			}
			ANS^=ans;
		}
		cout<<ANS<<'\n';

	}
}