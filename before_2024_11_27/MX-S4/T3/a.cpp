#include <iostream>
#include <vector>
#define ll long long 
const int maxn=3e5+10;
using namespace std;
#define int long long 
int a[maxn];
int pre[maxn];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    // freopen("seq3.in","r",stdin);
    int n, q, c1, c2, w1, w2;
    cin >> n >> q >> c1 >> c2 >> w1 >> w2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    for (int i = 0; i < q; i++) {
        int opt, x, y;
        cin >> opt >> x >> y;

        if (opt == 1) {
            a[x - 1] += y; // 转换为0索引
            for (int j = x - 1; j < n; j++) {
                pre[j + 1] += y;
            }
        } else if (opt == 2) {
            x--; // 转换为0索引
            y--; // 转换为0索引
            bool youyou = false;
            for (int l = 1; l <= c1; l++) {
                for (int i = x; i <= y - l + 1; i++) {
                    long long total = pre[i + l] - pre[i];
                    if (total <= w1) {
                        youyou = true;
                        break;
                    }
                }
                if (youyou) break;
            }
            if (!youyou) {
                cout << "tetris\n";
                continue;
            }
            bool yy = false;
            for (int l = 1; l <= c2; l++) {
                for (int i = x; i <= y - l + 1; i++) {
                    long long total = pre[i + l] - pre[i];
                    if (total > w2) {
                        yy = true;
                        break;
                    }
                }
                if (yy) break;
            }
            if (yy) {
                cout << "tetris\n";
            } else {
                cout << "cont\n";
            }
        }
    }

    return 0;
}
