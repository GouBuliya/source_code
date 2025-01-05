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
    int t=re();
    while(t--)
    {
        string S1,T,s2;
        cin>>S1>>T>>s2;
        string S2;
        for(int i=0;i<s2.length()-1;++i)
            S2.push_back(s2[i]);
        if(S1=="eat"&&S2=="eat")
        {
            cout<<"or"<<'\n';
            continue;
        }
        if(S1=="eat"||S2=="eat")
        {
            string ans=(S1=="eat"?S2:S1);
            cout<<ans<<'\n';
            continue;
        }
        else 
        {
            cout<<S1<<'\n';
            continue;
        }
    }
    

    return 0;
}
}
signed main ()
{
    return my::main();
}

