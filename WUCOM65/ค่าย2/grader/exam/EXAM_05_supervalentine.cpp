#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int,int> pii;
int V,E;
vector<pii> g[200001];

void revPrim(){
    int dis=0;

    bool vis[200001]; 
    memset(vis,0,sizeof(vis));

    priority_queue<pii,vector<pii>> pq;
    pq.push({1,1});

    while(!pq.empty()){
        pii node = pq.top();
        pq.pop();
        if(vis[node.s]) continue;
        vis[node.s] = 1;
        dis+=node.f-1;
        for(auto e:g[node.s])
            if(!vis[e.s])
                pq.push({e.f,e.s});  
    }

    cout << dis;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>V>>E;
    while(E--){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({w,v});
        g[v].push_back({w,u});
    }

    revPrim();
    

    return 0;
}