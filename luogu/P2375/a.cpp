#include<bits/stdc++.h>
namespace my {
#define ll long long 
#define pn cout<<"\n";
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
    const int INF = (1 << 30);
    ll re()
    {
        ll t;
        std::cin >> t;
        return t;
    }
    signed main()
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        int t = re();
        std::function<void(std::string&)>solve = [](std::string& s)->void
            {
                int cnt = 1;
                int n = s.size();
                std::vector<int>next(n);
                std::vector<int>ans(n);
                ans[0] = 1;
                std::function<void()>fun_next = [&]()->void
                    {
                        int j = 0;

                        for (int i = 1;i < n;i++)
                        {
                            while (j && (s[i] != s[j])) j = next[j - 1];
                            j += (s[i] == s[j]);next[i] = j;ans[i] = ans[j - 1] + 1;
                        }
                    };
                std::function<void()>fun_ans = [&]()->void
                    {
                        int j = 0;
                        const int mod = 1e9 + 7;
                        for (int i = 0;i < n;++i)
                        {
                            while (j > 0 && s[i] != s[j])j = next[j - 1];
                            j+=(s[i]==s[j]);
                            while (j * 2 > i + 1)j = next[j - 1];
                            cnt = ((ll)cnt * (ll)(ans[j - 1] + 1)) % mod;
                        }
                    };
                fun_next();
                fun_ans();
                std::cout << cnt << std::endl;

            };
        while (t--)
        {
            std::string s;
            std::cin >> s;
            solve(s);
        }
        return 0;
    }
}
signed main()
{
    return my::main();
}

