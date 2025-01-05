#include<bits/stdc++.h>
using namespace std;
int main(){
	map<string,int>t;
	string c,s,c1,s1,c2,s2;
	int n,ans=0;
	cin>>n;
	while(n--)
	{ 
		cin>>c>>s;
		c2=c[0];c2+=c[1];//c2表示输入的c的前两位
		s2=s[0];s2+=s[1];//s2表示输入的s的前两位
		c1=c2;c1+=" ";c1+=s2;//c1表示合并c和s的结果
		s1=s2;s1+=" ";s1+=c2;//s1表示合并s和c的结果
		ans+=t[s1];
		if(c2==s2)//特判
		ans-=t[c1];
		t[c1]++;
	}
	cout<<ans<<endl;
    	return 0;
} 
