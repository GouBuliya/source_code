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
// string str[507];
void solve()
{
    int cnt=0;
    string s[600];
    while (true)
    {
        ++cnt;
        cin >> s[cnt];
        if (s[cnt] == "0")
            break;
        bool occ = false;
        for (int i = 1; i < cnt; i++)
        {
            if (s[i] == s[cnt])
            {
                occ = true;
                break;
            }
        }
        if (occ == false)
            cout << s[cnt];
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