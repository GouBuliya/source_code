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
int c[1000001];
int mmax = 0;
signed main()
{
    int N;
    cin >> N;

    //    cout<<N;
    for (int i = 1; i <= N; ++i)
    {
        int x;
        cin >> x;
        mmax = max(mmax, x);
        int m = sqrt(x);

        for (int j = 1; j <= m; j++)
            if (x % j == 0)

            {
                c[j]++;

                if (x != j * j)
                    c[x / j]++;
            }
    }

    int x = mmax;
    // cout << mmax << endl;
    for (int i = 1; i <= N; ++i)
    {
        while (c[x] < i)
        {
            x--;
        }
        cout << x << endl;
    }

    return 0;
}