#include <bits/stdc++.h> 
using namespace std;
vector<pair<char,int>> A,B;
int ans[200000+10];
signed main ()
{

    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string S,T;
    cin>>S>>T;
    int lens=S.length();
    int lent=T.length();
    int j=0;
    for(int i=0;i<lent;++i)
    {
        if(S[j]==T[i])
        {
            
            ans[j+1]=i+1;j++;
        }
    }
    for(int i=1;i<=lens;++i)
        cout<<ans[i]<<" ";
    cout<<'\n';
}



