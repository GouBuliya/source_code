#include <bits/stdc++.h>
using namespace std;
namespace FastIO
{
    char buf[1 << 21], *p1 = buf, *p2 = buf;
#define getchar() (p1 == p2 && (p1 = buf, p2 = (p1 + fread(buf, 1, 1 << 21, stdin))) == p1 ? EOF : *p1++)
    template <typename T>
    inline T read()
    {
        T x = 0, w = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
            w |= (ch == '-'), ch = getchar();
        while ('0' <= ch && ch <= '9')
            x = x * 10 + (ch ^ '0'), ch = getchar();
        return w ? -x : x;
    }
    template <typename T>
    inline void write(T x)
    {
        if (!x)
            return;
        write<T>(x / 10), putchar((x % 10) ^ '0');
    }
    template <typename T>
    inline void print(T x)
    {
        if (x > 0)
            write<T>(x);
        else if (x < 0)
            putchar('-'), write<T>(-x);
        else
            putchar('0');
    }
    template <typename T>
    inline void print(T x, char en) { print<T>(x), putchar(en); }
};
#undef getchar()
namespace my
{
    using namespace FastIO;
    const int maxnm=2e6+10;
    int a[maxnm];
    int n,m,q;
    void solve()
    {
        int op=read<int>();
        if(op==1)
        {
            int x=read<int>(),y=read<int>();
            inplace_merge(a+x*n+1,a+x*n+n+1,a+y*n+1,a+y*n+n+1);
        }
        else 
        {
            int i=read<int>(),j=read<int>();
            write<int>(a[i*n+j]);
        }
        return;
    }
    signed main()
    {
        n=read<int>();
        m=read<int>();
        q=read<int>();
        for(int i=0;i<m;++i)
            for(int j=1;j<=n;++j)
                a[i*n+j]=read<int>();
        while(q--)
            solve();
        return 0;
    }
};
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    return my::main();
}
