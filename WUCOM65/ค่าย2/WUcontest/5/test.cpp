#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first 
#define s second
vector<pair<int,int>> g[2001];
int n,m,p,u;
long long dp[2001][2001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>p>>u>>m;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
    }

    priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
    pq.push({0,{0,p}});

    memset(dp,0,sizeof(dp));
    while(!pq.empty()){
        int sumw = pq.top().f;
        int d = pq.top().s.f;
        int idx = pq.top().s.s;
        pq.pop();

        if(dp[idx][d] || d>m) continue;
        dp[idx][d] = sumw;
        for(auto e:g[idx]){
            pq.push({sumw+e.second, {d+1,e.first}});
        }
    }

    int t; cin>>t;
    while(t--){
        long long l; cin>>l;
        
        long long mn=1e18;
        for(int i=1;i<=m;i++){
                if(!dp[u][i]) continue;
                if((i-1)*l > mn) break;
                mn = min(mn,dp[u][i] +  (i-1)* l);
        }
        cout << mn << ' ';
    }

    return 0;
}