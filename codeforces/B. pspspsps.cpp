
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool can_form_permutation(const string& s) {
    int n = s.size();
    vector<bool> used_prefix(n + 1, false);
    vector<bool> used_suffix(n + 1, false);
    int current_max_prefix = 0;
    int current_max_suffix = 0;

    // Check prefix conditions
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'p') {
            current_max_prefix++;
            if (current_max_prefix > n || used_prefix[current_max_prefix]) {
                return false;
            }
            used_prefix[current_max_prefix] = true;
        }
    }

    // Reset used arrays
    fill(used_prefix.begin(), used_prefix.end(), false);
    fill(used_suffix.begin(), used_suffix.end(), false);

    // Check suffix conditions
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 's') {
            current_max_suffix++;
            if (current_max_suffix > n || used_suffix[current_max_suffix]) {
                return false;
            }
            used_suffix[current_max_suffix] = true;
        }
    }

    // Combine both checks
    fill(used_prefix.begin(), used_prefix.end(), false);
    fill(used_suffix.begin(), used_suffix.end(), false);
    current_max_prefix = 0;
    current_max_suffix = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'p') {
            current_max_prefix++;
            if (current_max_prefix > n || used_prefix[current_max_prefix]) {
                return false;
            }
            used_prefix[current_max_prefix] = true;
        }
        if (s[n - 1 - i] == 's') {
            current_max_suffix++;
            if (current_max_suffix > n || used_suffix[current_max_suffix]) {
                return false;
            }
            used_suffix[current_max_suffix] = true;
        }
    }

    // Ensure all numbers are used exactly once
    for (int i = 1; i <= n; ++i) {
        if (!used_prefix[i] && !used_suffix[i]) {
            return false;
        }
    }

    // Ensure no conflicts between prefix and suffix
    for (int i = 1; i <= n; ++i) {
        if (used_prefix[i] && used_suffix[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (can_form_permutation(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}



