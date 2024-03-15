#include<bits/stdc++.h>
using namespace std;
bool vis[5001];
vector<int> g[5001];
int co=0;
int DFS(int i){
    vis[i]=1;
    co++;
    for(auto e:g[i]){
        if(!vis[e]){
            DFS(e);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,m; cin>>n>>m;
    
    while(m--){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(vis,0,sizeof(vis));
    int mx=0,cnt=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            DFS(i);
            mx = max(mx,co);
            cnt++;
            co=0;
        }
    }
    cout << cnt << '\n' << mx;

    return 0;
}