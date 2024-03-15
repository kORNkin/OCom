#include<bits/stdc++.h>
using namespace std;
int dp[1000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    int arr[n+1], mx = 0; 
    for(int i=1; i<=n; i++) {
        cin>>arr[i];
        if(i < 3) dp[i] = arr[i];
        for(int j = 2; j <= 5 && i-j > 0 ; j++){
            dp[i] = max(dp[i],dp[i-j]+arr[i]);
        }
        mx = max(mx, dp[i]);
    }
    cout << max(dp[n],dp[n-1]);

    return 0;
}