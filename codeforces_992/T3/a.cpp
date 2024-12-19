#include<bits/stdc++.h>
using namespace std;
namespace my{
#define ll long long 
#define ull unsigned long long
#define int long long 
const int INF=(1<<31);
ll re ()
{
    ll t;
    cin>>t;
    return t;
}
void solve ()
{
    int n=re(),k=re();
    vector<bool>K;
    int tot=0;
    if(n<=60&&k>(1ull<<(ull)(n-1)))
    {cout<<-1<<'\n';return;}
            
    k--;
    while(k)
    {
        K.push_back(k%2);
        k/=2;
        tot++;
    }
    vector<int>A,B;
    while(K.size()<n-1)
        K.push_back(0);
    for(int i=n-2,j=1;i>=0;i--,j++)
    {
        if(!K[i])
        {
            A.push_back(j);
        }
        else B.push_back(j);
    }

    reverse(B.begin(),B.end());
    for(auto &i:A)
        cout<<i<<" ";
    cout<<n<<" ";
    for(auto &i:B)
        cout<<i<<" ";
    cout<<'\n';
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
        solve();
    }
    return 0;
}
}
signed main ()
{
    return my::main();
}