#include<bits/stdc++.h>
#define ll long long
#define INF 0x7fffffff
const int POS_N=10001;
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
using namespace std;
int re()
{
    int x=0,t=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*t;
}
int l,r;
int p[114514];
signed main()
{
    for(int i=1;i<114514;i++)
    {
        for(int j=ceil(1.0*l/p[i])*p[i];j<=r;j+=p[i])
        {
        }
    }
    return 0;
}