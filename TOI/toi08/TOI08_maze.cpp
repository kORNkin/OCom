#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pii pair<int,int>
int g[151][151];
int ds[151][151], de[151][151];
int n,m,cnt, ans=1e9;
pair<int,int> arr[2];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
bool valid(int x,int y){ if(x<=0 || y<=0 || x>n || y>m) return 0; else return 1;}
void BFS(int x,int y,int ch){
    queue<pii> q;
    q.push({x,y});
    ds[x][y] = 1;
    de[x][y] = 1;
    while(!q.empty()){
        int x = q.front().f;
        int y = q.front().s;
        q.pop();

        for(int i=0; i<4; i++){
            int xx=x+dx[i], yy=y+dy[i];
            if(ch == 1){
                if(!valid(xx,yy) || ds[xx][yy]) continue;
                ds[xx][yy] = ds[x][y] + 1;
            }else {
                if(!valid(xx,yy) || de[xx][yy]) continue;
                if(ds[xx][yy]) cnt++, ans = min(ans, ds[xx][yy]+de[x][y]);
                de[xx][yy] = de[x][y] + 1;
            }
            if(g[xx][yy]) q.push({xx,yy});
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n>>m;
    cin>>arr[0].f>>arr[0].s;
    cin>>arr[1].f>>arr[1].s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    BFS(arr[0].f,arr[0].s,1);
    BFS(arr[1].f,arr[1].s,-1);

    cout << cnt << '\n' << ans ;      

    return 0;
}