#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> g[100001];
ll n, sz[100001], ans;
bitset<100001> vis;
pair<ll,ll> mx[100001];

void dfs_cnt(int u){
    vis[u] = 1;
    for(auto &v:g[u]){
        if(!vis[v]){
            dfs_cnt(v);
            sz[u] += sz[v];
            if(mx[u].first < sz[v]) {
                mx[u].second = mx[u].first;
                mx[u].first = sz[v];
            }else if(mx[u].second < sz[v]) mx[u].second = sz[v];
        }
    } ++sz[u];
}

void dfs(int u){
    vis[u] = 1;
    for(auto &v:g[u]){
        if(!vis[v]){
            ll tmp;
            tmp = max(n - sz[u], (mx[u].first == sz[v]? mx[u].second: mx[u].first));
            tmp *= mx[v].first;
            ans = max(ans, tmp);
            dfs(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 1; i < n; i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs_cnt(1);

    vis.reset();
    dfs(1);
    
    cout << ans;

    return 0;
}