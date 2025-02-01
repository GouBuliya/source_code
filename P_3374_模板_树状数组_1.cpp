#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pn cout<<'\n';
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
namespace my {
    const int INF = (1 << 30);
    ll re()
    {
        ll t; std::cin >> t;return t;
    }
    int n, m;
    std::vector<int>tree;
    void cha(int x, int y)
    {
        for (int i = x;i <= n;i += i & -i)
            tree[i] += y;
    }
    void cha(int l, int r, int x)
    {
        cha(l, x);
        cha(r + 1, -x);
    }
    int fi(int x)
    {
        int ret = 0;
        for (int i = x;i;i -= i & -i)
            ret += tree[i];
        return ret;
    }
    int fi(int l, int r)
    {
        return fi(r) - fi(l - 1);
    }

    void solve()
    {
        n = re();
        m = re();
        tree.resize(n+1);
        for (int i = 1;i <= n;++i)
        {
            int t = re();
            cha(i, t);
        }
        for (int i = 1;i <= m;++i)
        {
            int op = re();
            if (op == 1)
            {
                int x = re();
                int k = re();
                cha(x, k);
            }
            else
            {
                int x = re();
                int y = re();
                std::cout << fi(x, y) << endl;
            }
        }

    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}