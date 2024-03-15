#include<bits/stdc++.h>
using namespace std;

long long n;
char g[1001][1001];
bool vis[1001][1001];

long long dx[] = {1, 0, 0, -1};
long long dy[] = {0, 1, -1, 0};

long long ans;

vector<pair<long long, long long>> v;

bool valid(long long x, long long y){
    return x >= 0 && y >= 0 && x < n && y < n && g[x][y] == 'X' && !vis[x][y];
}

void solve(long long x, long long y){
    queue<pair<long long, long long>> q;
    q.push({x, y});
    vis[x][y] = 1;

    int cnt = 0;
    pair<int, int> mn, mx;
    mn = {1e9, 1e9};
    mx = {0, 0};

    while(!q.empty()){
        x = q.front().first, y = q.front().second;
        q.pop();

        cnt++;
        mn = min(mn, {x, y});
        mx = max(mx, {x, y});

        for(long long i = 0; i < 4; i++){
            long long xx = x + dx[i], yy = y + dy[i];
            if(valid(xx, yy)){
                vis[xx][yy] = 1;
                q.push({xx, yy});
            } 
        }
    }

    if((mx.first - mn.first + 1) * (mx.second - mn.second + 1) == cnt) ans++;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
            if(g[i][j] == 'X'){
                v.push_back({i, j});
            }
        }
    }

    for(auto e : v){
        if(vis[e.first][e.second]) continue;
        solve(e.first, e.second);
    }

    cout << ans;

    return 0;
}

/*


000000
00XX00
00XX00
000000

XX00X
XX000
00XXX
X0000
00XX0

*/