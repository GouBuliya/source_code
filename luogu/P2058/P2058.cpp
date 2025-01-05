// // /*用map离散化加去自带的二分查找函数，构造对应的前嘴和数组
// // 其中map<int,int>为<时间，乘客的种类数>
// // code:
// // ```
// // int n=re();
// // int prefix_pos=1;
// // for(int j=1;i<=n;++j)
// // {
// // map<int,int>data;
// // int time=re();
// // int k=re();
// // for(int i=1;i<=k;++i)
// //     {
// //         arr[i]=re();
// //     }
// // int it=unique(arr+1,arr+1+k)-arr-1;
// // data[time]=it;
// // prefix[prefix_pos]=prefix[prefix-1]+data[time]=it;
// // prefix_pos++;
// // }
// // for(auto &i:data)
// // {
// //     int pos=data.lowbr_scach(data.begin(),data.end(),i.frist)
// // }
// // ```*/
// #include <bits/stdc++.h>
// #define ll long long
// #define int long long
// #define pn putchar('\n')
// #define mclear(a) memset(a, 0, sizeof a)
// #define fls() fflush(stdout)
// using namespace std;
// int re()
// {
//     int x = 0, t = 1;
//     char ch = getchar();
//     while (ch > '9' || ch < '0')
//     {
//         if (ch == '-')
//             t = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9')
//         x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
//     return x * t;
// }
// map<int, pair<int, vector<int>>> data;
// map<int, int> prefix;
// const int maxn = 1e5 + 7;
// int arr[maxn];
// signed main()
// {
//     int n = re();
//     int prefix_pos = 0;
//     for (int j = 1; j <= n; ++j)
//     {
//         int time = re();
//         int k = re();
//         for (int i = 1; i <= k; ++i)
//             arr[i] = re();
//         int it = unique(arr + 1, arr + 1 + k) - arr - 1; // debug:int it=unique(arr+1,arr+1+k)-arr-1;
//         data[time] = pair<int, vector<int>>(it, vector<int>(arr + 1, arr + 1 + it));
//     }
//     for (auto &i : data)
//     {
//         auto pos = data.lower_bound(i.first - 86400); // 查找24小时内的首个船只
//         if (i.first - 86400 < 0)
//         {
//             vector<int> ans;
//             ans = i.second.second;
//             auto it = data.begin();
//             while (it.operator*().first != i.first)
//             {
//                 ans.insert(ans.end(), it.operator*().second.second.begin(),
//                            it.operator*().second.second.end());
//                 it++;
//             }
//             sort(ans.begin(), ans.end());
//             auto Intans = unique(ans.begin(), ans.end());
//             printf("%lld\n", Intans - ans.begin());
//         }
//     }
//     return 0;
// }
// 第二版：使用队列，当时间超过86400时，退出队列，重新计算，当进入队列时，重新计算
// #include <bits/stdc++.h>
// #define ll long long
// #define pn putchar('\n')
// #define mclear(a) memset(a, 0, sizeof a)
// #define fls() fflush(stdout)
// using namespace std;
// int re()
// {
//     int x = 0, t = 1;
//     char ch = getchar();
//     while (ch > '9' || ch < '0')
//     {
//         if (ch == '-')
//             t = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9')
//         x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
//     return x * t;
// }
// vector<int> ans(1);
// queue<pair<int, int>> data_k_time;
// signed main()
// {
//     int n = re();
//     int time;
//     vector<int>::iterator ans_frist;
//     for (int i = 1; i <= n; ++i)
//     {
//         time = re();
//         int k = re();
//         data_k_time.push(pair<int, int>(time, k));
//         vector<int> data_Map(1);
//         for (int j = 1; j <= k; ++j)
//             data_Map.push_back(re());
//         ans.insert(ans.end(), data_Map.begin(), data_Map.end());
//         if (time - data_k_time.back().second > 86400)
//         {
//             ans_frist = ans.begin() + data_k_time.back().first;
//             data_k_time.pop();
//         }
//         for(auto j=ans_frist;j<=ans.end();j++)
//         printf("%d ",*j);
//     }
//     return 0;
// }
#include <bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
int re()
{
    int x = 0, t = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x * t;
}
map<int, int> data; // 数字->cishu
queue<pair<int,vector<int>>> data_Map;
signed main()
{

    int n = re();
    int ans=0;
    for (int i = 1; i <= n; ++i)
    {
        int time = re();
        int k = re();
        int a;
        if(!data_Map.empty()&&time-data_Map.front().first>86400)
        {
            vector<int> tamp=data_Map.front().second;
            for(auto&i:tamp)
            {
                if(data[i]==1)
                {
                    ans--;
                    data[i]--;
                }
                else
                    data[i]--;
            }
        }
        vector<int> temp;
        for (int j = 1; j <= k; ++j)
        {
            a = re();
            temp.push_back(a);
            if(data[a]==0)
            {
                ans++;
            }
            data[a]++;
        }
        data_Map.push(pair <int,vector<int>>(time,temp));
        printf("%d\n",ans);
    }
    return 0;
}
