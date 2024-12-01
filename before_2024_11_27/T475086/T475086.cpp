// #include <bits/stdc++.h>
// #define ll long long
// #define pn putchar('\n')
// #define mclear(a) memset(a, 0, sizeof a)
// #define fls() fflush(stdout)
// using namespace std;
// int re()
// {
//     int x = 0, t = 1;
//     char ch = getchar();
//     while (ch > '9' || ch < '0')
//     {
//         if (ch == '-')
//             t = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9')
//         x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
//     return x * t;
// }
// const int maxn = 2 * 1e3;
// int arr[maxn];
// int dp[maxn];
// ll ans = 0;
// signed main()
// {
//     int n = re();
//     for (int i = 1; i <= n; ++i)
//     {
//         arr[i] = re();
//         ans+=arr[i];
//     }
//     for (int i = 1; i <= n; ++i)
//     {

//         dp[1] = arr[i];
//         int pos = 1;
//         for (int k = i + 1; k <= n; ++k)
//         {
//             // while (!(arr[k] - arr[j] == j))
//             // {
//             //     k++;
//             // }
//             // if (arr[k] - arr[j] == j)
//             // {
//             //     if (pos % 2 == 1)
//             //     {
//             //         dp[pos] =dp[pos-1]+ arr[j];
//             //     }
//             //     else
//             //     {
//             //         dp[pos] = dp[pos-1]-arr[j];
//             //     }
//             //     pos++;
//             // }
//             if (arr[k] - arr[pos + i - 1] == pos)
//             {
//                 if ((pos + 1) % 2 == 1)
//                 {
//                     dp[pos + 1] = dp[pos] + arr[k];
//                     ans += dp[pos + 1];
//                 }
//                 else
//                 {
//                     dp[pos + 1] = dp[pos] - arr[k];
//                     ans += dp[pos + 1];
//                 }

//                 pos++;
//             }
//         }

//         // cout << ans << endl;
//     }
//     cout << ans << endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    
    long long n, a, pe = 0, po = 0, ans = 0;
    cin >> n;
    
    for(long long i = 0; i < n; ++i) {
        cin >> a;
        if (i & 1) { // i is odd
            po = a + pe;
            ans += po;
        } else { // i is even
            pe = a + po;
            ans += pe;
        }
    }
    
    cout << ans;
    
    return 0;
}