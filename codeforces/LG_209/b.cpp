#include<bits/stdc++.h>
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
const int maxn=3e5+10;
vector<int>A;
vector<bool>vis(maxn);
vector<pair<int,vector<int>>>G;
signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n=re();
    vector<int>B(n+1);
    for(int i=0;i<n;++i)
    {
        int t=re();
        A.push_back(t);
        B[t]=i;
    }

    for(int i=1;i<=n;++i)
    {
        if(!vis[i])
        {
            int p=B[i];
            vis[p]=1;
            vector<int>k;
            k.push_back(A[p]);
            while(p>0&&p<=n&&(A[p-1]>A[p]||A[p+1]>A[p]))
                {
                    if(A[p+1]>A[p-1])
                    {
                        k.push_back(A[p+1]);
                        vis[p+1]=1;
                    }
                    else
                    {
                        k.push_back(A[p-1]);
                        vis[p-1]=1;
                    }
                }
            sort(k.begin(),k.end());
            G.push_back({k[0],k});
            cout<<i<<endl;
        }
    }
    sort(G.begin(),G.end());
    for(auto &[m,i]:G)
        for(auto &j:i)
            cout<<j<<" ";
    cout<<endl;
    return 0;
}
}
signed main ()
{
    return my::main();
}
