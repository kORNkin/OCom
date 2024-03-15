#include<bits/stdc++.h>
using namespace std;

int n,m,ans,dis[100001];
vector<pair<int,int>> g[100001];
bool vis[100001];

void dfs(int i,int sum){
    if(dis[i]) return;
    dis[i] = sum;
    for(auto e:g[i]){
        if(dis[e.first]) continue;
        dfs(e.first,sum^e.second);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i=0; i<n-1; i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        
    } dfs(1,0);
    while(m--){
        int u,v; cin>>u>>v;
        cout << (dis[u]^dis[v]) << '\n';
    }

    return 0;
}