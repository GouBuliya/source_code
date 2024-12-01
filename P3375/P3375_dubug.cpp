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
const int maxn=1e6+7;
char A[maxn];
char B[maxn];
int __next[maxn];
signed main()
{

    scanf("%s\n%s",A,B);
    int LA=strlen(A);
    int LB=strlen(B);
    cout<<A<<endl;
    printf("%d\n",LB);fls();
    for(int i=0,j=0;i<LB;++i)
    {
        int n=0;
        int k=0;j=i;
        while (j>=0&&k<i)
        {
            if(B[j]!=B[k])
                break;
            else
                __next[i]++;
            j--,k++;
        }
    }

    return 0;
}
