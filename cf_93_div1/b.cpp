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
    string S;
    cin>>S;
    vector<int>next(S.size());
    int j=0;
    vector<int>vis(S.size()+1);
    for(int i=1;i<S.size();++i)
    {
        while(j>0&&S[i]!=S[j])
            j=next[j-1];
        if(S[i]==S[j])
            j++;
        next[i]=j;
        vis[j]++;
    }
    j=S.size()-1;
            vis[next[j]]--;
    while(next[j]>0&&j>0)
    {
        string T=S.substr(S.size()-next[j]);
        cout<<endl;
        
        if(vis[next[j]]>0)
        {
            cout<<T<<endl;
            return 0;
        }
        j=next[j-1];
    }
    cout<<"Just a legend"<<endl;

    return 0;
}
}
signed main ()
{
    return my::main();
}

