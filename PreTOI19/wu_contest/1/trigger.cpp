#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll ind[100001], dis[100001], ans, cnt;
vector<ll> g[100001];

void dfs(int u, int p){
    dis[u] = 1;
    for(auto &v: g[u]){
        if(v == p) continue;
        dfs(v, u);
        dis[u] += dis[v];
    }
    cnt += dis[u];
}

void dfs2(int u, int p, ll mem) {
    if(u == p){
        for(auto &v : g[u]){
            if(v == p) continue;
            dfs2(v, u, mem);
        }  
        return;
    }
    int dp = dis[p], du = dis[u];
    int chd = 0;
    for(auto &v : g[u]){
        if(v == p) continue;
        chd += dis[v];
    }   
    dis[p] = dp - du;   
    dis[u] = dis[p] + chd + 1;
    mem = mem - (dp - dis[p]) + (dis[u] - du);
    ans = max(mem, ans);
    for(auto &v : g[u]){
        if(v == p) continue;
        dfs2(v, u, mem);
    }  
    dis[p] = dp;
    dis[u] = du;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0 ; i < n-1 ; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        ind[u]++;
        ind[v]++;
    }

    dfs(6, 6);

    ans = cnt;
    dfs2(6, 6, cnt);

    cout << ans;

    return 0;
}