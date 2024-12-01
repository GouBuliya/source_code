#include <bits/stdc++.h>
#define ll long long
#define INF = 0x7fffffff
const int POS_N = 10001;
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
struct Node
{
    /* data */
    int mode;
    string str;
    int pos;
    int adda = 0;
    int addb = 0;
    int addc = 0;
    int addd = 0;
    int adde = 0;

} node[1001];
int find(string str, int N)
{
    for (int i = 1; i <= N; ++i)
    {
        if (node[i].str == str&&node[i].mode)

        {
            // cout<<"find:"<<"node"<<i<<":"<<node[i].str<<endl;
            return i;
        }
    }
    return 0;
}
set<string> server;

int Long(int x)
{
    int Long = 0;
    if(!x)
    return 1;
    while (x)
    {
        x /= 10;
        Long++;
    }
    return Long;
}
bool cheak(int n)
{
    string add;
    cin >> add;
    node[n].pos = n;
    if (add == "Server")
    {
        node[n].mode = 1;
    }
    else
    {
        node[n].mode = 0;
    }
    cin >> add;
    node[n].str = add;

    int modle = 1;
    if (add.size() > 25)
        return 0;
    int dian = 0, hao = 0;
    for (int i = 0; i < add.size(); ++i)
    {
        if (add[i] == '.')
            dian++;
        if (add[i] == ':')
            hao++;
    }
    if (dian != 3 || hao != 1)
        return 0;

    for (int i = 0; i < add.size(); ++i)
    {
        if (modle == 1)
        {
            if (add[i] == '.')
            {
                modle++;
                continue;
            }
            else if (add[i] >= '0' && add[i] <= '9')
            {

                node[n].adda = node[n].adda * 10 + (add[i] - '0');
            }
            else
                return 0;
        }
        else if (modle == 2)
        {
            if (add[i] == '.')
            {
                modle++;
                continue;
            }
            else if (add[i] >= '0' && add[i] <= '9')
            {
                node[n].addb = node[n].addb * 10 + (add[i] - '0');
            }
            else
                return 0;
        }
        else if (modle == 3)
        {
            if (add[i] == '.')
            {
                modle++;
                continue;
            }
            else if (add[i] >= '0' && add[i] <= '9')
            {
                node[n].addc = node[n].addc * 10 + (add[i] - '0');
            }
            else
                return 0;
        }
        else if (modle == 4)
        {
            if (add[i] == ':')
            {
                modle++;
                continue;
            }
            else if (add[i] >= '0' && add[i] <= '9')
            {
                node[n].addd = node[n].addd * 10 + (add[i] - '0');
            }
            else
                return 0;
        }
        else if (modle == 5)
        {
            if (add[i] == '\n'||add[i]=='\r')
            {
                modle++;
                continue;
            }
            else if (add[i] >= '0' && add[i] <= '9')
            {
                node[n].adde = node[n].adde * 10 + (add[i] - '0');
            }
            else
                return 0;
        }
    }
    if (node[n].adda > 255 || node[n].addb > 255 || node[n].addc > 255 || node[n].addd > 255 || node[n].adde > 65535)
        return 0;

    if ((Long(node[n].adda) + Long(node[n].addb) + Long(node[n].addc) + Long(node[n].addd) + Long(node[n].adde) + 4) != add.size())
    {
        // cout<<add<<endl;
        // cout<<add.size()<<endl;
        // cout<<Long(node[n].adda) <<endl<< Long(node[n].addb) <<endl<< Long(node[n].addc) <<endl<<Long(node[n].addd) <<endl<< Long(node[n].adde) <<endl<< 4<<endl;
        return 0;
    }
    return 1;
}
int server_n=0;
void solve(int N)
{
    if (cheak(N))
    {
        if (node[N].mode)
        {
            if (server.find(node[N].str) != server.end())
            {
                printf("FAIL\n");
                // server_n++;

            }
            else
            {
                printf("OK\n");
                // server_n++;
                server.insert(node[N].str);
            }
        }
        else
        {

            int tmp = find(node[N].str, N);
            if (tmp)
                printf("%d\n", tmp);
            else
            {
                printf("FAIL\n");
            }
        }
    }
    else
    {
        printf("ERR\n");
    }
}
signed main()
{
    // freopen("in.txt","w",stdout);
    int N = re();
    for (int i = 1; i <= N; ++i)
    {
        solve(i);
    }
    fclose(stdout);
    return 0;
}