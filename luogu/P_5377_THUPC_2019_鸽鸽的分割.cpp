#include<bits/stdc++.h>
#define ll long long
#define pn cout<<'\n';
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
namespace my{
const int INF=(1<<30);
ll re ()
{ ll t; std::cin>>t;return t;}
signed main()
{int n;
    while(std::cin >> n)
		if(n==0LL || n==1LL)	printf("1\n");
		else printf("%lld\n", 1+n*(n-1)/2+n*(n-1)*(n-2)*(n-3)/4/3/2/1);
    return 0;
}}
signed main()
{return my::main();}