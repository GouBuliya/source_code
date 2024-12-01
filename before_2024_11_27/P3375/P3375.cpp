#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e6+10;

int nxt[maxn];
int j=0;
char s1[maxn];
char s2[maxn];

signed main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    cin>>s1+1;
    cin>>s2+1;
    int len1=strlen(s1+1);
    int len2=strlen(s2+1);
    //构造next数组
    for(int i=2;i<=len2;++i)
    {
        while(j&&s2[i]!=s2[j+1])
            j=nxt[j];
        if(s2[i]==s2[j+1])
            j++;
        nxt[i]=j;
    }
    // for(int i=1;i<=len2;++i)
        // cout<<nxt[i]<<" ";
    //进行匹配
    j=0;
    for(int i=1;i<=len1;++i)
    {
        while (j&&s1[i]!=s2[j+1])
            j=nxt[j];
        if(s1[i]==s2[j+1])++j;
        if(j==len2)
        {
            cout<<i-len2+1<<endl;
            j=nxt[j];
        }
    }
    for(int i=1;i<=len2;++i)cout<<nxt[i]<<" ";
    return 0;
}
