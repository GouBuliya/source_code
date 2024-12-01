#include<bits/stdc++.h>
using namespace std;
string add(string &A,string &B)
{   
    vector<int>a,b,c;
    for(auto &i:A)
        a.push_back(i-'0');
    for(auto &i:B)
        b.push_back(i-'0');
    
    for(auto i=a.size(),j=b.size();j>=0&&i>=0;i--,j--)
        if(i+1&&j+1)c.push_back(a[i]+b[i]);
        else if(i+1)c.push_back(a[i]);
        else if(j+1)c.push_back(b[i]);
    bool flag=0;
    for(auto i=c.size();i>=0;i--)
    {
        if(c[0]>10)
        {
            flag=1;
            c[0]%=10;
        }
        if(c[i]>10)
            c[i-1]++,c[i]%=10;
    }
    string ans;
    for(int i=0;i<=c.size();++i)
    {
        if(flag)ans+='1',flag=0;
        ans+=char(c[i]+'0');
    }
    return ans;
}
signed main ()
{ string A,B;
    cin>>A>>B;
    cout<<add(A,B);
}
