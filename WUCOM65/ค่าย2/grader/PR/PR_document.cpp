#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);

    int n,m; cin>>m>>n;
    int arr[n+1][m+1], dp[n+2][m+2];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            dp[i][j] = arr[i][j];
        }
    }
    int mn=1e9;
    for(int j=2;j<=m;j++) {
        for(int i=1;i<=n;i++){
            dp[i][j] = arr[i][j] + min(dp[(i==1)?n:i-1][j-1] , dp[i][j-1]);
            if(j==m) mn = min(mn,dp[i][j]);
        } 
    }
    cout << mn;
    return 0;
}