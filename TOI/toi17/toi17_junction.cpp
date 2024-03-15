/*
Author: kornkin.png
Algor: Binary Search (On Answer) + DFS
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll n, l, r, src;
vector<pll> g[80001];
pll dp[80001];

void dfs(int u, int p, ll &m){
    dp[u] = {0, 0};
    int wleft = 0;
    
    for(auto &[v, w] : g[u]){
        if(v == p) continue;

        dfs(v, u, m);

        dp[u].second += dp[v].second;
        if(dp[v].first + w > m)
            dp[u].second++;
        else wleft += dp[v].first + w;
    }

    if(wleft > m) {
        wleft = 0;
        dp[u].second++;
    }

    dp[u].first = wleft;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        ll u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        r += w;
    }

    for(int i = 0; i <= n; i++){
        if(g[i].size() == 1){
            src = i; break;
        }   
    }

    while(l < r){
        ll m = (l + r) >> 1;
        dfs(src, -1, m);
        if(dp[src].second >= 3) l = m + 1;
        else r = m; 
    }

    cout << l;

    return 0;
}