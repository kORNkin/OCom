#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct tree{
    ll idx, dis, k;
    bool operator < (const tree &r)const{
        return dis > r.dis;
    }
};

ll n, m, k, dp[100001][6];
vector<pair<ll, ll>> g[100001];
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m >> k;
    while(m--){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    for(int i = 1; i <= n; i++) for(int j = 0; j <= k; j++) dp[i][j] = 1e18; 
    priority_queue<tree> pq;
    dp[1][0] = 0;
    pq.push({1, 0, 0});
    while(!pq.empty()){
        tree now = pq.top();
        pq.pop();

        if(now.idx == n){
            cout << now.dis;
            return 0;
        }

        for(auto &[v, w] : g[now.idx]){
            if(w <= -100){
                if(now.k == k || dp[v][now.k + 1] <= now.dis) continue;
                dp[v][now.k + 1] = now.dis;
                pq.push({v, now.dis, now.k + 1});
            } 
            else if(w < 0) {
                if(dp[v][now.k] <= now.dis) continue;
                dp[v][now.k] = now.dis;
                pq.push({v, now.dis, now.k});
            }
            else if(dp[v][now.k] > now.dis + w){
                dp[v][now.k] = now.dis + w;
                pq.push({v, now.dis + w, now.k});
            }
        }
    }
    cout << -1;

    
    return 0;
}