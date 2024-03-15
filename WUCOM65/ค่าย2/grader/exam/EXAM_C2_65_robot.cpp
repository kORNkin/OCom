#include<bits/stdc++.h>
using namespace std;

int g[1001][1001];

struct node{
    int x, y, p, hp;

    bool operator < (const node &r)const{
        return p < r.p;
    }
};

int dx[] = {1, 0, 1};
int dy[] = {0, 1, 1};

void solve(){
    int n, m, k; cin >> n >> m >> k;
    priority_queue<node> pq;
    pq.push({0, 0, 0, k});

    while(!pq.empty()){
        node now = pq.top();
        pq.pop();

        if(now.x == n - 1 && now.y == m - 1){

        }
        
        for(int i = 0; i < 3; i++){
            int x = now.x + dx[i], y = now.y + dy[i];
            if(now.hp - g[x][y] >= 0){
                
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}