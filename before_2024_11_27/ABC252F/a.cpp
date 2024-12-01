#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
#define int long long 
int A[maxn];
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int L,N;
    cin>>N>>L;
    priority_queue<int>que;
    long long sum=0;
    for(int i=1;i<=N;++i)
        {
            int t;
            cin>>t;
            sum+=t;
            que.push(-t);
        }
    int k=0;
    if(L-sum)
    {
        que.push(-1*(L-sum));
    }
    while(que.size()>1)
    {
        int a=-1*(que.top());que.pop();
        int b=-1*que.top();que.pop();
        que.push(-1*(a+b));
        k+=a+b;
        cout<<k<<" "<<a<<" "<<b<<endl;
    }
    cout<<k<<endl;
    


}

