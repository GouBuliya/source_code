#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp1 cout<<1<<endl;
int re()
{
        int t;
        cin>>t;
        return t;
}
const int maxn=100;
int A[maxn];
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=re();
    while(t--)
    {
        int n=re();int k=re();
        memset(A,0,sizeof(A));
        int now=0;
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            int a=re();
            if(a>=k)
            {
                now+=a;
            }
            else if(a==0&&now)
            {
                now--;
                ans++;
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}
