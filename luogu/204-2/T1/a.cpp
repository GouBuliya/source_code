#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
#define int long long
vector<int> G[maxn];
vector<int> F[maxn];//向上的图
int new_edge=1;
void add(int x)
{
    G[x].push_back(new_edge);
    F[new_edge++].push_back(x);
}
    //在x节点上生成一个儿子
int ans=0;
void init(int x)
{
    G[1].push_back(2);
    F[2].push_back(1);
    for(int i=2;i<x;++i)
    {
        add(i);
        ans++;
    }
}
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int k;
    cin>>k;
    priority_queue<int>que;
    for(int i=1;i<=k;++i)
    {
        int t;
        cin>>t;
        que.push(t);
    }
    ans+=que.top();que.pop();
    ans+=que.size();
    cout<<ans<<endl;



}
