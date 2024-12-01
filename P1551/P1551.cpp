#include <bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
const int inf = 10001;
inline int re()
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
int pre[inf];
int root(int x) // 寻根
{
    return pre[x] = pre[x] == x ? x : root(pre[x]);
}
void merge(int x, int y)
{
    x = root(x);
    y = root(y);
    // pre[x] = root(y);
    if (x == y)
        return;
    else
    {
        pre[x] = y;
    }
}

void solve()
{

    int N = re();

    int M = re(); // N个人，M个关系，询问p
    int P = re();
    for (int i = 1; i <= N; ++i)
    {
        pre[i] = i;
    } // 初始化，将每个元素的父亲指向自己
    for (int i = 1; i <= M; ++i)
    {
        int X = re(), Y = re();
        merge(X, Y);
    }
    for (int i = 1; i <= P; ++i)
    {
        int X = re(), Y = re();

        int x = root(X);
        int y = root(Y);
        if (x == y)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}
signed main()
{
    solve();
    return 0;
}