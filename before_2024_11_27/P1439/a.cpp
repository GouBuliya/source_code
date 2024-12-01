#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp1 cout<<1<<endl;
int re()
{
    int t;
    cin>>t;
    return  t;
}
const int maxn=1e5+10;
int A[maxn];
int f[maxn];
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n=re();
    for(int i=1;i<=n;++i)
        A[re()]=i;
    int len=0;
    f[len]=0;
    for(int i=1;i<=n;++i)
    {
        int m=re();
        if(A[m]>f[len])
        {
            f[++len]=A[m];
        }
    

        else 
        {
           // int p=upper_bound(f+1,f+1+len,A[i])-f;
            int l=0,r=len;
            while(l<=r)
            {
                int mid=f[(l+r)/2];
                if(A[m]<mid)r=(l+r)/2-1;
                else l=(l+r)/2+1;
            }

            f[l]=A[m];
        }
    }
    cout<<len<<endl;
}
