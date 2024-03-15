#include<bits/stdc++.h>
using namespace std;
char g[1002][1002];
int vis[1002][1002];
int n,m;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool valid(int x,int y,int ch){
    if(x<1 || y<1 || x>n || y>m)
        return 0;
    if(ch==1 && g[x][y]=='X')
        return 0;
    if(ch==2 && g[x][y]=='.')
        return 0;
    
    return !vis[x][y];
}

int cnt=0;
void flood(int x,int y,int ch){
    vis[x][y] = ch;
    for(int i=0;i<4;i++){
        int xx=x+dx[i], yy=y+dy[i];
        if(ch==2 && vis[xx][yy]==1) cnt++;
        if(valid(xx,yy,ch)){
            flood(xx,yy,ch);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    vector<pair<int,int>> mem;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
            if(g[i][j] == 'X') mem.push_back({i,j});
        }
    }

    flood(1,1,1);
    int mx=0;
    for(auto e:mem){
        if(!vis[e.first][e.second]){
            cnt=0;
            flood(e.first,e.second,2);
            mx = max(cnt,mx);
        }
    } cout << mx;

    return 0;
}
/*
8 7
.......
.XXXXX.
.X...X.
.X.X.X.
.X.X.X.
.X...X.
.XXXXX.
.......

7 6
......
.X.X..
.X.X..
.X..X.
.X..X.
.XXXX.
......

4 6
......
.X.X..
..X.X.
......

5 6
......
..XX..
.X.XX.
..XX..
......

5 5
.....
..X..
.X.X.
..X..
.....
*/