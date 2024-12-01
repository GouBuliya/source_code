#include <bits/stdc++.h>
#define ll long long
#define INF = 0x7fffffff
const int POS_N = 10001;
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
//=============== 类================
class Node
{
private:
    /* data */
public:
    int A, B;
    int data;
} node[100000 + 5];
//============全局变量======
int pre[20005]; // N的父亲
int foe[20005]; // N的敌人
int root(int x) // 寻根函数，查找x的根
{
    return pre[x] = pre[x] == x ? x : root(pre[x]);
}
void add(int x, int y) // 合并函数，将x，y合并
{
    x = root(x), y = root(y);
    if (x == y)
        return;
    else
    {
        pre[x] = y;
    }
}
int re() // 快读
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
bool cmp(Node x, Node y) // 自定义sort
{
    return x.data > y.data;
}
bool cheak(int x, int y) // 检查函数，如果true输出结果//
{
    return root(x) == root(y) ? true : false;
}
void solve() // 项目函数
{
    int N = re(), M = re();
    for(int i=1;i<=N;++i)
    {
        pre[i]=i;
    }
    for (int i = 1; i <= M; ++i)

    {
        node[i].A = re();
        node[i].B = re();
        node[i].data = re();
    }
    sort(node + 1, node + M + 1, cmp);
    for (int i = 1; i <= M+1; ++i)
    {
        if (cheak(node[i].A, node[i].B))
        {
            printf("%d", node[i].data);
            break;
        }
        else
        {
            if (!foe[node[i].A])
                foe[node[i].A] = node[i].B;
            else
                add(foe[node[i].A], node[i].B);
            if (!foe[node[i].B])
                foe[node[i].B] = node[i].A;
            else
                add(foe[node[i].B], node[i].A);
        }
    }
    return;
}
signed main()
{
    
    solve();return 0;
}