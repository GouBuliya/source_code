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
        int n = re();
        std::vector<int>A(n + 1);
        std::vector<int>sk(n + 1);
        std::vector<int>l(n + 1);
        std::vector<int>r(n + 1);
        for (int i = 1;i <= n;++i)
        {
            std::cin >> A[i];

        }
        int k = 0;
        int top = 0;
        for (int i = 1;i <= n;++i)
        {
            int k = top;
            while (k > 0 && A[sk[k]] > A[i])k--;
            if (k)r[sk[k]] = i;
            if (k < top)l[i] = sk[k + 1];
            sk[++k] = i;
            top = k;
        }
        int lans=0,rans= 0;
        for (int i = 1;i <= n;++i)
            lans ^= i * (l[i] + 1),rans ^= i * (r[i] + 1);
        std::cout << lans << " " << rans << endl;

    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}