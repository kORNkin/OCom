#include<bits/stdc++.h>
using namespace std;

vector<int> g[1001];
int tin[1001], low[1001], t;
bitset<1001> vis, is_articulation_p;

void dfs(int i,int par = -1){
    tin[i] = low[i] = t++;
    vis[i] = 1;
    int chd = 0;
    for(auto v:g[i]){
        if(v == par) continue;
        if(!vis[v]){
            dfs(v,i);
            low[i] = min(low[i],low[v]);
            if(par != -1 && low[v] >= tin[i]){
                is_articulation_p[i] = 1;
            }
            ++chd;
        }else low[i] = min(low[i], tin[v]);
    }

    if(par == -1 && chd > 1) is_articulation_p[i] = 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin>> n >> m;
    while(m--){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0; i<n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    return 0;
}