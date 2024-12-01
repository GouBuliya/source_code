#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int A[maxn];
pair<int,int> B[maxn];
int C[maxn];
int D[maxn];
priority_queue<int,vector<int>,greater<int>>que;
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>A[i],C[A[i]]++,D[A[i]]++;
    for(int i=1;i<=n;++i)
        cin>>B[i].first,B[i].second=i;
    sort(B+1,B+1+n,less<pair<int,int>>());
    

    for(int i=1;i<=n;++i)
    {
        if(C[A[B[i].second]]>1)
        {
            que.push(B[i].first);
            C[A[B[i].second]]--;
        }
    }
    int ans=0;
    int cnt=1;
    for(int i=1;i<=n&&cnt<=k;++i)
    {
        
        if(D[i]!=0)
        {
            cnt++;
        }
    }
    cnt=k-cnt+1;
    while(cnt--)
    {
        ans+=que.top();
        que.pop();
    }
    cout<<ans<<endl;
}
//8 7
//1 1 3 1 5 3 7 1
//5 7 4 8 1 3 5 2
//1 2 3 4 5 6 7 8
//2 0 3 0 1 0 7 0
//1 2 3 4 5 5 7 8
//算法策略：
//输入A 同时记录这个任务有几个人同时做（开桶）
//输入B 
//对 B 预处理如果对应编号的任务多于1人，入堆
//取出堆的元素
//去完成剩下的任务直到==k
