#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 9;
vector<int> G[MAXN];
int n, m, a[MAXN];
void dfs(int now, int x){
	a[now] = x;
	for (int i = 0; i < G[now].size(); i++){
		if (!a[G[now][i]]) dfs(G[now][i], x);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		G[y].push_back(x);
	}
	for (int i = n; i > 0; i--){
		if (!a[i]) dfs(i, i);
	}
	for (int i = 1; i <= n; i++) cout << a[i] << ' ';
	return 0;
}

