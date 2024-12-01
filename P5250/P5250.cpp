#include <bits/stdc++.h>
#define ll long long
#define INF = 0x7fffffff
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
set<int> box;
void solve()
{
    int N = re();
    for (int I = 1; I <= N; ++I)   
    {
        int Mode = re();
        int Lang = re();
        if (Mode == 1)
        {
            if (box.find(Lang) != box.end())
            {
                cout << "Already Exist" << endl;
            }
            else
            {
                box.insert(Lang);
            }
        }
        else
        {
            if (box.empty())
            {
                cout << "Empty" << endl;
            }
            else if (box.find(Lang) != box.end())
            {
                box.erase(box.find(Lang));
                cout << Lang << endl;
            }
            else
            {
                set<int>::iterator i = box.lower_bound(Lang), j = i;
                if (j != box.begin())
                    --j;
                if (i != box.end() && Lang - (*j) > (*i) - Lang)
                    j = i;
                cout << (*j) << endl, box.erase(j);
            }
        }
    }
}
signed main()
{
    solve();
    return 0;
}