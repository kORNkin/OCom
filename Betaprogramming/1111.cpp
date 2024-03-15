#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, dis[100002], mx;
vector<pair<int ,int>> g[100002];
bitset<100002> vis;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q;

    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();

        mx = max(mx, dis[u]);
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto &[v, w] : g[u]){
            if(vis[v]) continue;
            dis[v] = dis[u] + w;
            q.push(v);
        }
    }

    cout << mx;

    return 0;
}