#include <bits/stdc++.h>
const int maxn=31;
const int maxm=1e5+10;
int n;
int a[maxm];
int f[maxn];

using namespace std;
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in","r",stdin);
    #endif
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;++i)
    {
        int maxnum=-1e9;
        for(int k=0;k<=30;k++)
        {
            if((1<<k)&a[i])
            {
                maxnum=max(maxnum,f[k]+1);
            }
        }
        for(int k=0;k<=30;++k)
        {
            if((1<<k)&a[i])
            {
                f[k]=maxnum;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=30;i++)
        ans=max(ans,f[i]);
    cout<<ans<<endl;

}

