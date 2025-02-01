#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pn cout << "\n";
#define all(a) a.begin(), a.end()

const int INF = 1e9;

ll re() {
    ll t;
    cin >> t;
    return t;
}

// Function to find the minimum number of tickets needed for a query
int minTickets(int f, int d, const vector<pair<int, int>>& intervals) {
    int ans = 0;
    int pos = f;
    int next_pos = f;
    int i = 0;
    int n = intervals.size();
    while (pos < d) {
        bool found = false;
        while (i < n && intervals[i].first <= pos) {
            if (intervals[i].second > next_pos) {
                next_pos = intervals[i].second;
            }
            i++;
            found = true;
        }
        if (!found || next_pos <= pos) {
            return -1;
        }
        pos = next_pos;
        ans++;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = re(), m = re(), k = re();
    vector<vector<pair<int, int>>> s(k);
    
    for (int i = 0; i < m; ++i) {
        int x = re(), y = re(), a = re();
        --x; --y; --a;
        s[a].push_back({x, y});
    }

    for (auto &v : s) {
        sort(all(v));
        vector<pair<int, int>> merged;
        for (auto& p : v) {
            if (merged.empty() || merged.back().second < p.first)
                merged.push_back(p);
            else
                merged.back().second = max(merged.back().second, p.second);
        }
        v = move(merged);
    }

    vector<pair<int, int>> all_avail;
    for (int i = 0; i < k; ++i) {
        vector<pair<int, int>> tmp;
        int prev = 0;
        for (auto& p : s[i]) {
            if (p.first > prev)
                tmp.push_back({prev, p.first});
            prev = p.second;
        }
        if (prev < n - 1)
            tmp.push_back({prev, n - 1});
        all_avail.insert(all_avail.end(), tmp.begin(), tmp.end());
    }
    sort(all(all_avail));

    int q = re();
    while (q--) {
        int f = re(), d = re();
        --f; --d;
        int ans = minTickets(f, d, all_avail);
        cout << ans << "\n";
    }

    return 0;
}