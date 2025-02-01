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
    std::vector<std::vector<int>>A;
    std::vector<std::vector<int>>B;
    std::vector<std::vector<int>>l;
    std::vector<std::vector<int>>r;
    int ans = 0;
    std::vector<std::vector<int>>siz;
    void DFS(int p, int i)
    {
        if (p == 0)return;
        if (l[i][p] != 0) { DFS(l[i][p], i); }
        if (r[i][p] != 0) { DFS(r[i][p], i); }
        if (l[i][p] != 0) siz[i][p] += siz[i][l[i][p]];
        if (r[i][p] != 0) siz[i][p] += siz[i][r[i][p]];
        ans = std::max(ans, (siz[i][p] * B[i][p]));
    }
    void solve()
    {
        int n = re();
        int m = re();
        A.resize(n + 1, std::vector<int>(m + 1));
        B.resize(n + 1, std::vector<int>(m + 1));
        siz.resize(n + 1, std::vector<int>(m + 1, 0));
        l.resize(n + 1, std::vector<int>(m + 1, 0));
        r.resize(n + 1, std::vector<int>(m + 1, 0));
        for (int i = 1;i <= n;++i)
            for (int j = 1;j <= m;++j)
            {
                std::string s;
                std::cin >> s;
                A[i][j] = (s == "F");
            }
        for (int i = 1;i <= n;++i)
            for (int j = 1;j <= m;++j)
                B[i][j] = A[i][j] ? B[i - 1][j] + 1 : 0;
      
        for (int i = 1;i <= n;++i)
        {
            std::vector<int>sk(m + 1,0);
            int top = 0;
            for (int j = 1;j <= m;++j)
            {
                siz[i][j] = 1;
                int k = top;
                while (k > 0 && B[i][sk[k]] > B[i][j])
                {
                    k--;
                }
                if (k != 0)
                {
                    r[i][sk[k]] = j;
                }
                if (k < top)
                {
                    l[i][j] = sk[k + 1];
                }
                sk[++k] = j;
                top = k;
            }
            DFS(sk[1],i);
        }
        std::cout << ans * 3 << endl;
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}