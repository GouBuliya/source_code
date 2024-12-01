#include<bits/stdc++.h>
#define ll long long
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
const int maxn=5e5+10;
int b[maxn];
int n,m;
inline int lowbit(int x){return x&(-x);}
void add(int x,int y)
{
    for(int i=x;i<=n;i+=lowbit(i))
        b[i]+=y;
}
int ask(int x)
{
    int y=0;
    for(int i=x;i;i-=lowbit(i))
        y+=b[i];
    return y;
}
signed main()
{
    n=re(),m=re();
    for(int i=1;i<=n;i++)
    {
        add(i,re());
    }
    for(int i=1;i<=m;++i)
    {
        int t=re();
        if(t==1)
        {
            int x=re(),k=re();
            add(x,k);
        }
        else
        {
            int x=re(),y=re();
            printf("%d\n",ask(y)-ask(x-1));
        }
    }

    return 0;
}
                                                                                                                                                                                  
