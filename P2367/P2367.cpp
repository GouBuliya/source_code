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
int arr[5000001];
int diff[5000001];
void diff_f(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        diff[i] = arr[i] - arr[i - 1];
    }
}
int prefix[5000001];
signed main()
{
    int n = re();
    int p = re();
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = re();
    }
    diff_f(n);
    for (int i = 1; i <= p; ++i)
    {
        int x=re(), y=re(), z=re();
        diff[x] += z;
        diff[y + 1] -= z;
        
    }
    int mmin=INT32_MAX;
    for (int i = 1; i <= n; ++i)
    {
        arr[i]=arr[i-1]+diff[i];
        mmin=min(arr[i],mmin);
        // cout<<diff[i]<<endl;
    }
    
    cout<<mmin<<endl;
    return 0;
}
