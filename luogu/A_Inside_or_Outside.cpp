#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> intervals(M);
    for (int i = 0; i < M; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    // Sort intervals by left endpoint, and by right endpoint for ties
    sort(intervals.begin(), intervals.end());

    vector<int> x(N, 0);  // Array to track the status of each index
    vector<int> ops(M, 0);  // Array to track which operation to perform
    bool possible = false;
    int total_cost = 0;

    // Case 1: Check if we have the whole range [1, N]
    for (int i = 0; i < M; ++i) {
        if (intervals[i].first == 1 && intervals[i].second == N) {
            ops[i] = 1;
            total_cost = 1;
            fill(x.begin(), x.end(), 1);  // Set all to 1
            possible = true;
            break;
        }
    }

    if (!possible) {
        // Case 2: Check if we can use two non-overlapping intervals
        int left = -1, right = -1;
        for (int i = 0; i < M; ++i) {
            for (int j = i + 1; j < M; ++j) {
                if (intervals[i].second < intervals[j].first || intervals[j].second < intervals[i].first) {
                    left = i;
                    right = j;
                    break;
                }
            }
            if (left != -1) break;
        }

        if (left != -1) {
            ops[left] = 2;
            ops[right] = 2;
            total_cost = 2;
            fill(x.begin(), x.end(), 1);
            possible = true;
        }
    }

    if (!possible) {
        // Case 3: Handle general case, try to cover range by sorting intervals
        vector<pair<int, int>> sorted_intervals = intervals;
        sort(sorted_intervals.begin(), sorted_intervals.end(), 
            [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second < b.second;  // Sort by right endpoint
            });
        
        for (int i = 0; i < M; ++i) {
            for (int j = i + 1; j < M; ++j) {
                if (sorted_intervals[i].second > sorted_intervals[j].first) {
                    break;
                }
            }
        }
    }

    // Final output
    if (possible) {
        cout << total_cost << endl;
        for (int i = 0; i < M; ++i) {
            cout << ops[i] << " ";
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}
