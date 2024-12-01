#include <bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
#define int long long
int re()
{
 int t;
 cin>>t;
 return t;
}
const int maxn=1e5+10;
struct car
{
    int d,In,Out;
    int a,v;
}A[maxn];
bool cmp(car A,car B)
{
    if(A.d==B.d)
        return A.Out<B.Out;
    else 
        return A.In>B.In;
}
int P[maxn];int L;int V;int n,m;
void solve()
{
    n=re(),m=re(),L=re(),V=re();
    for(int i=1;i<=n;++i)
        A[i].d=re(),A[i].v=re(),A[i].a=re();
    for(int i=1;i<=m;++i)
        P[i]=re();
    for(int i=1;i<=n;++i)
    {
        if(A[i].a==0)
        {
            if(A[i].v>V)
            {
                A[i].In=P[lower_bound(P+1,P+m+1,A[i].d)-P];
                A[i].Out=P[m];
            }
            else 
            {
                A[i].In=-1;
                A[i].Out=-1;
                A[i].Out=1e6+7;
            }
        }
        if(A[i].a>0)
        {
            if(A[i].v>V)
            {
                A[i].In=P[lower_bound(P+1,P+m+1,A[i].d)-P];
                A[i].Out=P[m];
            }
            else 
            {
                int u=(V*V-A[i].v*A[i].v);
                int v=2*A[i].a;
                if(u/v>L-A[i].d)
                 {
                A[i].In=-1;
                A[i].Out=1e6+7;
                }
                else 
                {
                    A[i].In=P[lower_bound(P+1,P+1+m,(A[i].d+(u/v)))-P];
                    A[i].Out=P[m];
                }
            }
                
        }
        if(A[i].a<0)
        {
            if(A[i].v>V)
                {
                    int p=P[lower_bound(P+1,P+1+m,A[i].d)-P];
                    if(p>(A[i].d+(double(V*V-A[i].v*A[i].v))/2*A[i].a))
                    {
                        A[i].In=-1;
                        A[i].Out=-1;
                A[i].Out=1e6+7;
                    }
                    else 
                    {
                        int t=p-A[i].d;
                        int vf=(A[i].v*A[i].v+2*A[i].a*t);
                        if(double(V*V-vf)/2*A[i].a<0)
                        {
                        A[i].In=-1;
                        A[i].Out=-1;
                        A[i].Out=1e6+7;
                        }
                         
                        else {
                        A[i].In=p;
                        int v=(2*A[i].a);
                        int u=(V*V-A[i].v*A[i].v);
                        A[i].Out=P[lower_bound(P+1,P+1+m,u/v)-P+1];
                        int s=A[i].d+(u/v);
                        if(!(s>=A[i].Out))
                            A[i].Out=P[lower_bound(P+1,P+1+m,u/v)-P];
                        }
                    }
                }
            else 
            {
                A[i].In=-1;
                A[i].Out=-1;
                A[i].Out=1e6+7;
            }
        }
    }
    sort(A+1,A+1+n,cmp);
    int i=1;
    while(A[i].In!=-1)
    {
        i++;
    }
    i--;
    cout<<i;
    vector<bool>vis;
    for(int t=0;t<=i;t++)
        vis.push_back(0);
    int ans=i;
        for(int k=1+1;k<=i;++k)
        {
            if(A[1].In>=A[k].In&&A[1].Out<=A[k].Out&&!vis[k]){ans--;vis[k]=1;}
        }
    cout<<" "<<m-ans;
    

}   
signed main()
{
#ifndef ONLINE_JUDGE
#endif
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int t=re();
  while(t--)
  {
      solve();
  }
   return 0;
}

