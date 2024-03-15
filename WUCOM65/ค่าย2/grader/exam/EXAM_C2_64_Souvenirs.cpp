#include<bits/stdc++.h>
using namespace std;
int n,m,src,tar,k;
vector<pair<int,int>> g[1001];
void dijkstra(){
    vector<int> dis(n+1,1e9);
    vector<bool> vis(n+1,0);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,k});
    dis[k] = 0;
    while(!pq.empty()){
        int idx = pq.top().second;
        pq.pop();

        if(vis[idx]) continue;
        vis[idx]=1;
        for(auto e:g[idx]){
            int w=e.second, v=e.first;
            if(dis[idx]+w < dis[v]){
                dis[v] = dis[idx]+w;
                pq.push({dis[v],v});
            }
        }
    }
    cout << dis[src]+dis[tar];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m>>src>>tar>>k;
    while(m--){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    dijkstra();

    return 0;
}