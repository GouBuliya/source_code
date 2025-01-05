#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,shou,now;
	cin>>n;
	char a[n],b[n],ans[n];
	cin>>a>>shou;
	for(int i=0;i<n;i++)b[i]=a[i];
	sort(b,b+n);//自动排序
    // cout<<b<<endl;
	for(int i=0;i<n;i++)
	{
		if(b[i]==a[shou-1])
		{
			now=i;
			b[i]=')';//标记，退出
			break;
		}
	}
    // cout<<b<<endl;

	ans[0]=a[now];//计入答案
	for(int i=1;i<n;i++)//ans[i]表示倒数第i+1个字母
	{
		for(int j=n-1;j>=0;j--)//从后往前搜到第一个与原char串匹配的字典序串
		{
			if(b[j]==a[now])
			{
				now=j;//更改现在所在位置，即跳到前一个字母
				ans[i]=a[now];//计入答案
				b[j]=')';//标记
				break;
			}
		}	
	}
	for(int i=n-1;i>=0;i--)cout<<ans[i];//倒序输出
}