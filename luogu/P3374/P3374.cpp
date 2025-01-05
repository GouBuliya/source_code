// #include <bits/stdc++.h>
// #define ll long long
// #define pn putchar('\n')
// #define mclear(a) memset(a, 0, sizeof a)
// #define fls() fflush(stdout)
// using namespace std;
// int re()
// {
//     int x = 0, t = 1;
//     char ch = getchar();
//     while (ch > '9' || ch < '0')
//     {
//         if (ch == '-')
//             t = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9')
//         x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
//     return x * t;
// }
// const int maxn = 5 * 1e5 + 7;
// int arr[maxn];
// ll prefix[maxn];
// int n = re();
// int m = re();
// int BIT[maxn];
// int lowbit(int x) { return x & (-x); }
// void add_BIT(int x, int k)
// {
//     for (int i = x; i <= n; i += lowbit((i)))
//         BIT[i] += k;
// }
// ll sum(int x)
// {
//     ll res = 0;
//     for (int i = x; i; i -= lowbit(i))
//         res += BIT[i];
//     return res;
// }
// ll pre(int x, int y)
// {
//     return sum(y) - sum(x-1);
// }
// signed main()
// {
//     for (int i = 1; i <= n; ++i)
//         arr[i] = re();
//     for (int i = 1; i <= n; ++i)
//     {
//         prefix[i] = prefix[i - 1] + arr[i];
//         BIT[i] = prefix[i] - prefix[i - lowbit(i)];
//     }
//     for (int i = 1; i <= m; ++i)
//     {
//         int mod = re();
//         int x=re(),y=re();
//         if (mod == 1)
//             add_BIT(x, y);
//         else
//             printf("%lld\n",pre(x,y));
//     }
//     return 0;
// }
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
const int maxn=5*1e5+7;
int n,m;
int A[maxn];
ll BIT[maxn];
int lowbit(int x){return x&(-x);}
void BIT_add(int x,int y)
{
    for(int i=x;i<=n;i+=lowbit(i))
        BIT[i]+=y;
}
ll BIT_sum(int x)
{
    ll res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=BIT[i];
    return res;
}
ll BIT_pre(int x,int y)
{
    return BIT_sum(y)-BIT_sum(x-1);
}
signed main()
{
    n=re();m=re();
    for(int i=1;i<=n;++i)
        A[i]=re(),BIT_add(i,A[i]);
    
    for(int i=1;i<=m;++i)
    {
        int mod=re();
        int x=re();
        int y=re();
        if(mod==1)
        {
            BIT_add(x,y);
        }
        else
        {
            printf("%lld\n",BIT_pre(x,y));
        }
    }
    return 0;
}
                                                                                                                                                                                  
