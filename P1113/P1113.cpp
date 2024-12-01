#include <bits/stdc++.h>
#define ll long long
#define inf = 0x7fffffff
const int pos_n = 10001;
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
struct node
{

    vector<int> pre;
    int len = 0;

} node[10001];
int vis[10001];
int dfs(int x)
{
    if(vis[x])
    return vis[x];
    for(int i=0;i<node[x].pre.size();++i)
    {
        vis[x]=max(vis[x],dfs(node[x].pre[i]));
    }
    vis[x]+node[x].len;
    return vis[x];
}
void solve()
{
    int n = re();
    for (int i = 1; i <= n; ++i)
    {
        node[i].len = re();
        int tmp;
        while (scanf("%d", &tmp) && tmp)
        {
            node[i].pre.push_back(tmp);
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        ans=max(ans,dfs(i));
    }
    cout<<ans;  
}
signed main()
{
    solve();
    return 0;
}