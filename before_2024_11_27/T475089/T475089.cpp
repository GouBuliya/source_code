// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// const int maxn=1e5+7;
// struct Node{
// 	int w;
// 	bool op;
// 	int pos;
// 	vector<int>son;
// 	int fa=-1;
// 	int tag;
// }tree[2*maxn];
// int re()
// {
//     int x = 0, t = 1;
//     char ch = getchar();
//     while (ch > '9' || ch < '0')
//     {
//         if (ch == '-')
//             t = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9')
//         x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
//     return x * t;
// }
// bool cmp(Node a,Node b)
// {
// 	return a.w<b.w;
// }
// set <Node,bool(*)(Node,Node)> ans(cmp);
// void dfs(int p)
// {
// 	if(tree[p].son.size()==0)
// 	{
// 		return;
// 	}
// 	for(int i=0;i<tree[p].son.size();++i)
// 	{
// 		if(!tree[tree[p].son[i]].op)
// 		{
// 			tree[tree[p].son[i]].op=1;
// 			ans.insert(tree[tree[p].son[i]]);
// 			dfs(tree[p].son[i]);
// 		}
// 	}
// }
// signed main ()
// {
// 	n=re(),m=re();
// 	for(int i=1;i<n;++i)
// 	{
// 		int pos=re();
// 		tree[pos].pos=pos;
// 		int son =re();
// 		tree[pos].son.push_back(son);
// 		tree[son].fa=pos;
// 	}
// 	for(int i=1;i<=n;++i)
// 		tree[i].w=re();
// 	int temp_max=-1;
// 	for(int i=1;i<=n;++i)
// 	{
// 		tree[i].op=re();
// 		if(tree[i].op)
// 		{
// 			ans.insert(tree[i]);
// 		}
// 	}
// 	printf("%d\n",ans.rbegin().operator*().w);
// 	for(int i=1;i<=m;++i)
// 	{
// 		int mod=re();
// 			if(tree[mod].op)
// 		{
// 			tree[mod].op=0;
// 			ans.erase(tree[i]);
// 		}
// 		else
// 		{
// 			tree[mod].op=1;
// 			ans.insert(tree[mod]);
// 			dfs(mod);
// 		}
// 		printf("%d\n",ans.rbegin().operator*().w);
// 	}

// }
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAXN = 2e5 + 10;
const int LOGN = 18; // log2(MAXN)

int n, m, ttt = 1;
int in[MAXN], out[MAXN], depth[MAXN];
vector<int> adj[MAXN];
int weight[MAXN];
bool state[MAXN];
int segTree[4 * MAXN];

void dfs(int u, int p) {
    in[u] = ttt++;
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
    out[u] = ttt;
}

void buildSegmentTree(int node, int start, int end) {
    if (start == end) {
        segTree[node] = state[start] ? weight[start] : INT_MIN;
    } else {
        int mid = (start + end) / 2;
        buildSegmentTree(2*node, start, mid);
        buildSegmentTree(2*node+1, mid+1, end);
        segTree[node] = max(segTree[2*node], segTree[2*node+1]);
    }
}

void updateSegmentTree(int node, int start, int end, int idx, int val) {
    if (start == end) {
        segTree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid)
            updateSegmentTree(2*node, start, mid, idx, val);
        else
            updateSegmentTree(2*node+1, mid+1, end, idx, val);
        segTree[node] = max(segTree[2*node], segTree[2*node+1]);
    }
}

int querySegmentTree(int node, int start, int end, int l, int r) {
    if (r < start || end < l)
        return INT_MIN;
    if (l <= start && end <= r)
        return segTree[node];
    int mid = (start + end) / 2;
    return max(querySegmentTree(2*node, start, mid, l, r),
               querySegmentTree(2*node+1, mid+1, end, l, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> weight[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> state[i];
    }

    dfs(1, 0); // DFS from root 1
    buildSegmentTree(1, 1, n);

    cout << (state[1] ? weight[1] : INT_MIN) << '\n';
    while (m--) {
        int x;
        cin >> x;
        if (state[x]) {
            state[x] = false;
            updateSegmentTree(1, 1, n, in[x], INT_MIN);
        } else {
            state[x] = true;
            updateSegmentTree(1, 1, n, in[x], weight[x]);
            for (int v : adj[x]) {
                if (depth[v] > depth[x] && !state[v]) {
                    state[v] = true;
                    updateSegmentTree(1, 1, n, in[v], weight[v]);
                }
            }
        }
        cout << max(querySegmentTree(1, 1, n, 1, n), INT_MIN) << '\n';
    }
    return 0;
}