#include <bits/stdc++.h>
#define ll long long
#define INF 0x7fffffff
const int POS_N = 10001;
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
const int MAX_SIZE = 1000000;  // 假设前50000个素数不会超过100万
const int PRIME_COUNT = 50000; // 需要找的素数个数
int primes[MAX_SIZE]; // 存储素数的数组
int primeCount = 0;   // 当前找到的素数个数
void generatePrimes()
{
    bool isPrime[MAX_SIZE];
    for (int i = 2; i * i < MAX_SIZE; ++i)
    {
        isPrime[i] = true;
    }
    for (int p = 2; p * p < MAX_SIZE; ++p)
    {
        if (isPrime[p])
        {
            for (int i = p * p; i < MAX_SIZE; i += p)
            {
                isPrime[i] = false;
            }
        }
    }
    int index = 0;
    for (int i = 2; primeCount < PRIME_COUNT && i < MAX_SIZE; ++i)
    {
        if (isPrime[i])
        {
            primes[index++] = i;
            ++primeCount;
        }
    }
}
using namespace std;
#define int long long
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
int arr[1000001];
int phi[1000001];
void solve()
{
    int l=re();
    int r=re();
    for(int i=0;i+l<=r;++i)
    {
        arr[i]=phi[i]=i+l;
    }
    for(int i=0;primes[i]<=1e6;++i)
    {
        for(int j=(l-1)/(primes[i]+1)*primes[i];j<=r;++j)
        {
            int temp=j-l;
            if(phi[temp]%primes[i]==0)
            {
                phi[temp]/=primes[i]*(primes[i]-1);
            }
            while (arr[temp]%primes[i]==0)
            {
                arr[temp]/=primes[i];
            }
            
        }
    }
    int ans=0;
    for(int i=0;i<=r-l;++i)
    {
        if(arr[i]>1)
        {
            phi[i]=phi[i]/arr[i]*(arr[i]-1);
        }
        ans=(ans+i+l-phi[i])%666623333;
    }
    cout<<ans<<endl;
}
signed main()
{
    generatePrimes();
    solve();
    return 0;
}