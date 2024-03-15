#include<bits/stdc++.h>
using namespace std;
char g[201][201];
bool vis[201][201][301][9];
int n, m;
int dx[] = {1,-1,0,0,0};
int dy[] = {0,0,1,-1,0};
struct Map{
    int x, y, gem, gem_cnt, tm, tm_mod; 
};
queue<Map> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            cin >> g[i][j];
            if(g[i][j] == 'G') g[i][j] = 'a' + (cnt++); 
            else if(g[i][j] == 'S') q.push({i, j, 0, 0, 1, 1});
        } 
    }

    while(!q.empty()){
        Map now = q.front();
        q.pop();
        vis[now.x][now.y][now.gem][now.tm_mod] = 1;

        if(g[now.x][now.y] >= 'a' && g[now.x][now.y] <= 'z'){
            if(!(now.gem & (1<<g[now.x][now.y] - 'a'))){
                now.gem |= (1<<g[now.x][now.y] - 'a');
                ++now.gem_cnt;
            }
        }

        if(now.gem_cnt == 7){
            cout << now.tm - 1;
            return 0; 
        }

        ++now.tm;
        ++now.tm_mod;
        if(now.tm_mod == 7) now.tm_mod = 1;
        
        for(int i = 0; i < 5; i++){
            int xx = now.x + dx[i], yy = now.y + dy[i];
            if(xx < 0 || xx >= n || yy < 0 || yy >= m || vis[xx][yy][now.gem][now.tm_mod] || g[xx][yy] == '#') continue;
            if(g[xx][yy] > '0' && g[xx][yy] < '9' && now.tm_mod != g[xx][yy] - '0' && now.gem_cnt < g[xx][yy] - '0') continue;
            vis[xx][yy][now.gem][now.tm_mod] = 1;
            q.push({xx, yy, now.gem, now.gem_cnt, now.tm, now.tm_mod});
        }
    }
    cout << -1;

    return 0;
}