#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pn cout<<'\n';
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
#define int long long
namespace my {
    const int INF = (1 << 30);
    ll re()
    {
        ll t; std::cin >> t;return t;
    }
    void solve()
    {
        int n=re(),k=re();
        std::vector<int>A(n+1);
        std::vector<int>ans(n+1);
        for(int i=1;i<=n;++i)
        std::cin>>A[i];

        std::deque<int>dq;
        for(int i=1;i<=n;++i)
        {
        while(dq.size()&&dq.front()<=i-k)dq.pop_front();
        while(dq.size()&&A[dq.back()]>=A[i])
        dq.pop_back();
        dq.push_back(i);
        ans[i]=A[dq.front()];
        } //单调上升
        for(int i=0;i<n;++i)
        {
            std::cout<<ans[i]<<endl;
        }
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}