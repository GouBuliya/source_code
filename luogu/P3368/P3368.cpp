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
// const int maxn=500000+7;
// int arr[maxn];
// int prefix[maxn];
// int BIT[500000+7];
// int n;
// int m;
// int lowbit (int x)
// {
//     return x&(-x);
// }
// void add(int x,int y)
// {
//    for(int i=x;i<=n;i+=lowbit(i))BIT[i]+=y;
// }
// ll sum(int x)
// {
//     ll res=0;
//     for(int i=x;i;i-=lowbit(i))res+=BIT[i];
//     return res;
// }
// signed main()
// {
//     int op;
//     n=re(),m=re();
//     for(int i=1;i<=n;++i)
//     {
//         arr[i]=re();
//         prefix[i]=arr[i]-arr[i-1];
//         add(i,prefix[i]);
//     }
//     while (m--)
//     {
//         int op=re();
//         if(op==1)
//         {
//             int x=re(),y=re(),k=re();
//             add(x,k);
//             add(y+1,-k);
//         }
//         else
//         {
//             int x=re();
//             printf("%d\n",sum(x));
//         }
//     }

//     return 0;
// }
#include <bits/stdc++.h>
#define ll long long
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
const int maxn = 5 * 1e5 + 7;
int n, m;
int arr[maxn];
int BIT[maxn];
int lowbit(int x)
{
    return x & (-x);
}
void BIT_add(int x, int y)
{
    for (int i = x; i <= n; i += lowbit(i))
        BIT[i] += y;
}
ll BIT_sum(int x)
{
    ll res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += BIT[i];
    return res;
}
ll BIT_pre(int x)
{
    return BIT_sum(x);
}
signed main()
{
    n = re(), m = re();
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = re();
        BIT_add(i, arr[i] - arr[i - 1]);
    }
    for (int i = 1; i <= m; ++i)
    {
        int mod = re();
        if (mod == 1)
        {
            int x = re(), y = re(), k = re();
            BIT_add(x,k);BIT_add(y+1,-k);
        }
        else
        {
            int x = re();
            printf("%lld\n", BIT_pre(x));
        }
    }
    return 0;
}
