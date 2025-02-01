#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool canReachBases(int n, int b, vector<vector<int>>& adjMatrix, vector<int>& startPositions) {
    auto bfs = [&](int start) -> bool {
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(start - 1);
        visited[start - 1] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            // If the current node is a base, skip further exploration from here
            if (current + 1 <= b) continue;

            for (int nextNode = 0; nextNode < n; ++nextNode) {
                if (adjMatrix[current][nextNode] == 1 && !visited[nextNode]) {
                    q.push(nextNode);
                    visited[nextNode] = true;
                }
            }
        }

        // Check if all non-base nodes are reachable
        for (int i = 0; i < n; ++i) {
            if ((i + 1 > b) && !visited[i]) return false;
        }
        return true;
    };

    for (int k = 0; k < 100; ++k) { // We try up to 100 steps, as k is much larger than 100
        bool allReached = true;
        for (int start : startPositions) {
            if (!bfs(start)) {
                allReached = false;
                break;
            }
        }
        if (allReached) {
            return true;
        }
    }

    return false;
}

int main() {
    int n, b, r;
    cin >> n >> b >> r;

    vector<vector<int>> adjMatrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < n; ++j) {
            adjMatrix[i][j] = row[j] - '0';
        }
    }

    vector<int> startPositions(r);
    for (int i = 0; i < r; ++i) {
        cin >> startPositions[i];
    }

    if (canReachBases(n, b, adjMatrix, startPositions)) {
        cout << "0" << endl; // Since we only check up to 100 steps, we output 0 if possible within 100 steps
    } else {
        cout << "-1" << endl;
    }

    return 0;
}



