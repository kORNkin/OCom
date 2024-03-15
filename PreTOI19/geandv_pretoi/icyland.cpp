//LCA + Longest Path On Tree
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int L = ceil(log2(200001)) + 1;
ll n, m, A, B, mxD, t[200001], dis[200001], lv[200001], dp[200001][L];
vector<pair<int ,int>> g[200001];
bitset<200001> vis;
vector<ll> ans; 

void dfs1(int u, int dis){
    vis[u] = 1;
    if(mxD < dis) mxD = dis, A = u;
    for(auto &[v, w] : g[u]){
        if(vis[v]) continue;
        dfs1(v, dis + w);
    }
}

void dfs2(int u, int p){
    vis[u] = 1;
    dp[u][0] = p;
    if(mxD < dis[u]) mxD = dis[u], B = u;
    for(int i = 1; i < L; i++){
        dp[u][i] = dp[dp[u][i - 1]][i - 1];
    }
    
    for(auto &[v, w] : g[u]){
        if(vis[v]) continue;

        dis[v] = dis[u] + w;
        lv[v] = lv[u] + 1;
        dfs2(v, u);
    }
}

int lca(int a, int b){
    if(lv[a] < lv[b]) swap(a, b);

    int d = lv[a] - lv[b]; 
    for(int i = 0; i <= log2(d); i++){
        if((1 << i) & d){
            a = dp[a][i];
        }
    }

    if(a == b) return a;

    for(int i = L - 1; i >= 0; i--){
        if(dp[a][i] != dp[b][i]){
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i < n; i++){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dfs1(1, 0);

    vis.reset(), mxD = 0;
    dfs2(A, A);

    for(int i = 1; i <= n; i++){
        ll a = dis[i];
        ll b = mxD + dis[i] - dis[lca(B, i)] * 2;
        ans.push_back(max(a, b));
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < m; i++) cin >> t[i];
    sort(t, t + m, greater<int>());
    ll sum = 0;
    for(int i = 0; i < m; i++) sum += t[i] * ans[i];
    cout << sum;

    return 0;
}
