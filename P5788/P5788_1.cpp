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

vector <int>pos(1);
vector <int>data(1);
void solve()
{
    int n = re();
    
    for(int i=1;i<=n;++i)
    {
        data.push_back(re());
        pos.push_back(i);
    }
    reverse(data.begin(),data.end());
    reverse(pos.begin(),pos.end());
    stack<int>st;
    stack<int>st_p;
    for (int i = 1; i <= n; ++i)
    {
        int temp=data[i];
        int temp_pos=pos[i];
        if(st.empty())
        {
             st.push(temp);
             st_p.push(temp_pos);
        }
        while (!st.empty()&&temp<st.top())
        {
            st.pop();
            st_p.pop();
            
        }st.push(temp);
        int ans=st_p.top();
        st_p.push(temp_pos);
        cout<<ans<<" ";
        
    }
    // reverse(veArr.begin(),veArr.end());
    
    
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