#include <iostream>
#include <vector>

using namespace std;

const int MAX_VALUE = 1e7;
vector<int> sg(MAX_VALUE + 1, 0);  // SG值缓存
vector<int> phi(MAX_VALUE + 1);     // 欧拉函数值缓存

// 计算欧拉函数φ(x) 使用筛法预处理
void compute_phi() {
    for (int i = 0; i <= MAX_VALUE; ++i) {
        phi[i] = i;
    }
    for (int i = 2; i <= MAX_VALUE; ++i) {
        if (phi[i] == i) {
            for (int j = i; j <= MAX_VALUE; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

// 计算SG函数值，使用迭代方式避免递归
void compute_sg() {
    sg[0] = 0;
    sg[1] = 0;
    for (int x = 2; x <= MAX_VALUE; ++x) {
        bool used[3] = {false, false, false}; // 用于计算mex，最多只需要 0, 1, 2 三个状态

        used[sg[phi[x]]] = true;  // φ(x)的SG值
        used[sg[x - 1]] = true;   // x-1的SG值

        int mex = 0;
        while (used[mex]) {
            mex++;
        }

        sg[x] = mex;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    compute_phi();
    compute_sg();

    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        int nim_sum = 0;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            nim_sum ^= sg[num];
        }
        cout << (nim_sum != 0 ? "Alice" : "Bob") << endl;
    }

    return 0;
}
