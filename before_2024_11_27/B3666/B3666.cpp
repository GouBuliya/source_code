#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int re()
{
    int x=0,t=1;char ch=getchar();
    while (ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*t;
}
std::stack<int>st;
int arr[1000007];
signed main ()
{
    int t=re();
    int ans=0;

    for(int i=1;i<=t;++i)
    {
        arr[i]=re();
        while (!st.empty()&&arr[st.top()]<=arr[i]){ans^=st.top(),st.pop();}
        st.push(i);
        ans^=i;
        cout<<ans<<endl;
    }
    return 0;
}
