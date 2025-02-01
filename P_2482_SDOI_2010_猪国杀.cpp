#include<bits/stdc++.h>
namespace my {
#define ll long long
#define pn std::cout << "\n"
#define mset(a, x) memset(a, x, sizeof a)
#define mcpy(a, b) memcpy(a, b, sizeof a)
#define all(a) a.begin(), a.end()
#define fls() fflush(stdout)
const int INF = (1 << 30);

ll re() {
    ll t;
    std::cin >> t;
    return t;
}

std::vector<std::vector<char>> A;
std::vector<int> B;
std::vector<char> C;
std::vector<int> D;
std::vector<int> E;
std::vector<char> F;
std::vector<bool> G;
std::vector<char> H;
int n, m, cnt;

void mp(int x) {
    if (!m) m++;
    A[x][++B[x]] = H[m];
    m--;
}

void js(int x1, int x2);

void jd(int x1, int x2) {
    if (x1 == 1 && C[x2] == 'Z') {
        B[x2]--;
        if (!B[x2]) js(x1, x2);
        return;
    }
    int j = 1, k = 1;
    while (true) {
        while (A[x2][j] != 'K' && j <= B[x2]) j++;
        if (j > B[x2]) {
            B[x2]--;
            if (!B[x2]) js(x1, x2);
            return;
        }
        A[x2][j] = 'U';
        while (A[x1][k] != 'K' && k <= B[x1]) k++;
        if (k > B[x1]) {
            B[x1]--;
            if (!B[x1]) js(x2, x1);
            return;
        }
        A[x1][k] = 'U';
    }
}

void kil(int x1, int x2) {
    for (int i = 1; i <= B[x2]; ++i) {
        if (A[x2][i] == 'D') {
            A[x2][i] = 'U';
            return;
        }
    }
    B[x2]--;
    if (!B[x2]) js(x1, x2);
}

void js(int x1, int x2) {
    for (int i = 1; i <= B[x2]; ++i) {
        if (A[x2][i] == 'P') {
            B[x2]++;
            A[x2][i] = 'U';
            return;
        }
    }
    D[E[x2]] = D[x2];
    E[D[x2]] = E[x2];
    if (x2 == 1) {
        std::cout << "FP\n";
        for (int i = 1; i <= n; ++i) {
            if (B[i] <= 0) std::cout << "DEAD\n";
            else {
                for (int j = 1; j <= B[i]; ++j) {
                    if (A[i][j] != 'U') std::cout << A[i][j] << " ";
                }
                pn;
            }
        }
        exit(0);
    }
    if (C[x2] == 'F') cnt--;
    if (!cnt) {
        std::cout << "MP\n";
        for (int i = 1; i <= n; ++i) {
            if (B[i] <= 0) std::cout << "DEAD\n";
            else {
                for (int j = 1; j <= B[i]; ++j) {
                    if (A[i][j] != 'U') std::cout << A[i][j] << " ";
                }
                pn;
            }
        }
        exit(0);
    }
    if (C[x2] == 'F') {
        mp(x1);
        mp(x1);
        mp(x1);
    }
    if (C[x2] == 'Z' && C[x1] == 'M') {
        B[x1] = 0;
        G[x1] = false;
    }
}

bool wxkj(int x1, int x2, int x3) {
    int i = x1;
    while (true) {
        if (x3 == 1) {
            if ((F[x2] == C[i]) || (C[i] == 'M' && F[x2] == 'Z') || (C[i] == 'Z' && F[x2] == 'M')) {
                for (int j = 1; j <= B[i]; ++j) {
                    if (A[i][j] == 'J') {
                        A[i][j] = 'U';
                        F[i] = C[i];
                        return !wxkj(i, x1, 0);
                    }
                }
            }
        } else {
            if (((C[i] == 'Z' || C[i] == 'M') && F[x1] == 'F') || (C[i] == 'F' && (F[x1] == 'Z' || F[x1] == 'M'))) {
                for (int j = 1; j <= B[i]; ++j) {
                    if (A[i][j] == 'J') {
                        A[i][j] = 'U';
                        F[i] = C[i];
                        return !wxkj(i, x1, 0);
                    }
                }
            }
        }
        i = D[i];
        if (i == x1) break;
    }
    return false;
}

void nmrq(int x1) {
    for (int i = D[x1]; i != x1; i = D[i]) {
        if (!wxkj(x1, i, 1)) {
            int j;
            for (j = 1; j <= B[i]; ++j) {
                if (A[i][j] == 'K') {
                    A[i][j] = 'U';
                    break;
                }
            }
            if (j > B[i]) {
                B[i]--;
                if (!B[i]) js(x1, i);
                if (i == 1 && F[x1] == 'U') F[x1] = 'L';
            }
        }
    }
}

void wjqf(int x1) {
    for (int i = D[x1]; i != x1; i = D[i]) {
        if (!wxkj(x1, i, 1)) {
            int j;
            for (j = 1; j <= B[i]; ++j) {
                if (A[i][j] == 'D') {
                    A[i][j] = 'U';
                    break;
                }
            }
            if (j > B[i]) {
                B[i]--;
                if (!B[i]) js(x1, i);
                if (i == 1 && F[x1] == 'U') F[x1] = 'L';
            }
        }
    }
}

void hh() {
    if (!cnt) {
        std::cout << "MP\n";
        for (int i = 1; i <= n; ++i) {
            if (B[i] <= 0) std::cout << "DEAD\n";
            else {
                for (int j = 1; j <= B[i]; ++j) {
                    if (A[i][j] != 'U') std::cout << A[i][j] << " ";
                }
                pn;
            }
        }
        exit(0);
    }
    for (int i = 1; i; i = D[i]) {
        mp(i);
        mp(i);
        bool kill = true;
        for (int j = 1; j <= B[i]; ++j) {
            if (!B[i]) break;
            if (A[i][j] == 'U') continue;
            if (A[i][j] == 'P') {
                if (B[i] != 4) {
                    B[i]++;
                    A[i][j] = 'U';
                    continue;
                }
            }
            if (A[i][j] == 'K') {
                if (!kill && !G[i]) continue;
                if (C[i] == 'M' && (F[D[i]] != 'L' && F[D[i]] != 'F')) continue;
                if (C[i] == 'F' && (F[D[i]] != 'M' && F[D[i]] != 'Z')) continue;
                if (C[i] == 'Z' && (F[D[i]] != 'F')) continue;
                A[i][j] = 'U';
                kil(i, D[i]);
                F[i] = C[i];
                kill = false;
                continue;
            }
            if (A[i][j] == 'F') {
                if (C[i] == 'F') {
                    A[i][j] = 'U';
                    jd(i, 1);
                    F[i] = C[i];
                    j = 0;
                    continue;
                }
                for (int k = D[i]; k != i; k = D[k]) {
                    if ((C[i] == 'M' && (F[k] == 'L' || F[k] == 'F')) || (C[i] == 'Z' && F[k] == 'F')) {
                        A[i][j] = 'U';
                        jd(i, k);
                        F[i] = C[i];
                        j = 0;
                        break;
                    }
                }
                continue;
            }
            if (A[i][j] == 'N') {
                A[i][j] = 'U';
                nmrq(i);
                j = 0;
                continue;
            }
            if (A[i][j] == 'W') {
                A[i][j] = 'U';
                wjqf(i);
                j = 0;
                continue;
            }
            if (A[i][j] == 'Z') {
                A[i][j] = 'U';
                G[i] = true;
                j = 0;
                continue;
            }
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> m;
    A.assign(n + 1, std::vector<char>(2005, 'U'));
    B.assign(n + 1, 4);
    C.resize(n + 1);
    D.resize(n + 1);
    E.resize(n + 1);
    F.assign(n + 1, 'U');
    G.assign(n + 1, false);
    H.resize(m + 1);

    for (int i = 1; i <= n; ++i) {
        std::string s;
        std::cin >> s;
        C[i] = s[0];
        if (C[i] == 'F') cnt++;
        for (int j = 1; j <= 4; ++j) {
            std::cin >> s;
            A[i][j] = s[0];
        }
        D[i] = i + 1;
        E[i] = i - 1;
    }
    D[n] = 1;
    E[1] = n;

    for (int i = 1; i <= m; ++i) {
        std::string s;
        std::cin >> s;
        H[m - i + 1] = s[0];
    }

    hh();

    return 0;
}
}

signed main() {
    return my::main();
}