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
const int maxn = 1e6 + 7;
char a[maxn];
char b[maxn];
int __next[maxn];//此数组表示此时B数组的次大公共前后缀
signed main()
{
   cin >> a + 1;
   cin >> b + 1;
   int lb = strlen(b + 1);
   int la=strlen(a+1);
   int j = 0;//abcfabcc
   for (int i = 2; i <= lb; ++i)//i表示，b数组前i位，j表示
   {
      j = __next[i - 1];
      while (j && b[j+1] != b[i])//如果次大前缀的末尾+1不等于下标i的字符，根据__next回溯到j
         j=__next[j];//将
      if(b[j+1]==b[i])
         ++j;
      __next[i]=j;
   }//构造__next数组
   // j=0;
   // for(int i=1;i<=la;++i)
   // for(int i=1;i<=la;++i)
   // for(int i=1;i<=la;++i)
   // {
   // {
   //    while (j>0&&b[j+1]!=a[i])// 如果失配就跳回__next[j]
   //       j=__next[j];
   //    if(b[j+1]==a[i])//如果得配，就j++即B字符数组指针向前
   //       ++j;
   //    if(j==lb)//如果长度相等，那么就是匹配成功，输出
   //       printf("%d\n",i-lb+1);
   // }
   // for(int i=1;i<=lb;++i)
   //    printf("%d ",__next[i]);
   for(int i=1;i<=lb;++i)
   printf("%d ",__next[i]);
   return 0;
}
