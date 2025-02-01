#include<bits/stdc++.h>
#define ll long long
#define pn cout<<'\n';
#define endl '\n'
#define mset(st,x) memset(st,x,sizeof st)
#define mcpy(st,b) memcpy(st,b,sizeof st)
#define all(st) st.begin(),st.end()
#define fls() fflush(stdout)
namespace my {
    const int INF = (1 << 30);
    inline int re()
    {
        int x = 0, f = 1;char ch = getchar();
        while (ch < '0' || ch>'9') { if (ch == '-') f = -1;ch = getchar(); }
        while (ch >= '0' && ch <= '9') { x = x * 10 + ch - 48;ch = getchar(); }
        return x * f;
    }
    struct ST
    {
        const int t = 20;
        std::vector<std::vector<int>>st;
        void st_init(std::vector<int>b)
        {
            st.resize(t, std::vector<int>(b.size()));
            for (int i = 1;i <= b.size() - 1;i++)
                st[0][i] = b[i];
            for (int j = 1;j <= 18;j++)
                for (int i = 1;i + (1 << j) - 1 <= b.size();i++)
                    st[j][i] = std::max(st[j - 1][i], st[j - 1][i + (1 << j - 1)]);
        }
        int get(int l, int r)
        {
            int k = std::__lg(r - l + 1);
            return std::max(st[k][l], st[k][r - (1 << k) + 1]);
        }
    };
    void solve()
    {
        int n = re();int m = re();
        std::vector<int>A(n + 1);
        ST st;
        for (int i = 1;i <= n;++i)
        {
            A[i] = re();
        }
        st.st_init(A);
        for (int i = 1;i <= m;++i)
        {
            int l = re(), r = re();

            std::cout << st.get(l, r) << endl;
        }
    }
}
signed main()
{
    int t = 1;while (t--)my::solve();return 0;
}