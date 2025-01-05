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
void solve ()
{
    string str;

    cin>>str;
    int ans=0;
    for(int i=0;i<=8;++i)
    {
        if(str[i]=='1')
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    
}
signed main()
{
    solve();
    return 0;
}
                                                                                                                                                                                  
