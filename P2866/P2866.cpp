#include <bits/stdc++.h>
#define ll long long
#define INF 0x7fffffff
const int POS_N = 10001;
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
int re()
{
    int x = 0, t = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x * t;
}
int a[100000];
stack<int> st;
void solve()
{
    int n=re();
        
    ll ans =0;
    for(int i=1;i<=n;++i)
    {a[i]=re();
        while (!st.empty()&&a[i]>=st.top())
        {
            st.pop();
        }
        ans+=st.size();
        st.push(a[i]);
    }
    cout<<ans<<endl;
}
signed main()
{
    int N = 1;
    while (N--)
    {
        solve();
    }
    return 0;
}