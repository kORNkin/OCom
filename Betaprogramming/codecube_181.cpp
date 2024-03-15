#include <bits/stdc++.h>
using namespace std;

int n, m, p, mx, l, r, par[40001], sz[40001];
vector<tuple<int, int, int>> edgs;
vector<pair<int, int>> sd;

int findP(int i, int p){
    return (p == i? i : par[i] = findP(p, par[p]));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m >> p;
    while(m--){
        int u, v, w; cin >> u >> v >> w;
        edgs.emplace_back(u, v, w);
        mx = max(mx, w);
    }

    while(p--){
        int u, v; cin >> u >> v;
        sd.emplace_back(u, v);
    }
    
    r = mx + 1;
    while(l < r){
        int m = (l + r + 1) >> 1;
        for(int i = 1; i <= n; i++) par[i] = i, sz[i] = 0;;

        for(auto [u, v, w] : edgs){
            if(w >= m) continue;
            u = findP(u, par[u]);
            v = findP(v, par[v]);

            if(sz[u] < sz[v]) par[u] = v; 
            else {
                par[v] = u;
                if(sz[u] == sz[v]) sz[u]++;
            }
        }

        bool ch = 0;
        for(auto [u, v] : sd){
            u = findP(u, par[u]);
            v = findP(v, par[v]);
            if(u == v){
                ch = 1;
                break;
            }
        } 
        if(ch) r = m - 1;
        else l = m;
    }
    cout << (l > mx? -1: l);

    return 0;
}