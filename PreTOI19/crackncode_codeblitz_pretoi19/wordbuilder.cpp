#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k;
string a, b;
vector<ll> g[200001];
ll dis[200001];
bitset<200001> vis;
vector<ll> alp[26];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    cin >> a;
    while(m--){ 
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> b;

    for(int i = 1; i <= n; i++) dis[i] = 1e9;
    priority_queue<pair<ll, ll> , vector<pair<ll, ll>>, greater<pair<ll ,ll>>> pq;
    pq.push({0, 1});
    dis[1] = 0;

    while(!pq.empty()){
        ll idx = pq.top().second, d = pq.top().first;    
        pq.pop();

        if(vis[idx]) continue;
        vis[idx] = 1;
        for(auto &v : g[idx]){
            if(!vis[v] && dis[v] > d + 1){
                dis[v] = d + 1;
                pq.push({dis[v], v});
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        alp[a[i - 1] - 'A'].push_back(dis[i]);
    }
    for(int i = 0; i < 26; i++) sort(alp[i].begin(), alp[i].end(), greater<int>());
    long long ans = 0;
    for(int i = 0; i < k; i++){
        if(alp[b[i] - 'A'].empty()){
            cout << -1;
            return 0;
        }
        ans += alp[b[i] - 'A'].back();
        alp[b[i] - 'A'].pop_back();
    }
    cout << ans * 2;

    return 0;
}