#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
struct PlsTakeThisInExam{
    int idx,prev,k;
    long long dis;
    bool operator < (const PlsTakeThisInExam &r)const{
        return dis > r.dis;
    }
};
int n,m,l,q;
vector<pair<int,int>> g[80001];
bool po[80001];
long long dp[80001][10];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m>>l>>q; 
    while(m--){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
    } int x;
    while(l--){
        cin>>x;
        po[x]=1;
    }

    memset(dp,0x3f3f3f3f,sizeof(dp));
    for(int i=1;i<=n;i++) for(int j=0;j<=q;j++) dp[i][j] = 1e18;
    dp[1][0] = 0;
    priority_queue<PlsTakeThisInExam> pq;
    pq.push({1,0,0,0});
    while(!pq.empty()){
        PlsTakeThisInExam now = pq.top();
        pq.pop();
        if(now.idx == n){
            cout << dis; 
            return 0;
        }
        if(po[now.idx] && now.k < q && now.idx != now.prev) {
            pq.push({now.idx, now.idx, now.k+1, now.dis});
        } 
        for(auto e:g[now.idx]){
            long long dd = e.second/(1<<now.k);
            if(dp[e.first][now.k] > now.dis + dd){
                dp[e.first][now.k] = now.dis + dd;      
                pq.push({e.first, now.prev, now.k, dp[e.first][now.k]});
            }
        }
    }

    return 0;
}