#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
using namespace std;
int re()
{
    int x=0,t=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*t;
}
stack<int>st;
const int maxn=1e5+10;
int A[maxn];
int ans[maxn];
signed main()
{
    int n=re();
    for(int i=1;i<=n;++i)
        A[i]=re();
    for(int i=n;i>=1;--i)
    {
        while (!st.empty()&&A[st.top()]<=A[i])
        {
            st.pop();
        }
        if(!st.empty())ans[i]=st.top();
        else ans[i]=0;
        st.push(i);
    }
    for(int i=1;i<=n;++i)
    cout<<ans[i]<<endl;
}
                                                                                                                                                                                  
