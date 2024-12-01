#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int n,M1,M2;
struct hb
{
    int l,r;
    bool opt=0;
}m1[maxn],m2[maxn],temp[maxn];
auto cmp = [](const hb &l,const hb &r)
{
    return l.l<r.l;
};
auto cmp1 = [](const hb &l,const hb &r)
{
    return l.r<r.r;
};


priority_queue<hb,vector<hb>,decltype(cmp)> quea(cmp);//国内
priority_queue<hb,vector<hb>,decltype(cmp)> queb(cmp);//国外
vector<hb> qm1;
vector<hb> qm2;

int solve1(int T)
{
    int t=T;
    int now=0;
    int ans=0;
priority_queue<hb,vector<hb>,decltype(cmp1)> que(cmp1);//国外
    for(auto i:qm1)
    {
        
        if(t)
        {
            que.push(i);
            t--;
            ans++;
        }
        else 
        {
            if(!que.empty()&&i.l>que.top().r)
            {
                que.pop();
                que.push(i);
                ans++;
            }
        }
    } 
    return ans;  
}
int solve2(int T)
{
    int t=T;
    int now=0;
    int ans=0;
priority_queue<hb,vector<hb>,decltype(cmp1)> que(cmp1);//国外
    for(auto i:qm2)
    {
        
        if(t)
        {
            que.push(i);
            t--;
            ans++;
        }
        else 
        {
            if(!que.empty()&&i.l>que.top().r)
            {
                que.pop();
                que.push(i);
                ans++;
            }
        }
    } 
    return ans;  
}
signed main()
{
    scanf("%d %d %d",&n,&M1,&M2);
    for(int i=1;i<=M1;++i)
    {
        scanf("%d %d",&m1[i].l,&m1[i].r);
        quea.push(m1[i]);
    }for(int i=1;i<=M2;++i)
    {
        scanf("%d %d",&m2[i].l,&m2[i].r);
        queb.push(m2[i]);
    }
    // for(int i=1;i<=M1;++i)
    // {
    //     qm1.push_back(quea.top());
    //     quea.pop();
    // }
    // for(int i=1;i<=M2;++i)
    // {
    //     qm2.push_back(queb.top());
    //     queb.pop();
    // }
    int ans=0;
    for(int l=0;l<=n;++l)
    {
        int r=n-l;
        int p=0;
        p+=solve1(l);
        p+=solve2(r);
        ans=max(ans,p);

    }
    printf("%d",ans);
}