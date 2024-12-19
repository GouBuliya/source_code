#include<bits/stdc++.h>
using namespace std;
namespace my{
#define ll long long 
const int INF=(1<<30);
ll re ()
{
    ll t;
    cin>>t;
    return t;
}
const int maxn=1e4;
class tree{
    public:
        int tot=0;
        int word[maxn];
        int tree[maxn][26];
        int ans=0;
        void insert(string &S)
        {
            int res=0;
            int u=0;
            for(auto i:S)
            {
                i-='a';
                if(tree[u][i]==0)
                    tree[u][i]=++tot;
                u=tree[u][i];
                res+=word[u];
            }
            word[u]++;
            ans=max(ans,res+1);
        }
        
};
signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n=re();
    tree T;
    while(n--)
    {
        string S;
        cin>>S;
        T.insert(S);
    }
    cout<<T.ans<<endl;
    return 0;
}
}
signed main ()
{
    return my::main();
}

