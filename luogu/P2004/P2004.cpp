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
int mat[1000+10][1000+10];
int maxx, maxy;
int max_C_mat_area = -INF;
int prefix[1000+10][1000+10];
void solve()
{
    int n = re();
    int m = re();
    int c = re();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            mat[i][j] = re();
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + mat[i][j];
        }
    }
    for (int i =  c; i <= n; ++i)
    {
        for (int j =  c; j <= m; ++j)
        {
            int area_C_mat = 0;
            area_C_mat = prefix[i][j] - prefix[i - c][j] - prefix[i][j - c] + prefix[i - c][j - c];
            // max_C_mat_area=max(max_C_mat_area,area_C_mat);
            // cout<<area_C_mat<<endl;
            if (max_C_mat_area < area_C_mat)
            {
                maxx = i - c;
                maxy = j - c;
                max_C_mat_area=area_C_mat;
            }
        }
    }
    // for(int i=0;i+c<=n+1;++i)
    //     for(int j=0;j+c<=m+1;++j)
    //     {
    //         int area_C_mat = prefix[i+c][j+c] + prefix[i][j] - prefix[i][j + c] + prefix[i + c][j];
    //         cout<<area_C_mat<<endl;
    //     }
    cout << maxx+1 << " " << maxy+1 << endl;
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