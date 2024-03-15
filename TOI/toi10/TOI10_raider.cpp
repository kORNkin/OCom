#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pii pair<int,int>
int n,m;
int g[202][202];
int dx[] = {0,1,0,-1,1,-1};
int dy[] = {1,0,-1,0,1,1};
bool vis[202][202][202];

bool valid(int x,int y, int dis){
    if(x<0 || y<0 || x>=n || y>=m || g[x][y]==0 || dis%g[x][y]!=0)
        return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }

    int md = (n-1)>>1;
    queue<pair<long long,pii>> q;
    if(g[md+1][0]==1) q.emplace(1,make_pair(md+1, 0));
    if(g[md][0]==1)   q.emplace(1,make_pair(md, 0));
    if(g[md-1][0]==1) q.emplace(1,make_pair(md-1, 0));
 
    while(!q.empty()){
        int x = q.front().s.f;
        int y = q.front().s.s;
        long long d = q.front().f;
        q.pop();

        if(vis[x][y][d]) continue;
        if(x == md && y==m-1){
            cout << d;
            return 0;
        }
        vis[x][y][d]=1;
        for(int i=0;i<6;i++){
            int xx=x+dx[i], yy=y+dy[i];
            if(dx[i] != 0 && x%2 == 1) yy--;
            if(valid(xx,yy,d+1)){
                q.emplace(d+1,make_pair(xx,yy));
            }
        }
    }

    return 0;
}