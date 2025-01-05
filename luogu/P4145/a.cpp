#include <bits/stdc++.h>
#define ll int
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
ll re()
{
    int t;
    cin >> t;
    return t;
}
const int maxn = 1e5 + 8;
int A[maxn];
int tag[maxn];
int B[maxn];
void push_up(int l, int r, int p)
{
    B[p] = B[ls] + B[rs];
}
void build(int l, int r, int p)
{
    if (l == r)
    {
        B[p] = A[l];
        return;
    }
    const int mid=(l+r)/2;
    build (l,mid,ls);
    build (mid+1,r,rs);
    push_up(l,r,p);
}
void tag_appty(int l,int r,int p,int k)
{
    tag[p]+=k;  
    
}
void push_down(int l,int r,int p)
{

}
void add(int nl,int nr,int l,int r,int k,int p)
{
    if(nl<=l&&nr>=r)
    {
        tag_appty(l,r,p,k);
        return ;
    }
    int mid=(l+r)/2;
    if(nl<=mid)

}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
