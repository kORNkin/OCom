#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

struct caR{
    int idx,sum,fuel,pass;
    bool operator < (const caR &r)const{
        return sum > r.sum;
    }
};

int n,s,d,f,m;
int cost[101], dis[101][101][2];
vector<pair<int,int>> g[101];
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++) cin>>cost[i];
    cin>>s>>d>>f>>m;

    while(m--){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    for(int i=1;i<=n;i++) for(int j=0;j<=f;j++) dis[i][j][0] = dis[i][j][1] = 1e9;

    priority_queue<caR> pq;
    pq.emplace(caR{s,0,0,1});
    dis[s][0][1]=0;
    while(!pq.empty()){
        int idx = pq.top().idx, sum = pq.top().sum;
        int fuel = pq.top().fuel, pass = pq.top().pass;
        pq.pop();

        if(fuel == f && idx == d){
            cout << sum; return 0;
        }

        if(dis[idx][fuel][pass] < sum) continue;

        if(pass == 1 && dis[idx][f][0] > sum){
            dis[idx][f][0] = sum;
            pq.emplace(caR{idx,sum,f,0});
        }
        if(fuel < f && dis[idx][fuel+1][pass] > cost[idx] + sum){
            dis[idx][fuel+1][pass] = cost[idx] + sum;
            pq.emplace(caR{idx,cost[idx] + sum,fuel+1,pass});
        }   
        for(pair<int,int> &go:g[idx]){
            if(go.second <= fuel && dis[go.first][fuel-go.second][pass] > sum){
                dis[go.first][fuel-go.second][pass] = sum;
                pq.emplace(caR{go.first,sum,fuel-go.second,pass});
            }
        }
    }

    return 0;
}