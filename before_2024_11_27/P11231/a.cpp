#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int A[maxn];
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>A[i];
    }
    sort(A+1,A+1+n);
    int j=n;
    int ans=0;
    for(int i=n;i>=1&&j>=1;i--)
    {
        while(A[j]>=A[i])
            j--;
        if(A[j]<A[i]&&j>=1)
        {
            ans++;j--;
        }
    }
    cout<<n-ans<<endl;
}
/*有n个卡牌，第i张卡代表r[i]权值，有若干次操作
 ：选择两个数i，j让i对j发起攻击，如果i>j,j卡牌退出，且i不能再攻击
，求未退出游戏的怪物的最小值
注意到：要使未退出游戏的怪尽可能少，就要使退出游戏的怪尽可能多，退出游戏的条件是：i>j 也就是尽可能使操作有效，即尽量使i>j的操作多
维护两个指针，i表示i，j表示小于i且被没有攻击过的j*/
