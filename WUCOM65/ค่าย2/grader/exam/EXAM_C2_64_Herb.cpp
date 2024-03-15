#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);

    int n,t; cin>>n>>t;
    int arr[n+1][n+1];
    long long dp[n+1][n+1];
    while(t--){
        for(int i=1;i<=n;i++){
            for(int j=1; j<=i;j++){
                cin>>arr[i][j];
            }
        }
        memset(dp,0,sizeof(dp));
        long long mx = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i][j] = arr[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
                mx = max(mx,dp[i][j]);
            }
        } cout << mx << '\n';
    }

    return 0;
}
