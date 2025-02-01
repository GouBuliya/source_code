#include<bits/stdc++.h>
#define ll long long
using namespace std;
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
    signed main()
    {
        std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int N, D;
        cin >> N >> D;
        int T[N], L[N];

        for (int i = 0; i < N; ++i) {
            cin >> T[i] >> L[i];
        }

        for (int k = 1; k <= D; ++k) {
            int max_weight = 0;
            for (int i = 0; i < N; ++i) {
                int weight = T[i] * (L[i] + k);
                max_weight = max(max_weight, weight);
            }
            cout << max_weight << endl;
        }

        return 0;
    }
}
signed main()
{
    return my::main();
}