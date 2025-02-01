#include<bits/stdc++.h>
#define ll long long
#define pn cout<<'\n';
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
#define int long long
namespace my{
const int INF=(1<<30);
ll re ()
{ ll t; std::cin>>t;return t;}
void solve()
{
    int n=re();
    int l=re();
    int r=re();
    std::vector<int>A(n+1);
    for(int i=1;i<=n;++i)
        A[i]=re();
    std::sort(A.begin()+1,A.begin()+l);
    std::sort(A.begin()+l,A.begin()+r+1);
    std::sort(A.begin()+r+1,A.begin()+n+1);
    int tot=0;
    for(int i=l;i<=r;++i)
    {
        tot+=A[i];
    }
    for(int i=1;i<l&&i<=r-l+1;++i)
    {
        if(A[i]<A[r-i+1])
            tot+=A[i]-A[r-i+1];
    }
    int ans=0;
    for(int i=l;i<=r;i++)
    {
        ans+=A[i];
    }
    for(int i=1;i<=n-r&&i<=r-l+1;++i)
    {
        if(A[r+i]<A[r-i+1])
        {
            ans+=A[r+i]-A[r-i+1];
        }
    }
    std::cout<<std::min(ans,tot)<<std::endl;
}
}
signed main()
{std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t=my::re();while(t--)my::solve();return 0;}