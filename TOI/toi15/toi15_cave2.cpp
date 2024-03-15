#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node{
    ll ind, dis, cnt, par;
    bool operator < (const Node &rhs) const{
        return dis > rhs.dis;
    }
};

ll N, P, U, E;
vector<pair<ll, ll>> g[2001];
vector<pair<ll, ll>> ans[2001]; 
bool vis[2001], ch;

void D(){ 
    priority_queue<Node> pq;
    pq.push({P, 0, 0, P});

    while(!pq.empty()){
        Node now = pq.top();
        pq.pop();        
    
        for(auto &[v, w] : g[now.ind]){
            ch = 0;
            for(auto x:ans[v]){
                if(now.dis + w > x.first && (now.ind ^ P ? now.cnt + 1: now.cnt) > x.second){
                    ch = 1; break;
                }
            }

            if(!ch) {
                pq.push({v, now.dis + w, (now.ind ^ P ? now.cnt + 1: now.cnt), now.ind});
                ans[v].push_back({now.dis + w, (now.ind ^ P ? now.cnt + 1: now.cnt)});
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> P >> U >> E;
    for(int i = 0; i < E; i++){
        ll u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    D();

    int l; cin >> l;
    while(l--){
        ll h, mn = 1e18; cin >> h;
        for(auto x:ans[U]){
            mn = min(mn, x.first + x.second * h);
        }
        cout << mn << ' ';
    }

    return 0;
}