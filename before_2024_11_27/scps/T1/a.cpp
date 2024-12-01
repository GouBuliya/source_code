#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int maxn=1e5+10;
int A[11][maxn];
int m[11][11];
int tt=1;
auto cmp=[](int l,int r){return m[tt][A[tt][l]]>m[tt][A[tt][r]];};
priority_queue<int,vector<int>,decltype(cmp)> que(cmp);
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("bargain1.in","r",stdin);
    int op;
    cin>>op;
    int t;
    cin>>t;
    while(t--)
    {
        char ch;
        int p=1;
        ll ans=0;
        string str;
        cin>>str;
        for(auto &i:str)
        {
            A[tt][p++]=i-'0';
        }

        for(int i=1;i<10;++i)
            cin>>m[tt][i];
        --p;
        
        for(int i=1;i<=(p);++i)
        {
            que.push(A[tt][i]);
        }
        bool flag=true;
        for(int i=1;i<=p&&flag;++i)
        {
            if(p-i<6)
            {

                vector<int>arr;
                ll n=0;
                int t=1;
                while(!que.empty()){
                arr.push_back(que.top());
                que.pop();}
                vector<int> b(arr);
                
                sort(arr.begin(),arr.end());
                for(auto &j:arr)
                    n+=(t++)*j;
                for(auto &j:b)
                    que.push(j);
                if(n<=m[tt][A[tt][que.top()]])
                {
                    ans+=n;
                    cout<<ans<<endl;flag=0;
                    break;
                }
                else
                {
                    ans+=m[tt][A[tt][que.top()]];
                    que.pop();
                }
            }
            else 
            {
                 ans+=m[tt][A[tt][que.top()]];
                    que.pop();
            }
        }
        tt++;//m[tt][A[tt][pos]]==>que 
    }
    }
    

    


