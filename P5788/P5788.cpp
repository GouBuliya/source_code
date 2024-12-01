#include <bits/stdc++.h>
#define ll long long
#define INF 0x7fffffff
const int POS_N = 10001;
#define pn putchar('\n')
// #define int long long
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

int arr[3000007];
int ans[3000007];
stack<int> st;
void solve()
{
    // int n = re();
    int n;scanf("%d",&n);
    for (int i = 1; i <= n; ++i)
        // arr[i] = re();
        scanf("%d",&arr[i]);
    for (int i = n; i >= 1; --i)
    {
        while (!st.empty() && arr[i] >= arr[st.top()])
            st.pop();
        if (!st.empty())
            ans[i] = st.top();
        st.push(i);
    }
    for (int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);
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