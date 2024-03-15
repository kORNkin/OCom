#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
struct flood{
    int cnt,x,y;
};
int n,m;
char g[51][51];
int vis[51][51];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool valid(int x,int y){
    if(x<0 || y<0 || x>=n || y>=m || g[x][y] == 'X' || g[x][y] == 'D' || g[x][y]=='*')
        return 0;
    return !vis[x][y];
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);

    cin>>n>>m;
    queue<flood> q;
    int id,jd;
    vector<pair<int,int>> mem;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]=='S') q.push({0,i,j});
            else if(g[i][j]=='*') mem.push_back({i,j});
        }
    }
    for(auto e:mem) q.push({0,e.f,e.s});
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();

        if(vis[x][y]==1){
            vis[x][y]++;
            continue;
        }

        for(int i=0;i<4;i++){
            int xx=x+dx[i], yy=y+dy[i];
            if(xx>=0 && yy>=0 && xx<n && yy<m && g[x][y] == 'S' && g[xx][yy] == 'D') {
                cout << cnt+1; return 0;
            }   
            if(valid(xx,yy)){
                if(g[xx][yy]=='S') {
                    if(g[x][y]=='*') vis[xx][yy]=1;
                    else continue;
                }
                g[xx][yy] = g[x][y];
                q.push({cnt+1,xx,yy});
            }            
        }        
    }
    cout << "KAKTUS";
    return 0;
}