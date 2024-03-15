#include<bits/stdc++.h>
using namespace std;

int n;
double arr[3000], dp[3000][3000], ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0 ; i < n; i++) {
        cin >> arr[i];
    }

    dp[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            dp[i + 1][j + 1] += dp[i][j] * arr[i];
            dp[i + 1][j] += dp[i][j] * (1 - arr[i]);
        }
    }

    for(int i = n / 2 + 1; i <= n; i++) ans += dp[n][i];

    cout.precision(10);
    cout << ans;

    return 0;
}
