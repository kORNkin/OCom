#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct Pooh{
    long long dis,idx,doraemon;
    bool operator < (const Pooh &r)const{
        return dis > r.dis;
    }
};
long long dp[100001][2];
long long n,m,k,t;
vector<pair<long long,long long>> g[100001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m>>k>>t;
    while(m--){
        long long u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    
    for(int i=1;i<=n;i++) dp[i][0] = dp[i][1] = 1e18;
    dp[1][0] = 0;
    priority_queue<Pooh> pq;
    pq.push({0ll,1,0ll});

    while(!pq.empty()){
        long long idx = pq.top().idx, dis = pq.top().dis, use = pq.top().doraemon;
        pq.pop();

        for(auto &e:g[idx]){
            long long d = e.second, j = e.first;
            if(!use && k < d && dp[j][1] > dp[idx][use] + k){
                dp[j][1] = dp[idx][use] + k;
                pq.push({dp[j][1],j,1});
            }
            if(dp[j][use] > dp[idx][use] + d){
                dp[j][use] = dp[idx][use] + d;
                pq.push({dp[j][use],j,use});
            }
        }
    } 
    long long d = min(dp[n][0], dp[n][1]);           
    if(d > t) cout << "No Honey TT";
    else {
        cout << "Happy Winnie the Pooh :3\n";
        cout << d; 
    } 
    return 0;
}