#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
const int maxn = 3 * 1e5 + 7;
int n;
int Li[maxn],Lx[maxn],Ri[maxn],Rx[maxn];
int A[maxn];
stack<int>st;

int la=1,ra=1,lb=1,rb=1;
signed main ()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>A[i];
	for(int i=1;i<=n;i++)
	{
		while (!st.empty()&&A[st.top()]<=A[i])
		{
			st.pop();
		}
		if(st.empty())Lx[i]=0;
		else Lx[i]=st.top();
		st.push(i);
	}
	while (!st.empty())st.pop();
	for(int i=1;i<=n;i++)
	{
		while (!st.empty()&&A[st.top()]>=A[i])
		{
			st.pop();
		}
		if(st.empty())Li[i]=0;
		else Li[i]=st.top();
		st.push(i);	
	}
	while(!st.empty())st.pop();
	for(int i=n;i>=1;i--)
	{
		while (!st.empty()&&A[st.top()]>A[i])
		{
			st.pop();
		}
		if(st.empty())Ri[i]=n+1;
		else Ri[i]=st.top();
		st.push(i);
	}
	while(!st.empty())st.pop();
	for(int i=n;i>=1;i--)
	{
		while (!st.empty()&&A[st.top()]<A[i])
		{
			st.pop();
		}
		if(st.empty())Rx[i]=n+1;
		else Rx[i]=st.top();
		st.push(i);
	}
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		ans+=A[i]*(i-Lx[i])*(Rx[i]-i);
		ans-=A[i]*(i-Li[i])*(Ri[i]-i);
	}

	cout<<ans<<endl;
}
