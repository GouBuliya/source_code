#include<bits/stdc++.h>
#define ll long long 
#define pn cout<<"\n";
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
const int INF=(1<<30);
ll re() { ll t; std::cin >> t; return t; }
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::string s;
    std::cin >> s;
    std::set<std::string> st;
    auto isStrange = [&](std::string& sub) {
        int n = sub.size();
        std::vector<int> f(26, -1), l(26, -1), c(26, 0);
        for (int i = 0; i < n; ++i) {
            int ch = sub[i] - 'a';
            if (f[ch] == -1) f[ch] = i;
            l[ch] = i;
            c[ch]++;
        }
        for (int i = 0; i < 26; ++i) {
            if (f[i] != -1 && l[i] - f[i] + 1 != c[i]) return false;
        }
        return true;
    };
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j <= s.size(); ++j) {
            std::string sub = s.substr(i, j - i);
            if (isStrange(sub)) st.insert(sub);
        }
    }
    std::cout << st.size() << std::endl;
    return 0;
}
