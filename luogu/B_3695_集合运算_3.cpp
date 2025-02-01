#include<bits/stdc++.h>
#define ll long long
#define pn cout<<'\n';
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
namespace my {
    const int INF = (1 << 30);
    ll re()
    {
        ll t; std::cin >> t;return t;
    } 
    const int maxn=3e4+10;
    std::vector<std::bitset<maxn*2>>A(maxn);
    std::bitset<maxn*2>bit;
    void solve()
    {
       int n=re();
       int m=re();
       int q=re();
       for(int i=1;i<=n;++i)
       {
            int t=re();
            for(int j=1;j<=t;++j)
            {
                A[i].set(re());
            }
       }
       for(int i=1;i<=m;++i)
       {
            bit.set(i);
       }
       for(int i=1;i<=q;++i)
       {
            int op=re();
            int x=re();
            int y=re();
            if(op==1)
            {
                A[x]=A[x]<<y&bit;
            }
            else if(op==2)
            {
                A[x]=A[x]>>y&bit;
            }
            else if(op==3)
            {
                std::cout<<(A[x]&A[y]).count()<<std::endl;
            }else if(op==4)
            {
                std::cout<<(A[x]|A[y]).count()<<std::endl;
            }else if(op==5)
            {
                std::cout<<(A[x]^A[y]).count()<<std::endl;
            }
       }
    }
}
signed main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t = 1;while (t--)my::solve();return 0;
}