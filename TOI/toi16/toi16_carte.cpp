#include<bits/stdc++.h>
using namespace std;

int R, K, mx, arr[401], dp[401][401];

int solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i], dp[i][i] = 1;
    for(int i = n-1; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            dp[i][j] = 1e9;
            for(int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            if(arr[i] == arr[j]) dp[i][j]--;
        }
    }
    return dp[0][n - 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> R >> K;
    for(int i = 0; i < R; i++){
        mx = max(mx, solve());
    }

    cout << mx;

    return 0;
}