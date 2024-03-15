#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,m,s,d;
vector<pair<int,int>> g[20001];
int diss[20001],disd[20001];

void D(int src,int dis[]){
    for(int i=1;i<=n;i++) dis[i]=1e9;
    vector<bool> vis(n+1,0);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,src});
    dis[src] = 0;
    while(!pq.empty()){
        int idx = pq.top().second;
        pq.pop();

        if(vis[idx]) continue;
        vis[idx] = 1;
        for(auto e:g[idx]){
            if(dis[e.first] > dis[idx]+e.second){
                dis[e.first] = dis[idx]+e.second;
                pq.push({dis[e.first],e.first});
            }
        }
    }   
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m>>s>>d;
    while(m--){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    D(s,diss);
    D(d,disd);
    for(int i=1;i<=n;i++){
        cout << diss[i] << ' ' << disd[i] << '\n';
    }

    return 0;
}