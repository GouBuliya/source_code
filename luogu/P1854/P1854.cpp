#include<bits/stdc++.h> //万能头；
using namespace std;
int c[3000];
int v[3000];
int f[3000];
int num[3000];
int main(){
//以上这部分死活都转换不成代码。。。。。。。
    int t=0,n,a,l,p,q,x,y;
    scanf("%d:%d %d:%d %d",&q,&p,&x,&y,&n); //令人无奈的“简单的”输入；
    if(x<q) {cout<<0; return 0;}
    if(x==q && y<=p) {cout<<0; return 0;}//以上这两个是判断去学校的时间是否大于现在时间，若大于。。。。还看个辣子樱花
    if(y>=p) {t+=y-p;t+=60*(x-q);}//后分钟数大于前分钟数时
    if(y<p) {t+=60-p;t+=60*(x-q-1);t+=y;}   //先加到前的满时，再小时差，再加上后的那几分钟；
    l=n;//全部换为01的总长的初值；
    for(int i=1;i<=n;i++)
    {
        cin>>c[i]>>v[i]>>num[i];
        if(num[i]!=1 && num[i]!=0)
        {
            a=i;
            for(int j=2;j<=num[a];j++) //由于前面已经输入时保存了一个，循环从2开始即可以在这里少循环一个，达到要的num；
            {
                c[++l]=c[i];v[l]=v[i];//注意v[l]不能++；
            }
        }
        if(num[i]==0)
        {
            for(int j=1;j<=50;j++)//无限？直接给你50个！（40不够）
            {
                c[++l]=c[i];v[l]=v[i];
            }
        }
    }
    for(int i=1;i<=l;++i)
      for(int j=t;j>=c[i];--j) 
          f[j]=max(f[j],f[j-c[i]]+v[i]);//一维的01背包；
    cout<<f[t]; //答案！！
    return 0;
}
