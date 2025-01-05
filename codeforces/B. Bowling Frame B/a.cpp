#include <bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
bool cheak(int w, int b, int rd)
{
    if (w >= rd || b >= rd)
    {
        return true;
    }
    return 0;
}
void solve()
{
    int w, b;
    cin >> w >> b;
    if(w>b)swap(w,b);
    int rd = 1;
    while (cheak(w, b, rd))
    {
        if (rd % 2 == 1)
        {
            if (w % 2 == 1 && w >= rd)
            {
                w -= rd;
                rd++;
            }
            else if (b % 2 == 1 && b >= rd)
            {
                b -= rd;
                rd++;
            }
            else if (w >= rd)
            {
                w -= rd;
                rd++;
            }
            else if (b >= rd)
            {
                b -= rd;
                rd++;
            }
        }
        else
        {
            if (w % 2 == 0 && w >= rd)
            {
                w -= rd;
                rd++;
            }
            else if (b % 2 == 0 && b >= rd)
            {
                b -= rd;
                rd++;
            }
            else if (w >= rd)
            {
                w -= rd;
                rd++;
            }
            else if (b >= rd)
            {
                b -= rd;
                rd++;
            }
        }
    }
    cout << rd-1 << endl;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
