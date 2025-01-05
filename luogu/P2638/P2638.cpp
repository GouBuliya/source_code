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
unsigned long long jc(int n)
{
    if(n==1)
    {
        return n;
    }
    unsigned long long ans = 1;
    while (n != 1)
    {
        ans *= n;
        n--;
    }
    
    return ans;
}
unsigned long long Binomial_coefficient(int n,int m)
{
    return jc(n)/jc(m)*jc(n-m);
}
signed main()
{
    int n = re();
    int a = re();
    int b = re();
    uint64_t ans = 0;
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            ans = ans + Binomial_coefficient(n-1,i+n-1)*Binomial_coefficient(n-1,j+n-1);
        }
    }
    cout<<ans<<endl;
    return 0;
}