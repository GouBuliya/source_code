#include<bits/stdc++.h>
using namespace std;
namespace my {

#define ll long long 
    const int INF = (1 << 31);
    ll re()
    {
        ll t;
        cin >> t;
        return t;
    }
    const int maxn=1e6+10;
    vector<int>next(maxn);
    string S;
    signed main()
    {
#ifndef ONLINE_JUDGE
    // freopen("/home/li-xufeng/Downloads/P3435_1.in","r",stdin);
#endif
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = re();
        // cout<<n<<endl;
        cin >> S;
      
        int j = 0;
        for (int i = 1;i < n;++i)
        {
            while (j > 0 && S[j] != S[i])
                j = next[j - 1];
            if (S[i] == S[j])
                j++;
            next[i] = j;
        }
             ll ans = 0;
        // for(int i=0;i<S.size();++i)
        //     cout<<next[i]<<" ";cout<<endl;
        for(int i=2,j=2;i<=S.size();++i,j=i)
        {
            while(next[j-1])j=next[j-1];
            if(next[i-1])next[i-1]=j;
            ans+=(i)-j;
        }
        cout << ans << endl;
        return 0;
    }
}
signed main()
{
    return my::main();
}

