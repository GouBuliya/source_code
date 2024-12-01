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
}void solve()
{
	int n,k; cin>>n>>k;
	int l=k-1,r=n-k;
	if(l%2!=r%2) {cout<<-1<<endl; return;}
	if((!l&&r)||(!r&&l)) {cout<<-1<<endl; return;}
	if(n==1)
	{
		cout<<1<<endl;
		cout<<1<<endl;
	}
	else if(l%2==0&&r%2==0)
	{
		cout<<5<<endl;
		cout<<1<<" "<<k-1<<" "<<k<<" "<<k+1<<" "<<k+2<<endl;
	}
	else if(l%2!=0&&r%2!=0)
	{
		cout<<3<<endl;
		cout<<1<<" "<<k<<" "<<k+1<<endl;
	}
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int t=re();
    while(t--)
        solve();
    return 0;
}
                                                                                                                                                                                  

