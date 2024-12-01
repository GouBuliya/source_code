#include <bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;

const int maxn = 1e6 + 10;
std::map<string, int> mp1;
std::map<string, int> mp2;
int tp = 1;
int drr1[maxn];
int drr2[maxn];
int arr1[maxn];
int arr2[maxn];
int nex[maxn];
signed main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    string t;
    int pos = 1;
    arr1[0]=arr2[0]=0;
    while (std::cin >> t && t != "$")
    {
        arr1[pos] = mp1[t];
        if (!arr1[pos])
        {
            mp1[t] = tp;
            arr1[pos] = tp;tp++;
        }
        ++pos;
    }
    for (int i = 1; i <= pos; ++i)
        drr1[i] = arr1[i] - arr1[i - 1];
    int la = pos - 1;
    pos = 1;
    tp = 1;
    while (std::cin >> t && t != "$")
    {
        arr2[pos] = mp2[t];
        if (!arr2[pos])
        {
            mp2[t] = tp;
            arr2[pos] = tp;tp++;
        }
        ++pos;
    }
    for (int i = 1; i <= pos; ++i)
        drr2[i] = arr2[i] - arr2[i - 1];
    int j = 0;
    int lb = pos - 1;
    for (int i = 2; i <= lb; ++i)
    {
        while (j && drr2[j + 1] != drr2[i])
            j = nex[j];
        if (drr2[j + 1] == drr2[i])
            j++;
        nex[i] = j;
    }
    j = 0;
    for (int i = 1; i <= la; ++i)
    {
        while (j && drr1[i] != drr2[j + 1])
            j = nex[j];
        if (drr1[i] == drr2[j + 1])
            j++;
        if (j == lb)
        {
            cout << i - lb + 1 << endl;
            break;
        }
    }
    for (int i = 1; i <= la; ++i)
        cout << drr1[i] << " ";
    cout << endl;
    for (int i = 1; i <= lb; ++i)
        cout << drr2[i] << " ";
    cout << endl;
    for (int i = 1; i <= la; ++i)
        cout << arr1[i] << " ";
    cout << endl;
    for (int i = 1; i <= lb; ++i)
        cout << arr2[i] << " ";
    
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e6+10;
// #define int  long long
// int n,m,fail[N],a[N],b[N],s[N],t[N],bz,cnt,tot;
// map<string,int> mp;
// map<string,int> dc;
// map<string,int> mp_2;
// string s1[N],s2;
// signed main(){
//     while(cin>>s2){
//         if(s2=="$") break;
//         n++;
//         s1[n]=s2;
//     }
//     while(cin>>s2){
//         if(s2=="$") break;
//         m++;
//         if(mp_2[s2]==0){
//             tot++;
//             mp_2[s2]=tot;
//             b[m]=tot;
//         }
//         else b[m]=mp_2[s2];
//         if(m!=1) t[m-1]=b[m]-b[m-1];
//     }
//     for(int i=1;i<=n;i++){
//         if(mp[s1[i]]==0){
//             cnt++;
//             dc[s1[i]]=cnt;
//             a[i]=cnt;
//         }
//         else a[i]=dc[s1[i]];
//         mp[s1[i]]++;
//         mp[s1[i-m+1]]--;
//         if(i!=1) s[i-1]=a[i]-a[i-1];
//     }
//     if(m==1){
//         cout<<1<<endl;
//         exit(0);
//     }
//     fail[0]=0;
//     fail[1]=0;
//     int ind=0;
//     for(int i=1;i<m-1;i++){
//         while(ind&&t[i+1]!=t[ind+1]) ind=fail[ind];
//         if(t[i+1]==t[ind+1]){
//             ind++;
//         }
//         fail[i+1]=ind;
//     }
//     ind=0;
//     for(int i=0;i<n-1;i++){
// 	while(ind&&s[i+1]!=t[ind+1]){
// 	    ind=fail[ind];
// 	}
// 	if(t[ind+1]==s[i+1]){
// 	    ind++;
// 	}
// 	if(ind==m-1){
// 	    bz=i-m+2;
//             break;
// 	}
//     }
//     cout<<bz+1<<endl;
//     for(int i=0;i<n;++i)
//     {
//         cout<<s[i]<<" ";
//     }cout<<endl;
//     for(int i=0;i<m;++i)
//     {
//         cout<<t[i]<<" ";
//     }
//     return 0;
// }
