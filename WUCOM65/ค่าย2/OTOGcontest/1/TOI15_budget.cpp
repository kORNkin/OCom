#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
struct Roof{
    int v,dis;
};
int V,E;
vector<Roof> g[3001];
vector<pair<int,int>> cost;
vector<int> ans;

void Prim(){
    priority_queue<pii , vector<pii>, greater<pii>> pq;
    vector<bool> vis(V,0);

    pq.push({0,0});
    while(!pq.empty()){
        pii node = pq.top();
        pq.pop();

        if(!vis[node.s] && node.f)
            ans.push_back({node.f});
        vis[node.s] = 1;
        for(auto e:g[node.s]){
            if(!vis[e.v]){
                pq.push({e.dis,e.v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>V>>E;
    for(int i=0;i<E;i++){
        int u,v,dis,r;
        cin>>u>>v>>dis>>r;
        if(r) dis=0;
        g[u].push_back({v,dis});
        g[v].push_back({u,dis});
    }
    int q; cin>>q;
    while(q--){
        int dis,price;
        cin>>dis>>price;
        cost.push_back({dis,price});
    }

    Prim();

    sort(cost.begin(), cost.end(), [&](pii a, pii b){
        if(a.s==b.s) return a.f > b.f;
        return a.s < b.s;
    });

    int sum=0;
    for(auto dis:ans){
        for(auto cst:cost){
            if(dis <= cst.f){
                sum+=cst.s;
                break;
            }
        }
    } cout << sum ;

    return 0;
}