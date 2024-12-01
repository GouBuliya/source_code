#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int re()
{
    int x=0,t=1;char ch =getchar();
    while (ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*t;
}
deque <int> dq;
vector <int>arr(1);
signed main ()
{
    int n=re();
    int m=re();
    for(int i=1;i<=n;++i)
    {
        arr.push_back(re());
        if(dq.size()&&dq.front()+m-1<i)dq.pop_front();
        while(!dq.empty()&&arr[i]>=arr[dq.back()])
        {dq.pop_back();}
        dq.push_back(i);
        if(i>=m)cout<<dq.size()<<endl;
    }
    return 0;
}

