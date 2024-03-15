#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct E{
    ll u, v, w, i;
    bool operator < (E &r){
        return w > r.w;
    }
};
ll n, m, par[100001], sz[100001];
vector<E> edges;
bitset<100001> vis;

int findP(int i, int p){
    return (i == p ? i : par[i] = findP(p, par[p]));
}

void solve(){
    for(int i = 1; i <= n; i++) par[i] = i;

    sort(edges.begin(), edges.end());

    ll dis = 0, cnt = 0;
    for(auto [u, v, w, i] : edges){
        u = findP(u, par[u]);
        v = findP(v, par[v]);
        if(u == v) continue;    
        vis[i] = 1;
        dis += w;
        cnt++;

        if(sz[u] < sz[v]) par[u] = v;
        else {
            par[v] = u;
            if(sz[u] == sz[v]) sz[u]++;
        }
    }
    
    for(int i = 0; i < edges.size(); i++){
        if(!vis[edges[i].i]){
            dis += edges[i].w;
            vis[edges[i].i] = 1;
            cnt++;
            break;
        }
    }

    if(cnt != n) {
        cout << -1; return;
    }

    int t; cin >> t;
    cout << dis << '\n';
    if(t == 2) {
        for(int i = 1; i <= m; i++){
            if(vis[i]) cout << i << ' ';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        ll u, v, w; cin >> u >> v >> w;
        edges.push_back({u, v, w, i});
    }

    solve();

    return 0;
}
