#include<bits/stdc++.h>
namespace my{
#define ll long long 
#define pn std::cout<<"\n";
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end() 
#define fls() fflush(stdout)
const int INF=(1<<30);
ll re ()
{
    ll t;
    std::cin>>t;
    return t;
}
auto chk = [](ll a, ll b, ll c, ll d) {
    return (a - b + c - d) % 4 == 0 && (a - b + c - d) >= 0;
};

signed main ()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr); 
    
    auto T = re();
    while (T--) {
        auto n = re();
        std::vector<ll> A(n), B(n);
        for (auto &x : A) x = re();
        for (auto &x : B) x = re();
        
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (!chk(A[i], B[i], A[n-1-i], B[n-1-i])) {
                ok = false;
                break;
            }
        }
        
        if (ok) std::cout << "Yes\n";
        else std::cout << "No\n";
    }
    
    return 0;
}
}
signed main ()
{
    return my::main();
}