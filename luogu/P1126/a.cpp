#include<bits/stdc++.h>
using namespace std;
namespace my{
#define ll long long 
const int INF=(1<<30);
ll re ()
{
    ll t;
    cin>>t;
    return t;
}
int g[55][55];
int G[55][55];
int sffx[5][5];
int nffx[5][5];
void build(int n,int m)
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            G[i][j]=G[i+1][j]=G[i+1][j+1]=G[i][j+1]=g[i][j];
        }
}
void build_end(int x,int y)
{
    G[x][y]=G[x+1][y+1]=G[x+1][y]=G[x][y+1]=3;
}
int FX[5]={0,-1,0,1,0};
int YX[5]={0,0,1,0,-1};
void init()
{
    for(int i=1;i<=4;++i)
    {
        for(int j=i,tot=0;tot<4;++tot)
        {
            if(j==5)
                j=1;
            sffx[i][j++]=tot;
        }
        for(int j=i,tot=0;tot<4;++tot)
        {
            if(j==0)
                j=4;
            nffx[i][j--]=tot;
        }
    }
}
pair<int,int>begin_p;
pair<int,int>end_p;
int dis[55][55];
bool vis[55][55][5];

void BFS(int bx, int by, int fx) {
    queue<tuple<int, int, int, int>> que;  //队列存储 (x, y,方向,时间)
    memset(dis, INF, sizeof(dis));  // 初始化为INF，表示未访问
    memset(vis, 0, sizeof(vis));    // 初始化为0，表示未访问
    vis[bx][by][fx] = 1;
    que.push({bx, by, fx, 0});  // 起点入队
    dis[bx][by]=0;
    while (!que.empty()) {
        auto [ux, uy, fx, tot] = que.front();
        que.pop();

        for (int i = 1; i <= 4; ++i) {
            tot = sffx[fx][i];  // 更新步数
            for (int j = 1; j <= 3; ++j) {
                int vx = ux + FX[i] * j, vy = uy + YX[i] * j;
                if (vx < 1 || vy < 1 || G[vx][vy] == 1 || vis[vx][vy][i]) {
                    continue;  // 遇到边界或障碍，跳过
                }
                vis[vx][vy][i] = 1;
                if (dis[vx][vy] > tot + j) {
                    que.push({vx, vy, i, tot + j});
                    dis[vx][vy] = tot + j;  // 更新最短时间
                }
            }
        }
    }
}
signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n=re();int m=re();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>g[i][j];
    build(n,m);
    begin_p={re(),re()};
    end_p={re(),re()};
    build_end(end_p.first,end_p.second);  
    string fx;
    cin>>fx;
    int Fx;
    if(fx=="N")Fx=1;
    if(fx=="E")Fx=2;
    if(fx=="S")Fx=3;
    if(fx=="W")Fx=4;
    BFS(begin_p.first,begin_p.second,Fx);
    if(dis[end_p.first][end_p.second]==INF)
        cout<<-1<<endl;
    else 
        cout<<dis[end_p.first][end_p.second]<<endl;
    return 0;
}
}
signed main ()
{
    return my::main();
}
/*将所有的格子处理成“reboot ”map*/

