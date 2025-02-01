#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> findTrapezoid(int n, vector<int>& sticks) {
    unordered_map<int, int> cnt;
    for (int stick : sticks) {
        cnt[stick]++;
    }

    // 找出所有出现次数 >= 2 的长度作为腰的候选
    vector<int> legs;
    for (auto& pair : cnt) {
        if (pair.second >= 2) {
            legs.push_back(pair.first);
        }
    }

    if (legs.empty()) {
        return {-1};
    }

    // 遍历所有候选的腰的长度
    for (int leg : legs) {
        vector<int> bases;
        for (int stick : sticks) {
            if (stick != leg) {
                bases.push_back(stick);
            }
        }
        // 检查是否有两条不同的底边
        if (bases.size() >= 2) {
            // 确保两条底边长度不同
            if (bases[0] != bases[1]) {
                return {leg, leg, bases[0], bases[1]};
            } else if (bases.size() >= 3 && bases[1] != bases[2]) {
                return {leg, leg, bases[1], bases[2]};
            }
        }
    }

    return {-1};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> sticks(n);
        for (int i = 0; i < n; ++i) {
            cin >> sticks[i];
        }

        vector<int> result = findTrapezoid(n, sticks);
        if (result.size() == 1 && result[0] == -1) {
            cout << -1 << "\n";
        } else {
            for (int i = 0; i < 4; ++i) {
                cout << result[i] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}