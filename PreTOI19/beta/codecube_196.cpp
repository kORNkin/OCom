#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
#define pll pair<ll,ll>
const ll N = 1e18;
struct G{
    ll n,w;
};
int n,m;
int a,b,c,d;
vector<G> g[100001];

bool Nonononono[100001];

void solve(int src,vector<ll> &dis){
    vector<bool> vis(n+1,0);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0,src});
    dis[src] = 0;
    while(!pq.empty()){
        ll v = pq.top().s;
        pq.pop();

        if(vis[v]) continue;
        vis[v] = 1;
        
        for(auto node:g[v]){
            if(dis[v]+node.w < dis[node.n] && !Nonononono[node.n]){
                dis[node.n] = dis[v]+node.w;
                pq.push({dis[node.n],node.n});
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        ll u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    cin>>a>>b>>c>>d;

    vector<ll> disa(n+1,N), disb(n+1,N), disc(n+1,N);
    solve(a,disa); solve(b,disb);
    for(int i=1;i<=n;i++) if(disa[i]+disb[i] == disa[b]) Nonononono[i]=1;
    solve(c,disc);
    if(disc[d] < 1e18) cout << disc[d];
    else cout << "-1";

    return 0;
}