#include <cmath>
#include <ctime>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>//头文件准备
using namespace std;
int s[100005][2],sum[100005][2],c[100005],x[100005];//定义二维数组方便分组
int n,m,ans;
int main(){
    scanf ("%d %d",&n,&m);//其实m没有什么用处
    for (int i=1;i<=n;i++){
        scanf ("%d",&x[i]);
    }
    for (int i=1;i<=n;i++){
        scanf ("%d",&c[i]);
        s[c[i]][i%2]++;//求出这个分组中有多少个数
        sum[c[i]][i%2]=(sum[c[i]][i%2]+x[i])%10007;//事先求出累加和，注意，要mod10007
    }
    for (int i=1;i<=n;i++){
        ans=(ans+i*((s[c[i]][i%2]-2)*x[i]%10007+sum[c[i]][i%2]))%10007;//依次然后代入，注意，也要mod10007
    }
    printf ("%d\n",ans);//最后输出
    return 0;
}