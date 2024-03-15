#include<bits/stdc++.h>
using namespace std;

long long n, arr[100001], dp[100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    memset(dp, 127, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i >= 1) dp[i] = min(dp[i], abs(arr[i] - arr[i - 1]) + dp[i - 1]);
        if(i >= 2) dp[i] = min(dp[i], abs(arr[i] - arr[i - 2]) + dp[i - 2]);
    }
    cout << dp[n - 1];

    return 0;
}