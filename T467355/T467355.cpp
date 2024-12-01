#include <bits/stdc++.h>
#define ll long long
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
const int maxn = 1e5 + 7;
int arr[maxn];
int b[maxn];

stack<int> oushu;
stack<int> jishu;
signed main()
{
    int n = re();
    map<int, int> M;
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = re();
        M[arr[i]]++;
    }
    int zhoulei = 0;
    for (auto &i : M)
    {
        if (i.second % 2 == 0)
        {
            oushu.push(i.first);
        }
        else
        {
            jishu.push(i.first);
            zhoulei++;
        }
    }
    int a = 0, b = 0;
    int a_pos, b_pos;
    vector<int> ans;
    if (zhoulei % 2 == 1)
    {
        printf("-1");
        return 0;
    }
    else
    {
        while (ans.size() < n)
        {

            if (!oushu.empty()&&a == 0)
            {
                a_pos = oushu.top();
                oushu.pop();
                a = M[a_pos];
            }
            if (!jishu.empty()&&b == 0)
            {
                b_pos = jishu.top();
                jishu.pop();
                b = M[b_pos];
            }
            if(a)ans.push_back(b_pos);
            if(b)ans.push_back(a_pos);
            b--,a--;
        }//5 4 5 3
    }
    for(auto &i:ans)
    {
        printf("%d ",i);
    }
    return 0;
}
