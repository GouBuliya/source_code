#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
namespace my{
#define ll long long
#define pn cout<<"\n"
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
const int INF=(1<<30);
ll re(){ll x;std::cin>>x;return x;}

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    auto S=[]{
        int n=re(),m=re();
        std::map<int,int> mp;
        for(int i=0;i<n;i++) mp[re()]++;
        __gnu_pbds::priority_queue<int> q;
        for(int i=0;i<m;i++) q.push(re());
        
        while(!q.empty()&&m<=n){
            int t=q.top();q.pop();
            if(mp.count(t)&&mp[t]-->0){
                if(mp[t]==0) mp.erase(t);
            }else{
                m++;
                int a=t/2,b=(t+1)/2;
                q.push(a);q.push(b);
            }
        }
        
        for(auto& p:mp)if(p.second>0)return puts("No"),0;
        return puts("Yes"),0;
    };
    
    for(int T=re();T--;)S();
    return 0;
}
}

signed main(){return my::main();}