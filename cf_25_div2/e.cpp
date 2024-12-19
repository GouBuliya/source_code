#include<bits/stdc++.h>
namespace my{
#define ll long long 
#define pn std::cout<<"\n";
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
#define min(x,y) (x)<(y)?(x):(y)
#define max(x,y) (x)>(y)?(x):(y)
const int INF=(1<<30);
ll re ()
{
    ll t;
    std::cin>>t;
    return t;
}
signed main ()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::vector<std::string>s(3);
    for(int i=0;i<3;++i)
        std::cin>>s[i];

    std::vector<std::vector<int>>next(3);
    for(int i=0;i<3;++i)
        next[i].resize(s[i].size());

    std::function<void(std::string &,std::vector<int> &)> fun_next=[](std::string &s,std::vector<int>&A) ->void 
    {
        int j=0;
        if(s.size()==1)
        {A[0]=0;}
        for(int i=1;i<s.size();++i)
        {
            if(i<0||j<0)continue;
            while(j>0&&s[j]!=s[i])
                j=A[j-1];
            if(s[i]==s[j])
                j++;
            A[i]=j;
            // std::cout<<A[i]<<" ";
        }
        
            // pn
        return ;
    };
    for(int i=0;i<3;++i)
            fun_next(s[i],next[i]);

    std::function<int(std::string &,std::string &,std::vector<int>&)> fun_kmp =[](std::string &s1,std::string &s2,std::vector<int>&next)->int 
    {
        int j=0;
        for(int i=0;i<s1.size()&&i<s2.size();i++)
        {
            if(i<0||j<0)continue;
            while(j>0&&s1[i]!=s2[j])
                j=next[j-1];
            if(s1[i]==s2[j])
                j++;
            if(j>=s2.size()||j>=s1.size())
            {
                // pn
                return j;
            }
            // std::cout<<j<<" ";
        }
        // pn
        return j;
    };
    int ans=1e9;
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            if(i==j)
                continue;
            int ch1=fun_kmp(s[i],s[j],next[j]);
            for(int k=0;k<3;++k)
            {
                if(k==j||k==i)
                    continue;
                if(s[i].size()>=s[j].size())
                {
                    std::string t=s[i];
                    t.resize(max(s[i].size()-ch1,0));
                    t+=s[j];
                    
                    // std::cout<<ch1<< " "<<t<<" "<<s[i]<<" "<<s[j]<<std::endl;
                    std::vector<int>nex(t.size());
                    int ch2=max(fun_kmp(t,s[k],next[k]),fun_kmp(s[k],t,nex));
                    ans=min(ans,s[i].size()+s[j].size()+s[k].size()-ch1-ch2);
                }
                else
                {
                    std::string t=s[j];
                    t.resize(max(s[j].size()-ch1,0));
                    t+=s[i];
                    // std::cout<<ch1<< " "<<t<<" "<<s[i]<<" "<<s[j]<<std::endl;

                    std::vector<int>nex(t.size());
                    int ch2=max(fun_kmp(t,s[k],next[k]),fun_kmp(s[k],t,nex));
                    ans=min(ans,s[i].size()+s[j].size()+s[k].size()-ch1-ch2);
                }
            }
        }
    }
    std::cout<<ans<<std::endl;
    return 0;
}
}
signed main ()
{
    return my::main();
}

