#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
#define maxn 200005
using namespace std;
int re()
{
    int x=0;
    bool t=1;
    char ch=getchar();
    while(ch>'9'||ch<'0')
        t=ch=='-'?0:t,ch=getchar();
    while(ch>='0'&&ch<='9')
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return t?x:-x;
}
int n;
char a[maxn];
void solve()
{
    n=re();
    scanf("%s",a+1);
    ll ans=0;
    for(int i=1,cur=1;i<n;i++)
    {
        if(a[i]!='>')
        {
            ans+=cur;
            cur++;
        }
        else
            cur=1;
    }
    for(int i=1,cur=1;i<n;i++)
    {
        if(a[i]!='<')
        {
            ans+=cur;
            cur++;
        }
        else
            cur=1;
    }
    for(int i=1,cur=1;i<n;i++)
    {
        if(a[i]=='=')
        {
            ans-=2*cur;
            cur++;
        }
        else
            cur=1;
    }
    printf("%lld\n",ans);
}
signed main()
{
    int T=re();
    while(T--)
        solve();
    return 0;
}  }
