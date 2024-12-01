#include <cstdio>
using namespace std;
const int maxn=1e6+7;
char str[maxn];
int nex[maxn];int n;
signed main()
{
    
    scanf("%d%s",&n,str+1);
    int j=0;
    for(int i=2;i<=n;++i)
    {
        while (j&&str[j+1]!=str[i])j=nex[j];
        if(str[j+1]==str[i])++j;
        nex[i]=j;
    }
    printf("%d",n-nex[n]);
    return 0;
}
// #include<cstdio>
// using namespace std;
// const int maxn=1111111;
// int n,kmp[maxn];//kmp数组即next数组
// char ss[maxn];
// int main()
// {
// 	scanf("%d%s",&n,ss+1);
// 	int j=0;
// 	for(int i=2;i<=n;++i)
// 	{
// 		while(j&&ss[i]!=ss[j+1]) j=kmp[j];
// 		if(ss[i]==ss[j+1]) ++j;
// 		kmp[i]=j;
// 	}
// 	printf("%d",n-kmp[n]);
// 	return 0;
// }
