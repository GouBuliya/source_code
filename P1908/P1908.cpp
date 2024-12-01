// #include <bits/stdc++.h>
// #define ll long long
// #define INF 0x7fffffff
// const int POS_N = 1e5 * 5 + 7;
// #define pn putchar('\n')
// #define mclear(a) memset(a, 0, sizeof a)
// #define fls() fflush(stdout)
// #define int long long
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
// ll arr[POS_N];
// ll c[POS_N];
// ll ans = 0;
// void m_sort(int l, int r)
// {
//     if (l == r)
//         return;
//     int mid = (l + r) / 2;
//     m_sort(l, mid);
//     m_sort(mid + 1, r);
//     int i=l,j=mid+1,k=l;
//     while (i<=mid&&j<=r)
//     {
//         if(arr[i]<=arr[j])
//             c[k++]=arr[i++];
//         else
//         {   
//             c[k++]=arr[j++],ans+=mid-i+1;
//         }
//     }
//     while (i<=mid)
//         c[k++]=arr[i++];
//     while (j<=r)
//         c[k++]=arr[j++];
//     for(int v=l;v<=r;++v)
//     {
//         arr[v]=c[v];
//     }        
    
// }
// void solve()
// {
//     int n = re();
//     for (int i = 1; i <= n; ++i)
//         arr[i] = re();
//     m_sort(1, n);
//     printf("%lld ", ans);
// }
// signed main()
// {
//     int N = 1;
//     while (N--)
//     {
//         solve();
//     }
//     return 0;
// }
//树状数组
#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define int long long
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
int IntArr[maxn];
int BIT[maxn];
int n;
int lowbit(int x)
{
    return x&(-x);
}
void add (int x,int y)
{
    for(int i=x;i<=n;i+=lowbit(i))
        BIT[i]+=y;
}
ll sum(int x)
{
    ll res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=BIT[i];
    return res;
}
int b[maxn];
signed main()
{
    n=re();ll ans=0;
    for(int i=1;i<=n;++i)
    {
        IntArr[i]=re();
        b[i]=IntArr[i];
    }  
    sort(b+1,b+1+n);
    int m=unique(b+1,b+1+n)-1-b;
    for(int i=n;i;i--)
    {
        int k=lower_bound(b+1,b+m+1,IntArr[i])-b;
        ans+=sum(k-1);
        add(k,1);
    }
    printf("%lld",ans);
    return 0;
}
                                                                                                                                                                                  
