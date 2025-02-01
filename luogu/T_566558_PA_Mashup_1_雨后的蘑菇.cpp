#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> plots(n);

    for (int i = 0; i < n; i++) {
        cin >> plots[i].second >> plots[i].first; // 存储为(a_i, b_i)，便于排序
    }

    // 按a_i降序排序，若a_i相同则按b_i降序
    sort(plots.begin(), plots.end(), greater<pair<long long, long long>>());

    long long total = 0;
    for (int i = 0; i < n; i++) {
        long long a = plots[i].first;
        long long b = plots[i].second;
        total += b + a * i; // 分配到的天数是i+1天，贡献为b + a*(i+1-1) = b + a*i
    }

    cout << total << endl;
    return 0;
}