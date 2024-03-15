#include<bits/stdc++.h>
using namespace std;

int n, m;
long long dx[10001], dy[10001];
vector<pair<int, int>> g[10001]; 

void D(long long dis[], int src){
    for(int i = 0; i < n ;i++) dis[i] = 1e18;
    bitset<10001> vis;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dis[src] = 0;
    while(!pq.empty()){
        int ind = pq.top().second, s = pq.top().first;
        pq.pop();

        if(vis[ind]) continue;
        vis[ind] = 1;

        for(auto &[v, w]:g[ind]){
            if(dis[v] > s + w){
                dis[v] = s + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);

    cin >> n >> m;
    int x, y, d;
    cin >> x >> y >> d;
    while(m--){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    D(dx, x);
    D(dy, y);

    int ind, disx, disy = 1e9;
    for(int i = 0; i < n; i++){
        if(disy > dy[i] && dx[i] <= d){
            disy = dy[i];
            disx = dx[i];
            ind = i;
        }
    }

    cout << ind << ' ' << disx << ' ' << disy;

    return 0;
}
