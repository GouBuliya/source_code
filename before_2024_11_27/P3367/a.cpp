#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int re ()
{
    int t;
    cin>>t;
    return t;
}
int N,M;
const int maxn=1e4+10;
int pre[maxn];
int root(int x)
{
    return pre[x]=pre[x]==x?x:root(pre[x]);
}
void merge (int x,int y)
{
     x=root(x);
    y = root(y);
    if(x==y)
        return;
    pre[x]=y;
}
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    N=re();M=re();
    for(int i=1;i<=N;++i)
        pre[i]=i;
    for(int i=1;i<=M;++i)
    {
        int op=re();
        if(op==1)
        {
            merge(re(),re());
        }
        else 
        {
            if(root(re())==root(re()))
                cout<<"Y"<<endl;
            else 
                cout<<"N"<<endl;
        }
    }
}