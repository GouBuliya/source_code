#include <bits/stdc++.h>
using namespace std;
#define ll long long
int maxn=1e5+10;
vector<int>A(maxn);
vector<int>H(10);
vector<int>F(maxn);
bool cmp(int l,int r){
    return H[l]<H[r];}
bool f(int x,int ln,int rn)
{
    int t=x;
    int p=0;
    while(t)
    {
        t/=10;
        p++;
    }
    if(p<=rn-ln+1)
        return 1;
    else
    {
        int n=0;
        int d=1;
        for(int i=ln;i<=rn;++i)
        {
            n+=H[F[i]]*d;
            d*=10;
        }
        if(n<x)
            return 0;
        else 
            return 1;
    }
}

signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("bargain1.in","r",stdin);
    int op,t,n;
    cin>>op>>t;
    while(t--)
    {
        string str;
        cin>>str;
        int p=1;
        int minA=1e9;
        for(auto &i:str)
        {
            A[p]=i-'0';
            minA=min(minA,A[p++]);
        }
        p--;
        for(int i=1;i<=p;++i)
            F[i]=A[i];
        int minH=1e9;
        for(int i=1;i<=9;++i)
        {
            cin>>H[i];
            minH=min(minH,H[i]);
        }
        sort(F.begin()+1,F.begin()+p,cmp);ll ans=0;
        for(int i=1;i<=p-1;++i)
        {
            ans+=H[F[i]];
        }
        cout<<ans+minA<<endl;
    }
}

        
