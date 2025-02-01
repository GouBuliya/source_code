#include<bits/stdc++.h>
namespace my {
    using namespace std;
#define ll long long 
#define pn cout << "\n";
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
const int INF = (1 << 30);

ll re() {
    ll t;
    std::cin >> t;
    return t;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    ll N = re(), M = re(), A = re(), B = re();
    std::vector<bool> bad(N + 1, false);
    while (M--) {
        ll L = re(), R = re();
        for (ll i = L; i <= R; ++i) bad[i] = true;
    }
    
    std::queue<ll> q;
    std::vector<bool> vis(N + 1, false);
    
    q.push(1); vis[1] = true;
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (cur == N) {
            cout << "Yes" << endl;
            return 0;
        }
        for (ll i = A; i <= B; ++i) {
            auto next = cur + i;
            if (next <= N && !bad[next] && !vis[next]) {
                vis[next] = true;
                q.push(next);
            }
        }
    }
    
    cout << "No" << endl;
    return 0;
}
}
signed main() {
    return my::main();
}
