#include <bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
int const INF = 1e9;
using namespace std;
ll re()
{
    ll x = 0, t = 1;
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
#define int long long
struct node
{
    int x, y;
} A, B, C;
signed main()
{
    A.x = re(), A.y = re(), B.x = re(), B.y = re();
    if (A.x == B.x || A.y == B.x)
    {
        if (A.x == B.x)
        {
            if (A.x == INF || B.x == INF)
            {
                C.x = max(A.x, B.x) - 1;
                C.y = A.y;
                cout << C.x << " " << C.y << endl;
                return 0;
            }
            if (A.x == -INF || B.x == -INF)
            {
                C.x = min(A.x, B.x) + 1;
                C.y = A.y;
                cout << C.x << " " << C.y << endl;
                return 0;
            }
            C.x = A.x + 1;
            C.y = A.y;
            cout << C.x << " " << C.y << endl;
            return 0;
        }
        else if (B.y == A.y)
        {
            if (A.y == INF || B.y == INF)
            {
                C.y = max(A.y, B.y) - 1;
                C.x = A.x;
                cout << C.x << " " << C.y << endl;
                return 0;
            }
            if (A.y == -INF || B.y == -INF)
            {
                C.y = min(A.y, B.y) + 1;
                C.x = A.x;
                cout << C.x << " " << C.y << endl;
                return 0;
            }
            C.y = A.y + 1;
            C.x = A.x;
            cout << C.x << " " << C.y << endl;
            return 0;
        }
    }
    else
    {
        C.x = A.x;
        C.y = B.y;
        cout << C.x << " " << C.y << endl;
    }
}
