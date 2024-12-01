#include <bits/stdc++.h>
using namespace std;
#define pp1 cout<<1<<endl;
int re()
{
        int t;
        cin>>t;
        return t;
}
const int maxn=100+10;
int M[maxn];
int J[maxn];
int f[maxn][maxn][2];
int S[maxn];
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
    #endif
    int n=re(),c=re();
    for(int i=1;i<=n;++i)
    {
        M[i]=re(),J[i]=re();
    }
    for(int i=1;i<=n;++i)
        S[i]=S[i-1]+J[i];
    for(int len=1;len<=n;++len)
    {
        for(int l=1;l+len-1<=n;++l)
        {
            int r=l+len-1;
            if(!(c>=l&&c<=r))
            {
                f[l][r][1]=f[l][r][0]=1e9;
                continue;
            }
            if(len==1)
            {
                f[l][r][1]=f[l][r][0]=0;
                continue;
            }
            f[l][r][1]=f[l][r][0]=1e9;
            vector<tuple<int,int,bool>>T;

            T.push_back({l+1,r,0});
            T.push_back({l+1,r,1});
            T.push_back({l,r-1,0});
            T.push_back({l,r-1,1});
            for(auto &[ll,rr,t]:T)
            {
                int u=l==ll?1:0;
                int x=t==0?ll:rr;
                int y=u==0?l:r;
                int dis=abs(M[x]-M[y]);
                int w1=S[ll-1];
                int w2=S[n]-S[rr];

                int w=dis*(w1+w2);
                f[l][r][u]=min(f[l][r][u],f[ll][rr][t]+w);
            }
            //f[l][r][0]=min(f[l][r][0],f[l+1][r][0]+(S[l]+S[n]-S[r-1])*(M[l+1]-M[l]));
            //f[l][r][1]=min(f[l][r][1],f[l][r-1][0]+(S[l-1]+S[n]-S[r-2])*(M[r]-M[l]));
            //f[l][r][1]=min(f[l][r][1],f[l][r-1][1]+(S[l-1]+S[n]-S[r-2])*(M[r]-M[r-1]));
            //f[l][r][0]=min(f[l][r][0],f[l+1][r][0]+(S[l]+S[n]-S[r-1])*(M[r]-M[l]));
        }
    }
    cout<<min(f[1][n][1],f[1][n][0]);       

    return 0;
}

