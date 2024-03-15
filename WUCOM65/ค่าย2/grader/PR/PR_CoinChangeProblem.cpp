#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);

    int k;
    cin>>k>>n;
    int dp[k+1],arr[n+1];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++) {
        cin>>arr[i]; dp[arr[i]]=1;
    }

    dp[0]=0;
    for(int i=1;i<=k;i++){
        int ans=1e9;
        for(int j=0;j<n;j++){
            if(i-arr[j] < 0) continue;
            ans = min(ans,dp[i-arr[j]]+1);
        }
        dp[i] = ans;
    }

    cout << dp[k];

	return 0;
}