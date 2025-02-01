#include<bits/stdc++.h>
#define ll long long
#define pn cout<<'\n';
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
#define int unsigned long long
namespace my {
    const int INF = (1 << 30);
    ll re()
    {
        ll t; std::cin >> t;return t;
    }
    int how_C(int n, int m) {
        if (m == 0 || n == m) return 1; // 终止条件
        if (m > n) return 0; // 无效情况
        return (how_C(n, m - 1) * (n - m + 1)) / m; // 递推公式
    }
    signed main()
    {
        std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
        int n = re();
        std::cout << how_C(n, 4) << std::endl;
        return 0;
    }
}
signed main()
{
    return my::main();
}