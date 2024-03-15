#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);

    cin>>n>>m;
    vector<pair<int,int>> g[n+1];
    while(m--){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    int k; cin>>k;
    while(k--){
        int v,w; cin>>v>>w;
        g[n].push_back({v,w});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
    pq.push({0,n});
    vector<int> dis(n+1,1e9);
    vector<bool> vis(n+1,0);
    dis[n] = 0;

    while(!pq.empty()){
        int idx = pq.top().second;
        pq.pop();

        if(vis[idx]) continue;
        vis[idx] = 1;

        for(auto e:g[idx]){
            if(dis[idx]+e.second < dis[e.first]){
                dis[e.first] = dis[idx]+e.second;
                pq.push({dis[e.first],e.first});
            }
        }
    } cout << dis[0];

    return 0;
}