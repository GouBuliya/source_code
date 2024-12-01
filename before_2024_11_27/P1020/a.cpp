#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define int long long
const int maxn=1e5+10;
vector<int> A(maxn);
int F[maxn];
int n;

signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("in","r",stdin);

    n=1;
    while(cin>>A[n])
        n++;
    n--;
    memset(F,0x3f,sizeof(F));
    reverse(A.begin()+1,A.begin()+1+n);
    F[0]=-1e18;
    int ans=0;
    for(int i=1;i<=n;++i)
    {   
        int p=upper_bound(F+1,F+1+n,A[i])-F;
        F[p]=min(F[p],A[i]);
        ans=max(ans,p);
    }
    
    cout<<ans<<" ";
    ans=0;
    memset(F,0x3f,sizeof(F));
    reverse(A.begin()+1,A.begin()+1+n);
    for(int i=1;i<=n;++i)
    {   
        int p=lower_bound(F+1,F+1+n,A[i])-F;
        F[p]=min(F[p],A[i]);
        ans=max(ans,p);
    }
    cout<<ans<<endl;


}
