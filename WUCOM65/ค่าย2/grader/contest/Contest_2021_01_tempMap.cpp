#include<bits/stdc++.h>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m;
int arr[101][101];
bool valid(int i,int j){
    if(i<0 || j<0 || i>=n || j>=m || !arr[i][j])
        return 0;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    
    int ans[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            ans[i][j]=arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                int sum=0,co=0;
                for(int k=0;k<4;k++){
                    if(valid(i+dx[k],j+dy[k])){
                        co++;
                        sum+=arr[i+dx[k]][j+dy[k]];
                    }
                }
                if(co) ans[i][j] = floor(sum/co);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << ans[i][j] << ' ';
        } cout << '\n';
    }

    return 0;
}