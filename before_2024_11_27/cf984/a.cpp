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
void solve()
{
    vector<int>A;
    int n=re();
    for(int i=1;i<=n;++i)
        A.push_back(re());
    bool flag=0;
    for(int i=0;i<A.size()-1;++i)
    {
        if(A[i]-A[i+1]==-5||A[i]-A[i+1]==-7||A[i]-A[i+1]==5||A[i]-A[i+1]==7)
            flag=0;
        else {
            flag=1;break;}
    }
    if(flag)
        cout<<"no"<<'\n';
    else 
        cout<<"yes"<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("ina","r",stdin);
    #endif
    int t=re();
    while (t--)
        solve();
    return 0;
}
                                                                                                                                                                                  

