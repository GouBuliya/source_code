#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<deque>
using namespace std;
const int maxsize = 2000010;
int n,m;
struct node
{
    int val;
    int pos;
}A[maxsize];
deque<node> min_Q;
inline int rd()
{
    int data = 0;
    int f = 1;
    char ch = getchar();
    while(ch < '0'||ch > '9')
    {
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0'&&ch <= '9')
    {
        data = (data<<3) + (data<<1) + ch - '0';
        ch = getchar();
    }
    return f * data; 
}
int min_que[maxsize]; 
int main()
{
    n = rd(),m = rd();
    for(int i = 1;i <= n;i++)
    {
        A[i].val = rd();
        A[i].pos = i - 1;
    }
    min_que[0] = 0;
    for(int i = 1;i < n;i++)
    {
        while(!min_Q.empty()&&min_Q.back().val >= A[i].val)
            min_Q.pop_back();
        min_Q.push_back(A[i]);
        while(!min_Q.empty()&&min_Q.front().pos < i - m)
            min_Q.pop_front();
        min_que[i] = min_Q.front().val;
    }
    for(int i = 0;i < n;i++)
        printf("%d\n",min_que[i]);	
            
}