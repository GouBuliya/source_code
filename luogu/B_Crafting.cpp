#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        int a[n], b[n];
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
            a[i] -= b[i];
        }
        
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] < 0) res++;
        }
        
        if (res >= 2) {
            cout << "No\n";
        } else {
            if (res == 1) {
                int maxShortfall = 0;
                for (int i = 1; i <= n; ++i) {
                    if (a[i] < 0) maxShortfall = -a[i];
                }
                
                for (int i = 1; i <= n; ++i) {
                    if (a[i] >= 0 && a[i] < maxShortfall) {
                        cout << "No\n";
                        goto end;
                    }
                }
            }
            cout << "Yes\n";
        }
    end:;
    }
    return 0;
}