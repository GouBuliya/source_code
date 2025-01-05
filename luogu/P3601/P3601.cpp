#include <bits/stdc++.h>
#define ll long long
#define INF 0x7fffffff
const int POS_N = 10001;
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
const int MAX_SIZE = 1000000; // 假设前50000个素数不会超过100万
const int PRIME_COUNT = 50000; // 需要找的素数个数

int primes[MAX_SIZE]; // 存储素数的数组
int primeCount = 0;   // 当前找到的素数个数

void generatePrimes() {
    bool isPrime[MAX_SIZE];
    for (int i = 2; i*i < MAX_SIZE; ++i) {
        isPrime[i] = true;
    }

    for (int p = 2; p * p < MAX_SIZE; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i < MAX_SIZE; i += p) {
                isPrime[i] = false;
            }
        }
    }

    int index = 0;
    for (int i = 2; primeCount < PRIME_COUNT && i < MAX_SIZE; ++i) {
        if (isPrime[i]) {
            primes[index++] = i;
            ++primeCount;
        }
    }
}
using namespace std;
ll re()
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
int pri_n[100001];
int c_n[100001];
__int128_t binpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
void solve()
{
    ll l = re();
    ll r = re();
    ll ans = 0;
    for (ll i = l; i <= r; ++i)
    {
        memset(pri_n, 0, sizeof pri_n);
        memset(c_n, 0, sizeof c_n);
        ll temp = i;
        ll pos = 0;
        for (int j = 0; primes[j]*primes[j] <= temp; ++j)
        {
            if (temp % primes[j] == 0)
            {
                pri_n[++pos] = primes[j];
                while (temp % primes[j] == 0)
                {
                    temp /= primes[j];
                    c_n[pos]++;
                }
            }
        }
        if (temp != 1)
        {
            pri_n[++pos] = temp;
            c_n[pos]++;
        }
        __int128_t T = 1;
        for (int i = 1; i <= pos; ++i)
        {
            T =(T* (pri_n[i] - 1) *binpow(pri_n[i],c_n[i]-1)%666623333)%666623333;
            // T =(T* (pri_n[i] - 1))%666623333;
            // for(int k=1;k<=c_n[i]-1;++k)
            // {
            //     T=T*pri_n[i]%666623333;
            // }
        }
        ans =(ans +i -T)%666623333;
    }
    cout << ans << endl;
}
signed main()
{
    generatePrimes();
    solve();
    return 0;
}