#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0;
char g[31][31];
bool vis[31][31];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool h=0;
vector<pair<int,int>> hole;

bool valid(int x,int y){
    if(x<0 || y<0 || x>=n || y>=m || g[x][y]=='#' || (g[x][y]=='H' && h))
        return 0;
    return !vis[x][y];
}

void solve(int x,int y){
    vis[x][y]=1;
    if(g[x][y] == '*') cnt++;
    for(int i=0;i<4;i++){
        if(valid(x+dx[i],y+dy[i])){
            solve(x+dx[i],y+dy[i]);
            if(g[x+dx[i]][y+dy[i]]=='H'){
                h=1;
                for(auto e:hole){
                    solve(e.first,e.second);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    int x,y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]=='C'){
                x=i,y=j;
            }else if(g[i][j]=='H'){
                hole.push_back({i,j});
            }
        }
    }

    memset(vis,0,sizeof(vis));
    solve(x,y);
    cout <<cnt;

    return 0;
}