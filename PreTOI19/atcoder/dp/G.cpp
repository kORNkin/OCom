#include<bits/stdc++.h>
using namespace std;

int n, m, dis[100001], mx;
vector<int> g[100001];
bitset<100001> vis, ind;

void dfs(int u){
    vis[u] = 1;

    int d = 0;
    for(auto v : g[u]){
        if(!vis[v]) dfs(v);
        d = max(d, dis[v] + 1);    
    }
    dis[u] = max(dis[u], d);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        ind[v] = 1;
    }

    for(int i = 1; i <= n; i++) if(!vis[i] && !ind[i]) dfs(i);

    for(int i = 1; i <= n; i++) mx = max(mx, dis[i]);
    cout << mx;

    return 0;
}
