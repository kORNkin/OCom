#include<bits/stdc++.h>
using namespace std;
int n;
int g[21][21];
bool vis[21][21];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool valid(int x,int y,int i,int j){
    if(x<1 || y<1 || x>n || y>n || g[i][j] >= g[x][y] || g[x][y]==100)
        return 0;
    return !vis[x][y];
}

int mx = 0;
void flood(int x,int y){
    vis[x][y]=1;
    mx=max(mx,g[x][y]);
    for(int i=0;i<4;i++){
        if(valid(x+dx[i],y+dy[i],x,y)){
            flood(x+dx[i],y+dy[i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    int x,y; cin>>x>>y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    }
    memset(vis,0,sizeof(vis));
    flood(y,x);

    cout << mx;

    return 0;
}