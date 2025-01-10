#include<bits/stdc++.h>
#define ll long long
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
    std::vector<bool>A;

    struct node
    {
        bool l, r;
        int lm, rm;
        int _max_1;
        int _max_0;
        int _size;
        int len;
    };
    std::vector<node>tree;
    std::vector<node>_tag;
#define ls (p<<1)
#define rs (p<<1|1)
    void push_up(int p)
    {
        if (tree[ls].r && tree[rs].l)
        {
            int __max = tree[ls].rm + tree[rs].lm;
            tree[p].lm = tree[ls].lm;
            tree[p].rm = tree[rs].rm;
            tree[p]._size = tree[ls]._size + tree[rs]._size;
            tree[p].len *= 2;
            tree[p]._max_1 = std::max(std::max(tree[ls]._max_1, tree[rs]._max_1), __max);
            tree[p]._max_0 = std::max(tree[ls]._max_0, tree[rs]._max_0);
        }
        else
        {
            if (tree[ls].l == tree[rs].r)
            {
                int __max = tree[ls].rm + tree[rs].lm;
                tree[p].lm = tree[ls].lm;
                tree[p].rm = tree[rs].rm;
                tree[p]._size = tree[ls]._size + tree[rs]._size;
                tree[p].len *= 2;
                tree[p]._max_1 = std::max(std::max(tree[ls]._max_1, tree[rs]._max_1), __max);
                tree[p]._max_0 = std::max(tree[ls]._max_0, tree[rs]._max_0);
            }
        }
    }
    signed main()
    {
        std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);

    }
}
signed main()
{
    return my::main();
}