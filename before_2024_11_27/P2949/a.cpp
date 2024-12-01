#include <bits/stdc++.h>
#define ll long long
using namespace std;
priority_queue<int,vector<int>,greater<int>> que;//pair.first=>D,pair.second=>
int n;
const int maxn=1e5+10;
struct S{
    int d,p;
}A[maxn];
bool cmp(S a,S b)
{
    return a.d<b.d;
}
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>A[i].d>>A[i].p;
    sort(A+1,A+1+n,cmp);
    ll ans=0;
    for(int i=1;i<=n;++i)
    {
        if(A[i].d<=que.size())
        {
            if(A[i].p>que.top())
            {
                ans-=que.top();
                que.pop();
                ans+=A[i].p;
                que.push(A[i].p);
           }
        }
        else
        {
            ans+=A[i].p;
            que.push(A[i].p);
        }
    }
    
    cout<<ans<<endl;

}
