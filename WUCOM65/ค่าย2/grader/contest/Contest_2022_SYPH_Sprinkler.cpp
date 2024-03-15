#include<bits/stdc++.h>
using namespace std;
char g[101][101];
int cnt[101][101];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;
bool valid(int x,int y){
    if(x<0 || y<0 || x>=n || y>=m || g[x][y]=='X')
        return 0;
    return 1;
}

void flood(int i,int j){
    cnt[i][j]++;
    for(int k=0;k<4;k++){
        int x=i+dx[k],y=j+dy[k];
        while(valid(x,y)){
            cnt[x][y]++;
            x+=dx[k];
            y+=dy[k];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>g[i][j];
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j]=='S')
                flood(i,j);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << cnt[i][j] << ' ';
        } cout << '\n';   
    }
    

    return 0;
}