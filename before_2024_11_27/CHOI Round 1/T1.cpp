#include <iostream>
#include <vector>

typedef unsigned long long ull;
#define ll long long
std::vector<ull> sieve_of_eratosthenes(ull limit) {
    std::vector<bool> is_prime(limit + 1, true);
    std::vector<ull> primes;

    is_prime[0] = is_prime[1] = false; // 0 和 1 不是质数

    for (ull num = 2; num <= limit; ++num) {
        if (is_prime[num]) {
            primes.push_back(num); // num 是质数
            // 标记 num 的倍数为合数
            for (ull multiple = num * num; multiple <= limit; multiple += num) {
                is_prime[multiple] = false;
            }
        }
    }

    return primes;
}
int re()
{
    int x=0,t=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*t;
}
    ull limit = 100000;
    std::vector<ull> prime = sieve_of_eratosthenes(limit);
void solve ()
{
    ll n=re(),k=re(),d=re();
    ll ans=n; 
    for(int i=1;i<=n;++i)
    {
           
    }
}
int main() {

    int t;
    t=re();
    while(t--)
        solve();


    return 0;
}