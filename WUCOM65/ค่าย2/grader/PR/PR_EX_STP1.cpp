#include<bits/stdc++.h>
using namespace std;
int n,m,src,tar;
vector<pair<int,int>> g[10001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m>>src>>tar;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    vector<int> dis(n,1e9);
    vector<bool> vis(n,0);
    priority_queue<pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>> pq;
    pq.push({0,src});
    dis[src] = 0;

    while(!pq.empty()){
        int idx = pq.top().second;
        pq.pop();

        if(vis[idx]) continue;
        vis[idx] = 1;
         
         for(auto e:g[idx]){
            if(dis[idx]+e.second < dis[e.first]){
                dis[e.first] = dis[idx]+e.second;
                pq.push({dis[e.first], e.first});
            }
         }
    }
    cout << dis[tar];

    return 0;
}