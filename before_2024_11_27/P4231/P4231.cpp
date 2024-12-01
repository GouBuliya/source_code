#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e7+1;
#define max(a,b) (a)>(b)?(a):(b) 
ll A[maxn];
ll B[maxn+1];
ll C[maxn+2];
ll l,r,e,s,N,M;//公差
ll sumA[maxn+1];
signed main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    for(int i=1;i<=M;++i)
    {
        cin>>l>>r>>s>>e;
        int d=(e-s)/(r-l);
        C[l]+=s;
        C[l+1]+=d-s;
        C[r+1]-=d+e;
        C[r+2]+=e;
    }

   ll maxans=-999999999999,ans=0;
    ll last=0,ands=0;

    for(int i=1;i<=N;++i)
    {
        last+=C[i];
        ands+=last;

        if(ans)
        ans^=ands;
        else
        ans=ands;
        maxans=max(maxans,ands);
        
    }
    cout<<ans<<" "<<maxans<<endl;
}