#include <bits/stdc++.h>
using namespace std;
struct P{
    int x, y, cnt, cur; //cur: 0 -> E, 1 -> N, 2 -> S
    bool operator < (const P &r) const{
        return cnt > r.cnt;
    }
};

int dx[] = {0, -1, 1};
int dy[] = {1, 0, 0};

int n, m, s;
string g[1000001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m >> s;
    for(int i = 0; i < n; i++){
        cin >> g[i];
    }

    priority_queue<P> pq;
    pq.push({s - 1, 0, 0, 0});
    while(!pq.empty()){
        P now = pq.top();
        pq.pop();

        if(now.y == m - 1){
            cout << now.cnt;
            return 0;
        }

        g[now.x][now.y] = '#';
        for(int i = 0; i < 3; i++){
            int x = now.x + dx[i], y = now.y + dy[i];
            if(x < 0 || x >= n || g[x][y] == '#') continue;
            pq.push({x, y, (i ^ now.cur? now.cnt + 1: now.cnt) ,i});
        }
    }
    cout << -1;

    return 0;
}