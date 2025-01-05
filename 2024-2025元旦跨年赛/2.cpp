#include<bits/stdc++.h>
namespace my {
#define ll long long 
#define pn cout<<"\n";
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
const int INF = (1<<30);

ll fast_mod(ll x, ll p) {
    return x % p;
}

struct SegmentTree {
    std::vector<ll> t, add, mod;
    int n, p;

    SegmentTree(const std::vector<ll>& arr, int p) : n(arr.size()), p(p) {
        t.resize(4 * n);
        add.resize(4 * n);
        mod.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void build(const std::vector<ll>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(arr, v * 2, tl, tm);
            build(arr, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    void push(int v, int tl, int tr) {
        if (add[v] || mod[v]) {
            if (mod[v]) {
                t[v] = fast_mod(t[v], p);
                add[v * 2] = fast_mod(add[v * 2], p);
                add[v * 2 + 1] = fast_mod(add[v * 2 + 1], p);
                mod[v * 2] = 1;
                mod[v * 2 + 1] = 1;
                mod[v] = 0;
            }
            t[v] += add[v] * (tr - tl + 1);
            if (tl != tr) {
                add[v * 2] += add[v];
                add[v * 2 + 1] += add[v];
            }
            add[v] = 0;
        }
    }

    void update_add(int v, int tl, int tr, int l, int r, ll k) {
        push(v, tl, tr);
        if (l > r) return;
        if (l == tl && r == tr) {
            add[v] += k;
            push(v, tl, tr);
        } else {
            int tm = (tl + tr) / 2;
            update_add(v * 2, tl, tm, l, std::min(r, tm), k);
            update_add(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r, k);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    void update_mod(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l > r) return;
        if (l == tl && r == tr) {
            mod[v] = 1;
            push(v, tl, tr);
        } else {
            int tm = (tl + tr) / 2;
            update_mod(v * 2, tl, tm, l, std::min(r, tm));
            update_mod(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    ll query_sum(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (l > r) return 0;
        if (l == tl && r == tr) return t[v];
        int tm = (tl + tr) / 2;
        return query_sum(v * 2, tl, tm, l, std::min(r, tm)) + query_sum(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r);
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, p, task;
    std::cin >> n >> m >> p >> task;
    std::vector<ll> arr(n);
    for (auto& x : arr) std::cin >> x;
    
    SegmentTree st(arr, p);
    std::vector<ll> res;

    for (int i = 0; i < m; ++i) {
        int op, l, r, k;
        std::cin >> op;
        if (op == 1) {
            std::cin >> l >> r >> k;
            st.update_add(1, 0, n - 1, l - 1, r - 1, k);
        } else if (op == 2) {
            std::cin >> l >> r;
            st.update_mod(1, 0, n - 1, l - 1, r - 1);
        } else if (op == 3) {
            std::cin >> l >> r;
            res.push_back(fast_mod(st.query_sum(1, 0, n - 1, l - 1, r - 1), p));
        }
    }

    for (auto x : res) std::cout << x << '\n';
    return 0;
}
};
signed main ()
{
my::main ();
return 0;
}