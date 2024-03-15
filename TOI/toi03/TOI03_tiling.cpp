#include<bits/stdc++.h>
using namespace std;
int n;
int arr[18][18];
bool vis[18][18];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int cnt=0;

int chx=0,chy=0;
bool valid(int x,int y,int m){
    if(x<0 || y<0 || x>=n || y>=n || arr[x][y] != m)    
        return 0;
    return !vis[x][y];
}
void DFS(int i,int j,int m){
    cnt++;
    vis[i][j]=1;

    for(int k=0;k<4;k++){
        int x=i+dx[k]; int y=j+dy[k];
        if(valid(x,y,m)){
            chx+=abs(dx[k]), chy+=abs(dy[k]);
            DFS(x,y,m);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];

    int good_plate=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j]){
                cnt=0;
                chx=0; chy=0;
                DFS(i,j,arr[i][j]);
                if(cnt==3 && chx<2 && chy<2) good_plate++;
            }
        }
    } cout << good_plate;

    return 0;
}