#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
const int maxn = 3e4 + 5;
bitset <maxn> s[maxn], f; 
int n, m, q; 
int read()
{
    int x;
    scanf("%d", &x);
    return x;
}
void print(int val) 
{
    printf("%d\n", val);
}
int main()
{
    n = read(), m = read(), q = read(); 
    for (int i = 1, c; i <= n; i++)
        for (int c = read(), j = 0, x; j < c; j++)
            scanf("%d", &x), s[i][x] = 1; 
    for (int i = 1; i <= m; i++) 
        f[i] = 1; 

    while (q--)
    {
        int opr = read(), x = read(), y = read();
        if (opr == 1)
            s[x] <<= y, s[x] &= f;
        else if (opr == 2)
            s[x] >>= y, s[x] &= f;
        else if (opr == 3)
            print((s[x] & s[y]).count());
        else if (opr == 4)
            print((s[x] | s[y]).count());
        else
            print((s[x] ^ s[y]).count());            
    }

}
