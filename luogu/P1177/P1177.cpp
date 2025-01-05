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
int arr_c[100000 + 7];
void merge_sort(int arr[], int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    merge_sort(arr, l, mid), merge_sort(arr, mid+1, r);
    for (int i = l, j = l, k = mid + 1; i <= r; ++i)
    {
        if (mid + 1 == j)
            arr_c[i] = arr[k++];
        else if (k == r + 1)
            arr_c[i] = arr[j++];
        else
            arr_c[i] = arr[j] < arr[k] ? arr[j++] : arr[k++];
    }
    for (int i = l; i <= r; ++i)
        arr[i] = arr_c[i];
}
int arr[100000+7];
void solve()
{
    
    int n = re();
    for (int i = 1; i <= n; ++i)
    {
        arr[i]=re();
    }
    merge_sort(arr,1,n);
    for(int i=1;i<=n;++i)
        printf("%d ",arr[i]);
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