#include<bits/stdc++.h>
using namespace std;

int n, m, mx;
bool g[10001][10001], vis[10001][10001];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

bool valid(int x, int y){
    return !vis[x][y] && !g[x][y] && x > 0 && y > 0 && x <= n && y <= m;
}

void solve(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;

    int cnt = 0;
    while(!q.empty()){
        x = q.front().first, y = q.front().second;
        q.pop();

        cnt++;

        bool ch = 0;
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(valid(xx, yy)) { 
                vis[xx][yy] = 1;
                q.push({xx, yy});
            }
        }
    }

    mx = max(cnt, mx);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char c; cin >> c;   
            if(c == '.') g[i][j] = 0;
            else g[i][j] = 1;
        }
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) 
        if(g[i-1][j] || g[i][j-1] || g[i+1][j] || g[i][j+1]) vis[i][j] = 1;
        
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) 
        g[i][j] = vis[i][j];

    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) 
        if(!vis[i][j] && (vis[i-1][j] || vis[i][j-1] || vis[i+1][j] || vis[i][j+1])) 
            g[i][j] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(vis[i][j]) continue;
            if(!g[i][j]) solve(i, j);
        }
    }

    cout << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!g[i][j]) cout << '.';
            else cout << "#";
        } cout << '\n';
    }

    cout << mx;

    return 0;
}

/*

5 7
..#....
....#..
.#.#...
#....#.
..##...

*/

/*
//Second Solution (more memory)

#include<bits/stdc++.h>
using namespace std;

int n, m, mx;
char g[1001][1001];
bool vis[1001][1001];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

bool valid(int x, int y){
    return !vis[x][y] && g[x][y] == '.' && x > 0 && y > 0 && x <= n && y <= m;
}

void solve(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;

    int cnt = 0;
    while(!q.empty()){
        x = q.front().first, y = q.front().second;
        q.pop();

        cnt++;

        bool ch = 0;
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(valid(xx, yy)) { 
                vis[xx][yy] = 1;
                q.push({xx, yy});
            }
        }
    }

    mx = max(cnt, mx);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];   
        }
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) 
        if(g[i-1][j] == '#' || g[i][j-1] == '#' || g[i+1][j] == '#' || g[i][j+1] == '#') 
            g[i][j] = '+';

    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) 
        if(g[i][j] == '.' && (g[i-1][j] == '+' || g[i][j-1] == '+' || g[i+1][j] == '+' || g[i][j+1] == '+')) 
            g[i][j] = '*';

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(vis[i][j]) continue;
            if(g[i][j] == '.') solve(i, j);
        }
    }

    cout << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << g[i][j];
        } cout << '\n';
    }

    cout << mx;

    return 0;
}

*/
