#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int INF=(1<<31);
ll re ()
{
    ll t;
    cin>>t;
    return t;
}
const int maxn=1e5;
const int maxm=1e4;
int nxt [maxn];
string S,P;
int lenS,lenP;
void init ()
{
    cin>>S>>P;
    lenS=S.length();
    lenP=P.length();
    int t=nxt[0]=-1;
    int j=0;
    while(j<lenP-1)
        if(t<0||P[j]==P[t])
            j++,t++,nxt[j]=t;
        else 
            t=nxt[t];
}
void kmp(string& S,string& P)
{
    int i=0,j=0;
    while(i<lenS&&j<lenP)
        if(j<0||P[j]==S[i])
            i++,j++;
        else 
            j=nxt[j];
    cout<<i<<endl;
}
signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();  
    kmp(S,P);
    
    return 0;
}

