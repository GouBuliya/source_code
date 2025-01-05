#include <bits/stdc++.h>
#define ll long long
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
char Map[1000 + 7][1000 + 7];
//设数组dp[i][j]表示在第i行第j列的最大答案
/**/
string ss;
const int dx[]={0,0,0,-1,+1};
const int dy[]={0,1,-1,0,0};
void DFS(int deep,int x,int y)
{
    if(Map[x][y]=='#')
        return;
    
} 
signed main()
{
    int n = re(), m = re();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%c", &Map[i][j]);
        }
        getchar();
    }
    
    return 0;
}
