#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the minimum number of operations needed
vector<int> minimum_operations(int t, vector<vector<int>> test_cases) {
    vector<int> results;

    for (int i = 0; i < t; ++i) {
        int n = test_cases[i].size();
        vector<int> a = test_cases[i];
        
        bool allZeros = true;
        
        for (int x : a) {
            if (x != 0) {
                allZeros = false;
                break;
            }
        }

        if (allZeros) {
            results.push_back(0);
        } else {
            // Since the operations always enable turning into 0 with correct subarray length,
            // we only need one operation if there are some non-zero elements in the array.
            results.push_back(1);
        }
    }

    return results;
}

int main() {
    int t;
    cin >> t;
    
    vector<vector<int>> test_cases(t);

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        test_cases[i] = vector<int>(n);

        for (int j = 0; j < n; ++j) {
            cin >> test_cases[i][j];
        }
    }

    vector<int> results = minimum_operations(t, test_cases);

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
