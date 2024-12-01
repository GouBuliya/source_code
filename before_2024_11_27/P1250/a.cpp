#include <bits/stdc++.h>
using namespace std;
const int N = 31000;
int n, m, ans = 0;
bool u[N] = {0};
struct Edge
{
    int x, y, z;
} a[N];
bool cmp(Edge a, Edge b)
{
    return a.y < b.y;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i].x >> a[i].y >> a[i].z;
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        int sum = 0;
        for (int j = a[i].x; j <= a[i].y; j++)
            if (u[j])
                sum++; // 统计已有的数量
        if (sum >= a[i].z)
            continue;                          // 满足就继续
        for (int k = a[i].y; k >= a[i].x; k--) // 不满足情况
        {
            if (!u[k])
            {
                u[k] = 1;
                sum++;
                ans++; // 答案++
                if (sum == a[i].z)
                    break; // 直到满足，退出
            }
        }
    }
    cout << ans; // 输出最后答案（即最少的树的数量）
    return 0;
}
