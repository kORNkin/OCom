#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first 
#define s second
vector<pair<int,int>> g[2001];
int n,m,p,u;
vector<pair<int,long long>> dp[2001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>p>>u>>m;
    while(m--){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
    }

    priority_queue<pair<long long,pii>, vector<pair<long long,pii>>, greater<pair<long long,pii>>> pq;
    pq.push({0,{0,p}});
    while(!pq.empty()){
        long long sumw = pq.top().f;
        int d = pq.top().s.f;
        int idx = pq.top().s.s;
        pq.pop();
        for(auto &e:g[idx]){
            bool ch=1;
            for(auto &i:dp[e.f]){
                if(d+1 >= i.first && sumw+e.second >= i.second){
                    ch=0; break;
                }
            }
            if(ch){
                dp[e.f].push_back({d+1,sumw+e.second});
                pq.push({sumw+e.second,{d+1,e.first}});
            }
        }
    }

    int t; cin>>t;
    while(t--){
        long long l; cin>>l;
        
        long long mn=1e18;
        for(auto &e:dp[u]){
            mn = min(mn,e.s +  (e.f-1)* l);
        }
        cout << mn << ' ';
    }
    return 0;
}