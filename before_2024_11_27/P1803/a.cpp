#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e6;
struct s{
    int l,r;
}S[maxn];
bool cmp(s a,s b)
{
    if(a.r!=b.r)return a.r<b.r;
    return a.l<b.l;
}
signed main ()
{
    int n,m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>S[i].l>>S[i].r;
    sort(S+1,S+1+n,cmp);
    ll ans=0;
    ll now=0;
    for(int i=1;i<=n;++i)
    {
        if(S[i].l>=now)
        {
            now=S[i].r;
            ans++;
        }
    }
    cout<<ans<<endl;


}
