#include<bits/stdc++.h>
namespace my{
#define ll long long
#define pn cout<<"\n"
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
const int INF=(1<<30);
ll re(){ll t; std::cin>>t; return t;}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n, m, t = 0;
    std::cin >> n >> m;

    auto G = std::vector<int>(n+1);
    auto A = std::vector<ll>(n+1), B = std::vector<ll>(n+1);

    for(int i = 1; i <= n; ++i) G[i] = i & -i;

    for(int i = 1; i < 256; ++i) t += G[i];

    ll last = 0;
    while(m--){
        int op; std::cin >> op;
        if(op == 1){
            ll x, w; std::cin >> x >> w;
            x ^= last; w ^= last;
            A[x] += w;
            for(int p = x, q = 0; p <= n;){
                B[p] += w;
                q += 256; p += t + G[q];
                if(p <= n) A[p] += w;
            }
        }
        else{
            ll x; std::cin >> x; x ^= last;
            ll ans = A[x];
            int u = 0;
            for(int i = 1; i < 256; ++i){
                u += G[i];
                if(x - u <= 0) break;
                ans += B[x - u];
            }
            std::cout << ans << "\n";
            last = ans;
        }
    }
    return 0;
}
}
signed main(){
    return my::main();
}
