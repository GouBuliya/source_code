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
vector<int> arr(1);
int n = re();
int k = re();
int maxl = 0;
int maxr = 0;
int f()
{
    int num = 0;
    int l = 1;
    int r = 1;
    int MAX = -INF;
    while (l <= r && r <= arr.size())
    {
        if (arr[r] == -INF)
        {
            while (arr[r] == -INF)
            {
                r++;
                l = r;
            }
            l = r;
        }
        if (l == r)
        {
            ++r;
        }
        else
        {
            if (arr[r] - arr[l] > k)
            {
                l++;
            }
            else
            {

                if (r + 1 - l > MAX)
                {
                    maxl = l;
                    maxr = r;
                    MAX = r - l + 1;
                }
                ++r;
            }
        }
    }
    for (int i = maxl; i <= maxr; ++i)
        arr[i] = -INF;
    return MAX;
}
void solve()
{
    for (int i = 1; i <= n; ++i)
        arr.push_back(re());
    sort(arr.begin() + 1, arr.end());
    int a = f();
    // arr.erase(arr.begin() + maxl, arr.begin() + maxr + 1);
    f();

    int ans = 0;
    for (auto &i : arr)
    {
        if (i == -INF)
        {
            ans++;
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