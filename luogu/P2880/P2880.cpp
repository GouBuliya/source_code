// #include <bits/stdc++.h>
// #define ll long long
// #define INF 0x7fffffff
// const int POS_N = 10001;
// #define pn putchar('\n')
// #define mclear(a) memset(a, 0, sizeof a)
// #define fls() fflush(stdout)
// using namespace std;
// int re()
// {
//     int x = 0, t = 1;
//     char ch = getchar();
//     while (ch > '9' || ch < '0')
//     {
//         if (ch == '-')
//             t = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9')
//         x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
//     return x * t;
// }
// const int MAXN = 50010;
// int arr[MAXN];

// void solve()
// {
//     int n = re(), q = re();
//     for (int i = 1; i <= n; ++i)
//         arr[i] = re();
//     for (int i = 1; i <= q; ++i)
//     {
//         int l = re(), r = re();
//         vector<int> st;
//         vector<int> st1;
//         for (int j = l; j <= r; ++j)
//         {
//             while (!st.empty() && st.back() >= arr[j]) // 求最小的
//                 st.pop_back();
//             st.push_back(arr[j]);
//         }
//         for (int j = l; j <= r; ++j)
//         {
//             while (!st1.empty() && st1.back() <= arr[j]) // 求最大的
//                 st1.pop_back();
//             st1.push_back(arr[j]);
//         }
//         // int top = 0;
//         // for (int j = l; j <= r; ++j)
//         // {
//         //     while (top > 0 && arr[j] <= st[top])
//         //         top--;
//         //     st[++top] = arr[j];
//         // }
//         // int top1=0;
//         // for (int j = l; j <= r; ++j)
//         // {
//         //     while (top1  && arr[j] > st[top1])
//         //         top1--;
//         //     st1[++top1] = arr[j];
//         // }
//         // int ans = st1.top() - st.top();
//         printf("%d\n", st1[0]-st[0]);
//     }
// }
// signed main()
// {
//     int N = 1;
//     while (N--)
//     {
//         solve();
//     }
//     return 0;
// }
//----------以上是单调站40分解法--------
//==========以下是ST表正解============
#include <bits/stdc++.h>
#define ll long long
#define INF 0x7fffffff
const int POS_N = 10001;
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
const int maxn = 180000 + 7;
int Fmax[maxn][20];
int Fmin[maxn][20];
int lg[maxn];
void solve()
{
    int n = re();
    int q = re();
    for (int i = 1; i <= n; ++i)
        Fmax[i][0] = Fmin[i][0] = re();
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i >> 1] + 1;
    for (int j = 1; j <= lg[n]; ++j)
        for (int i = 1; i <= n - (j << 1) + 1; ++i)
        {
            Fmax[i][j] = max(Fmax[i][j - 1], Fmax[i + (1 << (j - 1)) ][j - 1]);
            Fmin[i][j] = min(Fmin[i][j - 1], Fmin[i + (1 << (j - 1)) ][j - 1]);
        }
    for (int i = 1; i <= q; ++i)
    {
        int x=re(),y=re();
        int l=lg[y-x+1];
        printf("%d\n", max(Fmax[x][l],Fmax[y-(1<<l)+1][l])-min(Fmin[x][l],Fmin[y-(1<<l)+1][l]));
    }

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