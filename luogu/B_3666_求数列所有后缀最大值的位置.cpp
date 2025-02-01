#include<bits/stdc++.h>
#define ll long long
#define pn cout<<'\n';
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
#define int unsigned long long
namespace my{
const int INF=(1<<30);  
ll re ()
{ ll t; std::cin>>t;return t;}
void solve()
{
    int t=re();
    int ans=0;
std::stack<int>st;
int arr[1000007];
    for(int i=1;i<=t;++i)
    {
        arr[i]=re();
        while (!st.empty()&&arr[st.top()]<=arr[i]){ans^=st.top(),st.pop();}
        st.push(i);
        ans^=i;
        std::cout<<ans<<std::endl;
    }
}
}
signed main()
{std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t=1;while(t--)my::solve();return 0;} 