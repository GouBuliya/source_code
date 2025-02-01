#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 3005;
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<ll, ll>> cities(n);
        for(int i=0; i<n; ++i){
            cin >> cities[i].first >> cities[i].second;
        }
        
        // Precompute distances
        vector<vector<ll>> dist(n, vector<ll>(n));
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(i != j){
                    dist[i][j] = max(cities[i].first + cities[j].second, cities[j].first + cities[i].second);
                }
            }
        }
        
        // dp[mask][u]: min cost to visit subset 'mask' ending at city 'u'
        vector<vector<ll>> dp((1<<n), vector<ll>(n, INF));
        for(int i=0; i<n; ++i){
            dp[(1<<i)][i] = 0;
        }
        
        // Priority queue for Dijkstra's-like search
        priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;
        for(int i=0; i<n; ++i){
            pq.push({0, {1<<i, i}});
        }
        
        while(!pq.empty()){
            auto [cost, curr] = pq.top();
            pq.pop();
            int mask = curr.first, u = curr.second;
            
            if(dp[mask][u] < cost) continue;
            
            for(int v=0; v<n; ++v){
                if(!(mask & (1<<v))){
                    int new_mask = mask | (1<<v);
                    ll new_cost = cost + dist[u][v];
                    
                    if(new_cost < dp[new_mask][v]){
                        dp[new_mask][v] = new_cost;
                        pq.push({new_cost, {new_mask, v}});
                    }
                }
            }
        }
        
        // Calculate results for k from 2 to n
        vector<ll> res(n-1, INF);
        for(int mask=0; mask<(1<<n); ++mask){
            int cnt = __builtin_popcount(mask);
            if(cnt >= 2 && cnt <= n){
                for(int u=0; u<n; ++u){
                    if(mask & (1<<u)){
                        res[cnt-2] = min(res[cnt-2], dp[mask][u]);
                    }
                }
            }
        }
        
        for(int i=0; i<n-1; ++i){
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}



