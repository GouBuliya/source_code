#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;  // number of test cases
    while (t--) {
        int n;
        cin >> n;
        
        vector<pair<int, int>> haystacks(n);
        long long total_haybales = 0;
        
        // Reading the input for each haystack (a_i and b_i)
        for (int i = 0; i < n; ++i) {
            cin >> haystacks[i].first >> haystacks[i].second;
            total_haybales += haystacks[i].first;
        }
        
        // Sort haystacks by the initial number of haybales in descending order
        sort(haystacks.rbegin(), haystacks.rend());
        
        long long moves = 0;
        long long current_capacity = 0;
        
        // Iterate through each haystack
        for (int i = 0; i < n; ++i) {
            int a_i = haystacks[i].first;  // initial haybales
            int b_i = haystacks[i].second; // height limit after emptying
            
            // Add the haybales to the current capacity of the "pool"
            current_capacity += a_i;
            moves += a_i;
            
            // If current_capacity exceeds the total haybales, it's impossible
            if (current_capacity > total_haybales) {
                moves = -1;
                break;
            }
            
            // After emptying this haystack, it can hold up to b_i haybales
            current_capacity -= b_i;
        }
        
        cout << moves << endl;
    }
    
    return 0;
}
