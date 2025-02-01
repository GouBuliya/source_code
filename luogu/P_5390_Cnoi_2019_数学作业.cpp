#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[3000006]; 
const int mod=998244353;
int ans,res;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		scanf("%d",&n);
		ans=1,res=0;
		for (int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			res|=x;
			if (i!=1) ans=(ans*2)%mod;
		}
		res=res%mod;
		printf("%lld\n",(ll)ans*(ll)res%mod);
	}
	return 0;
}








hotblock1:
    Stmts; // <-- 热！
    if (/* 边界条件不成立 */ true)
        goto hotblock2; // 经常发生！ ------+
coldblock:                           /*   |   */
    Stmt; // <- 冷                        |
    Stmt; // <- 冷                        |
    Stmt; // <- 冷                        |  跨越了大量指令，代价高昂！
    Stmt; // <- 冷                        |
    Stmt; // <- 冷                        |
    Stmt; // <- 冷                        |
    Stmt; // <- 冷                        |
hotblock2:                          /*    |   */
    Stmts; // <- 热！           <----------+
hotblock1:
    Stmts; // <-- 热！
    if (/* 边界条件 */ false)
        goto coldblock; // 很少发生
hotblock2:                         /*   |  低代价！  */
    Stmts; // <- 热！  <-----------------+
coldblock:
    Stmt; // <- 冷
    Stmt; // <- 冷
    Stmt; // <- 冷
    Stmt; // <- 冷
    Stmt; // <- 冷