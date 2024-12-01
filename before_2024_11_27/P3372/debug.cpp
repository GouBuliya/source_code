#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;

#define int long long 
#define ll long long
int sgt[4 * maxn]; // 线段树数组
int arr[maxn];     // 数列
int tag[4 * maxn]; // 标记数组

int n, m;

void scan() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &arr[i]);
}

int left_son(int q) {
    return q << 1;
}

int right_son(int q) {
    return q << 1 | 1;
}

void push_up_sum(int q) {
    sgt[q] = sgt[left_son(q)] + sgt[right_son(q)];
}

void build(int q, int left, int right) {
    tag[q] = 0;
    if (left == right) {
        sgt[q] = arr[left];
        return;
    }
    int mid = (left + right) >> 1;
    build(left_son(q), left, mid);
    build(right_son(q), mid + 1, right);
    push_up_sum(q);
}

void apply_tag(int q, int left, int right, int k) {
    tag[q] += k;
    sgt[q] += k * (right - left + 1);
}

void push_down(int q, int left, int right) {
    if (tag[q]) {
        int mid = (left + right) >> 1;
        apply_tag(left_son(q), left, mid, tag[q]);
        apply_tag(right_son(q), mid + 1, right, tag[q]);
        tag[q] = 0;
    }
}

void update(int uleft, int uright, int left, int right, int q, int k) {
    if (uleft <= left && right <= uright) {
        apply_tag(q, left, right, k);
        return;
    }
    push_down(q, left, right);
    int mid = (left + right) >> 1;
    if (uleft <= mid)
        update(uleft, uright, left, mid, left_son(q), k);
    if (uright > mid)
        update(uleft, uright, mid + 1, right, right_son(q), k);
    push_up_sum(q);
}

int query(int q_left, int q_right, int left, int right, int q) {
    if (q_left <= left && right <= q_right)
        return sgt[q];
    push_down(q, left, right);
    int mid = (left + right) >> 1, res = 0;
    if (q_left <= mid)
        res += query(q_left, q_right, left, mid, left_son(q));
    if (q_right > mid)
        res += query(q_left, q_right, mid + 1, right, right_son(q));
    return res;
}

signed main(){
    scan();
    build(1, 1, n);
    while (m--) {
        int op;
        scanf("%lld", &op);
        if (op == 1) {
            int b, c, d;
            scanf("%lld%lld%lld", &b, &c, &d);
            update(b, c, 1, n, 1, d);
        } else if (op == 2) {
            int e, f;
            scanf("%lld%lld", &e, &f);
            printf("%lld\n", query(e, f, 1, n, 1));
        }
    }
    return 0;
}

                                                                                                                                                                                  
