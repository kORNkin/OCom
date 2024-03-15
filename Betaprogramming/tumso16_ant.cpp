#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, q, dp[100001][18], lv[100001], dis[100001];
vector<pair<ll, ll>> g[100001];

void dfs(int u, int p){
    lv[u] = lv[p] + 1;
    dp[u][0] = p;

    for(int i = 1; i < 18; i++)
        dp[u][i] = dp[dp[u][i - 1]][i - 1]; 
    
    for(auto &[v, w] : g[u]){
        if(v == p) continue;
        dis[v] = dis[u] + w;
        dfs(v, u); 
    }
}

int lca(int a, int b){
    if(lv[a] < lv[b]) swap(a, b);

    ll d = lv[a] - lv[b];
    for(int i = 0; i <= log2(d); i++) {
        if((1 << i) & d){
            a = dp[a][i];
        }
    }

    if(a == b) return a;

    for(int i = 17; i >= 0; i--){
        if(dp[a][i] != dp[b][i]){
            a = dp[a][i];
            b = dp[b][i];
        }
    } 

    return dp[a][0];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n;   
    for(int i = 1; i < n; i++){
        int v, w; cin >> v >> w;
        g[i].push_back({v, w});
        g[v].push_back({i, w});
    }

    dfs(1, 1);

    cin >> q;
    while(q--){
        int a, b; cin >> a >> b;
        cout << dis[a] + dis[b] - (dis[lca(a, b)] << 1) << '\n';
    }

    return 0;
}