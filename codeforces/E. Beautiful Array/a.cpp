#include <bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
int re()
{
    int x = 0, t = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x * t;
}
vector<ll> arr;
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int a = re();
    int b = re();
    for (int i = 1; i <= 4; ++i)
    {
        arr.push_back(a);
    }
    if (a < b)
    {
        int temp = (b - a) * 2 + 1;

        arr[2] = b;
        arr[3] = arr[2] + 1;
        arr[1] -= temp;
        cout << 3 << endl;

        for (int i = 1; i <= 3; ++i)
            cout << arr[i] << " ";
    }
    else 
    {
        int temp = (a - b) * 2 + 1;

        arr[2] = b;
        arr[3] = arr[2] - 1;
        arr[1] += temp;
        cout << 3 << endl;

        for (int i = 1; i <= 3; ++i)
            cout << arr[i] << " ";
    }
    return 0;
}
