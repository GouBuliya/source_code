#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tree {
    int n;
    vector<int> weights;
    vector<vector<int>> edges;
};

pair<int, pair<int, int>> dfs(int node, int parent, const vector<vector<int>>& adj_list, const vector<int>& weights, vector<int>& max_subtree_values, vector<pair<int, int>>& dp) {
    int max_value = weights[node - 1];
    int wins = 0, losses = 0;

    for (int neighbor : adj_list[node]) {
        if (neighbor != parent) {
            auto [child_max_value, child_dp] = dfs(neighbor, node, adj_list, weights, max_subtree_values, dp);
            max_value = max(max_value, child_max_value);
            wins += child_dp.first;
            losses += child_dp.second;
        }
    }

    max_subtree_values[node] = max_value;
    dp[node] = {wins, losses};
    return {max_value, {wins, losses}};
}

int count_winning_moves(int node, int parent, const vector<vector<int>>& adj_list, const vector<int>& weights, const vector<int>& max_subtree_values, const vector<pair<int, int>>& dp) {
    int total_wins = 0;

    for (int neighbor : adj_list[node]) {
        if (neighbor != parent) {
            int child_max_value = max_subtree_values[neighbor];
            int child_dp_true = dp[neighbor].first;
            int child_dp_false = dp[neighbor].second;

            if (child_max_value < weights[node - 1]) {
                total_wins += 1 + child_dp_false;
            } else {
                total_wins += child_dp_true;
            }

            if (child_max_value >= weights[node - 1]) {
                total_wins -= child_dp_true;
            }
        }
    }

    return total_wins;
}

string find_winning_nodes(const Tree& tree) {
    int n = tree.n;
    const vector<int>& weights = tree.weights;
    const vector<vector<int>>& edges = tree.edges;

    vector<vector<int>> adj_list(n + 1);
    for (const auto& edge : edges) {
        adj_list[edge[0]].push_back(edge[1]);
        adj_list[edge[1]].push_back(edge[0]);
    }

    vector<int> max_subtree_values(n + 1, 0);
    vector<pair<int, int>> dp(n + 1, {0, 0}); // dp[i][0]: wins if start at i, dp[i][1]: losses if start at i

    dfs(1, -1, adj_list, weights, max_subtree_values, dp);

    vector<int> winning_nodes;
    for (int i = 1; i <= n; ++i) {
        if (count_winning_moves(i, -1, adj_list, weights, max_subtree_values, dp) % 2 == 1) {
            winning_nodes.push_back(i);
        }
    }

    if (!winning_nodes.empty()) {
        string result = to_string(winning_nodes.size());
        for (int node : winning_nodes) {
            result += " " + to_string(node);
        }
        return result;
    } else {
        return "0";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> weights(n);
        for (int& weight : weights) {
            cin >> weight;
        }
        vector<vector<int>> edges(n - 1);
        for (auto& edge : edges) {
            cin >> edge[0] >> edge[1];
        }
        Tree tree = {n, weights, edges};
        cout << find_winning_nodes(tree) << endl;
    }
    return 0;
}
