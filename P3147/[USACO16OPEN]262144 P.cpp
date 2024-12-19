#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
#define maxn 300005
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
vector<tuple<int,int,int>>a[60];
signed main()
{
    n=re();
    for(int i=1;i<=n;i++)
        a[re()].push_back({i,i,1});
    int ans=0;
    for(int k=1;k<60;k++)
    {
        if(!a[k].size())
            continue;
        ans=k;
        sort(all(a[k]));
        auto tmp=a[k];
        a[k].clear();
        for(auto [l,r,cnt]:tmp)
        {
            if(a[k].size())
            {
                auto& [l2,r2,cnt2]=a[k].back();
                if(r2+1==l)
                    r2=r,cnt2+=cnt;
                else
                    a[k].push_back({l,r,cnt});
            }
            else
                a[k].push_back({l,r,cnt});
        }
        for(auto [l,r,cnt]:a[k])
        {
            if(cnt<=1)
                continue;
            if(cnt&1)
            {
                int mid=l+r>>1;
                a[k+1].push_back({l,mid-1,cnt>>1});
                a[k+1].push_back({mid+1,r,cnt>>1});
            }
            else
                a[k+1].push_back({l,r,cnt>>1});
        }
    }
    printf("%d\n",ans);
    return 0;
}