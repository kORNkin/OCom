#include<bits/stdc++.h>
using namespace std;

long long n, k, arr[100001], dp[100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    memset(dp, 127, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];

        for(int j = 1; j <= k && i - j >= 0; j++){
            dp[i] = min(dp[i], abs(arr[i] - arr[i - j]) + dp[i - j]);
        }
    }
    cout << dp[n - 1];

    return 0;
}