#include<bits/stdc++.h>
using namespace std;
char g[101][101];
int dis[101][101];
char ch[] = {'R','D','B','B'};
int dx[] = {0,1,0,1};
int dy[] = {1,0,1,0};
int chdx[] = {0,-1,0,-1};
int chdy[] = {-1,0,-1,0};
int n,m;
struct sewer{
    int x,y,t;
};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }

    queue<sewer> q;
    q.push({1,1,1});

    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        int t=q.front().t;
        q.pop();
        
        if(dis[x][y]!=0){
            if(dis[x][y] == t){
                cout << t << '\n' << x << ' ' << y;
                return 0;
            } 
            continue;
        }
        dis[x][y] = t;
        for(int i=0;i<4;i++){
            int xx=x+dx[i], yy=y+dy[i];
            if(xx>0 && yy>0 && xx<=n && yy<=m && g[x][y] == ch[i]){
                q.push({xx,yy,t+1});
            }
            xx=x+chdx[i], yy=y+chdy[i];
            if(xx>0 && yy>0 && xx<=n && yy<=m && g[xx][yy] == ch[i]){
                q.push({xx,yy,t+1});
            }
        }
    }

    return 0;
}