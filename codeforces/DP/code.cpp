#include <iostream>
using namespace std;
int f[2001][2001];
signed main()
{
    string A, B;
    cin >> A >> B;
    // 边界
    for (int j = 1; j <= B.size(); ++j)
    {
        f[0][j] = j;
    }
    for (int i = 1; i <= A.size(); ++i)
    {
        f[i][0] = i;
    }
    for (int i = 1; i <= A.size(); ++i)
    {
        for (int j = 1; j <= B.size(); ++j)
        {
            if(A[i-1]==B[j-1])
            {
                f[i][j]=f[i-1][j-1];
                continue;
            }
            f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
        }
    }
    cout<<f[A.size()][B.size()];
}