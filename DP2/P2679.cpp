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
tree_node *BST = NULL;
struct tree_node;
tree_node *head;
// int arr_inor[10000];
vector<int> arr_inor;
struct tree_node
{
    int data;
    tree_node *left = NULL;
    tree_node *right = NULL;
    // int ranking = 0;
    bool empty()
    {
        if (left == NULL && right == NULL)
        {
            return 1; // yes
        }
        return 0;
    }
    void ins(tree_node num)
    {

        // tree_node* BST=tree_node;
        if (empty())
        {
            if (num.data > data)
            {
                *right = num;
                // num.ranking = ranking + 1;
            }
            else
            {
                *left = num;
                // ranking++;
                // num.ranking = ranking + 1;
            }
        }
        else if (num.data > data && right == NULL)
        {
            *right = num;
            // num.ranking = ranking + 1;
        }
        else if (num.data < data && left == NULL)
        {
            *left = num;
            // ranking++;
            // num.ranking = ranking + 1;
        }
        else
        {
            /* code */
            if (num.data > data)
            {
                ins(*right);
            }
            else
            {
                ins(*left);
            }
        }
    }
    // int find(int x, tree_node *h)
    // {
    //     if (h->data == x)
    //     {
    //         return h->ranking;
    //     }

    //     else if (h->data > x)
    //     {
    //         /* code */
    //         if (h->left != NULL)
    //             return find(x, h->left);
    //         else
    //             return h->ranking+1;
    //     }
    //     else if (h->data < x)
    //     {
    //         if (h->right != NULL)
    //             return find(x, h->right);
    //         else
    //             return h->ranking;
    //     }
    // }

    void inor(vector<int>arr, tree_node *node_tmp)
    {
        // if(node_tmp->empty())
        // {
        //     arr_inor.push_back(node_tmp->data);
        //     return;
        // }
        // for(int i=0;i<3;++i)
        // {
        //     if(!i)
        //     {
        //         if(node_tmp->left!=NULL)inor(arr,node_tmp->left);
        //     }
        //     else if(i==1)
        //     {
        //         if()
        //     }

        // }
        if (node_tmp->empty())
        {
            arr_inor.push_back(node_tmp->data);
            return;
        }
        if (node_tmp->left != NULL)
        {
            inor(arr, node_tmp->left);
        }
        arr_inor.push_back(node_tmp->data);
        if (node_tmp->right != NULL)
        {
            inor(arr, node_tmp->right);
        }
        return;
    }
    int ranking(int x)
    {
        int l = 0, r = arr_inor.size(), mid, l_mid;
        while (l < r)
        {
            /* code */
            mid = (l + r) / 2;
            if (x >= arr_inor[mid - 1] || x <= arr_inor[mid + 1])
            {
                if (x <= arr_inor[mid])
                    return mid + 1;
                else
                    return mid;
            }
            if (arr_inor[mid] < x)
            {

                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    int look_up(int x)
    {
        return arr_inor[x - 1];
    }
    int pre(int x)
    {
        if (x - 2 >= 0)
            return arr_inor[x - 2];
        return -2147483647;
    }
    int rg(int x)
    {
        if(x<=arr_inor.size()-1)
            return arr_inor[x];
        return 2147483647;
    }

} node[1000000];

string str;
signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
#endif
    int N;
    cin>>N;
    *head=node[0];
    
    
    return 0;
}