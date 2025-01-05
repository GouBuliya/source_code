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
   vector<string> S;
    vector<string> T;
    
    while(1)
    {
        string s;
        cin>>s;
        if(s=="$")
            break;
        S.push_back(s);
    }
    while(1)
    {
        string s;
        cin>>s;
        if(s=="$")
            break;
        T.push_back(s);
    }
    vector<int>A(S.size());
    vector<int>B(T.size());
    int len=T.size();
    map<string,int>m;
    for(int i=0;i<S.size();i++)
    {
        if(m.find(S[i])==m.end())
        {
            m[S[i]]=i;
            A[i]=-1;
        }
        else {
            int t=i-m[S[i]];
            if(t>len)A[i]=-1;
            else
            {A[i]=t;}
            m[S[i]]=i;
        }
    }m.clear();
    for(int i=0;i<T.size();i++)
    {
        if(m.find(T[i])==m.end())
        {
            m[T[i]]=i;
            B[i]=-1;
        }
        else {
            int t=i-m[T[i]];
            if(t>len)B[i]=-1;
            else
            {B[i]=t;}
            m[T[i]]=i;
        }
    }
    int j=0;
    vector<int>nxt(B.size());
    for(int i=1;i<B.size();++i)
    {
        while(j>0&&B[i]!=B[j])
        {
            j=nxt[j-1];
        }
        if(B[i]==B[j])
            j++;
        nxt[i]=j;
    }
    j=0;
    for(int i=0;i<A.size();++i)
    {
        while(j>0&&A[i]!=B[j])
            j=nxt[j-1];
        if(A[i]==B[j])
            j++;
        if(j>=len)
        {cout<<i-len+2<<endl;
            break;}
            
    }
    return 0;
}
}
signed main ()
{
    return my::main();
}

