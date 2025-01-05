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
struct Node
{
    bool mode;
    int price;
    int time;
} record[100001];
struct preferential_card
{
    int time;
    int price;
};
vector<preferential_card> pre(1000);
int P;
int T;
void solve()
{
    int N = re();
    for (int i = 1; i <= N; ++i)
    {
        record[i].mode = re();
        record[i].price = re();
        record[i].time = re();
        if (record[i].time - pre[0].time > 45)
        {
            int temp = 1;
            while (record[i].time - pre[temp].time > 45)
            {
                temp++;
            }
            pre.erase(pre.begin(), pre.begin() + temp - 1);
        }

        if (!record[i].mode)
        {
            preferential_card temp;
            temp.price = record[i].price;
            temp.time = record[i].time;
            pre.push_back(temp);
        }
        else
        {
            if (pre.size() != 0)
            {
                bool flag = 0;
                for (int i = 0; i < pre.size(); ++i)
                {
                    if (record[i].price <= pre[i].price && record[i].time - pre[i].time <= 45)
                    {
                        P += 0;
                        flag = 1;
                        break;
                    }
                }
                if (!flag)
                {
                    P += record[i].price;
                }
            }
            else
                P += record[i].price;
        }
    }
    cout<<P<<endl;
}
signed main()
{
    
        solve();
    

    return 0;
}
