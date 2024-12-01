#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int re ()
{
    int t;
    cin>>t;
    return t;
}
double dist(int x1,int y1,int z1,int x2,int y2,int z2)
{
    double w1=(x1-x2)*(x1-x2);
    double w2=(y1-y2)*(y1-y2);
    double w3=(z1-z2)*(z1-z2);
    return sqrt(w1+w2+w3);
}

bool isintersect(int r,int x1,int y1,int z1,int x2,int y2,int z2)
{
    double d=dist(x1,y1,z1,x2,y2,z2);
    r*=2.0;
    if(d<=r)
        return true;
    else 
        return false;
}
const int maxn=1e3+10;
vector<int>pre(maxn);//1e3+4表示向下联通，1e3+5表示向上联通
int root(int x)
{
    return pre[x]=pre[x]==x?x:root(pre[x]);
}
void merge(int x,int y)
{
    x=root(x),y=root(y);
    if(x==y)
        return;
    pre[x]=y;
}

void slove()
{
    int n=re(),h=re(),r=re();
    for(int i=1;i<=n;++i)
        pre[i]=i;
    pre[1e3+4]=1e3+4;
    pre[1e3+5]=1e3+5;
    vector<tuple<int,int,int>>A;
    for(int i=1;i<=n;++i)
    {
        int x=re(),y=re(),z=re();
        A.push_back({x,y,z});
        if(z-r<=0)
            merge(1e3+4,i);
        if(z+r>=h)
            merge(1e3+5,i);
        for(int j=0;j<A.size()-1;++j)
        {
            //auto [x1,y1,z1]=A;
            int x1=get<0>(A[j]);
            int y1=get<1>(A[j]);
            int z1=get<2>(A[j]);
            if(isintersect(r,x,y,z,x1,y1,z1))
                merge(i,j);
        }
    }
    if(root(1e3+4)==root(1e3+5))
        cout<<"Yes"<<endl;
    else 
        cout<<"No"<<endl;
}
signed main ()
{
    int t=re();
    while(t--)
        slove();
}
