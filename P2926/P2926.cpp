#include <bits/stdc++.h>
#define ll long long
#define INF = 0x7fffffff
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

bool vis[100001];
int N;
struct Node
{
    int A,pos;
}node[100001];

int __f(int x)
{
    
    memset(vis,0,sizeof vis);
    
    for(int i=1;i<=N;++i)
    {
        if(vis[i])
        {
            continue;
        }
        else
        {
            if(node[x].A%node[i].A==0)
            {
                
            }
        }
    }
    // 朴素做法
    //  for(int i=1;i<=N;++i)
    //  {
    //      if(x%A[i]==0)
    //      {
    //          ans++;
    //      }
    //  }
    
}
bool cmp1(Node x,Node y)
{
    return x.A<y.A;
}
void solve()
{
    N = re();
    for (size_t i = 1; i <= N; ++i)
    {
        node[i].A = re();
        node[i].pos=i;
    }
    sort(node+1,node+N+1,cmp1);

    return;
}
signed main()
{
    solve();
    return 0;
}