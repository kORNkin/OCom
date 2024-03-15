#include<bits/stdc++.h>
using namespace std;
int n;
int g[1001][1001];
bool vis[1001][1001];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int tarx=0,tary=0;
int mx=0,mn=1e9;

struct Node{
    int k,x,y;
};

bool notValid(int x,int y){
    if(x<0 || y<0 || x>=n || y>=n || g[x][y] >= mn){
        return 1;
    } 
    return vis[x][y];
}
int cnt=0;
void solve(int x,int y,int k,int mx){
    cnt++;
    //cout << x << " " << y << " :" << g[x][y]<< '\n';
    if(x == tarx && y == tary){
        mn = min(mn,mx);
        return;
    }

    vector<Node> arr;
    for(int i=0;i<4;i++){
        int a=x+dx[i], b=y+dy[i];
        if(notValid(a,b)) continue;
        arr.push_back({g[a][b],a,b});
    }
    sort(arr.begin(),arr.end(), [&](Node a,Node b){
        return a.k < b.k;
    });
    for(Node e:arr){
        vis[e.x][e.y] = 1;
        solve(e.x,e.y, e.k , max(mx,e.k));
        vis[e.x][e.y] = 0;
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    int x=-1,y=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
            if(g[i][j]==0) 
            {
                if(tarx!=-1 && tary!=-1){
                    x=i; y=j;
                }else tarx=i,tary=j;
            }
        }
    }
    /*cout << x << " " << y << '\n';
    cout << tarx << ' ' << tary << "\n\n";*/

    memset(vis,0,sizeof(vis));
    vis[x][y] = 1;
    solve(x,y,0,0);

    cout << mn;
    cout << '\n' << cnt;
    return 0;
}
