#include<bits/stdc++.h>
#define ll long long
#define pn cout<<'\n';
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
namespace my{
const int INF=(1<<30);
ll re ()
{ ll t; std::cin>>t;return t;}
void solve()
{
    int n=re();
    int m=re();
    std::vector<int>A;
    for(int i=0;i<n;++i)
        A.push_back(re());
    int ans=1e9;
    std::vector<int>T(m+1);
    int num=0;
    int l=0;int r=0;
    int L=0;
    int R=-1;
    int ansl=0;int ansr=0;
    while(num!=m)
    {
        
        if(T[A[r]]==0)num++;
        T[A[r]]++;
        r++;
        R++;
    }
    
    ansr=R;
    while(T[A[l]]>1)
    {
        T[A[l]]--;
        l++;
        L++;
    }
    
    ansl=L;
    while(r<n)
    {
        T[A[r]]++;++r;++R;
        while(T[A[l]]>1){T[A[l]]--;l++;L++;}
        if(r-l<ansr-ansl)
        {
            ansl=L;
            ansr=R;
        }
        
    }
    std::cout<<ansl+1<< " " <<ansr+1<<std::endl;
}
}
signed main()
{std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);int t=1;while(t--)my::solve();return 0;}