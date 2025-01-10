#include <bits/stdc++.h>
namespace my {
#define ll long long
#define pn cout << "\n";
#define mset(a, x) memset(a, x, sizeof a)
#define mcpy(a, b) memcpy(a, b, sizeof a)
#define all(a) a.begin(), a.end()
#define fls() fflush(stdout)
    const int INF = (1 << 30);
    ll re() {
        ll t;
        std::cin >> t;
        return t;
    }
    class Sgt { // 线段树 sgt xds
    private:
        int ls(int x) { return x << 1; }
        int rs(int x) { return x << 1 | 1; }

        void push_up(int p) { tree[p] = tree[ls(p)] + tree[rs(p)]; }

        void push_down(int l, int r, int k, int p) {
            if (tag[p]) {
                int mid = (l + r) >> 1;
                tree[ls(p)] += k * (mid - l + 1);
                tree[rs(p)] += k * (r - mid);
                tag[ls(p)] += k;
                tag[rs(p)] += k;
                tag[p] = 0;
            }
        }

        bool Inrange(int L, int l, int R, int r) { return (l <= L) && (R <= r); }

        bool Ontorange(int L, int l, int R, int r) { return (R < l) || (L > r); }

    public:
        std::vector<int> tree;
        std::vector<int> tag;
        std::vector<int> A;

        void init(int n) {
            tree.resize(4 * n + 1);
            tag.resize(4 * n + 1);
            A.resize(n + 1);
            for (int i = 1; i <= n; ++i) {
                std::cin >> A[i];
            }

            std::function<void(int, int, int)> build = [&](int p, int l, int r) {
                if (l == r) {
                    tree[p] = A[l];
                }
                else {
                    int mid = (l + r) >> 1;
                    build(ls(p), l, mid);
                    build(rs(p), mid + 1, r);
                    push_up(p);
                }
                };
            build(1, 1, n);
        }

        void add(int ul, int ur, int l, int r, int p, int k) {
            if (Inrange(l, ul, r, ur)) {
                tree[p] += k * (r - l + 1);
                tag[p] += k;
            }
            else if (!Ontorange(l, ul, r, ur)) {
                int mid = (l + r) >> 1;
                push_down(l, r, tag[p], p);
                add(ul, ur, l, mid, ls(p), k);
                add(ul, ur, mid + 1, r, rs(p), k);
                push_up(p);
            }
        }

        int ask(int ul, int ur, int l, int r, int p) {
            if (Inrange(l, ul, r, ur)) {
                return tree[p];
            }
            else if (!Ontorange(l, ul, r, ur)) {
                int mid = (l + r) >> 1;
                push_down(l, r, tag[p], p);
                return ask(ul, ur, l, mid, ls(p)) + ask(ul, ur, mid + 1, r, rs(p));
            }
            return 0;
        }
    };
    class KMP {
    private:
        std::vector<int> next;

    public:
        std::string s, t;
        void fun(std::string& s1, std::string& s2) {
            s = s1;
            t = s2;
            next.resize(t.size());
            int j = 0;
            for (int i = 1; i < t.size(); ++i) {
                while (j && t[i] != t[j])
                    j = next[j - 1];
                if (t[i] == t[j])
                    j++;
                next[i] = j;
            }
            j = 0;
            for (int i = 0; i < s.size(); ++i) {
                while (j && s[i] != t[j])
                    j = next[j - 1];
                if (s[i] == t[j])
                    j++;
                if (j >= t.size()) {
                    std::cout << i + 1 - t.size() + 1 << std::endl;
                    j = next[j - 1];
                }
            }
            for (auto i : next)
                std::cout << i << " ";
        }
    };
    class qpow // 快速幂
    {
    public:
        ll pow(ll a, ll b, ll p) {
            ll ans = 1;
            ll base = a;
            while (b) {
                if (b & 1)
                    ans *= (base % p);
                base *= base;
                b >>= 1;
            }
            return ans % p;
        }
    };
    signed main() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        return 0;
    }
} // namespace my
signed main() { return my::main(); }
