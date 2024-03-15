#include<bits/stdc++.h>
using namespace std;
struct Robot{
    int x, y, dis;
};

int n, m, cnt, dp[2001][2001];
long long sum;
vector<pair<int, int>> A;
char g[2001][2001];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    memset(dp, -1, sizeof(dp));
    queue<Robot> q;

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> g[i][j];
            if(g[i][j] == 'A') A.push_back({i, j});
            else if(g[i][j] == 'X') q.push({i, j, 0});
        }
    }

    while(!q.empty()){
        Robot now = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){ 
            int x = now.x + dx[i], y = now.y + dy[i];
            if(x < 1 || y < 1 || x > n || y > m || g[x][y] == 'W') continue;
            if(dp[x][y] == -1 || dp[x][y] > now.dis + 1){
                dp[x][y] = now.dis + 1;
                q.push({x, y, dp[x][y]});
            }
        }
    }

    for(auto a:A){
        if(dp[a.first][a.second] != -1) sum += dp[a.first][a.second], cnt++;
    }

    cout << cnt << ' ' << (sum<<1);

    return 0;
}
