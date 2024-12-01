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
// int idx = 0;
// struct tree_node
// {
//     int data = -2147483647;
//     int left = -1, right = -1;
//     bool emtly()
//     {
//         if (left == -1 && right == -1)
//         {
//             return 1;
//         }
//         else
//             return 0;
//     }
// } node[500000];
// vector<int> inor_arr;
// void insert(int data, int pos)
// {

//     if (data < node[pos].data)
//     {
//         if (node[pos].left == -1)
//         {
//             node[pos].left = pos * 2;
//             node[node[pos].left].data = data;
//         }
//         else
//         {
//             insert(data, pos * 2);
//         }
//     }
//     else
//     {
//         if (node[pos].right == -1)
//         {
//             node[pos].right = pos * 2 + 1;
//             node[node[pos].right].data = data;
//         }
//         else
//         {
//             insert(data, pos * 2 + 1);
//         }
//     }
// }
// void inor(int pos)
// {
//     // if(node[node[pos].left].data==-2147483647)
//     // {
//     //     inor_arr.push_back(node[pos].data);
//     //     return;
//     // }
//     if (node[pos].emtly())
//     {
//         inor_arr.push_back(node[pos].data);
//         return;
//     }
//     if (node[pos].left != -1)
//     {
//         inor(node[pos].left);
//     }
//     inor_arr.push_back(node[pos].data);
//     if (node[pos].right != -1)
//     {
//         inor(node[pos].right);
//     }
// }
// int cheak_1(int num)
// {

//     return upper_bound(inor_arr.begin(), inor_arr.end(), num) - inor_arr.begin() - 1;
// }
// int cheak_2(int pos)
// {
//     return inor_arr[pos];
// }
// int pre(int num)
// {
//     if (inor_arr[0] >= num)
//         return -2147483647;
//     else
//     {
//         return inor_arr[lower_bound(inor_arr.begin(), inor_arr.end(), num) - inor_arr.begin() - 1];
//     }
// }
// int dg(int num)
// {
//     if (inor_arr[inor_arr.size() - 1] <= num)
//     {
//         return 2147483647;
//     }

//     else
//     {
//         return inor_arr[lower_bound(inor_arr.begin(), inor_arr.end(), num) - inor_arr.begin() + 1];
//     }
// }
// signed main()
// {

//     int N;
//     std::cin >> N;
//     for (int i = 0; i < N; ++i)
//     {
//         int mode;
//         int x;
//         std::cin >> mode >> x;
//         if (mode == 5)
//         {
//             insert(x, 1);
//         }
//         else
//         {
//             inor(1);
//             if (mode == 1)
//             {
//                 cout << cheak_1(x) << endl;
//             }
//             if (mode == 2)
//             {
//                 cout << cheak_2(x) << endl;
//             }
//             if (mode == 3)
//             {
//                 cout << pre(x) << endl;
//             }
//             if (mode == 4)
//             {
//                 cout << dg(x) << endl;
//             }
//         }
//     }
//     return 0;
// }
#include <iostream>
#include <algorithm>    
#include <cstdio>
using namespace std;
int a[10010];

int main()
{
    int q, num, number, size = 0;
    cin >> q;
    while (q--)
    {
        cin >> num;
        if (num == 5)
        {
            cin >> number;
            a[++size] = number;
        }
        else
        {
            sort(a + 1, a + size + 1);
            if (num == 1)
            {
                cin >> number;
                cout << lower_bound(a + 1, a + size + 1, number) - a << endl;
            }
            if (num == 2)
            {
                cin >> number;
                cout << a[number] << endl;
            }
            if (num == 3)
            {
                cin >> number;
                int p = lower_bound(a + 1, a + size + 1, number) - a;
                if (p == 1)
                    printf("-2147483647\n");
                else
                    cout << a[p - 1] << endl;
            }
            if (num == 4)
            {
                cin >> number;
                int *p = upper_bound(a + 1, a + size + 1, number);
                if (p == a + size + 1)
                    printf("2147483647\n");
                else
                    cout << *p << endl;
            }
        }
    }
}