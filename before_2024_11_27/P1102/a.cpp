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
const int maxn=2e5+10;
struct edge{
    int l;int r;int t;
}A[maxn];
bool cmp(edge C,edge B)
{
    if(C.r!=B.r)
    {
        return C.r<B.r;
    }
    else
    {
        return C.l<B.l;
    }
}
bool val[maxn];
signed main()
{


    int n=re();
    int h=re();
    for(int i=1;i<=h;++i)
        A[i].l=re(),A[i].r=re();
    sort(A+1,A+1+h,cmp);
    int ans=0;
    for(int i=1;i<=h;++i)
    {
        int k=0;
        for(int j=A[i].l;j<=A[i].r;++j)
        {
            if(val[j])
            k++;
            else
                break;
        }
        for(int j=A[i].r;k>=A[i].t||j>=A[i].l;--j)
        {
            val[j]=1;
            ans++;
            k++;
        }
    }
    cout<<ans<<endl;


}