#include<bits/stdc++.h>
#include <sched.h>
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

class Sgt {
private:
    int ls(int x) { return x << 1; }
    int rs(int x) { return x << 1 | 1; }
    
    void push_up(int p) {
        tree[p] = tree[ls(p)] + tree[rs(p)];
    }

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

    bool Inrange(int L, int l, int R, int r) {
        return (l <= L) && (R <= r);
    }

    bool Ontorange(int L, int l, int R, int r) {
        return (R < l) || (L > r);
    }

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
            } else {
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
        } else if (!Ontorange(l, ul, r, ur)) {
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
        } else if (!Ontorange(l, ul, r, ur)) {
            int mid = (l + r) >> 1;
            push_down(l, r, tag[p], p);
            return ask(ul, ur, l, mid, ls(p)) + ask(ul, ur, mid + 1, r, rs(p));
        }
        return 0;
    }
};

void main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Sgt A;
    int n = re(), m = re();
    A.init(n);

    for (int i = 1; i <= m; ++i) {
        int op = re();
        if (op == 1) {
            int x = re(), y = re(), k = re();
            A.add(x, y, 1, n, 1, k);
        } else {
            int x = re(), y = re();
            std::cout << A.ask(x, y, 1, n, 1) << std::endl;
        }
    }
}

}

int main() {
    my::main();
    return 0;
}
