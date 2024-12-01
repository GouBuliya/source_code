#include <bits/stdc++.h>

#define file(x) freopen(x,"r",stdin);
#define clos(x) freopen(x,"w",stdout);

using namespace std;

const int seed=114514;

mt19937_64 mt((unsigned long long)&seed);

inline int rand(int l,int r)
{
	return uniform_int_distribution<int>(l,r)(mt);//<>不填写默认为int类型
	// uniform_int_distribution生成整数，<>不填写默认为int 
	//uniform_real_distribution生成实数 ，<>不填写默认为double 
}

int main()
{
	clos("a.in");
	// 这是数据的格式 赋值直接a=rand(1,10000)即可
	return 0;
}

