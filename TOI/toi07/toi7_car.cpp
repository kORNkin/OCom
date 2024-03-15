#include <bits/stdc++.h>
using namespace std;

int m, n, t;
int g[101][101];
bitset<101> vis[101];
int dy[] = {-1,1,0};
bool found = 0;

void solve(int x, int y, string s){
    if(found) return;
    if(x == t) {
        for(auto c:s) cout << c << '\n';
        found = 1;
        return;
    }
    vis[x][y] = 1;
    for(int i = 0; i < 3; i++){
        int xx = x + 1, yy = y + dy[i];
        if(vis[xx][yy] || xx < 1 || yy < 1 || xx > t || yy > m || g[xx][yy] == 1) continue;
        s.push_back(i + 1 + '0');
        solve(xx, yy, s);
        s.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> t;
    for(int i = 1; i <= t; i++){
        for(int j = 1; j <= m; j++){
            cin >> g[i][j];
        }
    }

    solve(0,n,"");

    return 0;
}