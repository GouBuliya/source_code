# B. Move Back at a Cost's Solution
### 题意描述
给你一个长度为 $n$ 的整数序列 $a$ 你可以进行若干次操作.
- 选取一个索引 $i$ ($1 \le i \le n$),使 $a_i=a_i+1$ 并将其移到序列末端.



按照字典序输出进行若干次操作后字典序最小的序列.

### 解法
注意到,当操作后的序列为单调不降序列时,字典序才会最小,换句话说，使数字大的数对字典序的大小的贡献最小.

- 证明:假设序列 $A=[a_1,a_2,a_3...a_n]$ 为经过操作之后的字典序最小的序列,且 $\exists 1\le  i \le n$,满足 $a_i > a_{i+1}$,此时我们不妨删除 $a_i$ ,将 $a_i+1$ 放到序列末尾,构造序列B, $B=[a_1,a_2,...a_{i-1},a_{i+1}...,a_n...a_i]$,容易发现, $B<A$ 与命题矛盾,故,当序列单调时,字典序最小.

我们不妨将序列分为两类:需要移动的,和不需要移动的,并令原序列为 $A$,不需要移动的序列 $C$,需要移动的序列为 $B$.

容易发现，要使序列 $A$ 的字典序最小,$C$ 必须保证

$$ C_i=\min\limits_{i \le j \le n}A_j$$

显然，我们只需要维护一个序列 $A$ 的后缀最小值即可.

同时我们要保证 $\forall C_i \le \forall B_i+1$ ,只需维护一个$B$ 的 $mininum$ 即可.

容易得到,剩下的就是 $B$ 序列.

具体的,我们只需要在 $A$ 标出 $C$ 将剩下的 $\text{push}$ 进 $B$ 即可.

最后我们只需要将 $B$ 排序保证单调,同时将 $B$ 的所有元素加一,并将 $A$ 与 $B$ 拼接即可.

代码实现：
```cpp
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
namespace my{
#define ll long long 
const int INF=(1<<30);
ll re ()
{
    ll t;
    cin>>t;
    return t;
}
void solve()
{
   int n=re();
   vector<int>A,suf(n+1),B;
   vector<bool>vis(n,0);
   for(int i=1;i<=n;++i)
        A.push_back(re());
   suf[n]=1e9;
   for(int i=n-1;i>=0;i--)
       suf[i]=min(suf[i+1],A[i]);
   for(int i=0,mn=1e9;i<n;++i)
   {
       if(suf[i]==A[i])
       {
           if(A[i]>mn+1)
               break;
           vis[i]=1;
            cout<<A[i]<<" ";
       }
       else {
           mn=min(mn,A[i]);
       }
   }
   for(int i=0;i<n;++i)
       if(!vis[i])
            B.push_back(A[i]);
   sort(B.begin(),B.end());
   for(auto &i:B)
       cout<<i+1<<" ";
   cout<<'\n';
}   
signed main ()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=re();
    while(t--)
        solve();
    return 0;
}
}
signed main ()
{
    return my::main();
}
```
