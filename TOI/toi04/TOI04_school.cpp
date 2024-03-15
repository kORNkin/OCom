#include<bits/stdc++.h>
using namespace std;
int w,l;
char g[65][65];
bool vis[65][65];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool valid(int x,int y){
    if(x<1 || y<1 || x>l || y>w || g[x][y] != 'P')
        return 0;
    return !vis[x][y];
}

void DFS(int x,int y){
    vis[x][y]=1;

    for(int i=0;i<4;i++){
        if(valid(x+dx[i],y+dy[i])){
            DFS(x+dx[i],y+dy[i]);
        }
    }
}

int solve(int i,int j,int k){
    int cnt=0;
    memset(vis,0,sizeof(vis));
    for(int x=i-k+1;x<=i;x++){
        for(int y=j-k+1;y<=j;y++){
            if(!vis[x][y] && g[x][y]=='P'){
                cnt++;
                DFS(x,y);
            }
        }
    } return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>w>>l;
    
    int qs[l+1][w+1]; memset(qs,0,sizeof(qs));
    for(int i=1;i<=l;i++){
        for(int j=1;j<=w;j++){
            cin>>g[i][j];
            qs[i][j]=qs[i][j-1]+qs[i-1][j]+(g[i][j]=='P' || g[i][j]=='S') - qs[i-1][j-1];
        }
    } int mx=0;
    int amt=1e9;
    for(int i=1;i<=l;i++){
        for(int j=1;j<=w;j++){ 
            int k;
            for(k=min(i,j);k>=1;k--){
                if(qs[i][j]-qs[i-k][j]-qs[i][j-k]+qs[i-k][j-k] == k*k){
                    break;
                }
            }
            if(mx < k){
                mx=k;
                amt = solve(i,j,k);
            }
            else if(mx == k){
                int x = solve(i,j,k);
                if(amt > x) amt = x;
            }
        } 
    } 
    if(mx) cout << mx*mx << ' ' << amt;
    else cout << "0 0";

    return 0;   
}