#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
#define int long long
using namespace std;
inline int re()
{
    int x=0,t=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*t;
}
// inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int gcd(int a, int b) {
  return b==0?a:gcd(b,a%b);
}
inline int lcm(int x,int y) {return (x*y)/gcd(x,y);}
void solve()
{
    int a0=re(),a1=re(),b0=re(),b1=re();
    int ans=0;int p=a0/a1,q=b1/b0;
    for(int x=1;x*x<=b1;++x)
    {
        if(b1%x==0)
        {
            // if(gcd(x/a1,a0/a1)==1&&x%a1==0&&gcd(b1/x,b1/b0)==1)
            if(x%a1==0&&gcd(x/a1,p)==1&&gcd(q,b1/x)==1)
            {ans++;}
            int y=b1/x;
            if(y==x)
            continue;
            // if(gcd(y/a1,a0/a1)==1&&y%a1==0&&gcd(b1/y,b1/b0)==1)
            if(y%a1==0&&gcd(y/a1,p)==1&&gcd(q,b1/y)==1)
            {ans++;}
            
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    int N=re();
    while (N--)
    {
        solve();
    }
    
    return 0;
}
                                                                                                                                                                                  
