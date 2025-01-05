#include <bits/stdc++.h>
#define ll long long
#define INF 0x7fffffff
const int POS_N = 10001;
#define int long long
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
int A[3010];
int B[3010];

int d[5][5];
ll f[3010][3010][3];

int pd(char s)
{
    if (s == 'A')
        return 1;
    else if (s == 'T')
        return 2;
    else if (s == 'G')
        return 3;
    else
        return 4;
}
void solve()
{
    string strA, strB;
    cin >> strA >> strB;
    int n = strA.size();
    int m = strB.size();
    // shfit(strA, strB);
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 1; j <= 4; ++j)
        {
            d[i][j] = re();
        }
    }
    int a = re(), b = re();

    for (int i = 1; i <= n; i++)
        A[i] = pd(strA[i - 1]);
    for (int i = 1; i <= m; i++)
        B[i] = pd(strB[i - 1]);
     for(int i=1;i<=n;i++){
		f[i][0][1]=f[i][0][0]=-INF;
		f[i][0][2]=-a-b*(i-1);
	}
	for(int i=1;i<=m;i++){
		f[0][i][2]=f[0][i][0]=-INF;
		f[0][i][1]=-a-b*(i-1);
	}
	f[0][0][1]=f[0][0][2]=-INF;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            f[i][j][0] = max(f[i - 1][j - 1][0], max(f[i - 1][j - 1][1], f[i - 1][j - 1][2])) + d[A[i]][B[j]];
            f[i][j][1] = max(f[i][j - 1][1] - b, max(f[i][j - 1][0] - a, f[i][j - 1][2] - a));
            f[i][j][2] = max(f[i - 1][j][2] - b, max(f[i - 1][j][0] - a, f[i - 1][j][1] - a));
        }
    }
    cout << max(f[n][m][0], max(f[n][m][1], f[n][m][2])) << endl;
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