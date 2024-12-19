#include<bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
using namespace std;
int re()
{
    int x=0,t=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*t;
}
const int MAXN= 1e6 + 3;
typedef unsigned int       u32;
typedef unsigned long long u64;
const u32 BAS1 = 131, MOD1 = 1e9 + 7;
const u32 BAS2 =   131, MOD2 = 1e9 + 9;
ll H1[MAXN], P1[MAXN];
ll H2[MAXN], P2[MAXN];
ll ha[10007];
int get(int len,string S)
{
    int h=0;
    for(int i=0;i<len;++i)
    {
        h=h*BAS1+(u64)S[i];
    }
    return h&0x7fffffff;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        {
            string str;cin>>str;
            int len = str.length();
            ha[i]=get(len,str);
        }
    sort(ha+1,ha+1+n);
    int ans=0;
    for(int i=2;i<=n;++i)
    {
        if(ha[i]!=ha[i-1])
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
                                                                                                                                                                                  
