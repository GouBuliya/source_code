    #include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int n, m;
vector<int> alice_wins[MAXN], bob_wins[MAXN];
bool visited[MAXN][2];

void dfs(int card, bool is_alice, vector<bool>& result) {
    if (visited[card][is_alice]) return;
    visited[card][is_alice] = true;

    if (is_alice) {
        for (int next_card : alice_wins[card]) {
            result[0] = true; // Alice wins
            dfs(next_card, false, result);
        }
        if (!result[0]) {
            for (int next_card : bob_wins[card]) {
                dfs(next_card, true, result);
            }
        }
    } else {
        for (int next_card : bob_wins[card]) {
            result[1] = true; // Bob wins
            dfs(next_card, true, result);
        }
        if (!result[1]) {
            for (int next_card : alice_wins[card]) {
                dfs(next_card, false, result);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i=1;i<=n;i++){
            alice_wins[i].clear();
            bob_wins[i].clear();
            fill(visited[i], visited[i]+2, false);
        }

        for(int i=0;i<m;i++){
            int x, y;
            char w;
            cin >> x >> w >> y;
            if(w == '>'){
                alice_wins[x].push_back(y);
            }else{
                bob_wins[y].push_back(x);
            }
        }

        vector<string> results(n+1, "PRZEGRANA");
        for(int i=1;i<=n;i++){
            vector<bool> result(2, false); // {alice_wins, bob_wins}
            dfs(i, true, result);
            if(result[0]){
                results[i] = "WYGRANA";
            }else if(!result[1]){
                results[i] = "REMIS";
            }
        }

        string final_result = "PRZEGRANA";
        for(int i=1;i<=n;i++){
            if(results[i] == "WYGRANA"){
                final_result = "WYGRANA";
                break;
            }else if(results[i] == "REMIS" && final_result != "WYGRANA"){
                final_result = "REMIS";
            }
        }
        cout << final_result << "\n";
    }
    return 0;
}



