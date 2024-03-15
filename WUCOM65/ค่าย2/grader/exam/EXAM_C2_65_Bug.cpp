#include <bits/stdc++.h>
using namespace std;
long long dp[102][102];
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    int n,m; cin>>n>>m;
    int arr[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    long long mx=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = arr[i][j] + max(dp[i-1][j], max(dp[i-1][j-1], dp[i-1][j+1])); 
            mx = max(mx, dp[i][j]);
        }
    }
    cout << mx;
    
    return 0;
}