#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 998244353

ll f(ll n) {
    static vector<ll> fact = { 1 };
    while (fact.size() <= n) {
        fact.push_back(fact.back() * fact.size() % MOD);
    }
    return fact[n];
}

ll inv(ll x, ll m) {
    ll r = 1, p = m - 2;
    while (p) {
        if (p & 1) r = r * x % m;
        x = x * x % m;
        p >>= 1;
    }
    return r;
}

// Tree hashing function
ll tree_hash(const vector<vector<int>>& tree, int u, int parent) {
    vector<ll> children;
    for (int v : tree[u]) {
        if (v != parent) {
            children.push_back(tree_hash(tree, v, u));
        }
    }
    sort(children.begin(), children.end());
    ll hash = 1;
    for (ll h : children) {
        hash = (hash * (h + 1)) % MOD;
    }
    return hash;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> A(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    // Calculate the hash of the given tree
    ll target_hash = tree_hash(A, 0, -1);

    // Generate all possible trees using Prufer sequence
    int cnt = 0;
    vector<int> prufer(n - 2);
    function<void(int)> generate = [&](int pos) {
        if (pos == n - 2) {
            vector<int> degree(n, 1);
            for (int x : prufer) degree[x]++;
            int ptr = 0;
            while (degree[ptr] != 1) ptr++;
            int leaf = ptr;
            vector<vector<int>> tree(n);
            for (int x : prufer) {
                tree[leaf].push_back(x);
                tree[x].push_back(leaf);
                if (--degree[x] == 1 && x < ptr) {
                    leaf = x;
                }
                else {
                    ptr++;
                    while (degree[ptr] != 1) ptr++;
                    leaf = ptr;
                }
            }
            // Connect the last two nodes
            tree[leaf].push_back(n - 1);
            tree[n - 1].push_back(leaf);

            // Check if the generated tree is isomorphic to the given tree
            if (tree_hash(tree, 0, -1) == target_hash) {
                cnt++;
            }
            return;
        }
        for (int i = 0; i < n; i++) {
            prufer[pos] = i;
            generate(pos + 1);
        }
        };
    generate(0);

    ll tot = f(n - 1);
    ll ans = cnt * inv(tot, MOD) % MOD;
    cout << ans << "\n";

    return 0;
}