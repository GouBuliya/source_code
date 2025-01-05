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
void solve()
{
    int n=re();
    vector <ll>a(1),b(1);
    ll long_boat=0;
    for(int i=1;i<=n;++i)
    {
        int input_a_temp=re();
        a.push_back(input_a_temp);
        int input_b_temp=re();
        b.push_back(input_b_temp);
    }
    sort(a.begin()+1,a.begin()+1+n);
    sort(b.begin()+1,b.begin()+1+n);
    for(int i=1;i<=n;++i)
    {
        long_boat+=b[i]-a[i];
        if(i+1<=n)
        {
            if(b[i]>a[i+1])
            {
                long_boat-=b[i]-a[i+1];
            }
        }
    }
    cout<<long_boat<<endl;

}
signed main()
{
int N=1;
while(N--)
{
    solve();
}
    return 0;
}