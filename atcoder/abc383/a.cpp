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
signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n=re();
    int N=0;
    vector<int>T;
    vector<int>V;

    for(int i=1;i<=n;++i)
    {
        T.push_back(re());
        V.push_back(re());
    }
    int t=0;
    int p=0;

    while(t<=*T.rbegin())
    {
        if(N>0)
            N--;
        if(t==T[p])
        {
            N+=V[p];
            p++;
        }
        t++;
    }
    cout<<N<<endl;
    return 0;
}
}
signed main ()
{
    return my::main();
}

