#include<bits/stdc++.h>
using namespace std;
int n,m,src,tar;
vector<pair<int,int>> g[10001];

void finds(int i,int par[]){
    if(par[i]==i) {
       cout << i << ' '; return;
    }
    finds(par[i],par);
    cout << i << ' ';
}

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
    int par[n];
    for(int i=0;i<n;i++) par[i]=i;
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
                par[e.first] = idx; 
                pq.push({dis[e.first], e.first});
            }
         }
    }

    finds(tar,par);
    cout << '\n' << dis[tar];

    return 0;
}
/*
6
5
1 2
1 4 5
1 3 2
3 4 1
4 2 5
0 5 5
*/