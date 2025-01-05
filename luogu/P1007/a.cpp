#include<bits/stdc++.h>
#include <cctype>
using namespace std;
namespace my{
#define ll long long 
const int INF=(1<<31);
ll re ()
{
    ll t;
    cin>>t;
    return t;
}
const int maxn=5e3+10;
int A[maxn];
bool fx[maxn];
signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int L=re();
    int N=re();
    for(int i=1;i<=N;++i)
        cin>>A[i];
    int minans=0;
    for(int i=1;i<=N;++i)
    {
        minans+=min(A[i],L-A[i]);
    }
    cout<<minans<<" ";
    int time=0;
    int tot=N;
    A[0]=-1111;
    for(int i=1;i<=N;++i)
    {
        fx[i]=A[i]<(L/2)?1:0;
    }
    while(tot)
    {
        for(int i=1;i<=N;++i)
        {
            if(A[i]==-1)
            {continue;}
            if(A[i]<=0||A[i]>=L+1)
                A[i]=-1,tot--;
            if(fx[i])
            {
                time++;
                A[i]++;
            }
            else
            {
                time++;
                A[i]--;
            }
        }
        for(int i=1;i<=N;++i)
        {
            if(A[i]==A[i+1]||A[i]==A[i-1])
            {fx[i]=fx[i]?0:1;}
        }
    }
    cout<<time<<endl;
    return 0;
}
}
signed main ()
{
    return my::main();
}
/*注意到，对于答案的最值，分为两种情况，一种是对于每个点，它的time是min（begin-P,P-end)
而另一种情况是，对于每个点都进行至少一次*/
