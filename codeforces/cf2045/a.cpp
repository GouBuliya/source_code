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

const int maxn=220;
int G[maxn][maxn];
int ANS[4][maxn];
int FX[9]={0,0,-1,-1,-1,0,1,1,1};
int FY[9]={0,1,1,0,-1,-1,-1,0,1};
int Afx[9]={0,7,6,5,INF,3,2,1,INF};
int Bfx[9]={0,3,INF,1,8,7,INF,5,4};
int vis[maxn][9];
int ctof;
bool isen=0;
int n,m;
void dfs(int fx,int x,int y,int tot)
    {

        if(fx==INF)
            return;
        if(tot>=ctof)
        {
            isen=1;
            return;
        }
        if(x>=m+1||x<=0||y>=n+1||y<=0)
            return;
        if(G[x+FX[fx]][y+FY[fx]])
        {
            x+=FX[fx],y+=FY[fx];
            int k=G[x+FX[fx]][y+FY[fx]];
            dfs(k==2?Afx[fx]:Bfx[fx],x+FX[k==2?Afx[fx]:Bfx[fx]],y+FX[k==2?Afx[fx]:Bfx[fx]],tot+1);
        }
        else 
        {
            dfs(fx,x+FX[fx],y+FY[fx],tot);
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
    n=re(),m=re();
    string ans;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            char str;
            std::cin>>str;
            if(str=='.')
                G[i][j]=0;
            else if(str=='/')
                ctof++,G[i][j]=1;
            else if(str=='\\')
                ctof++,G[i][j]=2;
            
        }
                
    int  flag=0;
    for(int i=1;i<=4;i++)
        if(i==2||i==4)
        {
            for(int j=1;j<=n;++j)
            {
                dfs((i==2?3:7),(i==2?m+1:0),j,0);
                if(isen){
                    isen=0;
                    string str=i==2?"E ":"W ";
                    str+=(char)j+'0';
                    str+=' ';
                    ans+=str;
                    flag++;}
            }
        }
        else
        {
            for(int j=1;j<=m;++j)
            {
                dfs((i==1?5:1),(i==1?0:n+1),j,0);
                if(isen){
                    isen=0;
                    string str=i==1?"N ":"S "; 
                    str+=(char)j+'0';
                    str+=' ';
                    ans+=str;

                    flag++;
                }
            }
        }
    if(flag)
        cout<<0<<'\n';
    else
        cout<<flag<<'\n'<<ans<<'\n';

    return 0;
}
};
signed main ()
{
    return my::main();
}

