#include <bits/stdc++.h>
using namespace std;
int n, v[1145141], c, hyz; // c是连续签到的天数，hyz是活跃值
bool f[1145141];
int main()
{
    cin >> n;
    for (int i = 1; i <= 6; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
        if (f[i] == 1)
            c++;
        else
            c = 0; // 如果这天没签到，连续签到中断
        if (c >= 1 && c < 3)
            hyz += v[1];
        else if (c >= 3 && c < 7)
            hyz += v[2];
        else if (c >= 7 && c < 30)
            hyz += v[3];
        else if (c >= 30 && c < 120)
            hyz += v[4];
        else if (c >= 120 && c < 365)
            hyz += v[5];
        else if (c >= 365)
            hyz += v[6];
    }
    cout << hyz;
    return 0;
}