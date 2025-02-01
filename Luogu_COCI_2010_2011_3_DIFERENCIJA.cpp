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
        std::vector<int>A(n + 2);
        for (int i = 1;i <= n;++i)
        {
            std::cin >> A[i];
        }
        std::vector<int>st;
        std::vector<int>Lmax(n + 1, 0);
        std::vector<int>Lmin(n + 1, 0);
        std::vector<int>Rmin(n + 1, n + 1);
        std::vector<int>Rmax(n + 1, n + 1);
        for (int i = 1;i <= n;++i)
        {
            while (!st.empty() && A[i] >= A[st.back()])
            {

                st.pop_back();
            }
            if (!st.empty())Lmax[i] = st.back();
            st.push_back(i);

        }
        st.clear();
        for (int i = 1;i <= n;++i)
        {
            while (!st.empty() && A[i] <= A[st.back()])
            {

                st.pop_back();
            }
            if (!st.empty())Lmin[i] = st.back();
            st.push_back(i);


        }
        st.clear();
        for (int i = n;i >= 1;--i)
        {
            while (!st.empty() && A[i] > A[st.back()])
            {

                st.pop_back();
            }
            if (!st.empty())Rmax[i] = st.back();
            st.push_back(i);

        }
        st.clear();
        for (int i = n;i >= 1;--i)
        {
            while (!st.empty() && A[i] < A[st.back()])
            {

                st.pop_back();
            }
            if (!st.empty())Rmin[i] = st.back();
            st.push_back(i);


        }
        
        int ans = 0;
        for (int i = 1;i <= n;++i)
        {
            ans += (i - Lmax[i]) * (Rmax[i] - i) * A[i];
        }
        for (int i = 1;i <= n;++i)
        {
            ans -= (i - Lmin[i]) * (Rmin[i] - i) * A[i];

        }
        std::cout << ans << endl;

    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}

/**/