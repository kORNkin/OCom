#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

    short int n; cin>>n;
    short int a[n], b[n];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    int dp[n+1][n+1]; memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
            }
        }
    }
    cout << dp[n][n];

	return 0;
}