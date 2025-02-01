#include <iostream>
#include <vector>
using namespace std;

bool isPartitionPossible(const vector<pair<int, int>>& polyomino) {
    int n = polyomino.size();
    int totalArea = 0;
    for (const auto& p : polyomino) {
        totalArea += p.second - p.first + 1;
    }
    if (totalArea % 2 != 0) return false; // Area must be even

    int leftMost = polyomino[0].first;
    int rightMost = polyomino[0].second;
    for (int i = 1; i < n; ++i) {
        leftMost = min(leftMost, polyomino[i].first);
        rightMost = max(rightMost, polyomino[i].second);
    }

    int halfArea = totalArea / 2;
    int currentArea = 0;
    int cutPoint = leftMost;

    while (cutPoint <= rightMost) {
        for (int i = 0; i < n; ++i) {
            if (polyomino[i].first <= cutPoint && polyomino[i].second >= cutPoint) {
                currentArea += (polyomino[i].second - cutPoint + 1);
            }
        }
        if (currentArea == halfArea) {
            return true; // Found a valid cut point
        }
        cutPoint++;
    }

    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> polyomino(n);
        for (int i = 0; i < n; ++i) {
            cin >> polyomino[i].first >> polyomino[i].second;
        }
        if (isPartitionPossible(polyomino)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}