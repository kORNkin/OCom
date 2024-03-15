#include<bits/stdc++.h>
using namespace std;

long long n, arr[2][4], dp[2][4];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 3; j++){
            cin >> arr[i&1][j];
            for(int k = 1; k <= 3; k++)
                if(k != j) dp[i&1][j] = max(dp[i&1][j], dp[~i&1][k] + arr[i&1][j]);
        }
    }
    long long mx = 0;
    for(int j = 1; j <= 3; j++) mx = max(mx, dp[n&1][j]);
    cout << mx;

    return 0;
}