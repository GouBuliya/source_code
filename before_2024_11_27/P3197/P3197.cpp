/*************************************************************************
	> File Name: P3197.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Sat Jul 13 00:02:11 2024
 ************************************************************************/

#include<iostream>
using namespace std;
#define ll long long
const int mod = 100003;
inline ll pow(ll a)
{
	return (a*a)%mod;
}
ll n,m;
inline ll qpow(ll a,ll b)
{
	if(b==0)return 1;
	return (b&1)?pow(qpow(a,b>>1))*(a%mod)%mod:pow(qpow(a,b>>1));
}
signed main ()
{
	ll n,m;
	cin>>m>>n;
	ll U = qpow(m,n);
	ll CuA = 1ll*m * qpow(m-1,n-1);
	int ans=(U-CuA)%mod;
	if(ans<0)
	{
		ans+=mod;
	}
	cout<<ans<<endl;

	}
// #include<cstdio>
// #include <iostream>
// #define ll long long
// using namespace std;
// const ll mod=100003ll;
// inline int read()
// {
// 	char ch=getchar();
// 	int x=0,f=1;
// 	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
// 	while(ch>='0'&&ch<='9')
// 	{
// 		x=(x<<1)+(x<<3)+ch-'0';
// 		ch=getchar();
// 	}
// 	return x*f;
// }
// inline ll pow(ll a)
// {
// 	return (a*a)%mod;
// }
// ll n,m;
// inline ll qmi(ll a,ll b)
// {
// 	if(b==0)return 1;
// 	return (b&1)?pow(qmi(a,b>>1))*(a%mod)%mod:pow(qmi(a,b>>1));
// }
// int main()
// {
// 	scanf("%lld%lld",&m,&n);
// 	ll ans=qmi(m,n)-(m%mod)*qmi(m-1,n-1)%mod;
// 	while(ans<0)ans+=mod;
// 	ans%=mod;
// 	printf("%lld",ans);
// 	cout<<qmi(m,n)<<endl<<m*qmi(m-1,n-1)<<endl;
// 	return 0;
// }
