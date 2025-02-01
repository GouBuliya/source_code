#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

pair<int, vector<pair<int, int>>> min_cost_permutation(int n, vector<int>& p, vector<int>& q) {
    // Create a mapping from value to index for both permutations
    unordered_map<int, int> pos_p;
    unordered_map<int, int> pos_q;

    for (int i = 0; i < n; ++i) {
        pos_p[p[i]] = i;
        pos_q[q[i]] = i;
    }

    vector<pair<int, int>> operations;

    // Iterate over each position
    for (int i = 0; i < n; ++i) {
        if (p[i] != q[i]) {
            // Find the correct value for p[i]
            int target_value = q[i];
            int target_index = pos_p[target_value];

            // Swap p[i] with p[target_index]
            swap(p[i], p[target_index]);

            // Update the positions dictionary
            pos_p[p[target_index]] = target_index;
            pos_p[p[i]] = i;

            // Record the operation
            operations.emplace_back(i + 1, target_index + 1);
        }
    }

    return { operations.size(), operations };
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        vector<int> q(n);

        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> q[i];
        }

        auto result = min_cost_permutation(n, p, q);
        cout << result.first << "\n";

        for (const auto& op : result.second) {
            cout << op.first << " " << op.second << "\n";
        }
    }

    return 0;
}



