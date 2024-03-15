#include<bits/stdc++.h>
using namespace std;
bool vis[101];
int arr[101][101];
int n; 
int mx=0;
void solve(int deep,int sum){
    if(deep == n-1){
        mx= max(mx,sum);
        return ;
    }

    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i]=1;
            solve(deep+1,sum+arr[i][deep+1]);
            vis[i]=0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        vis[i]=1;
        solve(0,arr[i][0]);
        vis[i]=0;
    }
    cout << mx;
    return 0;
}