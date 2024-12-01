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
void slove()
{
    int n=re();
    vector<int>A;
    for(int i=1;i<=2*n;++i)
        A.push_back(re());
    int a=0,b=0;
    for(auto &i:A)
    {
        if(i==1)
            a++;
        else 
            b++;
    }
cout<<((a%2&&b%2)?1:0)<<" "<<min(a,b)<<endl;
}
signed main()
{
  int t=re();
  while(t--)
      slove();
  return 0;
}

