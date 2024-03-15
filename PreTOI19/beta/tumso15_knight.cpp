#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct G{
    int x,y,deep;
};
int n,m;
int dx[]={-1,-2,-2,-1,1,2,2,1};
int dy[]={-2,-1,1,2,2,1,-1,-2};
bool valid(int x, int y, string g[], vector<vector<bool>> &vis){
    if(x<0 || y<0 || x>=n || y>=m || g[x][y] == '#'){
        return 0;
    } return !vis[x][y];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin>>T;
    while(T--){
        cin>>n>>m;
        string g[n+5];
        vector<vector<bool>> vis(n+5, vector<bool>(m+5,0));
        queue<G> q;
        for(int i=0;i<n;i++) {
            cin>>g[i];
            for(int j=0;j<m;j++){
                if(g[i][j]=='S') q.push({i,j,0}), vis[i][j]=1;
            }
        } 
        vector<G> ans;
        while(!q.empty()){
            int x = q.front().x, y = q.front().y, deep = q.front().deep;
            q.pop();
            for(int i=0;i<8;i++){
                int xx=x+dx[i], yy=y+dy[i];
                if(valid(xx,yy,g,vis)){
                    vis[xx][yy]=1;  
                    if(g[xx][yy] == 'E'){
                        ans.push_back({xx,yy,deep+1});
                    }
                    q.push({xx,yy,deep+1});
                }
            }
        }
        //cout << ans.size() << '\n';
        sort(ans.begin(),ans.end(), [&] (G a,G b){
            if(a.x == b.x) return a.y < b.y;
            return a.x < b.x;
        });
        for(auto e:ans){
            cout << e.x+1 << ' ' << e.y+1 << ' ' << e.deep << '\n';
        }
    }
    return 0;
}
/*
1
5 5
...#.
.#E..
...#.
...E.
S....
*/