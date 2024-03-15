#include<bits/stdc++.h>
using namespace std;
vector<int> g[1001], articulation_point;
bitset<1001> vis;
int low[1001], tin[1001], cnt;

void dfs(int n, int p){
    int child = 0;
    low[n] = tin[n] = ++cnt;
    vis[n] = 1;
    for(auto &to:g[n]){
        if(to == p) continue;
        if(vis[to])
            low[n] = min(low[n], tin[to]);
        else {
            dfs(to, n);
            low[n] = min(low[n], low[to]);
            if(tin[n] <= low[to] && p != -1)
                articulation_point.push_back(n);
            ++child;
        } 
    }

    if(p == -1 && child > 1) 
        articulation_point.push_back(n);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i, -1);
        }
    }

    cout << "Articulation Points are:\n";
    for(auto &p : articulation_point) cout << p << ' ';

    return 0;
}
/*
8 9
1 2
1 3
2 3
3 4
4 5
5 6
5 7
6 7
6 8
*/