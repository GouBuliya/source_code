#include <iostream>
#include <vector>
using namespace std; 
const int mod = 998244353; 
const int maxn = 5e5 + 5; 
int n, k; 
int a[16]; 
int c[maxn]; 
vector<int> G[maxn]; 
int pathColor[16]; 
int preProd[16]; 
// 计算a数组的前缀乘积
void precompute() {
    preProd[0]=1; 
    for (int i = 1; i <= k; i++) {
        preProd[i]=1LL * preProd[i - 1]*a[i]% mod; 
    }
}
// 深度优先搜索计算子树大小和子树内权值和
vector<int> dfs(int u, int fa) {
    vector<int> subTreeSum(2, 0); 
    pathColor[c[u]]++; 
    int size_u = 1; 
    int sum_u = a[c[u]]; 
    for (auto v:G[u]) {
        if (v!= fa) {
            vector<int> subTreeV = dfs(v, u); 
            int temp = preProd[k]; 
            for (int i = 1; i <= k; i++) {
                if (pathColor[i]) {
                    temp = 1LL * temp*preProd[i - 1]% mod; 
                }
            }
            sum_u=(sum_u + 1LL * temp*(subTreeV[1]+1LL * subTreeV[0]*a[c[u]]% mod)% mod)% mod; 
            size_u += subTreeV[0]; 
        }
    }
    pathColor[c[u]]--; 
    subTreeSum[0]=size_u; 
    subTreeSum[1]=sum_u; 
    return subTreeSum; 
}
int main() {
    cin >> n >> k; 
    for (int i = 1; i <= k; i++) {
        cin >> a[i]; 
    }
    precompute(); 
    for (int i = 1; i <= n; i++) {
        cin >> c[i]; 
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v; 
        cin >> u >> v; 
        G[u].push_back(v); 
        G[v].push_back(u); 
    }
    vector<int> ans; 
    for (int i = 1; i <= n; i++) {
        vector<int> res = dfs(i, -1); 
        ans.push_back(res[1]); 
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i]; 
        if (i!= n - 1) {
            cout << " "; 
        }
    }
    cout << endl; 
    return 0; 
}