#include<bits/stdc++.h>
#define ll long long
#define pn cout<<'\n';
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
namespace my {
    class Sgt { // 线段树 sgt xds
    private:
        int ls(int x) { return x << 1; }
        int rs(int x) { return x << 1 | 1; }

        void push_up(int p) { tree[p] = tree[ls(p)] | tree[rs(p)]; }

        void push_down(int l, int r, int k, int p) {

            if (tag[p]) {
                int mid = (l + r) >> 1;
                tree[ls(p)] = tag[p];
                tree[rs(p)] = tag[p];
                tag[ls(p)] = k;
                tag[rs(p)] = k;
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
            std::function<void(int, int, int)> build = [&](int p, int l, int r) {
                if (l == r) {
                    tree[p] = (1 << 1);
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

        void update(int ul, int ur, int l, int r, int p, int k) {
            if (Inrange(l, ul, r, ur)) {
                tree[p] = (1 << k);
                tag[p] = (1 << k);
            }
            else if (!Ontorange(l, ul, r, ur)) {
                int mid = (l + r) >> 1;
                push_down(l, r, tag[p], p);

                update(ul, ur, l, mid, ls(p), k);
                update(ul, ur, mid + 1, r, rs(p), k);
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
                return ask(ul, ur, l, mid, ls(p)) | ask(ul, ur, mid + 1, r, rs(p));
            }
            return 0;
        }
    };
    const int INF = (1 << 30);
    ll re()
    {
        ll t; std::cin >> t;return t;
    }
    signed main()
    {
        std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
        int n = re();
        int T = re();
        int m = re();
        Sgt sgt;
        sgt.init(n);
        for (int i = 0;i < m;++i)
        {
            std::string S;
            std::cin >> S;

            if (S == "C")
            {
                int A = re();
                int B = re();
                if (A > B)std::swap(A, B);
                int C = re();
                sgt.update(A, B, 1, n, 1, C);

                fls();
            }
            else
            {
                int A = re();
                int B = re();
                if (A > B)std::swap(A, B);
                int ans = 0;
                ans = sgt.ask(A, B, 1, n, 1);
                int res = 0;
                for (int i = 30;i >= 0;--i)
                {
                    res += (ans >> i) & 1;
                }
                std::cout << res << std::endl;
            }

        }
        return 0;
    }
};
signed main()
{
    return my::main();
}