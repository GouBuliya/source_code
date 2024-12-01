#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;
const int maxm=2e5+10;
vector<int>G[maxm];
int dis[maxn];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>que;

void dj(int start)
{
    dis[start]=0;
    memset(dis,-1,sizeof(dis));
    
signed main ()
{
    
