#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct E{
    ll idx, dis, ti;
    bool operator < (const E &r) const{
        return dis > r.dis;
    }
};

ll n, m, t, x, y, dis[10001][9];
vector<pair<ll ,ll>> g[10001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(dis, 127, sizeof(dis));

    cin >> n >> m >> t >> x >> y;
    while(m--){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    priority_queue<E> pq;
    dis[x][0] = 0;
    pq.push({x, 0, 0});

    while(!pq.empty()){
        E now = pq.top();
        pq.pop();

        now.ti = (now.ti + 1) % t;

        if(now.ti == 0 && now.idx == y){
            cout << now.dis;
            return 0;
        }

        for(auto &[v, w] : g[now.idx]){
            if(dis[v][now.ti] > w + now.dis){
                dis[v][now.ti] = w + now.dis;
                pq.push({v, dis[v][now.ti], now.ti});
            }
        }
    }

    cout << -1;

    return 0;
}