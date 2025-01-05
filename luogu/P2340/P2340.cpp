// #include<bits/stdc++.h>
// #define ll long long
// #define pn putchar('\n')
// #define mclear(a) memset(a,0,sizeof a)
// #define fls() fflush(stdout)
// using namespace std;
// int re()
// {
//     int x=0,t=1;char ch=getchar();
//     while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
//     while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
//     return x*t;
// }//f[i][j]表示智商i情商j的最大和
// int f[1000][3];
// int A[1000][2];

// signed main()
// {
//     #ifndef ONLINE_JUDGE
//     // freopen("in.txt","r",stdin);
//     #endif
//     int N=re();
//     for(int i=1;i<=N;++i)
//     {
//         A[i][1]=re();
//         A[i][0]=re();
//     }
//     int maxx=-0x7fffffff;

//     for(int i=1;i<=N;++i)
//     {
//         if((f[i][1]+A[i][1])<0||(f[i][0]+A[i][0])<0)
//         {
//             continue;
//         }
//         else
//         {
//             if((A[i][1]+A[i][0])<0)
//             {
//                 continue;
//             }
//             else
//             {
//             f[i][1]+=A[i][1];f[i][0]+=A[i][0];
//             f[i][2]+=A[i][1]+A[i][0];

//             }

//         }
//     }

//     cout<<f[N][2]<<endl;
//     return 0;
// }

#include <bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
const int MR = 400000;
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
int f[2 * MR + 2]; //;
// F[I][j]
int A[1000][2];

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int N = re();
    for (int i = 1; i <= N; ++i)
    {
        A[i][1] = re();
        A[i][0] = re();
    }
    memset(f, -0x3f, sizeof(f));
    int mmax;
    f[MR] = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (A[i][1] >= 0)
        {
            for (int j = 2 * MR; j >= A[i][1]; j--)
            {
                f[j] = max(f[j], f[j - A[i][1]] + A[i][0]);
            }
        }
        else
        {
            for (int j = 0; j <= 2 * MR + A[i][1]; ++j)
            {
                f[j] = max(f[j], f[j - A[i][1]] + A[i][0]);
            }
        }
    }
    int ans=0;
    for (int i = MR; i <= MR * 2; ++i)
    {
        if(f[i]>0)
        {
           ans=max(ans,i+f[i]-MR); 
        }
    }
    cout << ans;
    return 0;
}
