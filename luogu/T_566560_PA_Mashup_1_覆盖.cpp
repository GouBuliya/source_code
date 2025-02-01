#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int s = n - k;

        bool valid = false;
        if ((n & s) == s) {
            if (s >= n - 1) {
                valid = true;
            }
        }
        cout << (valid ? 0 : 1) << '\n';
    }

    return 0;
}