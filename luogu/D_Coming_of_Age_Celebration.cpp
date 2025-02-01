#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FenwickTree {
public:
    explicit FenwickTree(int n) : size(n), tree(n + 1, 0) {}

    void update(int index, int delta) {
        while (index <= size) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

private:
    int size;
    vector<int> tree;
};

vector<int> solve(int N, const vector<int>& A) {
    vector<int> B(N);
    FenwickTree ft(N);

    for (int t = 0; t < N; ++t) {
        int received = ft.query(N) - ft.query(t);
        int given = min(A[t], N - t - 1);
        B[t] = A[t] + received - given;
        if (B[t] > 0) {
            ft.update(t + 1, 1);
        }
    }

    return B;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> result = solve(N, A);
    for (int i = 0; i < N; ++i) {
        cout << result[i] << (i < N - 1 ? ' ' : '\n');
    }

    return 0;
}