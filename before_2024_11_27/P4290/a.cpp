#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pp1 cout << 1 << endl;
int re()
{
    int t;
    cin >> t;
    return t;
}
const int maxn = 2e3 + 10;
int T[256];
bool R[5][5][5];
int A[maxn];
bool f[maxn][maxn][5];
signed main()
{

    int W[4];
    for (int i = 0; i < 4; ++i)
        cin >> W[i];
    T['W'] = 1;
    T['I'] = 2;
    T['N'] = 3;
    T['G'] = 4;
    string ss = "WING";
    for (int i = 0; i < 4; ++i){
        for (int j = 1; j <= W[i]; ++j)
        {
            string s;
           
            cin >> s; 
            int a = T[s[0]];
            int b = T[s[1]];
            int c = i+1;
            R[a][b][c] = true;
        }}
    string s;cin >> s;
    int n = s.length();
    
    for (int i = 0; i <n; ++i)
    {
        A[i + 1] = T[s[i]];
        // f[i+1][i+1][T[s[i]]]=true;
    }
    for (int len = 1; len <= n; ++len)
    {
        for (int l = 1; l + len - 1 <= n; ++l)
        {
            int r = l + len - 1;
            if (len == 1)
            {
                f[l][r][A[l]] = 1;
                continue;
            }
            for (int k = l; k < r; ++k)
            {
                for (int a = 1; a <= 4; ++a)
                    for (int b = 1; b <= 4; ++b)
                        for (int c = 1; c <= 4; ++c)
                            if (f[l][k][a] && f[k + 1][r][b] && R[a][b][c])
                                f[l][r][c] = 1;
            }
            // cout<<"l:"<<l<<" r:"<<r<<"  "<<f[l][l][1]<<f[l][l][2]<<f[l][l][3]<<f[l][l][4]<<endl;
        }
    }
    string ans;
    if (f[1][n][1])
        ans += 'W';
    if (f[1][n][2])
        ans += 'I';
    if (f[1][n][3])
        ans += 'N';
    if (f[1][n][4])
        ans += 'G';
    if (ans.empty())
    {
        cout << "The name is wrong!" << endl;
    }
    else
        cout << ans << endl;
    
}
