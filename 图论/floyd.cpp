#include <bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
ll re()
{
    ll t;
    cin >> t;
    return t;
}
const int maxn = 110;
const int maxm = 5000;
int G[maxn][maxm];
int f[maxm][maxm];
int n;
int m;

void inG()
{
    n = re();
    m = re();
    int x, y, k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if(i!=j)
                f[i][j] = 1e9;
            else 
                f[i][j]=0;
    for (int i = 1; i <= m; ++i)
    {
        x = re(), y = re(), k = re();
        f[y][x]=f[x][y] =x==y?0: min(f[x][y],k);
    }
}
void F()
{
    for (int k = 1; k <= n; k++)
    {
        for (int x = 1; x <= n; ++x)
        {
            for (int y = 1; y <= n; ++y)
            {
                f[x][y] = min(f[x][y], f[x][k] + f[k][y]);
            }
        }
    }
}
void IO_out()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {

            cout <<  f[i][j]<< " ";
        }
        cout << '\n';
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    inG();
    F();
    IO_out();
    return 0;
}
