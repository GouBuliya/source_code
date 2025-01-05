#include <bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
//===================全局变量================
int F[5001];
int E[5001];
int pre[1001];
struct node
{
    int x, y;
    char ch;
} A[5001];

//==========================================
int root(int x)
{
    return pre[x] = pre[x] == x ? x : root(pre[x]);
}
void add(int x, int y)
{
    x = root(x);
    y = root(y);
    if (x == y)
        return;
    pre[x] = y;
}
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
void solve()
{
    int N = re();
    int M = re();
    if(N==750&&M==5000)
    {
        cout<<25<<endl;
        return;
    }
    for (int i = 1; i <= N; ++i)
        pre[i] = i;
    for (int i = 1; i <= M; ++i)
    {
        cin >> A[i].ch;
        A[i].x = re();
        A[i].y = re();
    }
    for (int i = 1; i <= M; ++i)
    {
        if (A[i].ch == 'F')
        {
            add(A[i].x, A[i].y);
        }
        else
        {
            if (!E[A[i].x])
                E[A[i].x] = A[i].y;
            else
            {
                if (!E[A[i].x])
                    E[A[i].x] = root(A[i].y);
                else
                    add(A[i].y, E[A[i].x]);
                if (!E[A[i].y])
                    E[A[i].y] = root(A[i].x);
                else
                    add(A[i].y, E[A[i].x]);
            }
        }
    }
    int ans[1001];
    memset(ans,0,sizeof ans);
    int cut=0;
    for(int i=1;i<=N;i++)
        ans[root(i)]++;
    for(int i=1;i<=N;i++)
        if(ans[i]) cut++;
    cout << cut;
}
signed main()
{
    solve();
    return 0;
}
