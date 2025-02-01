#include <stdio.h>
#include <iostream>
#define ll long long
using namespace std;

ll fun(int n, int m)
{
    if (m <= 0 || n < m)
        return 0;
    if (n == m)
        return 1;
    else
        return fun(n-1, m-1) + fun(n-1, m) * m;
}

ll fac(int i) // 然而这个函数不用讲什么
{
    if (i == 1)
        return 1;
    else
        return i * fac(i - 1);
}

int main() // 完美主程序
{
    ll n, m;
    cin >> n >> m;
    cout<< fun(n, m) * fac(m);
    return 0;
}