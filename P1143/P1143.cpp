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
inline int char_to_int(char ch)
{
    if(ch>='A')
    {
        return ch-'A'+10;
    }
    return ch - '0';
}
inline char int_to_char(int x)
{
    if (x < 10)
    {
        return x+'0';
    }
    else
    {
        if (x == 10)
            return 'A';
        else if (x == 11)
        {
            return 'B';
        }
        else if (x == 12)
        {
            /* code */ return 'C';
        }
        else if (x == 13)
        {
            /* code */ return 'D';
        }
        else if (x == 14)
        {
            /* code */ return 'E';
        }
        else if (x == 15)
        {
            /* code */ return 'F';
        }
    }
}
void solve()
{
    int before = re();
    string num;
    cin >> num;
    int len = num.size();
    int after = re();
    int ten_num = 0;
    for (int i = 0; 1; ++i)
    {
        char ch = num[i];
        if (ch >='0'&&ch<='9'||ch>='A'&&ch<='F')
        {
            int N = pow(before, len - i - 1);
            ten_num += char_to_int(ch) * N;
            // printf("%d\n",ten_num);
        }
        else
        {
            break;
        }
    }
    // cout<<ten_num<<endl;
    string ans;
    while (ten_num)
    {
        int tmp=ten_num % after;
        ans+=int_to_char(tmp);
        ten_num/=after;
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
}
signed main()
{
    solve();
    return 0;
}
