// projects:[HAOI2007] 理想的正方形 | P2216
#include <bits/stdc++.h>
#define ll long long
#define INF 0x7fffffff
const int POS_N = 10001;
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
// #define int long long
#define __min(a, b) ((a) < (b) ? (a) : (b))
#define fls() fflush(stdout)
using namespace std;
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
const int MAXN = 1010;
int arr[MAXN][MAXN];
int max_mon[MAXN][MAXN];
int min_mon[MAXN][MAXN];
int a = re(), b = re(), n = re();
// deque<int> dq;
// 先用单调队列（升序）扫一遍，记录每个n*n矩阵的最大值，
// 再用单调队列（降序）扫一遍，记录每个n*n矩阵的最小值；
struct node
{
    int i, j;
};

deque<node> dq; // 队头即front最大，反之亦然
inline void add_min(int x1, int y1)
{
    while (!dq.empty() && dq.front().j <= y1 - n)
    {
        dq.pop_front(); /* code */
    }
    while (!dq.empty() && arr[dq.back().i][dq.back().j] > arr[x1][y1])
    {
        dq.pop_back();
    }
    node ans = {x1, y1};
    dq.push_back(ans);
}
inline void init_min(int x)
{
    dq.clear();
    for (int j = 1; j <= n; ++j)
    {
        for (int i = x; i < x + n; ++i)
        {
            add_min(i, j);
        }
    }
}
inline void add_max(int x1, int y1)
{
    while (!dq.empty() && dq.front().j <= y1 - n)
    {
        dq.pop_front(); /* code */
    }
    while (!dq.empty() && arr[dq.back().i][dq.back().j] < arr[x1][y1])
    {
        dq.pop_back();
    }
    node ans = {x1, y1};
    dq.push_back(ans);
}
inline void init_max(int x)
{
    while (!dq.empty())
    {
        dq.pop_back();
    }
    
    for (int j = 1; j <= n; ++j)
    {
        for (int i = x; i < x + n; ++i)
        {
            add_max(i, j);
        }
    }
}
void solve()
{
    for (int i = 1; i <= a; ++i)
    {
        for (int j = 1; j <= b; ++j)
        {
            arr[i][j] = re();
        }
    }
    
    int ans = INF;
    // time_t start = clock();

    for (int i = 1; i <= a - n + 1; ++i)
    {
        init_min(i);
        min_mon[i][n] = arr[dq.front().i][dq.front().j];
        for (int j = n + 1; j <= b; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                add_min(i + k, j);
            }
            min_mon[i][j] = arr[dq.front().i][dq.front().j];
        }
    }
    // time_t duration =clock()-start;
    // cerr<<"time = "<<duration<<endl;
    for (int i = 1; i <= a - n + 1; ++i)
    {
        init_max(i);
        max_mon[i][n] = arr[dq.front().i][dq.front().j];
        for (int j = n + 1; j <= b; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                add_max(i + k, j);
            }
            max_mon[i][j] = arr[dq.front().i][dq.front().j];
        }
    }
    for (int i = 1; i <= a - n + 1; ++i)
    {
        for (int j = n; j <= b; ++j)
        {
            ans = __min(ans, (max_mon[i][j] - min_mon[i][j]));
        }
    }
    cout << ans << endl;
}
signed main()
{
    int N = 1;
    while (N--)
    {
        solve();
    }
    return 0;
}