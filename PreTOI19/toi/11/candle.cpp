#include<bits/stdc++.h> //debug for faris
using namespace std;
char c[2001][2001];
bool vis[2001][2001];
int n,m,cnt=0;
short int di[8]={1,1,0,-1,-1,-1,0,1};
short int dj[8]={0,1,1,1,0,-1,-1,-1};
bool is_safe(int i,int j){
    if(i<0||i>=n||j<0||j>=m||c[i][j]=='0'){
        return false;
    }
    return !vis[i][j];
}
void floodfill(short int i,short int j){
    vis[i][j]=1;
    for(int k=0;k<8;k++){
        if(is_safe(i+di[k],j+dj[k])){
            floodfill(i+di[k],j+dj[k]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(short int i=0;i<n;i++){
        for(short int j=0;j<m;j++){
            cin>>c[i][j];
            vis[i][j]=0;
        }
    }
    for(short int i=0;i<n;i++){
        for(short int j=0;j<m;j++){
            if(!vis[i][j]&&c[i][j]=='1'){
                vis[i][j]=1;
                floodfill(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}