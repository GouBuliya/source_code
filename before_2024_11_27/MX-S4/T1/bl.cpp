// #include <iostream>
// #include <vector>
// #include <tuple>
// #include <numeric>

// using namespace std;

// vector<long long> battle_simulation(int n, int q, long long W, vector<long long>& a, vector<tuple<int, int, int>>& queries) {
//     vector<long long> results;
//     vector<long long> increments(n, 0); // 直接声明 n 大小的增益数组

//     for (const auto& query : queries) {
//         int l = get<0>(query);
//         int r = get<1>(query);
//         int d = get<2>(query);
        
//         // 更新增益数组
//         for (int i = l - 1; i < r; ++i) {
//             increments[i] += d;
//         }

//         // 应用增益到当前攻击力
//         vector<long long> current_attack = a;
//         for (int i = 0; i < n; ++i) {
//             current_attack[i] += increments[i];
//         }

//         // 模拟战斗
//         long long health = W;
//         long long total_attacks = 0;

//         while (true) {
//             for (int i = 0; i < n; ++i) {
//                 health -= current_attack[i];
//                 total_attacks++;
//                 if (health <= 0) {
//                     results.push_back(total_attacks - 1); // 不算致命攻击
//                     break;
//                 }
//                 current_attack[i] *= 2; // 攻击力翻倍
//             }
//             if (health <= 0) {
//                 break;
//             }
//         }

//         // 重置增益
//         fill(increments.begin(), increments.end(), 0);
//     }

//     return results;
// }

// int main() {
//     ios::sync_with_stdio(0),cin.tie(0);cout.tie(0);
//     int n, q;
//     long long W;
// 	
//     cin >> n >> q >> W;

//     vector<long long> a(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//     }

//     vector<tuple<int, int, int>> queries(q);
//     for (int i = 0; i < q; ++i) {
//         int l, r, d;
//         cin >> l >> r >> d;
//         queries[i] = make_tuple(l, r, d);
//     }

//     vector<long long> results = battle_simulation(n, q, W, a, queries);

//     for (const auto& res : results) {
//         cout << res << endl;
//     }

//     return 0;
// }
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;

#define ls ((q) << 1)
#define rs ((q) << 1 | 1)
const ll M = 1e18;
ll n, m, W, q;
const int maxn = 2e5 + 10;
ll B[maxn * 4], tagadd[maxn * 4], tagmul[maxn * 4];
ll A[maxn];

void build(int q, int l, int r) {
    tagadd[q] = 0;
    tagmul[q] = 1;
    B[q] = 0;
    if (l == r) {
        B[q] = A[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    B[q] = (B[ls] + B[rs]); // push_up
}

void appty_mul(int q, int left, int right, int k) {
    B[q] = (B[q] * k);
    tagmul[q] = (tagmul[q] * k);
    tagadd[q] = (tagadd[q] * k);
}

void appty_add(int q, int left, int right, int k) {
    tagadd[q] = (tagadd[q] + k);
    B[q] = (B[q] + k * (right - left + 1));
}

void push_down(int q, int l, int r) {
    if (!tagadd[q] && tagmul[q] == 1)
        return;
    int mid = (l + r) >> 1;
    appty_mul(ls, l, mid, tagmul[q]);
    appty_mul(rs, mid + 1, r, tagmul[q]);
    appty_add(ls, l, mid, tagadd[q]);
    appty_add(rs, mid + 1, r, tagadd[q]);
    tagadd[q] = 0;
    tagmul[q] = 1;
}

void add(const int ul, const int ur, int l, int r, int q, const int k) {
    if (ul <= l && r <= ur) {
        appty_add(q, l, r, k);
        return;
    }
    push_down(q, l, r);
    int mid = (l + r) >> 1;
    if (mid >= ul)
        add(ul, ur, l, mid, ls, k);
    if (mid < ur)
        add(ul, ur, mid + 1, r, rs, k);
    B[q] = (B[ls] + B[rs]); // push
}

ll ask(const int ul, const int ur, int l, int r, int q) {
    if (ul <= l && r <= ur)
        return B[q];
    push_down(q, l, r);
    int mid = (l + r) >> 1;
    ll res = 0;
    if (mid >= ul)
        res += ask(ul, ur, l, mid, ls);
    if (mid < ur)
        res += ask(ul, ur, mid + 1, r, rs);
    return res;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("wxyt3.in","r",stdin);
    
    cin >> n >> q >> W;
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    build(1, 1, n);
    ll w = W;

    while (q--) {
        int l, r, d;
        cin >> l >> r >> d;
        add(l, r, 1, n, 1, d);
        
        int t = 0, tag = 1;
        while (w) {
            ll Ask = ask(1, n, 1, n, 1) * tag;
            if (w > Ask) {
                w -= Ask;
                t += n;
            } else {
                int nl = 1, nr = n;
                while (nl < nr) {
                    int mid = (nl + nr + 1) >> 1;
                    if (w > ask(1, mid, 1, n, 1) * tag)
                        nl = mid;
                    else
                        nr = mid - 1;
                }
                t += nl;
                w = 0;
            }
            tag *= 2;
        }
        cout << t << endl;
        w = W;
    }
    return 0;
}
