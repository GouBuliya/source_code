/*#include<bits/stdc++.h>
using namespace std;
namespace my{
#define ll long long 
#define pn cout<<"\n";
#define mset(a,x) memset(a,x,sizeof a)
#define mcpy(a,b) memcpy(a,b,sizeof a)
#define all(a) a.begin(),a.end()
#define fls() fflush(stdout)
const int INF=(1<<30);
ll re ()
{
    ll t;
    std::cin>>t;
    return t;
}
void solve()
{
    int n=re();
    int a=re(),b=re(),c=re();
    int d=a+b+c;
    int q=n/d;
    if(q==0)
    {
        if(n<=0)
        {
            cout<<0<<endl;
            return;
        }
        n-=a;
        if(n<=0)
        {
            cout<<1<<endl;
            return;
        }
        n-=b;
        if(n<=0)
        {
            cout<<2<<endl;
            return;
        }
        n-=c;
        if(n<=0)
        {
            cout<<3<<endl;
            return;
        }       
    }
    n-=q*(d); 

        if(n<=0)
        {
            cout<<q*3+0<<endl;
            return;
        }
        n-=a;
        if(n<=0)
        {
            cout<<q*3+1<<endl;
            return;
        }
        n-=b;
        if(n<=0)
        {
            cout<<q*3+2<<endl;
            return;
        }
        n-=c;
        if(n<=0)
        {
            cout<<q*3+3<<endl;
            return;
        } 
}
signed main ()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t=re();
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
}
signed main ()
{
    return my::main();
}*/ 

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll read() {
    ll x;
    cin >> x;
    return x;
}

void solve() {
    ll n = read();  // Monocarp 要走的总距离
    ll a = read(), b = read(), c = read(); // 每天的步行距离

    ll cycle = a + b + c; // 每个完整周期的总距离
    ll fullCycles = n / cycle; // 完整周期数
    ll remainingDistance = n % cycle; // 剩余需要走的距离

    if (remainingDistance == 0) {
        cout << fullCycles * 3 << endl; // 恰好完成周期时的天数
        return;
    }

    ll days = fullCycles * 3; // 已完成的天数

    // 按顺序计算剩余距离的天数
    if (remainingDistance <= a) {
        cout << days + 1 << endl;
    } else if (remainingDistance <= a + b) {
        cout << days + 2 << endl;
    } else {
        cout << days + 3 << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = read(); // 测试用例数量
    while (t--) {
        solve();
    }

    return 0;
}

