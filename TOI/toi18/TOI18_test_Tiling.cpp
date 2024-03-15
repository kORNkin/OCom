#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    long long int dp[n+1][3];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    dp[1][0]=1;
    dp[1][1]=1;
    dp[1][2]=1;
    for(int i=2;i<=n;i++){
        dp[i][0] = (dp[i-1][0]+dp[i-2][0]+dp[i-2][1]+dp[i-2][2])%mod;
        dp[i][1] = (dp[i-1][2]+dp[i-1][0])%mod;
        dp[i][2] = (dp[i-1][1]+dp[i-1][0])%mod;
    } cout << dp[n][0];

    return 0;
}