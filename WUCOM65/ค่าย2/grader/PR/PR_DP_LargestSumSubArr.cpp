#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    long long dp[n+1],mx=-1e9;
    dp[0]=-1e9;
    for(int i=1;i<=n;i++){
        long long x; cin>>x;
        dp[i] = max(dp[i-1]+x, x);
        mx = max(mx,dp[i]);
    }
    cout << mx;

	return 0;
}
