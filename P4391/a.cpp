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
const int maxn=1e6+10;

int next[maxn];
signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int len=re();
    string S;
    cin>>S;
    int j=0;
    for(int i=1;i<len;++i)
    {
        while(j>0&&S[i]!=S[j])
            j=next[j-1];
        if(S[i]==S[j])
            j++;
        next[i]=j;
    }
    cout<<len-next[len-1]<<endl;
    return 0;
}
}
signed main ()
{
    return my::main();
}

