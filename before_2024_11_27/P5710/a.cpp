#include <bits/stdc++.h>
using namespace std;
int re()
{
    int t;
    cin>>t;
    return t;
}
int x;
bool a, b;
int main(){
	scanf("%d", &x);
	a = !(x & 1), b = (x > 4 && x <= 12);//a满足性质1，b满足性质2
	printf("%d %d %d %d", a & b, a | b, (a && !b || b && !a), !a && !b);
}
