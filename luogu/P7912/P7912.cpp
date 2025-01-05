#include <bits/stdc++.h>
#define ll long long
#define INF = 0x7fffffff
const int POS_N = 10001;
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
void wr(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        wr(x / 10);
    putchar(x % 10 + '0');
    return;
}
inline int re()
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
int head = 1;
int ilde;
struct Node
{
    int data;
    int la;
    int nx;
    bool flag = 1;
} node[200001];

void del(int pos)
{

    node[node[pos].la].nx = node[pos].nx;
    node[pos].flag = 0;
}
void solve()
{
    int N = re();
    ilde = N;
    for (int i = 1; i <= N; ++i)
    {
        node[i].data = re();
        node[i].la = i - 1;
        node[i].nx = i + 1;
    }
    while (head != ilde)
    {
        int h = head;

        if (!node[head].flag)
        {
            head++;
            continue;
        }

        bool flag = 1;
        while (h < ilde)
        {
            if (flag)
            {
                printf("%d ", h);
                del(h);
                flag = 0;
            }
            int now = node[h].data;
            h = node[h].nx;
            if (now == node[h].data)
                continue;
            else if (node[h].flag)
            {
                printf("%d ", h);
                fls();
                del(h);
            }
        }
        if (h == ilde && node[ilde].flag == 0)
            ilde = node[ilde].la;
        del(head - 1);
        pn;
    }
}
signed main()
{
    solve();
    return 0;
}