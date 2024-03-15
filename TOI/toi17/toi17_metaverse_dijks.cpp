#include<bits/stdc++.h>
using namespace std;
struct Node{
    int x, y;
};
struct PQ{
    int x, y, dis, idx, p;
    bool operator < (const PQ &r)const{
        if(dis == r.dis) return p < r.p;
        return dis > r.dis;
    }
};

int n, m, k, p, dp[20002][18], dis[20002];
bool vis[20002][18];
vector<Node> g, ge;
 
int D(int a, int b, int x, int y){ return abs(a-x) + abs(b-y); }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    priority_queue<PQ> pq;
    
    cin >> n >> m >> k >> p;
    dis[k] = D(1, 1, n, m);
    for(int i = 0; i < k; i++){
        int xs, ys, xe, ye;
        cin >> xs >> ys >> xe >> ye;
        g.push_back({xs,ys});
        ge.push_back({xe,ye});
        dis[i] = D(xe, ye, n, m);
    }
    for(int i = 0; i <= k + 1; i++) for(int j = 0; j <= p ; j++) dp[i][j] = 1e9;
    pq.push({1, 1, 0, k, p});
    dp[k][p] = 0;

    int ans = 1e9, ansp;

    while(!pq.empty()){
        PQ now = pq.top();
        pq.pop();

        if(now.x == n && now.y == m){
            cout << now.dis << ' ' << p - now.p;
            return 0;
        }

        if(vis[now.idx][now.p]) continue;
        pq.push({n, m, now.dis + dis[now.idx], k + 1, now.p});
        vis[now.idx][now.p] = 1;

        if(now.p){
            for(int i = 0; i < k; i++){
                if(i == now.idx) continue;
                int d = D(now.x, now.y, g[i].x, g[i].y);
                if(dp[i][now.p] > now.dis + d){
                    dp[i][now.p] = now.dis + d;
                    pq.push({ge[i].x, ge[i].y, dp[i][now.p], i, now.p - 1});
                }
            }
        }           
    }


    return 0;
}