#include<bits/stdc++.h>
using namespace std;
const int N = 500001;
int n, k, ans = 1e9, ans_cnt; 
int tin[N], low[N], sz[N], t;
vector<int> g[N];

void dfs(int u, int par = -1){
    tin[u] = low[u] = ++t;
    for(auto &v:g[u]){
        if(par == v) continue;
        if(!tin[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] ^ low[k]) sz[u] += sz[v] + 1;
            if(par != -1 && low[v] >= tin[u]) {
                if(ans_cnt < sz[u]){
                    ans = u, ans_cnt = sz[u];
                }else if(ans_cnt == sz[u]) ans = min(ans, u);
            }
        }else low[u] = min(low[u], tin[v]);
    } 
}

int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    if(k ^ 1) ans = 1;
    else ans = 2;
    for(int i = 1; i <= n; i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(k);
    cout << ans << '\n' << ans_cnt;

    return 0;
}