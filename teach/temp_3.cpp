#include <bits/stdc++.h>
#define MaxNumber 25
using namespace std;
int HorseX[9] = {0, 1, 2, 1, 2, -1, -2, -1, -2};
int HorseY[9] = {0, 2, 1, -2, -1, 2, 1, -2, -1};
bool Tag[MaxNumber][MaxNumber];
long long DP[MaxNumber][MaxNumber];
int Bx, By, Hx, Hy;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> Bx >> By >> Hx >> Hy;
    for (int i = 0; i < 9; i++)
    {
        int Dx = Hx + HorseX[i];
        int Dy = Hy + HorseY[i];
        if (Dx < 0 || Dy < 0 || Dx > Bx || Dy > By)
            continue;
        Tag[Dx][Dy] = 1;
    }
    //	for(int i=0;i<=Bx;i++){
    //		for(int j=0;j<=Bx;j++){
    //			cout<<Tag[i][j]<<' ';
    //		}
    //		cout<<'\n';
    //	}
    for (int i = 0; i <= Bx; i++)
        if (!Tag[i][0])
            DP[i][0] = 1;
    for (int i = 0; i <= By; i++)
        if (!Tag[0][i])
            DP[0][i] = 1;
    for (int i = 1; i <= Bx; i++)
        for (int j = 1; j <= By; j++)
            if (!Tag[i][j])
                DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
    cout << DP[Bx][By];
    return 0;
}