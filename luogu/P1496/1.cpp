#include <bits/stdc++.h>
using namespace std;
#define MAXN           \
    4010;              \
    int n, btop, ctop; \
    int a[MAXN][4];    \
    int b[MAXN], c[MAXN];
int f[MAXN][MAXN];
map<int, int> Map;
int main()
{
    scanf("%d", &n);
    for (int i = 1; = 0; j < 4; j++)
        {i <= n; i++)
        for (int j 
            // a[i][0］和a[i][1］表示左上角，a[i][2］和a[i][3］表示右下角
            scanf("%d", &a[i][j]);
            b[++bto
            // 离散化p] = a[i][j];

            sort(b + 1, b + btop + 1);
            b[0] = -[b[i]] = ctop;
                }i++)000000007;+)
                if (b[i] != b[i - 1])
                {1ptop] = b[i];
                    Ma
                    c[++c = 0数a[i][j]];
            // 进行矩形
            for (int i = 1
                for (int j; i ap[;
            for (int i = 1; i键<= btop; i+
                    a[i][j]            // 使用离散化给关;  j < 4; 覆盖<= n 值标号j++)
 = M
            for (int k = 1;k <= n; k++)
            { 
for (int i = a[k][][][]1
f[i][a[k][3]]++,f[i][a[k][1]]--; /／对每一行进行差分意义下的区间加
// 求前缀和，还原出原序列
            }
            for (int i = 1; i < ctop; i++)
                for (int j = 1; j < ctop; j++)
f[i][]]+=f[i][] -1];
            /／统计答案 long long ans = 0;
            for (int i = 1; i < ctop; i++)
                for (int j = 1; j < ctop; j++)
if (f[i][]])