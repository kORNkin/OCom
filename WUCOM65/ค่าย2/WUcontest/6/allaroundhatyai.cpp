#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int mx=0;
int n, arr[11][11];
bool vis[11];
void solve(int i,int j,int sum){
    if(i==n-1){
        mx = max(sum,mx);
        return;
    }

    for(int k=0;k<n;k++){
        if(!vis[k]){
            vis[k]=1;
            solve(k,j+1,sum+arr[k][j+1]);
            vis[k]=0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

     cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int k=0;k<n;k++){
        vis[k]=1;
        solve(k,0,arr[k][0]);
        vis[k]=0;
    }
    cout << mx;

    return 0;
}