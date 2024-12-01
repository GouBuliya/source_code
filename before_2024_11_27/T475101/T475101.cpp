/*************************************************************************
	> File Name: T475101.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Fri Jul 12 09:33:12 2024
 ************************************************************************/
//

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define i128 __int128_t
#define pn putchar('\n')
#define mclear(a) memset(a,0,sizeof a)
#define fls() fflush(stdout)
#define int i128
#define ll i128
int re()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	
	return x*t;
}
inline void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

ll PowerMode (ll a,ll b,ll mode)
{
    ll sum=1;
    a%=mode;                    //第一步，先取余
    while(b)                    //指数为0循环停止
    {
        if(b%2==1)               //奇数时，先乘一个a
        {
            sum=(sum*a)%mode;
        }
        b/=2;                    //反正都要减半
        a=a*a%mode;               //a就要平方（再取余）
    }
    return sum;
}
int Tower(int a, int b) {
    if (b == 0) return 0;
    if (b == 1) return a;
    int prev = Tower(a, b - 1);
    if (prev == 0) return 0;
    // 由于我们假设 a 和 b 都是小数，所以这里可以直接做异或
    int result = 0;
    for (int i = 0; i < prev; ++i) {
        result ^= a;
    }
    return result;
}

signed main() {
    string a,b;
	cin>>a>>b;
	if(b=="0")
	cout<<0<<endl;
	if((a[a.size()-1]^48)%2==1)
	{
		cout<<a<<endl;
	}
	else
	{
		if(b=="1")cout<<a<<endl;
		else
		cout<<0<<endl;
	}
    return 0;
}