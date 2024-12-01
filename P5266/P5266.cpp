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
map<string, int> box;
void solve()
{
    int N = re();
    while (N--)
    {
        int mode = re();
        if (mode == 1)
        {
            string name;
            cin >> name;
            int grade = re();
            if (box.find(name) == box.end())
            {
                box.insert(pair<string, int>(name, grade));
                cout << "OK" << endl;
            }
            else
            {
                box[name] = grade;
                cout << "OK" << endl;
            }
        }
        else if (mode == 2)
        {
            string name;cin >> name;
            
            if (box.find(name) == box.end())
            {
                cout << "Not found" << endl;
            }
            else
            {
                cout<<box[name]<<endl;
            }
        }
        else if(mode==3)
        {
            string name;cin >> name;
            
            if (box.find(name) == box.end())
            {
                cout << "Not found" << endl;
            }
            else
            {
                box.erase(box.find(name));
                cout<<"Deleted successfully"<<endl;
            }
        }
        else
        {
            cout<<box.size()<<endl;
        }
    }
}
signed main()
{
    solve();
    return 0;
}