观察式子 

$$a_i= |a| + 1 - i$$

我们不妨将其变形为

$$ |a|=a_i + i - 1 $$

$\text{Note that:}$因为 $|a| \ge 0$,所以当 $a_i=0$ 时,命题为假,同时容易发现 
$$\forall i-1 < |a|(0 \le i-1 \le n-1)$$ 
所以,我们只需要考虑前 $n$ 个位置.

不难发现，对于位置 $i$ ，使用操作可以使 $|a|+i-1$ ,我们不妨令 $u_i=|a|=a_i+i-1$ ，一次操作后我们有 $v_i=u_i + i-1$.

考虑建图后 $DFS$ ,具体的,创建一个包含所有 $n$ 的图,从节点 $n$ 开始 $DFS$,容易得到:

$$ ans=\max\limits_{i \in G}(v_i) $$

注意一下细节,并用 $vis$ 标记数组优化就过了.

```cpp
#include<bits/stdc++.h>
using namespace std;
namespace my{
#define ll long long 
const int INF=(1<<31);
#define int long long
ll re ()
{
    ll t;
    cin>>t;
    return t;
}
void solve()
{
    int n=re();
    vector<int>A;
    for(int i=0;i<n;++i)
        A.push_back(re());
    map<int,vector<ll>>adj;
    for(int i=1;i<n;++i)
    {
        int u=A[i]+i;
        int v=u+i;
        adj[u].push_back(v);
    }
    set<int>vis;
    function<void(ll)> dfs=[&](int u)->void 
    {
        if(vis.count(u))
            return;
        vis.insert(u);
        for(auto &i:adj[u])
            dfs(i);
    };
    dfs(n);
    cout<<*vis.rbegin()<<'\n';
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
    {
        solve ();
    }
    return 0;
}
}
signed main ()
{
    return my::main();
}


```
