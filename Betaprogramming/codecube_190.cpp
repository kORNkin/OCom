#include<bits/stdc++.h>
using namespace std;

int n, m, vis[100001];
vector<int> g[100001];
vector<pair<int, int>> edges;
stack<int> st;
bitset<100001> isl;

void dfs(int u, int p){
    vis[u] = 1;
    st.push(u);
    for(int &v : g[u]){
        if(v == p) continue;
        if(vis[v] == 1){
            while(!st.empty() && st.top() != v) {
                //cout << "u:" << u << " --> "<< st.top() << '\n';
                isl[st.top()] = 1, st.pop();
            }
            isl[v] = 1; st.pop();
        }
        if(!vis[v]) dfs(v, u);
    }
    if(!st.empty()) st.pop();
    vis[u] = 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back({u ,v});
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i, i);
    }

    for(int i = 0; i < m; i++){
        int u, v;
        tie(u, v) = edges[i];
        if(isl[u] && isl[v]) cout << "0 ";
        else cout << n - 1 << ' ';
    }
    
    return 0;
}

/*

*/