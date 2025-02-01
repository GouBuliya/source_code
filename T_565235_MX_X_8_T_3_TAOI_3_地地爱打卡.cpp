#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 2e5 + 10;

void bfs(int n, vector<vector<int>>& adj, int start, vector<int>& dist) {
    queue<int> q;
    memset(dist, -1, sizeof(int) * (n + 1));
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < q; ++i) {
        int s, t, x;
        cin >> s >> t >> x;
        if (s == t) {
            if (x == 0) {
                cout << "tribool" << endl;
            }
            else {
                cout << "expand" << endl;
            }
            continue;
        }

        vector<int> dist_t(n + 1, -1);
        bfs(n, adj, t, dist_t);

        if (dist_t[s] == -1) {
            cout << "expand" << endl;
            continue;
        }

        bool found = false;

        // Check if the direct path from s to t is even and equals x 
        if (dist_t[s] % 2 == 0 && dist_t[s] == x) {
            found = true;
        }
        else {
            // Check all possible u where s->u->t forms a valid path 
            for (int u = 1; u <= n; ++u) {
                if (dist_t[u] != -1) {
                    vector<int> dist_s_u(n + 1, -1);
                    bfs(n, adj, s, dist_s_u);
                    int a = dist_s_u[u];
                    int b = dist_t[u];
                    if (a != -1 && b != -1 && (a + b) % 2 == 1 && (a ^ b) == x) {
                        found = true;
                        break;
                    }
                }
            }
        }

        if (found) {
            cout << "tribool" << endl;
        }
        else {
            cout << "expand" << endl;
        }
    }

    return 0;
}