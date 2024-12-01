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
signed main()
{
    freopen("data.in","w",stdout);
    mt19937 Rand(time(0));
    int n=Rand()%100000;
    int m=Rand()%100000;
    printf("%d\n",n);
    while (n--)
    {
        printf("%d ",Rand()%10000);
    }
    printf("%d\n",m);
    while (m--)
    {
        printf("%d %d\n",Rand()%10000,Rand()%10000);
    }
    fclose(stdout);
    return 0;
}
                                                                                                                                                                                  
