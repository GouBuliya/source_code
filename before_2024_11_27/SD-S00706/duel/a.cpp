#include <bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
#define int long long
int re()
{
 int t;
 cin>>t;
 return t;
}
const int maxn=1e5+10;
int A[maxn];
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("duel4.in","r",stdin);
#endif
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int n=re();
  int j=n;
  int t=n;
  for(int i=1;i<=n;++i)
    A[i]=re();
  int ans=0;
  sort(A+1,A+1+n);
  for(int i=n;i>=1;i--)
  {
    while(A[j]>=A[i])
        j--;
    if(j<1)
        break;
    ans++;j--;
  }
  cout<<n-ans<<endl;
  return 0;
}

