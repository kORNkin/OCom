#include<bits/stdc++.h>
using namespace std;

int n, m, ans[3];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bitset<2005> vis[10005], g[10005];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    string s;
    for(int i = 1; i <= n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            g[i][j + 1] = (s[j] == '0'? 0: 1);
        }
    }   

    queue<pair<int, int>> q;
    int mxi, mxj, mni, mnj, cnt;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(g[i][j] && !vis[i][j]){
                mxi = mxj = cnt = 0;
                mni = mnj = 1e9;
                q.push({i, j});
                vis[i][j] = 1;

                while(!q.empty()){
                    int x = q.front().first , y = q.front().second;
                    q.pop();
                    
                    mxi = max(mxi, x);
                    mni = min(mni, x);
                    mxj = max(mxj, y);
                    mnj = min(mnj, y);
                    cnt++;

                    for(int k = 0; k < 4; k++){
                        int xx = x + dx[k], yy = y + dy[k];
                        if(xx < 1 || yy < 1 || xx > n || yy > m || !g[xx][yy] || vis[xx][yy]) continue;
                        vis[xx][yy] = 1;
                        q.push({xx,yy});
                    }
                }

                if(mxi - mni == mxj - mnj){
                    if(cnt == (mxi - mni + 1) * (mxi - mni + 1)) ans[0]++;
                    else ans[1]++;
                }else ans[2]++;
            }
        }
    }
    
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
    
    return 0;
}