
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        
        vector<int> price_points;
        for (int i = 0; i < n; i++) {
            price_points.push_back(a[i]);
            price_points.push_back(b[i]);
        }
        
        sort(price_points.begin(), price_points.end());
        price_points.erase(unique(price_points.begin(), price_points.end()), price_points.end());

        int max_profit = 0;
        
        for (int p : price_points) {
            int positive = 0, negative = 0;
            for (int i = 0; i < n; i++) {
                if (p <= a[i]) positive++;
                else if (p <= b[i]) negative++;
            }
            if (negative <= k) {
                max_profit = max(max_profit, positive + negative);
            }
        }
        
        cout << max_profit << endl;
    }
    return 0;
}

