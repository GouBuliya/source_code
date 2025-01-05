#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define Max 100010
#define mod 99991

using namespace std;

int fa[2 * Max], d[2 * Max];
struct node
{
    int real, map;
} un[Max];
vector<node> SShash[Max];
int tot, cnt;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int ask(int i, int j, bool k)
{
    if (find(i) == find(j))
        return 1;
    else if (k)
    {
        fa[find(j)] = find(i);
        return 0;
    }
    return 0;
}
int map(int i, int j, bool k)
{
    int x, y, ok = 1;
    int a = i % mod, b = j % mod;
    if (!SShash[a].empty())
    {
        for (int l = 0; l < SShash[a].size(); l++)
            if (i == SShash[a][l].real)
                x = SShash[a][l].map, ok = 0;
        if (ok)
            SShash[a].push_back((node){i, ++tot}), x = tot;
    }
    else
        SShash[a].push_back((node){i, ++tot}), x = tot;
    ok = 1;
    if (!SShash[b].empty())
    {
        for (int l = 0; l < SShash[b].size(); l++)
            if (j == SShash[b][l].real)
                y = SShash[b][l].map, ok = 0;
        if (ok)
            SShash[b].push_back((node){j, ++tot}), y = tot;
    }
    else
        SShash[b].push_back((node){j, ++tot}), y = tot;
    return ask(x, y, k);
}
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int i = 1; i <= 200010; i++)
            fa[i] = i;
        for (int i = 0; i < 100000; i++)
            SShash[i].clear();
        memset(d, 0, sizeof(d));
        memset(un, 0, sizeof(un));
        // 以上每步的初始化不能丢
        cnt = tot = 0;
        int num, now = 1;
        cin >> num;
        for (int i = 1; i <= num; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            if (z)
                map(x, y, 1);
            else
                un[++cnt].real = x, un[cnt].map = y;
        }
        for (int i = 1; i <= cnt; i++)
            if (map(un[i].real, un[i].map, 0))
            {
                now = 0;
                cout << "NO" << endl;
                break;
            }
        if (now)
            cout << "YES" << endl;
    }
    return 0;
}
